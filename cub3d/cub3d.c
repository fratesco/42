/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:49:42 by fgolino           #+#    #+#             */
/*   Updated: 2024/05/14 12:39:23 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_texture(t_data *data)
{
	int	i;

	i = 0;
	data->def_x = (data->res_w / 2) - 1;
	data->def_y = (data->res_h / 2) - 1;
	data->n.path = NULL;
	data->e.path = NULL;
	data->w.path = NULL;
	data->s.path = NULL;
	data->ceiling.color = 0;
	data->floor.color = 0;
	data->n.img = NULL;
	data->e.img = NULL;
	data->w.img = NULL;
	data->s.img = NULL;
	data->door.img = NULL;
	data->ceiling.img = NULL;
	data->floor.img = NULL;
	data->image.img = NULL;
	while (i < 14)
		data->frames[i++].img = 0;
}

void	initializer(t_data *data)
{
	data->map = NULL;
	data->map_height = 0;
	data->p = 0;
	data->list = NULL;
	data->z = 0;
	data->save_list = 0;
	data->player = malloc(sizeof(t_player));
	data->player->found = 0;
	data->player->r_l = 0;
	data->player->r_r = 0;
	data->player->m_b = 0;
	data->player->m_f = 0;
	data->player->m_r = 0;
	data->player->m_l = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0;
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->res_h = 1080;
	data->res_w = 1920;
	data->frame_c = 1;
	data->window = NULL;
	data->mlx = NULL;
	initialize_texture(data);
}

int	check_input(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc > 2)
		return (printf("Too many arguments\n"));
	else if (argc < 2)
		return (printf("Cub3d needs a .ber file as input!\n"));
	i = ft_strlen(argv[1]);
	if (i < 4)
		return (printf("Input is not a .ber file\n"));
	if (ft_strncmp(&argv[1][i - 4], ".ber", 4))
		return (printf("Input is not a .ber file\n"));
	data->ber_fd = open(argv[1], O_RDONLY);
	if (data->ber_fd == -1)
	{
		if (errno == 2)
			printf("The .ber file does not exist, check the path\n");
		else
			printf("Cub3d: %s: %s\n", argv[1], strerror(errno));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_input(argc, argv, &data))
		exit(1);
	initializer(&data);
	data.mlx = mlx_init();
	if (checker(&data, 0, 0) || !check_map(&data, 0, 0, 1)
		|| find_player(&data, 0, 0) || check_text_path(&data)
		|| create_images(&data))
	{
		get_next_line(-1);
		close(data.ber_fd);
		freerer(&data);
		exit(1);
	}
	close(data.ber_fd);
	mlx_handler(&data);
	return (0);
}
