/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:11:52 by eclark            #+#    #+#             */
/*   Updated: 2022/12/18 16:07:36 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef	struct	s_philo
{
	int				phi_id;
	int				fork_l;
	int				fork_r;
	int				ate;
	pthread_t		thread_id;
	long long		last_ate;
	struct s_stuff	*stuff;
}				t_philo;

typedef	struct	s_stuff
{
	int				num_phi;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				all_eaten;
	int				dead_phi;
	long long		time;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	msg;
	pthread_mutex_t meal_check;
	t_philo		philo[250];
}				t_stuff;

/*utils*/
int	ft_atoi(const char *str);
int	check_num(char *argv);

#endif
