#include"philo.h"

int check_syntax(char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(av[i])
    {
        while(av[i][j])
        {
		    if (!(av[i][j] >= '0' || av[i][j] <= '9'))
            {
                printf("%s : wrong argument", av[i]);
                return(1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

t_philo *init_philo(t_properties **data)
{
    t_philo *philo;
    int i;
    int philo_number;

    philo_number = (*data)->philo_number;
    i = 0;
    philo = (t_philo *)malloc(sizeof(t_philo) * philo_number);
    while(i <= philo_number)
    {
        philo[i].philo_id = i;
        philo[i].r_fork = i ;
        philo[i].l_fork = (i + 1)%philo_number;
        philo->meals_counter = 0;
        philo->data = (*data);
        i++;
    }
    return(philo);
}

t_properties *constructor(char **av)
{
    t_properties *data;

    data = malloc(sizeof(t_properties));
    if (!check_syntax(av))
    {
        data->philo_number = ft_atoi(av[1]);
        data->time_to_die = ft_atoi(av[2]);
        data->time_to_eat = ft_atoi(av[3]);
        data->time_to_sleep = ft_atoi(av[4]);
        if (av[5])
            data->meals_nbr = ft_atoi(av[5]);
        data->philo = init_philo(&data);
    }
    return(data);
}