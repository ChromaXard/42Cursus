/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:40:11 by event             #+#    #+#             */
/*   Updated: 2023/03/11 12:02:36 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

//includes of ./lib
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strncmp_pipex(const char *s1, const char *s2, size_t n);

//includes of ./pipex
void	pipex(int f1, int f2, char **argv, char **env);

//includes of ./pipex/childs
void	child_one(int fd, char *cmd, char **env, int *end);
void	child_two(int fd, char *cmd, char **env, int *end);

//includes of ./pipex/functions
void	free_list_path(char **paths);
void	ft_exec_this(char *cmd, char **env);
char	*ft_give_correct_path(char *cmd, char **env);

#endif