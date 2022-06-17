#include"philo.h"

int meals_tracker(t_properties *data)
{
	int i;
	int counter;

	i = -1;
	counter = 0;
	while(++i < data->philo_number)
	{
		if(data->meals_nbr != -1 && data->philo[i].meals_counter >= data->meals_nbr)
			counter++;
	}
	if (counter >= data->philo_number)
		return(0);
	else
		return(1);
}

int track_philos(t_properties *data)
{
    int i;
    int timeframe;

	while(1)
	{
		i = -1;
		while(++i < data->philo_number)
		{
			timeframe = getcurrenttime() - data->philo[i].last_meal;
			if (timeframe >= data->time_to_die)
			{
				print_status(&data->philo[i], "died");
				return(0);
			}
			if(!meals_tracker(data))
				return(0);
			else
				pthread_mutex_unlock(&(data->philo[i].can_eat));
		}
	}
    return(0);
}