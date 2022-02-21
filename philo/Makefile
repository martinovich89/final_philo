NAME		=	philo

SRCS		=	philo.c string.c utils.c mem.c clear.c time.c print.c init.c checks.c phase.c error.c

INC			=	philo.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -pthread #-fsanitize=thread

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%o: %c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
