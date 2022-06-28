#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	int		philo_id;
	pid_t	philo_pid;
	int		meals_counter;
	long long	last_meal;
	struct s_properties *data;
}	t_philo;

typedef struct s_properties
{
	int		philo_number;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_nbr;
	long long	time_of_start;
	sem_t		*well_fed_philos;
	sem_t		*write;
	sem_t		*can_eat;
	sem_t		*forks;
	t_philo		*philo;
}	t_properties;

int constructor(t_properties *data, char **av);
int	print_error(char *error_message);
int	ft_atoi(const char *str);
void	print_status(t_philo *philo, char *status);
void	ft_usleep(int time);
long long	getcurrenttime(void);
void	launch_philos(t_properties *data);
void philo_routine(t_philo *philo);
void print_status(t_philo *philo, char *message);

#endif