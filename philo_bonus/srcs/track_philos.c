/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:19 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/01 16:31:22 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	*death_tracker(void *philo_struct)
{
	t_philo	*philo;
	int		timeframe;

	philo = (t_philo *)philo_struct;
	while (1)
	{
		sem_wait(philo->data->can_eat);
		timeframe = getcurrenttime() - philo->last_meal;
		if (timeframe >= philo->data->time_to_die)
		{
			print_status(philo, " died");
			sem_wait(philo->data->write);
			exit(1);
		}
		sem_post(philo->data->can_eat);
	}
	return (0);
}

/*
this function is tracking the philos meals using a semaphore
it keeps decrementing the semaphore (that we increment every 
time a philo take a meal) since all the philos didn't take their first meal
and then it redo the same operation until they take all the meals
*/

void	*meals_tracker(void *data_struct)
{
	t_properties	*data;
	int				i;

	i = 0;
	data = (t_properties *)data_struct;
	while (i < data->philo_number)
	{
		sem_wait(data->well_fed_philos);
		i++;
	}
	sem_wait(data->write);
	i = -1;
	while (++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
	return (NULL);
}
