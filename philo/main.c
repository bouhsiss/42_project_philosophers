/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:48:22 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:48:24 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo.h"

int	main(int ac, char **av)
{
	t_properties	*data;

	if (ac == 5 || ac == 6)
	{
		data = (t_properties *)malloc(sizeof(t_properties));
		if (!constructor(data, av) || data->meals_nbr == 0)
			print_error("Error : invalid argument");
		launch_philos(data);
		track_philos(data);
	}
	else
		printf("Usage : <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
<number_of_times_each_philosopher_must_eat>");
}
