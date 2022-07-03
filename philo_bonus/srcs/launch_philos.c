/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:07 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/01 16:31:09 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	philo_routine(t_philo *philo)
{
	philo->last_meal = getcurrenttime();
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	launch_philos(t_properties *data)
{
	int			i;
	pthread_t	death_tid;
	pthread_t	meals_tid;
	int			stat_var;

	i = -1;
	if (data->meals_nbr != -1)
		pthread_create(&(meals_tid), NULL, &(meals_tracker), data);
	data->time_of_start = getcurrenttime();
	while (++i < data->philo_number)
	{
		data->philo[i].philo_pid = fork();
		if (data->philo[i].philo_pid < 0)
			perror("fork failed");
		if (data->philo[i].philo_pid == 0)
		{
			pthread_create(&(death_tid), NULL, &(death_tracker),
				&(data->philo[i]));
			philo_routine(&(data->philo[i]));
		}
	}
	waitpid(-1, &stat_var, 0);
	destructor(data);
}
