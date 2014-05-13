##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:37:28 2014 remi hillairet
## Last update Tue May  13 10:37:28 2014 remi hillairet
##

NAME	=	server

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-Wall -Wextra -Werror -Iinclude

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
