#include"philo_bonus.h"

void *death_tracker(void *philo_struct)
{
	t_philo *philo;
	int timeframe;

	philo = (t_philo *)philo_struct;
	while(1)
	{
		sem_wait(philo->data->can_eat);
		timeframe = getcurrenttime() - philo->last_meal;
		if(timeframe >= philo->data->time_to_die)
		{
			print_status(philo, "died");
			exit(1);
		}
		sem_post(philo->data->can_eat);
	}
	return(0);
}

/*
this function is tracking the philos meals using a semaphore
it keeps decrementing the semaphore (that we increment every time a philo take a meal) since all the philos didn't take their first meal
and then it redo the same operation until they take all the meals
*/

void *meals_tracker(void *data_struct)
{
	t_properties *data;
	int i = 0;

	data = (t_properties *)data_struct;
	while (i < data->philo_number)
	{
		sem_wait(data->meals_tracker);
		i++;
	}
	sem_wait(data->write);
	i = -1;
	while(++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
	return(NULL);
}

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
	waitpid(-1, &stat_var, 0);
	while(++i < data->philo_number)
	{
		while(++i < data->philo_number)
			kill(data->philo[i].philo_pid, SIGKILL);
	}
}