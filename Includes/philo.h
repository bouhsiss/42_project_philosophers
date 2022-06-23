#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>


typedef struct s_philo 
{
    int         philo_id;
    pthread_t   philo_t;
    int         r_fork;
    int         l_fork;
    int         meals_counter;
    long long   last_meal;
	pthread_mutex_t can_eat;
    struct s_properties *data;
}   t_philo;

typedef struct s_properties
{
    int     philo_number;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     meals_nbr;
    long long   time_of_start;
	int		should_end;
    pthread_mutex_t write;
    pthread_mutex_t *forks;
    t_philo *philo;
}   t_properties;
 
//Routine_actions
void philo_eat(t_philo *philo);
void philo_sleep(t_philo *philo);
void philo_think(t_philo *philo);
//philo_tools
int	ft_atoi(const char *str);
int print_error(char *error_message);
long long getcurrenttime();
void	ft_usleep(int time);
void print_status(t_philo *philo, char *status);
void	constructor(t_properties *data, char **av);
void start_philos(t_properties *data);
int track_philos(t_properties *data);

#endif