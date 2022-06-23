/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:48:53 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:50:01 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

int	meals_tracker(t_properties *data)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < data->philo_number)
	{
		if (data->meals_nbr != -1 && data->philo[i].meals_counter
			>= data->meals_nbr)
			counter++;
	}
	if (counter >= data->philo_number)
		return (0);
	else
		return (1);
}

int	track_philos(t_properties *data)
{
	int	i;
	long long	timeframe;

	while (!data->should_end)
	{
		i = -1;
		while (++i < data->philo_number)
		{
			pthread_mutex_lock(&(data->philo[i].can_eat));
			timeframe = getcurrenttime() - data->philo[i].last_meal;
			if (timeframe >= data->time_to_die)
			{
				print_status(&data->philo[i], "died");
				data->should_end = 1;
				return (0);
			}
			if (data->well_fed_philos == data->meals_nbr)
			{
				data->should_end=1;
				return (0);
			}
			pthread_mutex_unlock(&(data->philo[i].can_eat));
		}
	}
	return (0);
}