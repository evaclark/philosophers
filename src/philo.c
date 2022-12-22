/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:56:03 by eclark            #+#    #+#             */
/*   Updated: 2022/12/22 20:43:13 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_stuff *stuff)
{
	int	n;
	t_philo	philo;

	philosopher = stuff->philo;
	stuff->time = gettime();
	while (n < stuff->num_philo)
	{
			pthread_create(&philosopher[n], NULL, action, &(phi[i]));
			philosopher[i].last_ate = gettime();
			n++;
	}
	/*check for deaths*/
	/*function for clean exit*/
	return (0);
}

void	action(void *philosopher)
{
	int	n;

