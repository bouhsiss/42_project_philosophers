/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:49:43 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:49:47 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->forks[philo->r_fork]));
	print_status(philo, "has taken the right fork");
	pthread_mutex_lock(&(philo->data->forks[philo->l_fork]));
	print_status(philo, "has taken the left fork");
	pthread_mutex_lock(&(philo->data->can_eat));
	print_status(philo, "is eating");
	philo->last_meal = getcurrenttime();
	philo->meals_counter++;
	if (philo->meals_counter == philo->data->meals_nbr)
		philo->data->well_fed_philos++;
	pthread_mutex_unlock(&(philo->data->can_eat));
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->l_fork]));
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}
