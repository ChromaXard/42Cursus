/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:54:50 by akastler          #+#    #+#             */
/*   Updated: 2023/06/05 13:41:10 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	print_for_routine(int print, t_values *vals, t_philo *philo)
{
	if (print == 1)
	{
		pthread_mutex_lock(&vals->write);
		printf("%lldms %d died\n", give_time()
			- vals->prog_start, vals->is_dead + 1);
		pthread_mutex_unlock(&vals->write);
	}
	else if (print == 2)
	{
		pthread_mutex_lock(&vals->write);
		printf("%lldms all the philosophers have eaten\n",
			give_time() - vals->prog_start);
		pthread_mutex_unlock(&vals->write);
	}
	else if (print == 3)
	{
		pthread_mutex_lock(&philo->vals->write);
		printf("%lldms %d has taken a fork\n", give_time()
			- philo->vals->prog_start, philo->philo_number + 1);
		pthread_mutex_unlock(&philo->vals->write);
	}
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		*temp = '\0';
		temp++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*point;

	point = (unsigned char *)malloc(count * size);
	if (!point)
		return (0);
	if (point)
		ft_bzero(point, count * size);
	return (point);
}

long long	give_time(void)
{
	struct timeval	time;
	long long		mili;

	gettimeofday(&time, NULL);
	mili = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (mili);
}
