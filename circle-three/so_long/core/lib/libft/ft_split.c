/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:34:38 by akastler          #+#    #+#             */
/*   Updated: 2022/11/14 13:10:40 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_word(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (s[k] == c)
			j = 0;
		k++;
	}
	return (i);
}

static char	*ft_dupv2(char const *str, char c, size_t start)
{
	char	*s1;
	size_t	end;
	int		i;

	end = start;
	i = 0;
	while (str[end] != c && str[end])
		end++;
	s1 = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!s1)
		return (NULL);
	while (start < end && str[start])
	{
		s1[i++] = str[start++];
	}
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	str = ft_calloc((ft_word(s, c) + 1), sizeof(char *));
	if (!str)
		return (free_tab(str));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (j < ft_word(s, c))
		{
			str[j] = ft_dupv2(s, c, i);
			if (str[j++] == 0)
				return (free_tab(str));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (str);
}
