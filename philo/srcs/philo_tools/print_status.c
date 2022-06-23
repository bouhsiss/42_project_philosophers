/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:49:24 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:49:26 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void	print_status(t_philo *philo, char *status)
{
	int	timestamp;

	pthread_mutex_lock(&(philo->data->write));
	timestamp = getcurrenttime() - philo->data->time_of_start;
	printf("%d philo %d %s \n", timestamp, philo->philo_id, status);
	pthread_mutex_unlock(&(philo->data->write));
}
