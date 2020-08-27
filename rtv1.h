/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:16:48 by chbeast           #+#    #+#             */
/*   Updated: 2020/07/22 20:02:34 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <OpenCL/opencl.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include "./minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH 1920
# define LENGTH 1080

typedef struct			s_cam
{
	cl_float3			cntr;
	cl_float3			orient;
}						t_cam;

typedef enum
{
	PLANE,
	SPHR,
	CYLINDER,
	CONE
}	t_type;

typedef struct			s_object
{
	t_type				type;
	cl_float3			cntr;
	cl_float3			orient;
	float				r;
	float				alpha;
	cl_int3				clr;
	int					s;
}						t_object;

typedef	enum
{
	AMBIENT,
	POINT,
	DIRECTIONAL
}	t_light_type;

typedef	struct			s_light
{
	t_light_type		type;
	float				intensity;
	cl_float3			position;
}						t_light;

typedef	struct			s_scene
{
	t_light				*light;
	t_object			*object;
	t_cam				cam;
	int					n_of_obj;
	int					n_of_light;
	int					obj_cnt;
	int					light_cnt;

}						t_scene;

typedef struct			s_rt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	int					*data_addr;
	int					bpp;
	int					size_line;
	int					endian;
	cl_int				ret;
	cl_platform_id		platform;
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	cq;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				buf;
	cl_mem				obj_buf;
	cl_mem				light_buf;
	char				*code;
	size_t				global_work_size[1];
	t_scene				*scene;
}						t_rt;

t_scene					*make_scene(void);
char					*readere(void);
void					mlx_in(t_rt *rt);
void					cl_init(char *ker, t_rt *rt);
void					set_buff(t_rt *rt);
void					set_args(t_rt *rt);
void					render(t_rt *rt);
int						move_cam(int key, void *param);
int						close_red(void);
int						action(int key, void *param);
void					get_hooks(t_rt *rt);
void					make_normal_scene(t_scene *scene);
cl_float3				normalaize(cl_float3 v);
t_scene					*parse(int argc, char *argv, t_scene *scene);
void					parse_data(char **datastr, t_scene *scene);
void					ft_error(char *str);
void					cam_data(char **datastr, t_scene *scene);
void					obj_data(char **datastr, t_scene *scene);
void					light_data(char **datastr, t_scene *scene);
void					ambient_data(char **datastr, t_scene *scene);
void					free_tmp(char **sl);

#endif
