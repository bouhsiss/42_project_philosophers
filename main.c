#include"philo.h"

int main(int ac,char **av)
{
    t_properties *data=NULL;

    if (ac == 5 || ac == 6)
    {
		data = (t_properties *)malloc(sizeof(t_properties));
        constructor(data, av);
        if (!data)
            print_error("Error : invalid argument");
		start_philos(data);
		track_philos(data);
    }
    else
        printf("Usage : <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>");
}
