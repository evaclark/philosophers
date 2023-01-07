/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:56:03 by eclark            #+#    #+#             */
/*   Updated: 2023/01/07 20:44:32 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_stuff	*stuff;

	stuff = philo->stuff;
	pthread_mutex_lock(&(stuff->forks[philo->fork_l]));
	if (!(stuff->dead_phi))
		printf("%lld philo %d has taken a fork\n", (gettime() - stuff->time),
			philo->phi_id + 1);
	pthread_mutex_lock(&(stuff->forks[philo->fork_r]));
	if (!(stuff->dead_phi))
		printf("%lld philo %d has taken a fork\n", (gettime() - stuff->time),
			philo->phi_id + 1);
	pthread_mutex_lock(&(stuff->meal_check));
	if (!(stuff->dead_phi))
		printf("%lld philo %d is eating\n", (gettime() - stuff->time),
			philo->phi_id + 1);
	philo->last_ate = gettime();
	pthread_mutex_unlock(&(stuff->meal_check));
	if (!(stuff->dead_phi))
		sleepytime(stuff->time_eat, stuff);
	(philo->ate)++;
	pthread_mutex_unlock(&(stuff->forks[philo->fork_l]));
	pthread_mutex_unlock(&(stuff->forks[philo->fork_r]));
}

void	exit_all(t_stuff *stuff, t_philo *philo)
{
	int	n;

	n = -1;
	while (++n < stuff->num_phi)
	{
		pthread_join(philo[n].thread_id, NULL);
	}
	n = -1;
	while (++n < stuff->num_phi)
	{
		pthread_mutex_destroy(&(stuff->forks[n]));
	}
}

void	*action(void *philosopher)
{
	int		n;
	t_philo	*philo;
	t_stuff	*stuff;

	n = 0;
	philo = (t_philo *)philosopher;
	stuff = philo->stuff;
	if (philo->phi_id % 2)
		usleep(15000);
	while (stuff->dead_phi != 1)
	{
		eat(philo);
		if (stuff->all_eaten == 1)
			break ;
		if (!(stuff->dead_phi))
			printf("%lld philo %d is sleeping\n", (gettime() - stuff->time),
				philo->phi_id + 1);
		sleepytime(stuff->time_eat, stuff);
		if (!(stuff->dead_phi))
			printf("%lld philo %d is thinking\n", (gettime() - stuff->time),
				philo->phi_id + 1);
		n++;
	}
	return (NULL);
}

void	amidead(t_stuff *s, t_philo *phi)
{
	int	n;

	while (!(s->all_eaten))
	{
		n = -1;
		while (++n < s->num_phi && !(s->dead_phi))
		{
			pthread_mutex_lock(&(s->meal_check));
			if (time_diff(phi[n].last_ate, gettime()) > s->time_die)
			{
				printf("%lld philo %d died\n", (gettime() - s->time),
					phi->phi_id + 1);
				s->dead_phi = 1;
			}
			pthread_mutex_unlock(&(s->meal_check));
			usleep(100);
		}
		if (s->dead_phi == 1)
			break ;
		n = 0;
		while (s->num_eat != -1 && n < s->num_phi && (phi[n].ate >= s->num_eat))
			n++;
		if (n == s->num_phi)
			s->all_eaten = 1;
	}
}

int	philo(t_stuff *stuff)
{
	int		n;
	t_philo	*philo;

	n = 0;
	philo = stuff->philo;
	stuff->time = gettime();
	while (n < stuff->num_phi)
	{
		if (pthread_create(&(philo[n].thread_id), NULL, action, &(philo[n])))
			return (1);
		philo[n].last_ate = gettime();
		n++;
	}
	amidead(stuff, stuff->philo);
	exit_all(stuff, philo);
	return (0);
}
