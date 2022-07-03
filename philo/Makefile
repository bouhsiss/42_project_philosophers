RED = \033[0;31m
NC = \033[0m	
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
TFLAGS = -lpthread
INCLUDES = -I ./Includes
SRCS = philo.c \
./srcs/philo_tools/ft_atoi.c \
./srcs/philo_tools/Print_error.c \
./srcs/philo_tools/print_status.c \
./srcs/philo_tools/Time_tools.c \
./srcs/constructor.c \
./srcs/Routine_actions.c \
./srcs/launch_philos.c \
./srcs/track_philos.c \
./srcs/philo_tools/print_tools.c \


all : $(NAME)


$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME) 
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

clean :
	@echo "${RED}====================================="
	rm -f *.o
	@echo "====== object files removed ======"
	@echo "===================================${NC}\n"

fclean : clean
	@echo "${YELLOW}====================================="
	rm -f $(NAME) $(BONUS_NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n${NC}"

re : fclean all

.PHONY : all clean fclean re
