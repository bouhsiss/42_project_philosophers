#include"philo.h"

int check_syntax(char **av)
{
    int i;
    int j;

    i = 0;
    while(av[++i])
    {
        j = -1;
        while(av[i][++j])
        {
		    if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return(1);
        }
    }
    return(0);
}

void init_mutex(t_properties *data)
{
    int i;

    i = 0;
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_number);
    while(i < data->philo_number)
    {
        pthread_mutex_init(&(data->forks[i]), NULL);
        i++;
    }
}

t_philo *construct_philos(t_properties *data)
{
    t_philo *philo;
    int i;
    int philo_number;

    philo_number = data->philo_number;
    i = -1;
    philo = (t_philo *)malloc(sizeof(t_philo) * philo_number);
    while( ++i < philo_number)
    {
        philo[i].philo_id = i + 1;
        philo[i].philo_t =malloc(sizeof(pthread_t) * philo_number);
        philo[i].r_fork = i;
        philo[i].l_fork = (i + 1)%philo_number;
        philo[i].meals_counter = 0;
        philo[i].data = data;
    }
    return(philo);
}

t_properties *constructor(char **av)
{
    t_properties *data;

    data = (t_properties *)malloc(sizeof(t_properties));
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
        init_mutex(data);
		data->should_end = 0;
        data->philo = construct_philos(data);
        return(data);
    }
    return(NULL);
}