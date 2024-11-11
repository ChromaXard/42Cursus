/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:02:36 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 12:42:48 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static int	ft_next_pos_wall(char **map, int y, int x)
{
	if (map[y / 64][x / 64] == '1' || map[y / 64][x / 64] == '9'
	/*|| map[y / 64][x / 64] == 'T'*/)
		return (1);
	return (0);
}

void	ft_up(mlx_image_t *player, char **map, t_vars_game *info, t_images *img)
{
	if (ft_next_pos_wall(map, player->instances[0].y - 64,
			player->instances[0].x))
		return ;
	if (map[(player->instances[0].y - 64) / 64][(player->instances[0].x)
		/ 64] == 'E')
	{
		if (info->col_pick == info->nb_colec)
			ft_end_game(info, info->id, map, img);
		ft_printf("tu n'as pas encore ramassé tout les collectibles\n");
	}
	else
	{
		ft_move_y(img, -1);
		ft_write_move_window(info);
		if (map[player->instances[0].y / 64][player->instances[0].x
			/ 64] == 'C')
			ft_pos_is_c(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'X')
			ft_pos_is_x(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'K')
			ft_ennemy(img, map, info->id, info);
	}
}

void	ft_left(mlx_image_t *player, char **map, t_vars_game *info,
		t_images *img)
{
	if (ft_next_pos_wall(map, player->instances[0].y,
			player->instances[0].x - 64))
		return ;
	if (map[(player->instances[0].y) / 64][(player->instances[0].x - 64)
		/ 64] == 'E')
	{
		if (info->col_pick == info->nb_colec)
			ft_end_game(info, info->id, map, img);
		ft_printf("tu n'as pas encore ramassé tout les collectibles\n");
	}
	else
	{
		ft_move_x(img, -1);
		info->l_or_r = 0;
		ft_write_move_window(info);
		if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'C')
			ft_pos_is_c(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'X')
			ft_pos_is_x(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'K')
			ft_ennemy(img, map, info->id, info);
	}
}

void	ft_down(mlx_image_t *player, char **map, t_vars_game *info,
		t_images *img)
{
	if (ft_next_pos_wall(map, player->instances[0].y + 64,
			player->instances[0].x))
		return ;
	if (map[(player->instances[0].y + 64) / 64][(player->instances[0].x)
		/ 64] == 'E')
	{
		if (info->col_pick == info->nb_colec)
			ft_end_game(info, info->id, map, img);
		else
			ft_printf("tu n'as pas encore ramassé tout les collectibles\n");
	}
	else
	{
		ft_move_y(img, 1);
		ft_write_move_window(info);
		if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'C')
			ft_pos_is_c(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'X')
			ft_pos_is_x(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'K')
			ft_ennemy(img, map, info->id, info);
	}
}

void	ft_right(mlx_image_t *player, char **map, t_vars_game *info,
		t_images *img)
{
	if (ft_next_pos_wall(map, player->instances[0].y,
			player->instances[0].x + 64))
		return ;
	if (map[(player->instances[0].y) / 64][(player->instances[0].x + 64)
		/ 64] == 'E')
	{
		if (info->col_pick == info->nb_colec)
			ft_end_game(info, info->id, map, img);
		ft_printf("tu n'as pas encore ramassé tout les collectibles\n");
	}
	else
	{
		ft_move_x(img, 1);
		info->l_or_r = 1;
		ft_write_move_window(info);
		if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'C')
			ft_pos_is_c(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'X')
			ft_pos_is_x(map, info, player, img);
		else if (map[(player->instances[0].y) / 64][(player->instances[0].x)
			/ 64] == 'K')
			ft_ennemy(img, map, info->id, info);
	}
}
