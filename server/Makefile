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

CFLAGS	+=	-g -Wall -Wextra -Werror -Iinclude

SRCS	=	src/main.c				\
<<<<<<< HEAD
		src/buffer.c				\
		src/init.c 					\
=======
>>>>>>> fcb8e1b947bb7279dcf0fa2a9292621e29f824d6
		src/list/list.c				\
		src/list/map_list.c 			\
		src/list/remove_list.c			\
		src/test_list.c				\
		src/buffer.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
