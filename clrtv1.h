/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clrtv1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 22:51:28 by chbeast           #+#    #+#             */
/*   Updated: 2020/07/22 19:26:17 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLRTV1_H
# define CLRTV1_H

# define WIDTH 1920
# define LENGTH 1080

typedef struct	s_cam 
{
	float3	cntr;
	float3	orient;
}				t_cam;

typedef enum
{
	PLANE,
	SPHR,
	CYLINDER,
	CONE
}	t_type;

typedef struct	s_object
{
	t_type		type;
	float3		cntr;
	float3		orient;
	float		r;
	float		alpha;
	int3		clr;
	int			s;
}				t_object;

typedef	enum
{
	AMBIENT,
	POINT,
	DIRECTIONAL
}	t_light_type;

typedef	struct	s_light
{
	t_light_type	type;
	float			intensity;
	float3			position;
}					t_light;

typedef	struct	s_scene
{
	t_light		*light;
	t_object	*object;
	t_cam		cam;
	int			n_of_obj;
	int			n_of_light;

}				t_scene;

float3		mapping(int gid, float3 o);
float3		delta(float3 v1, float3 v2);
float3		mult_k(float3 v1, float k);
float3		mult_v(float3 v1, float3 v2);
float3		normalaize(float3 v);
float		object_intersect(float3 o, float3 v, t_object object);
float3		get_normal(float3 p, t_object closest_object);
int3		traceray(float3 o, float3 v, __global t_object *object, int n_of_obj, int3 color, __global t_light *light, int n_of_light);
float		computelight(float3 p, float3 n, __global t_light *light, int n_of_light, int n_of_obj, float3 v, __global t_object *object, t_object closest_object);
float		computeshadow(float3 p, float3 pos1, __global t_object *object, int n_of_obj, t_object closest_object, t_light_type light);
#endif
