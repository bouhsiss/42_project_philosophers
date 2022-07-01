#include"philo_bonus.h"

void	launch_philos(t_properties *data)
{
	int i;
	pthread_t	death_tid;
	pthread_t	meals_tid;

	i = -1;
	data->time_of_start = getcurrenttime();
	if(data->meals_nbr != -1)
		pthread_create(&(meals_tid), NULL, &(meals_tracker), data);
	while(++i < data->philo_number)
	{
		data->philo[i].philo_pid = fork();
		if (data->philo[i].philo_pid < 0)
			perror("fork failed");
		if (data->philo[i].philo_pid == 0)
		{
			data->philo[i].last_meal = getcurrenttime();
			pthread_create(&(death_tid), NULL, &(death_tracker), &(data->philo[i]));
			philo_routine(&(data->philo[i]));
		}
	}
	int stat_var;
	i = -1;
	while(waitpid(-1, &stat_var, 0) > 0);
	while(++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
}