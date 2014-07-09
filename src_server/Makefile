##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/server
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:37:28 2014 remi hillairet
## Last update Tue Jul  8 14:41:17 2014 Remi Hillairet
## Last update Thu May 15 13:32:33 2014 Brieuc
##

NAME	=	../server

CC	=	gcc

RM	=	rm -fv

CFLAGS	+=	-g3 -Wall -Wextra -Iinclude

SRCS	=	src/main.c					\
		src/list/list.c					\
		src/list/map_list.c 				\
		src/list/remove_list.c				\
		src/init_client.c				\
		src/init.c					\
		src/init_map.c					\
		src/free.c 					\
		src/run_server.c				\
		src/connect_client.c				\
		src/create_server.c				\
		src/read_socket.c				\
		src/deconnection_client.c			\
		src/write_socket.c				\
		src/set_fd_socket.c				\
		src/task/task.c					\
		src/task/command_fork.c				\
		src/task/command_list.c				\
		src/task/command_list_next.c			\
		src/task/timer_task.c				\
		src/timer.c					\
		src/create_write_task.c				\
		src/create_map.c				\
		src/task/command_voir.c				\
		src/manage_team.c				\
		src/task/command_expulse.c			\
		src/task/command_broadcast.c			\
		src/task/find_path.c				\
		src/graphic_client/manage_graphic_client.c	\
		src/graphic_client/read_write_graphic_client.c	\
		src/graphic_client/command_graphic_client.c	\
		src/timer_client.c				\
		src/task/command_incantation.c			\
		src/task/requirement_incantation.c		\
		src/timer_food.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) -lrt

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
