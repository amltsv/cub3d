/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:12:56 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:16:05 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_line(void *content)
{
	free(content);
}

void	ft_free_map_and_param(t_map *map, t_param *par, t_sprite *sprite)
{
	int i;

	i = -1;
	if (map->map)
		while (map->map[++i])
			free(map->map[i]);
	if (par)
	{
		if (par->ea_img)
			free(par->ea_img);
		if (par->no_img)
			free(par->no_img);
		if (par->so_img)
			free(par->so_img);
		if (par->we_img)
			free(par->we_img);
		if (par->s_img)
			free(par->s_img);
	}
	if (sprite)
		free(sprite);
}

void	ft_free(t_data *img)
{
	ft_free_map_and_param(&img->map, &img->par, img->sprite);
	if (img->win.win && img->win.mlx)
		mlx_destroy_window(img->win.mlx, img->win.win);
	if (img->win.img && img->win.mlx)
		mlx_destroy_image(img->win.mlx, img->win.img);
	exit(0);
}
