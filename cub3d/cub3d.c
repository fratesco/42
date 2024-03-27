/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:49:42 by fgolino           #+#    #+#             */
/*   Updated: 2024/03/27 12:34:12 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "cub3d.h"

void	initializer(t_data *data)
{
	data->map = NULL;
	data->n_path = NULL;
	data->e_path = NULL;
	data->w_path = NULL;
	data->s_path = NULL;
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
	checker(&data);
	close(data.ber_fd);
	freerer(&data);
	//void	*mlx;
	//void	*mlx_win;
//
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1280, 800, "Hello world!");
	//mlx_loop(mlx);
	

}