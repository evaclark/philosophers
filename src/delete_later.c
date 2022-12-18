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
