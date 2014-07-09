CC		=	g++ -g

RM		=	rm -fv

NAME		=	../../graphic-client

CXXFLAGS	=	-Wall -Wextra -Werror -W
CXXFLAGS	+=	-I$(INCLUDES)

SRCS		=	main.cpp \
			ClientGraphic.cpp \
			IsometricSprite.cpp \
			TextureManager.cpp \
			Socket.cpp \
			Task.cpp \
			TaskManager.cpp \
			ExecCommand.cpp \
			Map.cpp

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
