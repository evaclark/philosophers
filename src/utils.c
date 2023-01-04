/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:00:20 by eclark            #+#    #+#             */
/*   Updated: 2023/01/04 19:41:31 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = sign * -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * sign);
}

int	check_num(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')
			i++;
		if (!(argv [i] >= '0' && argv[i] <= '9'))
			return (-1);
	}
	return (0);
}

void	byebye(t_stuff *stuff, t_philo *philo)
{

}
