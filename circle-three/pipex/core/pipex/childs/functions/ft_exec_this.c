/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_this.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:30:15 by event             #+#    #+#             */
/*   Updated: 2023/03/20 15:30:09 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes.h"

void	ft_exec_this(char *cmd, char **env)
{
	char	*correct_path;
	char	**command_split;
	int		i;

	i = 0;
	command_split = ft_split(cmd, ' ');
	correct_path = ft_give_correct_path(command_split[0], env);
	if (execve(correct_path, command_split, env) == -1)
	{
		free_list_path(command_split);
		write(2, "pipex: ", 8);
		while (cmd[i])
			write(2, &cmd[i++], 1);
		write(2, ": command not found\n", 21);
		exit(1);
	}
}
