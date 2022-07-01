RED = \033[0;31m
NC = \033[0m	
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread
TFLAGS = -lpthread
INCLUDES = -I ./Includes
SRCS = philo_bonus.c \
./srcs/philo_bonus_tools/ft_atoi.c \
./srcs/philo_bonus_tools/Print_error.c \
./srcs/philo_bonus_tools/Time_tools.c \
./srcs/philo_bonus_tools/print_status.c \
./srcs/philo_bonus_tools/print_tools.c \
./srcs/constructor.c \
./srcs/launch_philos.c \
./srcs/routine_actions.c \
./srcs/track_philos.c \

all : $(NAME)


$(NAME) : $(LIB) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

bonus : $(BONUS)
	@echo "${MAGENTA}====================================="
	$(CC) $(CFLAGS) $(SRCS)  -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS_SRCS)  -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n${NC}"



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
