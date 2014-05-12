NAME	=	client

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-Wall -Wextra

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all