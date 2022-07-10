/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:59:02 by teevee            #+#    #+#             */
/*   Updated: 2020/10/28 20:59:03 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_param(t_param *param)
{
	param->c_col = 0;
	param->f_col = 0;
	param->dir = '\0';
	param->ea_img = NULL;
	param->we_img = NULL;
	param->so_img = NULL;
	param->s_img = NULL;
	param->no_img = NULL;
	param->f = 0;
	param->c = 0;
}

void	init_keys(t_key *key)
{
	key->down = 0;
	key->up = 0;
	key->left = 0;
	key->right = 0;
	key->r_right = 0;
	key->r_left = 0;
}
