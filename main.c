/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:02:20 by chbeast           #+#    #+#             */
/*   Updated: 2020/07/22 19:52:07 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	*readere(void)
{
	int		fd;
	char	*code;
	char	buf[10000];
	int		red;
	int		i;

	i = 0;
	red = 1;
	fd = open("rtv1.cl", O_RDONLY, 0777);
	red = read(fd, buf, 10000);
	close(fd);
	code = (char *)malloc(sizeof(char) * (red + 1));
	while (i < red)
	{
		code[i] = buf[i];
		i++;
	}
	code[i] = '\0';
	return (code);
}

int		main(int argc, char **argv)
{
	t_rt	*rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		return (0);
	if (read(open(argv[1], O_RDONLY, 0), argv[1], 0) == -1)
		ft_error("file open err");
	rt->scene = parse(argc, argv[1], rt->scene);
	make_normal_scene(rt->scene);
	mlx_in(rt);
	cl_init("raytracering", rt);
	set_buff(rt);
	render(rt);
	get_hooks(rt);
	mlx_loop(rt->mlx_ptr);
	return (0);
}
