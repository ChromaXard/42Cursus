/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:01:44 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 13:08:38 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_anim_head(t_all *all, int a, int b)
{
	if (all->info->nb_exp < 9 && all->info->nb_exp > 5)
	{
		all->img->player_iron_up_right_ok->instances[0].enabled = false;
		all->img->player_iron_up_ok->instances[0].enabled = false;
		all->img->player_gold_up_right_ok->instances[0].enabled = a;
		all->img->player_gold_up_ok->instances[0].enabled = b;
	}
	else if (all->info->nb_exp >= 9)
	{
		all->img->player_gold_up_right_ok->instances[0].enabled = false;
		all->img->player_gold_up_ok->instances[0].enabled = false;
		all->img->player_diamond_up_right_ok->instances[0].enabled = a;
		all->img->player_diamond_up_ok->instances[0].enabled = b;
	}
}
