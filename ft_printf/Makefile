NAME	= ft_printf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	=
AR = ar rcs
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
