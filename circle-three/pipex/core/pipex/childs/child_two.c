/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:25:45 by event             #+#    #+#             */
/*   Updated: 2023/03/17 15:44:58 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

void	child_two(int fd, char *cmd, char **env, int *end)
{
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	close(end[1]);
	close(fd);
	ft_exec_this(cmd, env);
}
