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
    pthread_mutex_t write;
    pthread_mutex_t eat;
    pthread_mutex_t *forks;
    t_philo *philo;
}   t_properties;
 

t_properties *constructor(char **av);
int	ft_atoi(const char *str);
int check_syntax(char **av);
int print_error(char *error_message);
int getcurrenttime();
void run_philos(t_properties *data);

#endif