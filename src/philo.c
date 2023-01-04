/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:56:03 by eclark            #+#    #+#             */
/*   Updated: 2023/01/03 17:17:49 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_stuff *stuff)
{
	int		n;
	t_philo	*philo;

	philo = stuff->philo;
	stuff->time = gettime();
	while (n < stuff->num_phi)
	{
			pthread_create(&philo[n], NULL, action, &(philo[n]));
			philo[n].last_ate = gettime();
			n++;
	}
	/*check for deaths*/
	/*function for clean exit*/
	return (0);
}

void	eat(t_philo *philo)
{
	t_stuff *stuff;

	stuff = philo->stuff;
	pthread_mutex_lock(&(stuff->forks[philo->fork_l]));
	/*print philo has taken l fork*/
	pthread_mutex_lock(&(stuff->forks[philo->fork_r]));
	/*print philo has taken r fork*/
	pthread_mutex_lock(&(stuff->meal_check));
	/*philo is eating*/
	philo->last_ate = gettime();
	pthread_mutex_unlock(&(stuff->meal_check));
	/*sleep*/
	pthread_mutex_unlock(&(stuff->forks[philo->fork_l]));
	pthread_mutex_unlock(&(stuff->forks[philo->fork_r]));
}

void	action(void *philosopher)
{
	int		n;
	t_philo *philo;
	t_stuff *stuff;

	n = 0;
	philo = (t_philo *)philosopher;
	stuff = philo->stuff;
	if ((philo->phi_id % 2) != 0)
		usleep(10000);
	while(stuff->dead_phi != 1)
	{
		eat(philo);
		if (stuff->all_eaten == 1)
			break ;
		/*sleep*/
		/*think*/
		n++;
	}
	return (NULL);
}

void	amidead(t_stuff *stuff, t_philo *philo)
{
	int	n;
	while(all_eaten != 1)
	{
		pthread_mutex_lock(&(stuff->meal_check));
	}
}