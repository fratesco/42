/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratesco <fratesco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:56:35 by mg                #+#    #+#             */
/*   Updated: 2024/04/28 23:34:58 by fratesco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_destroy_display(t_xvar *xvar)
{
	XCloseDisplay(xvar->display);
	free(xvar);
}
