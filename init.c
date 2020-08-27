/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:43:04 by chbeast           #+#    #+#             */
/*   Updated: 2020/03/11 01:39:41 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <unistd.h>

void	mlx_in(t_rt *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDTH, LENGTH, "RTv1");
	rt->img = mlx_new_image(rt->mlx_ptr, WIDTH, LENGTH);
	rt->data_addr = (int *)mlx_get_data_addr(rt->img, &(rt->bpp),
			&(rt->size_line), &(rt->endian));
}

void	cl_init(char *ker, t_rt *rt)
{
	rt->code = readere();
	rt->ret = clGetPlatformIDs(1, &(rt->platform), NULL);
	rt->ret = clGetDeviceIDs(rt->platform, CL_DEVICE_TYPE_GPU, 1,
			&(rt->device), NULL);
	rt->context = clCreateContext(NULL, 1, &(rt->device),
			NULL, NULL, &(rt->ret));
	rt->cq = clCreateCommandQueue(rt->context, rt->device, 0, &(rt->ret));
	rt->program = clCreateProgramWithSource(rt->context, 1,
			(const char **)&(rt->code), NULL, &(rt->ret));
	free(rt->code);
	rt->ret = clBuildProgram(rt->program, 1, &(rt->device),
			"-I ./", NULL, NULL);
	rt->kernel = clCreateKernel(rt->program, (const char *)ker, &(rt->ret));
}
