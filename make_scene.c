/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 00:24:41 by chbeast           #+#    #+#             */
/*   Updated: 2020/07/22 18:21:06 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "rtv1.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	cam_data(char **datastr, t_scene *scene)
{
	if (datastr[7] || !datastr[6])
		ft_error("parameter error");
	scene->cam.cntr = (cl_float3){{ft_atof(datastr[1]),
	ft_atof(datastr[2]), ft_atof(datastr[3])}};
	scene->cam.orient = (cl_float3){{ft_atof(datastr[4]),
	ft_atof(datastr[5]), ft_atof(datastr[6])}};
}

void	obj_data(char **datastr, t_scene *scene)
{
	if (datastr[13] || !datastr[12])
		ft_error("parameter error");
	if (ft_strequ(datastr[0], "CONE:"))
		scene->object[scene->obj_cnt].type = CONE;
	else if (ft_strequ(datastr[0], "PLANE:"))
		scene->object[scene->obj_cnt].type = PLANE;
	else if (ft_strequ(datastr[0], "SPHR:"))
		scene->object[scene->obj_cnt].type = SPHR;
	else if (ft_strequ(datastr[0], "CYLINDER:"))
		scene->object[scene->obj_cnt].type = CYLINDER;
	scene->object[scene->obj_cnt].cntr = (cl_float3){{ft_atof(datastr[1]),
	ft_atof(datastr[2]), ft_atof(datastr[3])}};
	scene->object[scene->obj_cnt].orient = (cl_float3){{ft_atof(datastr[4]),
	ft_atof(datastr[5]), ft_atof(datastr[6])}};
	scene->object[scene->obj_cnt].r = ft_atof(datastr[7]);
	scene->object[scene->obj_cnt].alpha = ft_atof(datastr[8]);
	scene->object[scene->obj_cnt].clr = (cl_int3){{ft_atoi(datastr[9]),
	ft_atoi(datastr[10]), ft_atoi(datastr[11])}};
	scene->object[scene->obj_cnt].s = ft_atof(datastr[12]);
	scene->obj_cnt++;
}

void	ambient_data(char **datastr, t_scene *scene)
{
	if (datastr[2] || !datastr[1])
		ft_error("parameter error");
	scene->light[scene->light_cnt].type = AMBIENT;
	scene->light[scene->light_cnt].intensity = ft_atof(datastr[1]);
	scene->light_cnt++;
}

void	light_data(char **datastr, t_scene *scene)
{
	if (datastr[5] || !datastr[4])
		ft_error("parameter error");
	if (ft_strequ(datastr[0], "POINT:"))
		scene->light[scene->light_cnt].type = POINT;
	else
		scene->light[scene->light_cnt].type = DIRECTIONAL;
	scene->light[scene->light_cnt].intensity = ft_atof(datastr[1]);
	scene->light[scene->light_cnt].position = (cl_float3){{ft_atof(datastr[2]),
	ft_atof(datastr[3]), ft_atof(datastr[4])}};
	scene->light_cnt++;
}
