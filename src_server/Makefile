##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:37:28 2014 remi hillairet
## Last update Mon Jun  2 15:06:01 2014 Remi Hillairet
## Last update Thu May 15 13:32:33 2014 Brieuc
##

NAME	=	../server

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-g3 -Wall -Wextra -Iinclude

SRCS	=	src/main.c				\
		src/list/list.c				\
		src/list/map_list.c 			\
		src/list/remove_list.c			\
		src/test_list.c				\
		src/timer.c				\
		src/buffer.c				\
		src/init_client.c			\
		src/init.c				\
		src/init_map.c				\
		src/free.c 				\
		src/command.c 				\
		src/action/action.c 			\
		src/action/exec_action.c 		\
		src/action/move_action.c 		\
		src/action/object_action.c		\
		src/run_server.c			\
		src/connect_client.c			\
		src/create_server.c			\
		src/read_write_socket.c			\
		src/deconnection_client.c		\
		src/set_fd_socket.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) -lrt

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
