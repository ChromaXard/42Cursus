/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:43:46 by akastler          #+#    #+#             */
/*   Updated: 2023/06/05 13:40:49 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	check_health(t_values *vals)
{
	int	i;

	i = 0;
	while (i < vals->nb_philo)
	{
		if (vals->max_eat > 0)
		{
			if (vals->philo[i].nb_eat >= vals->max_eat
				&& vals->philo[i].add_all_eat == 0)
			{
				vals->philo[i].add_all_eat = 1;
				vals->all_eat++;
			}
		}
		if (vals->all_eat == vals->nb_philo)
			return (1);
		if (give_time() - vals->philo[i].last_eat > vals->ttd)
		{
			vals->is_dead = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_sleep(long long time)
{
	struct timeval	a;
	struct timeval	b;

	gettimeofday(&a, NULL);
	gettimeofday(&b, NULL);
	while (((a.tv_sec - b.tv_sec) * 1000
			+ (a.tv_usec - b.tv_usec) / 1000) < time)
	{
		usleep(180);
		gettimeofday(&a, NULL);
	}
}

void	eat_time(t_philo *philo)
{
	if (philo->vals->all_eat == philo->vals->nb_philo
		|| philo->vals->is_dead >= 0)
		return ;
	pthread_mutex_lock(&philo->vals->forks[philo->fork_left]);
	print_for_routine(3, NULL, philo);
	if (philo->vals->nb_philo == 1)
	{
		return ;
		pthread_mutex_unlock(&philo->vals->forks[philo->fork_left]);
	}
	pthread_mutex_lock(&philo->vals->forks[philo->fork_right]);
	pthread_mutex_lock(&philo->vals->write);
	printf("%lldms %d has taken a fork\n", give_time()
		- philo->vals->prog_start, philo->philo_number + 1);
	pthread_mutex_unlock(&philo->vals->write);
	philo->last_eat = give_time();
	philo->nb_eat++;
	pthread_mutex_lock(&philo->vals->write);
	printf("%lldms %d is eating\n", give_time()
		- philo->vals->prog_start, philo->philo_number + 1);
	pthread_mutex_unlock(&philo->vals->write);
	ft_sleep(philo->vals->tte);
	pthread_mutex_unlock(&philo->vals->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->vals->forks[philo->fork_right]);
}

void	sleep_time(t_philo *philo)
{
	if (philo->vals->all_eat == philo->vals->nb_philo
		|| philo->vals->is_dead >= 0 || philo->vals->nb_philo == 1)
		return ;
	pthread_mutex_lock(&philo->vals->write);
	printf("%lldms %d is sleeping\n", give_time()
		- philo->vals->prog_start, philo->philo_number + 1);
	pthread_mutex_unlock(&philo->vals->write);
	ft_sleep(philo->vals->tts);
}

void	*philo_launch(void *thread)
{
	t_philo	*philo;

	philo = thread;
	if (philo->philo_number % 2)
		ft_sleep(philo->vals->tte);
	while (1)
	{
		eat_time(philo);
		sleep_time(philo);
		if (philo->vals->all_eat == philo->vals->nb_philo
			|| philo->vals->is_dead >= 0 || philo->vals->nb_philo == 1)
			break ;
		pthread_mutex_lock(&philo->vals->write);
		printf("%lldms %d is thinking\n",
			give_time() - philo->vals->prog_start, philo->philo_number + 1);
		pthread_mutex_unlock(&philo->vals->write);
		if (philo->vals->all_eat == philo->vals->nb_philo
			|| philo->vals->is_dead >= 0 || philo->vals->nb_philo == 1)
			break ;
	}
	pthread_exit(NULL);
}
