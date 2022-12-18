NAME = Philosophers
FLAGS = -Wall -Wextra -Werror

SRC = test.c utils.c
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

INC = inc/

all :
	gcc $(FLAGS) $(SRCS) -I$(INC) -o $(NAME)

clean :

fclean :
	rm $(NAME)

re : all clean fclean
