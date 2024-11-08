/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:05:15 by akastler          #+#    #+#             */
/*   Updated: 2023/06/05 13:40:07 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_philo(t_values *vals)
{
	int	i;

	i = 0;
	while (i < vals->nb_philo)
	{
		vals->philo[i].fork_left = i;
		if (i == vals->nb_philo - 1)
			vals->philo[i].fork_right = 0;
		else
			vals->philo[i].fork_right = i + 1;
		vals->philo[i].philo_number = i;
		vals->philo[i].vals = vals;
		vals->philo[i].nb_eat = 0;
		vals->philo[i].add_all_eat = 0;
		i++;
	}
}

void	ft_init_forks(t_values *vals)
{
	int	i;

	i = 0;
	while (i < vals->nb_philo)
	{
		pthread_mutex_init(&vals->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&vals->write, NULL);
}

void	philo_start_program(t_values *vals)
{
	vals->forks = ft_calloc(vals->nb_philo + 1, sizeof(pthread_mutex_t));
	ft_init_forks(vals);
	vals->philo = ft_calloc(vals->nb_philo + 1, sizeof(t_philo));
	ft_init_philo(vals);
	vals->prog_start = give_time();
	while (++vals->i < vals->nb_philo)
	{
		vals->philo[vals->i].created = give_time();
		vals->philo[vals->i].last_eat = give_time();
		pthread_create(&vals->philo[vals->i].philo_heart,
			NULL, philo_launch, &vals->philo[vals->i]);
	}
	vals->i = 0;
	while (check_health(vals) == 0)
		;
	if (vals->is_dead >= 0)
		print_for_routine(1, vals, NULL);
	else
		print_for_routine(2, vals, NULL);
	while (vals->i < vals->nb_philo)
		pthread_detach(vals->philo[vals->i++].philo_heart);
	free(vals->forks);
	free(vals->philo);
}

int	main(int argc, char **argv)
{
	t_values	values;

	if (argc != 5 && argc != 6)
		return (printf("Wrong number of arguments\n") - 27);
	else
	{
		if (init_vals(&values, argv) == -1)
		{
			printf("Error in args configuration\n");
			return (0);
		}
		else
			philo_start_program(&values);
	}
}
