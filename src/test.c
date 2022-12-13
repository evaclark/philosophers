/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:10:44 by eclark            #+#    #+#             */
/*   Updated: 2022/12/13 14:21:14 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*message(void *philo)
{
	struct timeval	current;

	usleep(1000);
	gettimeofday(&current, NULL);
	printf("Philo %ld\n", (struct philo*)philo->time));
	return (0);
}

void	init_philo(int argc, char **argv, t_philo *philo)
{
	struct timeval	start;
	int	n;

	n = ft_atoi(argv[1]);
	philo->time = gettimeofday(&start, NULL);
	if (argc == 2)
	{
		while (n > 0)
		{
			pthread_t philosopher[n];

			pthread_create(&philosopher[n], NULL, message, (void *)philo);
			pthread_join(philosopher[n], NULL);
			n--;
		}
	}
	usleep(1000);
}
int main(int argc, char **argv)
{
	t_philo philo;

	init_philo(argc, argv, &philo);
	exit (0);
}
