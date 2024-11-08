/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:06:24 by akastler          #+#    #+#             */
/*   Updated: 2023/06/05 13:37:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_values
{
	int				nb_philo;
	long long		tte;
	long long		ttd;
	long long		tts;
	int				max_eat;
	int				is_dead;
	int				all_eat;
	int				i;
	long long		prog_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	struct s_philo	*philo;
}	t_values;

typedef struct s_philo
{
	long long	last_eat;
	long long	created;
	int			nb_eat;
	int			philo_number;
	int			fork_left;
	int			fork_right;
	int			add_all_eat;
	t_values	*vals;
	pthread_t	philo_heart;
}	t_philo;

int			init_vals(t_values *vals, char **argv);
void		*ft_calloc(size_t count, size_t size);
long long	give_time(void);
void		*philo_launch(void *thread);
int			check_health(t_values *vals);
void		print_for_routine(int print, t_values *vals, t_philo *philo);

#endif