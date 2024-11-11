/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:27:19 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:05:50 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

int	ft_find_instance_ennemy(int y, int x, mlx_image_t *ennemy)
{
	int	inst;

	inst = 0;
	while (inst < ennemy->count)
	{
		if (ennemy->instances[inst].x == x && ennemy->instances[inst].y == y)
			return (inst);
		inst++;
	}
	return (-1);
}

void	ft_pos_is_c(char **map, t_vars_game *info, mlx_image_t *player,
		t_images *img)
{
	map[(player->instances[0].y) / 64][(player->instances[0].x) / 64] = '0';
	info->col_pick++;
	img->collec_ok->instances[ft_find_instance(player, img->collec_ok,
			info->nb_colec)].enabled = false;
	ft_printf("You just picked up a collectible !\n");
	ft_printf("You have %d/%d collectible now\n",
		info->col_pick, info->nb_colec);
	if (info->col_pick == info->nb_colec)
		ft_printf("You can now go to the exit !\n");
}

void	ft_write_move_window(t_vars_game *info)
{
	char	*str;
	char	*nb;
	char	*new;

	info->nb_move++;
	nb = ft_itoa(info->nb_move);
	str = "Number of Steps : ";
	new = ft_strjoin(str, nb);
	free(nb);
	mlx_delete_image(info->id, info->mlx_string);
	info->mlx_string = mlx_put_string(info->id, new, 0, 0);
	ft_printf("%s\n", new);
	free(new);
}
