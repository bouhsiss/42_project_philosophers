#include"philo.h"

void meals_tracker(t_properties *data)
{
	int i;
	int counter;

	i = -1;
	counter = 0;
	while(++i < data->philo_number)
	{
		if(data->meals_nbr != -1 && data->philo[i].meals_counter == data->meals_nbr)
			counter++;
	}
	if (counter >= data->philo_number)
		data->should_end = 1;
}

int track_philos(t_properties *data)
{
    int i;
    int timeframe;
	int counter;

	while(data->should_end == 0)
	{
		i = -1;
		counter = 0;
		while(++i < data->philo_number)
		{
			timeframe = getcurrenttime() - data->philo[i].last_meal;
			if (timeframe >= data->time_to_die)
			{
				print_status(&data->philo[i], "died");
				return(0);
			}
			meals_tracker(data);
		}
	}
    return(0);
}