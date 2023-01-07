/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:01:12 by eclark            #+#    #+#             */
/*   Updated: 2023/01/07 17:28:04 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime()
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	sleepytime(long long time, t_stuff *stuff)
{
	long long	n;

	n = gettime();
	while (!(stuff->dead_phi))
	{
		if (time_diff(n, gettime()) >= time)
			break ;
		usleep(100);
	}
}
