/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:25:17 by event             #+#    #+#             */
/*   Updated: 2023/03/17 15:44:53 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

void	child_one(int fd, char *cmd, char **env, int *end)
{
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	close(fd);
	ft_exec_this(cmd, env);
}
