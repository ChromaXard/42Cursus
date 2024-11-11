/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:27:30 by event             #+#    #+#             */
/*   Updated: 2023/03/17 15:47:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes.h"

void	free_list_path(char **paths)
{
	int	line;

	line = 0;
	while (paths[line])
	{
		free(paths[line]);
		line++;
	}
	free(paths);
}
