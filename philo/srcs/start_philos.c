/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:48:47 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:48:48 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void	*routine(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	while (69)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	launch_philos(t_properties *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_number)
	{
		data->philo[i].last_meal = getcurrenttime();
		pthread_create(&(data->philo[i].philo_t), NULL, &routine,
			&(data->philo[i]));
		usleep(50);
	}
}
