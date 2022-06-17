#include"philo.h"


void print_status(t_philo *philo, char *status)
{
    int timestamp;

    pthread_mutex_lock(&(philo->data->write));
    timestamp = getcurrenttime() - philo->data->time_of_start;
    printf("%d philo %d %s \n",timestamp, philo->philo_id, status);
    pthread_mutex_unlock(&(philo->data->write));
}
