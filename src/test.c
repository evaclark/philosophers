/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:10:44 by eclark            #+#    #+#             */
/*   Updated: 2022/12/18 17:01:25 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_stuff(int argc, char **argv, t_stuff *stuff)
{
	if (argc < 5)
		return (1);
	if (argc > 4)
	{
		stuff->num_phi = ft_atoi(argv[2]);
		stuff->time_die = ft_atoi(argv[3]);
		stuff->time_eat = ft_atoi(argv[4]);
		stuff->time_sleep = ft_atoi(argv[5]);
		stuff->all_eaten = 0;
		stuff->dead_phi = 0;
		if (argc == 6)
			stuff->num_eat = ft_atoi(argv[6]);
		else if (argc == 5)
			stuff->num_eat = -1;
		if (argc > 6)
			return (1);
	}
	return (0);
}

int	init_philo(t_stuff *stuff)
{
	int n;

	n = 0;
	while (n < stuff->num_phi)
	{
		stuff->philo[n].phi_id = n;
		stuff->philo[n].fork_l = n;
		stuff->philo[n].fork_r = (n + 1) % stuff->num_phi;
		stuff->philo[n].ate = 0;
		stuff->philo[n].last_ate = 0;
		stuff->philo[n].stuff = stuff;
		n++;
	}
	return (0);
}

int	init_mutex(t_stuff *stuff)
{
	int	n;

	n = 0;
	while (n < stuff->num_phi)
	{
		if (pthread_mutex_init((&stuff->forks[n]), NULL))
			return (1);
		n++;
	}
	if (pthread_mutex_init((&stuff->msg), NULL))
		return (1);
	if (pthread_mutex_init((&stuff->meal_check), NULL))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_stuff stuff;
	int	n;
	
	n = 0;
	while (argv[++n])
	{	
		if (check_num(argv[n]) != 0)
			return (0);
	}
	init_stuff(argc, argv, &stuff);
	init_philo(&stuff);
	init_mutex(&stuff);
	exit (0);
}
