#include"philo_bonus.h"

void print_status(t_philo *philo, char *message)
{
	int timestamp;

	sem_wait(philo->data->write);
	timestamp = getcurrenttime() - philo->data->time_of_start;
	dprintf(1,"%d philo %d %s \n", timestamp, philo->philo_id, message);
	sem_post(philo->data->write);
}