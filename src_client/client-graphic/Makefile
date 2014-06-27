##
## Makefile for zappy in /Users/remihillairet/Epitech/Github/Zappy/client/client-graphic
##
## Made by remi hillairet
## Login   <remihillairet@epitech.net>
##
## Started on  Tue May  13 10:45:47 2014 remi hillairet
## Last update Tue Jul  1 10:04:01 2014 Jeremy Peltier
##

CC		=	g++

RM		=	rm -fv

NAME		=	client

CXXFLAGS	=	-Wall -Wextra -Werror -W -fPIC
CXXFLAGS	+=	-I$(INCLUDES)

SRCS		=	main.cpp \
			ClientGraphic.cpp

OBJS		=	$(SRCS:.cpp=.o)

SFML		=	-L/usr/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

INCLUDES	=	./includes/

$(NAME): 	$(OBJS)
		$(CC) $(SFML) -o $(NAME) -I$(INCLUDES) $(OBJS)

all: 		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
