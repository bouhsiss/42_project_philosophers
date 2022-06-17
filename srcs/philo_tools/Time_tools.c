#include"philo.h"

void	ft_usleep(int time)
{
	long long start;

	start = getcurrenttime() ;
	while(getcurrenttime() < start + time)
		usleep(50);
}

long long getcurrenttime()
{
    struct  timeval time;

    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
