/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:25:37 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 13:46:06 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static int	if_is_so_long(t_all *all, int inst)
{
	if (all->img->torch1_ok->instances[inst].enabled == true
		|| (inst < all->info->len.x * all->info->len.x
			&& all->img->torch1_ok->instances[inst + 1].enabled == true)
		|| (inst > 0 && all->img->torch1_ok->instances[inst
				- 1].enabled == true) || (inst > all->info->len.x
			&& (all->img->torch1_ok->instances[inst - all->info->len.x
					- 1].enabled == true || all->img->torch1_ok->instances[inst
					- all->info->len.x + 1].enabled == true
				|| all->img->torch1_ok->instances[inst
					- all->info->len.x].enabled == true))
		|| (inst < all->info->len.y * all->info->len.x
			&& (all->img->torch1_ok->instances[inst + all->info->len.x
					- 1].enabled == true || all->img->torch1_ok->instances[inst
					+ all->info->len.x + 1].enabled == true
				|| all->img->torch1_ok->instances[inst
					+ all->info->len.x].enabled == true)))
	{
		return (1);
	}
	return (0);
}

static void	ft_anim4(t_all *all)
{
	t_position	cur;
	int			inst;

	cur.y = -1;
	inst = 0;
	while (all->map[++cur.y])
	{
		cur.x = -1;
		while (all->map[cur.y][++cur.x])
		{
			inst = ft_find_instance_ennemy(cur.y * 64, cur.x * 64,
					all->img->light_ok);
			if (if_is_so_long(all, inst))
				all->img->light_ok->instances[inst].enabled = true;
			else
				all->img->light_ok->instances[inst].enabled = false;
		}
	}
}

static void	ft_anim3(t_all *all)
{
	if (all->info->indicator % 25 == 0)
	{
		all->img->exit_close1_ok->instances[0].enabled = false;
		all->img->exit_close2_ok->instances[0].enabled = true;
	}
	else
	{
		all->img->exit_close1_ok->instances[0].enabled = true;
		all->img->exit_close2_ok->instances[0].enabled = false;
	}
	if (all->info->col_pick == all->info->nb_colec)
		all->img->exit_open_ok->instances[0].enabled = true;
	all->info->indicator++;
	ft_anim4(all);
}

static void	ft_anim2(t_all *all)
{
	int	i;

	i = -1;
	if (all->info->indicator % 100 == 0)
	{
		while (++i < all->img->dark_exp_ok->count)
		{
			all->img->dark_exp_ok->instances[i].enabled = false;
		}
		all->img->torch2_ok->enabled = false;
		all->info->indicator = 0;
	}
	else
	{
		while (++i < all->img->dark_exp_ok->count)
		{
			if (all->img->exp_ok->instances[i].enabled == true)
			{
				all->img->dark_exp_ok->instances[i].enabled = true;
				all->img->torch2_ok->enabled = true;
			}
		}
		all->img->torch2_ok->enabled = true;
	}
	ft_anim3(all);
}

void	ft_anim(void *mlx)
{
	t_all	*all;
	int		a;
	int		b;

	all = mlx;
	a = 0;
	b = 0;
	if (all->info->l_or_r == 1)
		a = 1;
	else
		b = 1;
	if (all->info->nb_exp < 3)
	{
		all->img->player_up_right_ok->instances[0].enabled = a;
		all->img->player_up_ok->instances[0].enabled = b;
	}
	else if (all->info->nb_exp < 6)
	{
		all->img->player_up_right_ok->instances[0].enabled = false;
		all->img->player_up_ok->instances[0].enabled = false;
		all->img->player_iron_up_right_ok->instances[0].enabled = a;
		all->img->player_iron_up_ok->instances[0].enabled = b;
	}
	ft_anim_head(all, a, b);
	ft_anim2(all);
}
