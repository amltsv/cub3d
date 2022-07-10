/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:12:46 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 19:48:20 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_max_length(t_list *head)
{
	int length;
	int tmp;

	tmp = 0;
	while (head != NULL)
	{
		if ((length = ft_strlen(head->content)) > tmp)
			tmp = length;
		head = head->next;
	}
	return (tmp);
}

static int		calc_rgb_color(char *src, int *index)
{
	int tmp;
	int count;

	tmp = 0;
	count = 0;
	while (src[*index] >= '0' && src[*index] <= '9')
	{
		tmp = (tmp * 10) + (src[*index] - '0');
		*index += 1;
		count++;
	}
	if (count != 0 && tmp >= 0 && tmp <= 255 &&
		(src[*index] == ',' || src[*index] == '\0'))
		return (tmp);
	return (-1);
}

unsigned long	ft_calc_color(char *src, int *flag, t_data *img)
{
	int				result[3];
	int				index;
	int				count;

	index = 0;
	count = 0;
	while (src[index] != 0 && ft_isspace(src[index]) == 1)
		index++;
	while (src[index] != 0 && count <= 2)
	{
		if ((result[count] = calc_rgb_color(src, &index)) == -1)
			error_msg("Error parse arguments F or C", img);
		else
			count++;
		if (src[index] == ',')
			index++;
	}
	if (count != 3 || src[index] != '\0')
		error_msg("Error parse arguments F or C", img);
	if (*flag == 1)
		error_msg("Second parametr", img);
	else
		*flag += 1;
	return (result[0] << 16 | result[1] << 8 | result[2]);
}

int				load_textures(t_texture *tex, t_win *win, t_param *par)
{
	if ((!(tex->no_tex.img = mlx_xpm_file_to_image(win->mlx, par->no_img,
		&tex->no_tex.width, &tex->no_tex.height)) ||
		!(tex->no_tex.addr = mlx_get_data_addr(tex->no_tex.img,
		&tex->no_tex.bit_pix, &tex->no_tex.length, &tex->no_tex.endian))) ||
		(!(tex->so_tex.img = mlx_xpm_file_to_image(win->mlx, par->so_img,
		&tex->so_tex.width, &tex->so_tex.height)) ||
		!(tex->so_tex.addr = mlx_get_data_addr(tex->so_tex.img,
		&tex->so_tex.bit_pix, &tex->so_tex.length, &tex->so_tex.endian))) ||
		(!(tex->we_tex.img = mlx_xpm_file_to_image(win->mlx, par->we_img,
		&tex->we_tex.width, &tex->we_tex.height)) ||
		!(tex->we_tex.addr = mlx_get_data_addr(tex->we_tex.img,
		&tex->we_tex.bit_pix, &tex->we_tex.length, &tex->we_tex.endian))) ||
		(!(tex->ea_tex.img = mlx_xpm_file_to_image(win->mlx, par->ea_img,
		&tex->ea_tex.width, &tex->ea_tex.height)) ||
		!(tex->ea_tex.addr = mlx_get_data_addr(tex->ea_tex.img,
		&tex->ea_tex.bit_pix, &tex->ea_tex.length, &tex->ea_tex.endian))) ||
		(!(tex->s_tex.img = mlx_xpm_file_to_image(win->mlx, par->s_img,
		&tex->s_tex.width, &tex->s_tex.height)) ||
		!(tex->s_tex.addr = mlx_get_data_addr(tex->s_tex.img,
		&tex->s_tex.bit_pix, &tex->s_tex.length, &tex->ea_tex.endian))))
		return (0);
	return (1);
}

void			make_map(t_data *img, t_list *head, int size)
{
	int		i;
	t_list	*tmp;

	img->map.x = size;
	img->map.y = ft_max_length(head);
	img->map.map = (char **)malloc(sizeof(char *) * (img->map.x + 1));
	img->map.map[img->map.x] = NULL;
	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		img->map.map[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	i = -1;
	if (img->map.map[size - 1][0])
		while (img->map.map[size - 1][++i])
			if (img->map.map[size - 1][i] == '0')
				if (img->map.map[size - 2][i] == '2' ||
					img->map.map[size - 2][i] == ' ' ||
					img->map.map[size - 2][i] == '0')
					error_msg("Invalid map", img);
	ft_check_space(img);
}
