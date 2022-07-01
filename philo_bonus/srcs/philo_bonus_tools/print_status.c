/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:32:18 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/01 16:32:20 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	print_status(t_philo *philo, char *message)
{
	int	timestamp;

	sem_wait(philo->data->write);
	timestamp = getcurrenttime() - philo->data->time_of_start;
	ft_putnbr_fd(timestamp, 1);
	ft_putstr_fd(" philo ", 1);
	ft_putnbr_fd(philo->philo_id, 1);
	ft_putendl_fd(message, 1);
	sem_post(philo->data->write);
}
