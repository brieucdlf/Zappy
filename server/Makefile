##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:37:28 2014 remi hillairet
## Last update Thu May 15 11:36:15 2014 Brieuc
##

NAME	=	server

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-g -Wall -Wextra -Iinclude

SRCS	=	src/main.c				\
		src/socket_functions.c			\
		src/list/list.c				\
		src/list/map_list.c 			\
		src/list/remove_list.c			\
		src/test_list.c				\
		src/timer.c				\
		src/buffer.c				\
		src/init_client.c			\
		src/init.c				\
		src/free.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) -lrt

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
