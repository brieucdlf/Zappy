CC	=	gcc -g

RM	=	rm -f

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	jeremy-ia

CFLAGS	=	-W -Wall -Wextra -Werror

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all