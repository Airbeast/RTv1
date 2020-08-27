#include "clrtv1.h"

float3		mapping(int gid, float3 o)
{
	float3 v;
	int x = gid % WIDTH;
	int y = gid / WIDTH;
	v.x = (((float)x - (WIDTH / 2)) / (WIDTH)) - o.x;
	v.y = ((-(float)y + (LENGTH / 2)) / (WIDTH)) - o.y;
	v.z = 1.0 - o.z;
	return (v);
}

float3		delta(float3 v1, float3 v2)
{
	return (v1 - v2);
}

float3		mult_k(float3 v1, float k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

float3		mult_v(float3 v1, float3 v2)
{
	float3 v = {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
	return (v);
}

float3		normalaize(float3 v)
{
	float k = sqrt(dot(v, v));
	v.x /= k;
	v.y /= k;
	v.z /= k;
	return (v);
}

float		object_intersect(float3 o, float3 v, t_object object)
{
	float2 res;
	float minc;
	float3 oc = delta(o, object.cntr);
	if (object.type == PLANE)
	{
		minc = dot(-oc, object.orient) / dot(v, object.orient);
		return (minc);
	}
	else
	{
		float3 tmp = delta(v, mult_k(object.orient, dot(v, object.orient)));
		float3 tmp2 = delta(oc, mult_k(object.orient, dot(oc, object.orient)));
		float k1 = cos(object.alpha) * cos(object.alpha) * dot(tmp, tmp) - sin(object.alpha) * sin(object.alpha) * dot(v, object.orient) * dot(v, object.orient);
		float k2 = 2.0 * cos(object.alpha) * cos(object.alpha) * dot(tmp, tmp2) - 2.0 * sin(object.alpha) * sin(object.alpha) * dot(v, object.orient) * dot(oc, object.orient);
		float k3 = cos(object.alpha) * cos(object.alpha) * dot(tmp2, tmp2) - sin(object.alpha) * sin(object.alpha) * dot(oc, object.orient) * dot(oc, object.orient) - object.r * object.r;
		float d = k2 * k2 - 4.0 * k1 * k3;
		if (d < 0.0)
			return (0.0);
		else
		{
			res.x = (-k2 + sqrt(d)) / (2.0 * k1);
			res.y = (-k2 - sqrt(d)) / (2.0 * k1);
		}
		minc = res.x > res.y ? res.y : res.x;
		return (minc);
	}
}

float3		get_normal(float3 p, t_object closest_object)
{
	float3 n;
	if (closest_object.type == PLANE)
		n = closest_object.orient;
	else if (closest_object.type == CONE)
	{
		float3 v1 = mult_v(delta(p, closest_object.cntr), closest_object.orient);
		if (dot(closest_object.orient, delta(p, closest_object.cntr)) < 0)
			v1 = delta(v1, mult_k(v1, 2));
		float3 n0 = mult_v(delta(p, closest_object.cntr), v1);
		float3 cn = n0 + delta(p, closest_object.cntr);
		n = (normalaize(delta(cn, delta(p, closest_object.cntr))));
	}
	else if (closest_object.type == CYLINDER)
	{
		float x = dot(delta(p, closest_object.cntr), closest_object.orient) / sqrt(dot(closest_object.orient, closest_object.orient));
		float3 a = closest_object.cntr + mult_k(closest_object.orient, x);
		n = (normalaize(delta(p, a)));
	}
	else if (closest_object.type == SPHR)
		n = (normalaize(delta(p, closest_object.cntr)));
	return (n);
}

int3		traceray(float3 o, float3 v, __global t_object *object, int n_of_obj, int3 color, __global t_light *light, int n_of_light)
{
	float tmin = 0.0;
	int i = 0;
	float res;
	float closest_t = 100000000.0;
	t_object closest_object;
	while (i < n_of_obj)
	{
		res = object_intersect(o, v, object[i]);
		if ((res < closest_t) && (res > tmin))
		{
			color = object[i].clr;
			closest_t = res;
			closest_object = object[i];
		}
		i++;
	}
	float3 p = o + mult_k(v, closest_t);
	float3 n = get_normal(p, closest_object);
	float k = computelight(p, n, light, n_of_light, n_of_obj, -v, object, closest_object);
	color.x = color.x * k > 255 ? 255 : color.x * k;
	color.y = color.y * k > 255 ? 255 : color.y * k;
	color.z = color.z * k > 255 ? 255 : color.z * k;
	return (color);
}
float		computeshadow(float3 p, float3 pos1, __global t_object *object, int n_of_obj, t_object closest_object, t_light_type light)
{
	float res;
	int i = 0;
	float tmax = (light == POINT) ? 1.0 : 10000.0;
	while (i < n_of_obj)
	{
		res = object_intersect(p, pos1, object[i]);
		if ((res < tmax && res > 0.0001))
			return (0.0);
		i++;
	}
	return (1.0);
}

float		computelight(float3 p, float3 n, __global t_light *light, int n_of_light, int n_of_obj, float3 v, __global t_object *object, t_object closest_object)
{
	float i = 0.0;
	int c = 0;
	while (c < n_of_light)
	{
		if (light[c].type == AMBIENT)
			i += light[c].intensity;
		else
		{
			float3 ps = light[c].type == POINT ? p : mult_k(light[c].position, 2.0);
			float3 pos1 = delta(light[c].position, ps);
			float sh = computeshadow(p, pos1, object, n_of_obj, closest_object, light[c].type);
			float nl1 = dot(n, pos1);
			float3 r = delta(mult_k(n, 2.0 * dot(n, pos1)), pos1);
			float rv = dot(r, v);
			if (nl1 > 0)
				i += (light[c].intensity * nl1 * sh) / sqrt(dot(n, n) * dot(pos1, pos1));
			if ((closest_object.s != -1) && (rv > 0) && nl1 > 0)
				i += (light[c].intensity * sh * pow((rv / sqrt(dot(r, r) * dot(v, v))), closest_object.s));
		}
		c++;
	}
	return (i);
}

__kernel void raytracering(__global int *buf, __global t_object *object, __global t_light *light, int n_of_obj, int n_of_light, t_cam cam)
{
	int gid = get_global_id(0);
	float3 v = mapping(gid, cam.cntr);
	int3 color = {0, 0, 0};
	color = traceray(cam.cntr, v, object, n_of_obj, color, light, n_of_light);
	buf[gid] = (color.x << 16 | color.y << 8 | color.z);
}
