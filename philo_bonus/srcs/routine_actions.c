/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:13 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/01 16:31:15 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_status(philo, " has taken a fork");
	sem_wait(philo->data->forks);
	print_status(philo, " has taken a fork");
	sem_wait(philo->data->can_eat);
	print_status(philo, " is eating");
	philo->last_meal = getcurrenttime();
	philo->meals_counter++;
	if (philo->meals_counter == philo->data->meals_nbr)
		sem_post(philo->data->well_fed_philos);
	sem_post(philo->data->can_eat);
	ft_usleep(philo->data->time_to_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, " is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, " is thinking");
}
