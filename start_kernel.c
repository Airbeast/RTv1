/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_kernel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:11:35 by chbeast           #+#    #+#             */
/*   Updated: 2020/03/20 19:15:30 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	set_buff(t_rt *rt)
{
	int	memlength;
	int	obj_length;
	int	light_length;

	memlength = sizeof(int) * WIDTH * LENGTH;
	obj_length = sizeof(t_object) * rt->scene->n_of_obj;
	light_length = sizeof(t_light) * rt->scene->n_of_light;
	rt->buf = clCreateBuffer(rt->context,
			CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
			memlength, rt->data_addr, &(rt->ret));
	rt->obj_buf = clCreateBuffer(rt->context, CL_MEM_READ_WRITE
	| CL_MEM_USE_HOST_PTR, obj_length, rt->scene->object, &(rt->ret));
	rt->light_buf = clCreateBuffer(rt->context, CL_MEM_READ_WRITE
	| CL_MEM_USE_HOST_PTR, light_length, rt->scene->light, &(rt->ret));
	rt->global_work_size[0] = WIDTH * LENGTH;
}

void	set_args(t_rt *rt)
{
	rt->ret = clSetKernelArg(rt->kernel, 0, sizeof(cl_mem),
			(const void *)&(rt->buf));
	rt->ret = clSetKernelArg(rt->kernel, 1, sizeof(cl_mem),
			(const void *)&(rt->obj_buf));
	rt->ret = clSetKernelArg(rt->kernel, 2, sizeof(cl_mem),
			(const void *)&(rt->light_buf));
	rt->ret = clSetKernelArg(rt->kernel, 3, sizeof(int),
			(const void *)&(rt->scene->n_of_obj));
	rt->ret = clSetKernelArg(rt->kernel, 4, sizeof(int),
			(const void *)&(rt->scene->n_of_light));
	rt->ret = clSetKernelArg(rt->kernel, 5, sizeof(t_cam),
			(const void *)&(rt->scene->cam));
}

void	render(t_rt *rt)
{
	rt->ret = clEnqueueWriteBuffer(rt->cq, rt->obj_buf, CL_TRUE, 0,
			sizeof(t_object) * rt->scene->n_of_obj,
			rt->scene->object, 0, NULL, NULL);
	rt->ret = clEnqueueWriteBuffer(rt->cq, rt->light_buf, CL_TRUE, 0,
			sizeof(t_light) * rt->scene->n_of_light,
			rt->scene->light, 0, NULL, NULL);
	set_args(rt);
	rt->ret = clEnqueueNDRangeKernel(rt->cq, rt->kernel, 1, NULL,
			rt->global_work_size, NULL, 0, NULL, NULL);
	rt->ret = clEnqueueReadBuffer(rt->cq, rt->buf, CL_TRUE, 0,
			sizeof(int) * WIDTH * LENGTH,
			rt->data_addr, 0, NULL, NULL);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img, 0, 0);
}
