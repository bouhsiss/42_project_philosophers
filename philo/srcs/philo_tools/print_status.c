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
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" philo ", 1);
	ft_putnbr_fd(philo->philo_id, 1);
	ft_putendl_fd(status, 1);
	pthread_mutex_unlock(&(philo->data->write));
}
