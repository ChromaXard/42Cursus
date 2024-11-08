/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:19:49 by akastler          #+#    #+#             */
/*   Updated: 2023/06/05 13:41:01 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	contain_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	signe;

	i = 0;
	j = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (str[i] - '0') + (j * 10);
		i++;
	}
	if (signe == -1)
		return (-j);
	return (j);
}

int	check_zero(t_values *vals)
{
	if (vals->ttd == 0
		|| vals->max_eat == 0 || vals->nb_philo == 0
		|| vals->tte == 0 || vals->tts == 0)
		return (1);
	return (0);
}

int	init_vals(t_values *vals, char **argv)
{
	vals->is_dead = -1;
	vals->all_eat = 0;
	vals->i = -1;
	if ((argv[1] && ft_strlen(argv[1]) > 0 && contain_digits(argv[1]) == 1)
		&& (argv[2] && ft_strlen(argv[2]) > 0 && contain_digits(argv[2]) == 1)
		&& (argv[3] && ft_strlen(argv[3]) > 0 && contain_digits(argv[3]) == 1)
		&& (argv[4] && ft_strlen(argv[4]) > 0 && contain_digits(argv[4]) == 1))
	{
		vals->nb_philo = ft_atoi(argv[1]);
		vals->ttd = ft_atoi(argv[2]);
		vals->tte = ft_atoi(argv[3]);
		vals->tts = ft_atoi(argv[4]);
		vals->max_eat = -1;
		if (argv[5])
		{
			if (!(ft_strlen(argv[5]) > 0 && contain_digits(argv[5]) == 1))
				return (-1);
			vals->max_eat = ft_atoi(argv[5]);
		}
	}
	else
		return (-1);
	if (check_zero(vals) == 1)
		return (-1);
	return (0);
}
