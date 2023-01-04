/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:01:12 by eclark            #+#    #+#             */
/*   Updated: 2023/01/03 16:09:56 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	gettime()
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return((current.tv_sec * 1000) + (current.tv_usec / 1000));
}
