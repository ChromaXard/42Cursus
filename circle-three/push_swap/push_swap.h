/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:47 by akastler          #+#    #+#             */
/*   Updated: 2023/01/28 14:43:32 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct s_list
{
	t_elem			*first;
	t_elem			*last;
	int				max_decal;
}					t_list;

typedef struct s_vars_radix
{
	t_list			*pile_b;
	int				decal;
	int				rota;
	int				tl;
}					t_vars_radix;

int					ft_push_swap(t_list *lst, char **argv);
int					ft_build_list(char **argv, t_list *lst);
int					ft_verif_char(char *str);
int					ft_verif_multiple_int(char *str);
char				*ft_strchr(const char *s, int c);
void				ft_clear_list(t_list *lst);
int					ft_deltop(t_list *lst);
void				ft_pushbottom(t_list *lst, int val, int index);
void				ft_pushtop(t_list *lst, int val, int index);
void				ft_view_list(t_list lst);
int					ft_build_str(char *str, t_list *lst);
int					ft_atoi(const char *str);
int					ft_verif_int(char *str);
char				*ft_itoa(int n);
int					ft_build_int(char *str, t_list *lst);
void				ft_init(t_list *lst);
void				ft_algo(t_list *lst);
void				ft_indexation(t_list *lst);
int					ft_verif_dup(t_list *lst);
int					ft_len_lst(t_list *lst);
void				ft_rotate_a(t_list *list);
void				push_a(t_list *pile_b, t_list *pile_a);
void				push_b(t_list *pile_a, t_list *pile_b);
int					ft_list_sorted(t_list *lst);
void				ft_swap_a(t_list *lst);
void				ft_reverse_rotate_a(t_list *lst);
void				ft_sort_mid(t_list *lst);
void				ft_sort_min(t_list *lst);

#endif