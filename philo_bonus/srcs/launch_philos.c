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
			kill(0, SIGINT);
			exit(1);
		}
		sem_post(philo->data->can_eat);
	}
	return(0);
}

void *meals_tracker(void *data_struct)
{
	t_properties *data;

	data = (t_properties *)data_struct;
	while (1)
	{
		if(data->well_fed_philos == data->philo_number)
		{
			kill(0, SIGINT);
			exit(1);
		}
	}
	
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
	while(++i < data->philo_number)
		waitpid(data->philo[i].philo_pid, &stat_var, 0);
	i = -1;
	while(++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
}