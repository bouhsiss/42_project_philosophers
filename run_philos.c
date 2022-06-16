#include"philo.h"

void print_status(t_philo *philo, char *status)
{
    int timestamp;

    pthread_mutex_lock(&(philo->data->write));
    timestamp = getcurrenttime() - philo->data->time_of_start;
    printf("%d philo %d %s\n",timestamp, philo->philo_id, status);
    pthread_mutex_unlock(&(philo->data->write));
}

void *routine(void *philo_struct)
{
    t_philo *philo;

	while(69)
	{
		philo = (t_philo *)philo_struct;
		pthread_mutex_lock(&(philo->data->forks[philo->r_fork]));
		print_status(philo, "has taken the right fork");
		pthread_mutex_lock(&(philo->data->forks[philo->l_fork]));
		print_status(philo, "has taken the left fork");
		print_status(philo, "is eating");
		philo->last_meal = getcurrenttime();
		philo->meals_counter++;
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&(philo->data->forks[philo->r_fork]));
		pthread_mutex_unlock(&(philo->data->forks[philo->l_fork]));
		print_status(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_status(philo, "is thinking");
	}
    return(NULL);
}

void run_philos(t_properties *data)
{
    int i;
    i = -1;
 
    while(++i < data->philo_number)
    {
        data->philo[i].last_meal = getcurrenttime();
        pthread_create(&(data->philo[i].philo_t), NULL, &routine, &(data->philo[i]));
        usleep(100);
    }
}