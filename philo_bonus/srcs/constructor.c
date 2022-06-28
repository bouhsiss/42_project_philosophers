#include"philo_bonus.h"

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

void init_sem(t_properties *data)
{
	int i;

	i = 0;
	sem_unlink("forks_sem");
	sem_unlink("write_sem");
	sem_unlink("can_eat_sem");
	data->forks = sem_open("forks_sem", O_CREAT, 0644, data->philo_number);
	data->write = sem_open("write_sem", O_CREAT, 0644, 1);
	data->can_eat = sem_open("can_eat_sem", O_CREAT, 0644, 1);
	data->well_fed_philos = sem_open("suervisor", O_CREAT, 0644, 0);
}

t_philo *construct_philos(t_properties *data)
{
	t_philo *philo;
	int i;
	int	philo_number;

	philo_number = data->philo_number;
	i = -1;
	philo = (t_philo *)malloc (sizeof(t_philo) * philo_number);
	while(++i < philo_number)
	{
		philo[i].philo_id = i + 1;
		philo[i].meals_counter = 0;
		philo[i].data = data;
	}
	return(philo);
}

int constructor(t_properties *data, char **av)
{
	if(!check_syntax(av))
	{
		data->philo_number  = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		if(av[5])
			data->meals_nbr = ft_atoi(av[5]);
		else
			data->meals_nbr = -1;
		data->time_of_start = getcurrenttime();
		init_sem(data);
		data->philo = construct_philos(data);
		return(EXIT_SUCCESS);
	}
	return(EXIT_FAILURE);
}