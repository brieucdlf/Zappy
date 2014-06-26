##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:37:28 2014 remi hillairet
## Last update Tue Jun 10 11:19:24 2014 romain combe
## Last update Thu May 15 13:32:33 2014 Brieuc
##

NAME	=	../server

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-g3 -Wall -Wextra -Iinclude

SRCS	=	src/main.c				\
		src/create_server.c			\
		src/list/list.c				\
		src/list/map_list.c			\
		src/list/remove_list.c			\
		src/init.c				\
		src/free.c				\
		src/set_fd_socket.c			\
		src/run_server.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
