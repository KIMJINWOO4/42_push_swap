NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = com.c com2.c com3.c ft_atoi.c ft_split.c greedy.c \
		push_swap.c sort.c stack.c utils.c utils2.c utils3.c utils4.c
OBJS = $(SRCS:.c=.o)
RM = rm
INC = push_swap.h
RMFLAGS = -f

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

$(NAME): $(TOTAL_OBJS)
	$(CC) $(CFLAGS) -I ${INC} -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus