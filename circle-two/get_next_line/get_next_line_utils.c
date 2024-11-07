/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:56:50 by akastler          #+#    #+#             */
/*   Updated: 2023/01/02 14:36:50 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*temp;
// 	size_t			i;

// 	i = 0;
// 	temp = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		*(char *)(temp + i) = '\0';
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	unsigned char	*point;

// 	point = malloc(count * size);
// 	if (!point)
// 		return (NULL);
// 	ft_bzero(point, count * size);
// 	return (point);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 		ft_calloc(1, 1);
// 	if (!s1 || !s2)
// 		return (0);
// 	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (str == NULL)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 		str[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		str[j++] = s2[i++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	char	*temp;

// 	temp = (char *)s;
// 	while (*temp != (char)c)
// 	{
// 		if (*temp == '\0')
// 			return (0);
// 		temp++;
// 	}
// 	return (temp);
// }

// size_t	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	if (s1 && !s2)
		free(s1);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (s1 = ft_free(&s1));
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			s[i] = s1[i];
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (s);
}
