/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:10:44 by eclark            #+#    #+#             */
/*   Updated: 2023/01/07 21:55:14 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_stuff(int argc, char **argv, t_stuff *stuff)
{
	if (argc < 5 || argc > 6)
	{
		printf("\e[35m\e[1mPlease enter 4 or 5 arguements :)\e[0m\n");
		return (1);
	}
	if (argc > 4 && argc < 7)
	{
		stuff->num_phi = ft_atoi(argv[1]);
		stuff->time_die = ft_atoi(argv[2]);
		stuff->time_eat = ft_atoi(argv[3]);
		stuff->time_sleep = ft_atoi(argv[4]);
		stuff->all_eaten = 0;
		stuff->dead_phi = 0;
		if (argc == 6)
			stuff->num_eat = ft_atoi(argv[5]);
		else if (argc == 5)
			stuff->num_eat = -1;
	}
	return (0);
}

int	init_philo(t_stuff *stuff)
{
	int	n;

	n = stuff->num_phi;
	while (--n >= 0)
	{
		stuff->philo[n].phi_id = n;
		stuff->philo[n].fork_l = n;
		stuff->philo[n].fork_r = (n + 1) % stuff->num_phi;
		stuff->philo[n].ate = 0;
		stuff->philo[n].last_ate = 0;
		stuff->philo[n].stuff = stuff;
	}
	return (0);
}

int	init_mutex(t_stuff *stuff)
{
	int	n;

	n = stuff->num_phi;
	while (--n >= 0)
	{
		if (pthread_mutex_init((&stuff->forks[n]), NULL))
			return (1);
	}
	if (pthread_mutex_init((&stuff->msg), NULL))
		return (1);
	if (pthread_mutex_init((&stuff->meal_check), NULL))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stuff	stuff;
	int		n;

	n = 0;
	if (!(argc > 1))
		return (0);
	if (ft_atoi(argv[1]) < 2 || ft_atoi(argv[1]) > 250)
		return (0);
	while (argv[++n])
	{	
		if (check_num(argv[n]) != 0)
		{
			printf("\e[31m\e[1mPlease enter only numerical arguements :)\e[0m\n");
			return (0);
		}
	}
	init_stuff(argc, argv, &stuff);
	init_philo(&stuff);
	init_mutex(&stuff);
	if (stuff.time_die < 0 || stuff.time_eat < 0 || stuff.time_sleep < 0)
		return (0);
	philo(&stuff);
	return (0);
}
