/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:13:03 by fgolino           #+#    #+#             */
/*   Updated: 2024/04/15 10:38:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_text_path(t_data *data)
{
	data->n.img = mlx_xpm_file_to_image(data->mlx,
			data->n.path, &data->n.w, &data->n.h);
	if (!data->n.img)
		return (printf("North texture path is wrong!\n"));
	data->s.img = mlx_xpm_file_to_image(data->mlx,
			data->s.path, &data->s.w, &data->s.h);
	if (!data->s.img)
		return (printf("South texture path is wrong!"));
	data->w.img = mlx_xpm_file_to_image(data->mlx,
			data->w.path, &data->w.w, &data->w.h);
	if (!data->w.img)
		return (printf("West texture path is wrong!"));
	data->e.img = mlx_xpm_file_to_image(data->mlx,
			data->e.path, &data->e.w, &data->e.h);
	if (!data->e.img)
		return (printf("East texture path is wrong!"));
}
