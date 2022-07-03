/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:47:55 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/03 17:47:57 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	destructor(t_properties *data)
{
	int	i;

	i = -1;
	sem_unlink("/forks_sem");
	sem_unlink("/write_sem");
	sem_unlink("/can_eat_sem");
	sem_unlink("/well_fed_philos");
	while (++i < data->philo_number)
		kill(data->philo[i].philo_pid, SIGKILL);
}
