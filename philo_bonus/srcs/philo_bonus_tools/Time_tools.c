/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:49:11 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/06/23 01:49:12 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"philo_bonus.h"

void	ft_usleep(int time)
{
	long long	start;

	start = getcurrenttime();
	while (getcurrenttime() < start + time)
		usleep(50);
}

long long	getcurrenttime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
