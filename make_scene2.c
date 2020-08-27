/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:19:36 by chbeast           #+#    #+#             */
/*   Updated: 2020/07/22 20:03:02 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "rtv1.h"

void			parse_data(char **datastr, t_scene *scene)
{
	if (ft_strequ(datastr[0], "objnum:"))
	{
		scene->n_of_obj = ft_atoi(datastr[1]);
		scene->object = (t_object *)malloc(sizeof(t_object) * scene->n_of_obj);
	}
	else if (ft_strequ(datastr[0], "lightnum:"))
	{
		scene->n_of_light = ft_atoi(datastr[1]);
		scene->light = (t_light *)malloc(sizeof(t_light) * scene->n_of_light);
	}
	else if (ft_strequ(datastr[0], "cam:"))
		cam_data(datastr, scene);
	else if ((ft_strequ(datastr[0], "SPHR:"))
			|| (ft_strequ(datastr[0], "PLANE:"))
			|| (ft_strequ(datastr[0], "CYLINDER:"))
			|| (ft_strequ(datastr[0], "CONE:")))
		obj_data(datastr, scene);
	else if (ft_strequ(datastr[0], "DIRECTIONAL:")
	|| ft_strequ(datastr[0], "POINT:"))
		light_data(datastr, scene);
	else if (ft_strequ(datastr[0], "AMBIENT:"))
		ambient_data(datastr, scene);
	else
		ft_error("invalid data");
}

t_scene			*parse(int argc, char *argv, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**datastr;

	line = NULL;
	datastr = NULL;
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (argc != 2)
		ft_error("data err");
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error("file open err");
	scene->obj_cnt = 0;
	scene->light_cnt = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		datastr = ft_strsplit(line, ' ');
		parse_data(datastr, scene);
		free_tmp(datastr);
		ft_strdel(&line);
	}
	if ((scene->n_of_obj != scene->obj_cnt)
	|| (scene->n_of_light != scene->light_cnt))
		ft_error("wrong count of obj");
	ft_strdel(&line);
	return (scene);
}

void			free_tmp(char **sl)
{
	int	i;

	i = -1;
	while (sl[++i])
		free(sl[i]);
	free(sl);
	sl = NULL;
}

cl_float3		normalaize(cl_float3 v)
{
	float k;

	k = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= k;
	v.y /= k;
	v.z /= k;
	return (v);
}

void			make_normal_scene(t_scene *scene)
{
	int i;

	i = 0;
	while (i < scene->n_of_obj)
	{
		if (scene->object[i].type != SPHR)
			scene->object[i].orient = normalaize(scene->object[i].orient);
		i++;
	}
}
