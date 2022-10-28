/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:10:44 by eclark            #+#    #+#             */
/*   Updated: 2022/10/28 15:16:45 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *message()
{
	sleep(1);
	printf("wowowowoowow\n");
	return (NULL);
}

int main(int argc, char **argv)
{
	int			n;

	n = ft_atoi(argv[1]);
	printf("hi\n");
	if (argc == 2)
	{
		while (n > 0)
		{
			pthread_t philosopher[n];

			pthread_create(&philosopher[n], NULL, message, NULL);
			pthread_join(philosopher[n], NULL);
			n--;
		}
	}
	sleep(1);
	printf("the end\n");
	exit (0);
}