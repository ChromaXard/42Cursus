/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:52 by akastler          #+#    #+#             */
/*   Updated: 2023/04/04 12:13:20 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_text_to_img2(t_images *img, mlx_t *id)
{
	img->exp_ok = mlx_texture_to_image(id, img->exp);
	img->dark_exp_ok = mlx_texture_to_image(id, img->dark_exp);
	img->torch1_ok = mlx_texture_to_image(id, img->torch1);
	img->torch2_ok = mlx_texture_to_image(id, img->torch2);
	img->light_ok = mlx_texture_to_image(id, img->light);
}

static void	ft_text_to_img(t_images *img, mlx_t *id)
{
	img->ground_ok = mlx_texture_to_image(id, img->ground);
	img->exit_close1_ok = mlx_texture_to_image(id, img->exit_close1);
	img->exit_close2_ok = mlx_texture_to_image(id, img->exit_close2);
	img->exit_open_ok = mlx_texture_to_image(id, img->exit_open);
	img->player_up_ok = mlx_texture_to_image(id, img->player_up);
	img->player_up_right_ok = mlx_texture_to_image(id, img->player_up_right);
	img->player_iron_up_ok = mlx_texture_to_image(id, img->player_iron_up);
	img->player_iron_up_right_ok
		= mlx_texture_to_image(id, img->player_iron_up_right);
	img->player_gold_up_ok
		= mlx_texture_to_image(id, img->player_gold_up);
	img->player_gold_up_right_ok
		= mlx_texture_to_image(id, img->player_gold_up_right);
	img->player_diamond_up_ok
		= mlx_texture_to_image(id, img->player_diamond_up);
	img->player_diamond_up_right_ok
		= mlx_texture_to_image(id, img->player_diamond_up_right);
	img->wall_ok = mlx_texture_to_image(id, img->wall);
	img->cracked_wall_ok = mlx_texture_to_image(id, img->cracked_wall);
	img->corner_ok = mlx_texture_to_image(id, img->corner);
	img->collec_ok = mlx_texture_to_image(id, img->collec);
	img->ennemy_ok = mlx_texture_to_image(id, img->ennemy);
	img->ennemy1_ok = mlx_texture_to_image(id, img->ennemy1);
	img->ennemy2_ok = mlx_texture_to_image(id, img->ennemy2);
	ft_text_to_img2(img, id);
}

static void	ft_create_texture2(t_images *imgs)
{
	imgs->player_up = mlx_load_png("./core/graphics/texture/player_up.png");
	imgs->player_up_right
		= mlx_load_png("./core/graphics/texture/player_up_right.png");
	imgs->player_iron_up
		= mlx_load_png("./core/graphics/texture/player_iron.png");
	imgs->player_iron_up_right
		= mlx_load_png("./core/graphics/texture/player_iron_right.png");
	imgs->player_gold_up
		= mlx_load_png("./core/graphics/texture/player_gold.png");
	imgs->player_gold_up_right
		= mlx_load_png("./core/graphics/texture/player_gold_right.png");
	imgs->player_diamond_up
		= mlx_load_png("./core/graphics/texture/player_diamond.png");
	imgs->player_diamond_up_right
		= mlx_load_png("./core/graphics/texture/player_diamond_right.png");
	imgs->torch1 = mlx_load_png("./core/graphics/texture/torch1.png");
	imgs->torch2 = mlx_load_png("./core/graphics/texture/torch2.png");
	imgs->light = mlx_load_png("./core/graphics/texture/light.png");
}

void	ft_create_texture(t_images *imgs, mlx_t *id)
{
	imgs->ground = mlx_load_png("./core/graphics/texture/ground.png");
	imgs->exit_close1 = mlx_load_png("./core/graphics/texture/exit_close.png");
	imgs->exit_close2 = mlx_load_png("./core/graphics/texture/exit_close2.png");
	imgs->exit_open = mlx_load_png("./core/graphics/texture/exit_open.png");
	imgs->wall = mlx_load_png("./core/graphics/texture/wall.png");
	imgs->cracked_wall
		= mlx_load_png("./core/graphics/texture/cracked_wall.png");
	imgs->corner = mlx_load_png("./core/graphics/texture/corner.png");
	imgs->collec = mlx_load_png("./core/graphics/texture/collec.png");
	imgs->ennemy = mlx_load_png("./core/graphics/texture/ennemy.png");
	imgs->ennemy1 = mlx_load_png("./core/graphics/texture/ennemy1.png");
	imgs->ennemy2 = mlx_load_png("./core/graphics/texture/ennemy2.png");
	imgs->exp = mlx_load_png("./core/graphics/texture/exp.png");
	imgs->dark_exp = mlx_load_png("./core/graphics/texture/dark_exp.png");
	ft_create_texture2(imgs);
	if (imgs->ground && imgs->exit_close1 && imgs->exit_close2
		&& imgs->exit_open && imgs->wall && imgs->cracked_wall && imgs->corner
		&& imgs->collec && imgs->ennemy && imgs->ennemy1 && imgs->ennemy2
		&&imgs->dark_exp && imgs->exp && imgs->player_up
		&& imgs->player_up_right && imgs->player_iron_up
		&& imgs->player_iron_up_right && imgs->player_gold_up
		&& imgs->player_gold_up_right && imgs->player_diamond_up
		&& imgs->player_diamond_up_right && imgs->torch1 && imgs->torch2
		&& imgs->light)
		ft_text_to_img(imgs, id);
}
