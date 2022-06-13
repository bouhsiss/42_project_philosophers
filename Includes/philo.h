#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo 
{
    int         philo_id;
    int         r_fork;
    int         l_fork;
    int         meals_counter;
    struct s_properties *data;
}   t_philo;

typedef struct s_properties
{
    int     philo_number;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     meals_nbr;
    t_philo *philo;
}   t_properties;


t_properties *constructor(char **av);
int	ft_atoi(const char *str);
int check_syntax(char **av);

#endif