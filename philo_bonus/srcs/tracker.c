#include"philo_bonus.h"


void *death_tracker(void *philo_struct)
{
	t_philo *philo;
	int timeframe;

	philo = (t_philo *)philo_struct;
	while(1)
	{
		timeframe = getcurrenttime() - philo->last_meal;
		if(timeframe >= philo->data->time_to_die)
		{
			print_status(philo, " died");
			exit(1);
		}
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
	int count;
	int i;

	data = (t_properties *)data_struct;
	count = 0;
	while(count < data->meals_nbr)
	{
		i = 0;
		while (i < data->philo_number)
		{
			sem_wait(data->meals_tracker);
			i++;
		}
		count++;
	}
	sem_wait(data->write);
	i = -1;
	while(++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
	return(NULL);
}
