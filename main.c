#include"philo.h"

int main(int ac,char **av)
{
    t_properties *data;
    
    if (ac == 5 || ac == 6)
    {
        if (check_syntax(av))
            return(1);
        data = constructor(av);
        printf("1 == %d\n", data->philo_number);
        printf("2 == %d\n", data->time_to_die);
        printf("3 == %d\n", data->time_to_eat);
        printf("4 == %d\n", data->time_to_sleep);
        printf("5 == %d\n", data->meals_nbr);
        printf("philo->1 == %d\n", data->philo[1].philo_id);
        printf("philo->2 == %d\n", data->philo[1].r_fork);
        printf("philo->3 == %d\n", data->philo[1].l_fork);
        printf("philo->4 == %d\n", data->philo[1].meals_counter);
    }
    else
        printf("Usage : <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>");
}