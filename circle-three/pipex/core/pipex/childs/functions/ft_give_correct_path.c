/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_correct_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:26:18 by event             #+#    #+#             */
/*   Updated: 2023/03/17 15:47:16 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes.h"

static char	*ft_give_path(char **env)
{
	int	line;

	line = 0;
	while (env[line])
	{
		if (ft_strncmp_pipex("PATH=", env[line], 5) == 0)
		{
			return (env[line]);
		}
		line++;
	}
	return (NULL);
}

static char	*ft_give_correct_path_else(char *cmd, char **env)
{
	char	*path;
	char	**all_path;
	char	*cmd_path;
	char	*cmd_slash;
	int		line;

	line = 0;
	path = ft_give_path(env);
	all_path = ft_split(path + 5, ':');
	while (all_path[line] && cmd)
	{
		cmd_slash = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(all_path[line], cmd_slash);
		free(cmd_slash);
		if (access(cmd_path, F_OK | X_OK) == -1)
			line++;
		else
		{
			free_list_path(all_path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_list_path(all_path);
	return (NULL);
}

char	*ft_give_correct_path(char *cmd, char **env)
{
	if (!cmd)
		return (NULL);
	if (ft_strncmp_pipex(cmd, "/", 1) == 0)
	{
		if (access(cmd, F_OK | X_OK) == -1)
			return (NULL);
		else
			return (cmd);
	}
	else
	{
		return (ft_give_correct_path_else(cmd, env));
	}
	return (NULL);
}
