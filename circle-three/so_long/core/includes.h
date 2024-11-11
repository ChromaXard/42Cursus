/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:12:36 by event             #+#    #+#             */
/*   Updated: 2023/04/05 13:02:41 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//include of the classic librairies (files are in ./lib)
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/libft/libft.h"
// its my include of MLX at my home
//# include "/home/chromaxard/MLX42/include/MLX42/MLX42.h"
# include "/Users/akastler/goinfre/MLX42/include/MLX42/MLX42.h"

//structure for the position or size of the map
typedef struct s_position
{
	int				y;
	int				x;
}					t_position;

//structure for number of each element in the map
typedef struct s_vars_game
{
	t_position		len;
	t_position		cur;
	int				nb_wall;
	int				nb_colec;
	int				nb_start_pos;
	int				nb_exit;
	int				status;
	int				col_pick;
	int				nb_move;
	int				indicator;
	int				l_or_r;
	int				nb_exp;
	mlx_t			*id;
	mlx_image_t		*mlx_string;
	int				*status_ennemy;
	int				*status_wall;
	char			**map;
	int				nb_blocks;
}					t_vars_game;

//structure for images and textures for mlx
typedef struct s_images
{
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_up_right;
	mlx_texture_t	*player_iron_up;
	mlx_texture_t	*player_iron_up_right;
	mlx_texture_t	*player_gold_up;
	mlx_texture_t	*player_gold_up_right;
	mlx_texture_t	*player_diamond_up;
	mlx_texture_t	*player_diamond_up_right;
	mlx_texture_t	*wall;
	mlx_texture_t	*cracked_wall;
	mlx_texture_t	*corner;
	mlx_texture_t	*collec;
	mlx_texture_t	*ground;
	mlx_texture_t	*exit_close1;
	mlx_texture_t	*exit_close2;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*ennemy;
	mlx_texture_t	*ennemy1;
	mlx_texture_t	*ennemy2;
	mlx_texture_t	*exp;
	mlx_texture_t	*dark_exp;
	mlx_texture_t	*torch1;
	mlx_texture_t	*torch2;
	mlx_texture_t	*light;
	mlx_image_t		*player_up_ok;
	mlx_image_t		*player_up_right_ok;
	mlx_image_t		*player_iron_up_ok;
	mlx_image_t		*player_iron_up_right_ok;
	mlx_image_t		*player_gold_up_ok;
	mlx_image_t		*player_gold_up_right_ok;
	mlx_image_t		*player_diamond_up_ok;
	mlx_image_t		*player_diamond_up_right_ok;
	mlx_image_t		*wall_ok;
	mlx_image_t		*cracked_wall_ok;
	mlx_image_t		*corner_ok;
	mlx_image_t		*collec_ok;
	mlx_image_t		*ground_ok;
	mlx_image_t		*exit_close1_ok;
	mlx_image_t		*exit_close2_ok;
	mlx_image_t		*exit_open_ok;
	mlx_image_t		*ennemy_ok;
	mlx_image_t		*ennemy1_ok;
	mlx_image_t		*ennemy2_ok;
	mlx_image_t		*exp_ok;
	mlx_image_t		*dark_exp_ok;
	mlx_image_t		*torch1_ok;
	mlx_image_t		*torch2_ok;
	mlx_image_t		*light_ok;
}					t_images;

typedef struct s_all
{
	mlx_t			*id;
	char			**map;
	t_images		*img;
	t_vars_game		*info;
}					t_all;

//functions of ./map_verif
char				**check_map(char *map, t_vars_game *vars);

//functions of ./map_verif/utils
int					flood_fill(char **tab, t_position size, t_position begin);
int					ft_check_file(char *map);
char				*ft_get_line_map(int fd);
void				ft_info_map(char **map, t_vars_game *info);
void				ft_replace_nl(char **str);

//functions of ./map_verif/utils/ft_info_map_utils
void				ft_add_info_map(char *line, t_vars_game *info, int nb_line);
int					ft_check_wall(char **str, int nb_line);

//functions of ./utils
char				**ft_dup_tab(char **tab);
void				ft_free_tab(char **tab);
void				ft_init_vars(t_vars_game *info);
int					ft_nb_line(char **tab);

//functions of ./core/graphics
void				mlx_funct(char **map, t_vars_game *info);
void				ft_img_window(char **map, t_images *img, mlx_t *id);
void				ft_put_image(t_position cur, char **map, t_images *img,
						mlx_t *id);
void				ft_create_texture(t_images *imgs, mlx_t *id);

//function for the inputs
void				ft_up(mlx_image_t *player, char **map, t_vars_game *info,
						t_images *img);
void				ft_left(mlx_image_t *player, char **map, t_vars_game *info,
						t_images *img);
void				ft_down(mlx_image_t *player, char **map, t_vars_game *info,
						t_images *img);
void				ft_right(mlx_image_t *player, char **map, t_vars_game *info,
						t_images *img);
void				ft_escape(t_images *img, char **map, mlx_t *id,
						t_vars_game *info);
void				ft_move_x(t_images *img, int identify);
void				ft_move_y(t_images *img, int identify);
void				ft_break_wall(t_vars_game *info, mlx_image_t *player,
						t_images *img, mlx_t *id);
void				ft_place_wall(t_vars_game *info, mlx_image_t *player,
						t_images *img, mlx_t *id);
void				ft_attack(t_vars_game *info, mlx_image_t *player,
						t_images *img, mlx_t *id);

//functions for end the game
void				ft_delete_imgs(t_images *img);
void				ft_end_game(t_vars_game *info, mlx_t *id, char **map,
						t_images *img);

//utilities for movements and action
int					ft_find_instance(mlx_image_t *player, mlx_image_t *img,
						int nb_img);
void				ft_pos_is_c(char **map, t_vars_game *info,
						mlx_image_t *player, t_images *img);
void				ft_ennemy(t_images *img, char **map, mlx_t *id,
						t_vars_game *info);
void				ft_pos_is_x(char **map, t_vars_game *info,
						mlx_image_t *player, t_images *img);
int					ft_find_instance_ennemy(int y, int x, mlx_image_t *ennemy);

//bonus function
void				ft_write_move_window(t_vars_game *info);
void				ft_anim(void *all);
void				ft_place_torch(t_vars_game *info, mlx_image_t *player,
						t_images *img);
void				ft_destroy_torch(t_vars_game *info, mlx_image_t *player,
						t_images *img);
void				ft_anim_head(t_all *all, int a, int b);

#endif