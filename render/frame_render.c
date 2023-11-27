/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:12:46 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 15:16:20 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracing.h"

static int	cross_window(int keycode)
{
	(void)keycode;
	printf("Exiting...\n");
	exit(0);
}

static int	key_press(int keycode)
{
	if (keycode == 53)
	{
		printf("Exit !\n");
		exit(0);
	}
	return (0);
}

void	create_frame(t_data data)
{
	t_mlx	ml;
	t_point	origin;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	ml.mlx = mlx_init();
	ml.win = mlx_new_window(ml.mlx, IMAGE_WIDTH, IMAGE_HEIGHT, "Orion Nebula");
	ml.img = mlx_new_image(ml.mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	ml.image_ptr = (unsigned int *)mlx_get_data_addr(ml.img, &ml.bit,
			&ml.size, &ml.endian);
	ray_tracer(data, ml, origin);
	mlx_put_image_to_window(ml.mlx, ml.win, ml.img, 0, 0);
	mlx_key_hook(ml.win, key_press, (void *)0);
	mlx_hook(ml.win, 17, 0, cross_window, (void *)0);
	mlx_loop(ml.mlx);
}
