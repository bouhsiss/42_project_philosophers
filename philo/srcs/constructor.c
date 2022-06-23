/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:48:41 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:49:55 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

int	check_syntax(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		}
	}
	return (0);
}

void	init_mutex(t_properties *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t)
			* data->philo_number);
	while (i < data->philo_number)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->write), NULL);
	pthread_mutex_init(&(data->can_eat), NULL);
}

t_philo	*construct_philos(t_properties *data)
{
	t_philo	*philo;
	int		i;
	int		philo_number;

	philo_number = data->philo_number;
	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * philo_number);
	while (++i < philo_number)
	{
		philo[i].philo_id = i + 1;
		philo[i].r_fork = i;
		philo[i].l_fork = (i + 1) % philo_number;
		philo[i].meals_counter = 0;
		philo[i].data = data;
	}
	return (philo);
}

int	constructor(t_properties *data, char **av)
{
	if (!check_syntax(av))
	{
		data->philo_number = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		if (av[5])
			data->meals_nbr = ft_atoi(av[5]);
		else
			data->meals_nbr = -1;
		data->time_of_start = getcurrenttime();
		data->well_fed_philos = 0;
		init_mutex(data);
		data->philo = construct_philos(data);
		return (1);
	}
	else
		return (0);
}
