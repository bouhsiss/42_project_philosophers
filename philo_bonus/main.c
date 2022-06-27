#include"philo_bonus.h"

int main(int ac, char **av)
{
	t_properties *data;

	if (ac == 5  || ac == 6)
	{
		data = (t_properties *)malloc(sizeof(t_properties));
		if(constructor(data, av) || data->meals_nbr == 0)
			print_error("Error : invalid argument");
		launch_philos(data);
	}
}