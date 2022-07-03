/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:29:30 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/07/01 16:29:32 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	int					philo_id;
	pid_t				philo_pid;
	int					meals_counter;
	long long			last_meal;
	struct s_properties	*data;
}	t_philo;

typedef struct s_properties
{
	int			philo_number;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_nbr;
	long long	time_of_start;
	sem_t		*well_fed_philos;
	sem_t		*write;
	sem_t		*can_eat;
	sem_t		*forks;
	t_philo		*philo;
}	t_properties;

int			constructor(t_properties *data, char **av);
int			print_error(char *error_message);
int			ft_atoi(const char *str);
void		print_status(t_philo *philo, char *status);
void		ft_usleep(int time);
long long	getcurrenttime(void);
void		launch_philos(t_properties *data);
void		print_status(t_philo *philo, char *message);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		*death_tracker(void *philo_struct);
void		*meals_tracker(void *data_struct);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		destructor(t_properties *data);

#endif
