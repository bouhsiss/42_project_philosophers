#include"philo.h"

void *routine(void *philo_struct)
{
    t_philo *philo;

    philo = (t_philo *)philo_struct;
    printf("%d\n", philo->data->philo_number);
    return(NULL);
}

void run_philos(t_properties *data)
{
    int i;
    i = 0;

    while(i < data->philo_number)
    {
        pthread_create(&(data->philo[i].philo_t), NULL, routine, &(data->philo[i]));
        i++;
    }
    i = 0;
    while(i < data->philo_number)
    {
        pthread_join(data->philo[i].philo_t, NULL);
        i++;
    }
}