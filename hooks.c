/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:28:14 by chbeast           #+#    #+#             */
/*   Updated: 2020/03/24 16:25:02 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		move_cam(int key, void *param)
{
	t_rt *rt;

	rt = (t_rt *)param;
	if (key == 124)
		rt->scene->cam.cntr.x -= 0.03;
	if (key == 123)
		rt->scene->cam.cntr.x += 0.03;
	if (key == 125)
		rt->scene->cam.cntr.y += 0.03;
	if (key == 126)
		rt->scene->cam.cntr.y -= 0.03;
	if (key == 27)
		rt->scene->cam.cntr.z -= 0.1;
	if (key == 24)
		rt->scene->cam.cntr.z += 0.1;
	render(rt);
	return (0);
}

int		close_red(void)
{
	exit(0);
}

int		action(int key, void *param)
{
	t_rt *rt;

	rt = (t_rt *)param;
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126
	|| key == 27 || key == 24)
		move_cam(key, rt);
	return (0);
}

void	get_hooks(t_rt *rt)
{
	mlx_hook(rt->win_ptr, 2, 0, action, rt);
	mlx_hook(rt->win_ptr, 17, 0, close_red, rt);
}
