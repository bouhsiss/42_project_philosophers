#include"philo.h"

int getcurrenttime()
{
    struct  timeval time;

    gettimeofday(&time, NULL);
    return(time.tv_sec * 1000000 + time.tv_usec);
}