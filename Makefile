##
## Makefile for Zappy in /home/delafo_b/tek2/repo/Zappy
##
## Made by Brieuc de La Fouchardiere
## Login   <delafo_b@epitech.net>
##
## Started on  Mon Jun  2 11:23:49 2014 Brieuc de La Fouchardiere
## Last update Fri Jul 11 11:42:40 2014 Remi Hillairet
##

CLIENT_FILES	=	src_client/client-ia/

CLIENT_GRAPHIC	=	src_client/client-graphic/

SERVER_FILES	=	src_server/

all:
	$(MAKE) -C $(CLIENT_FILES)
	$(MAKE) -C $(SERVER_FILES)
	$(MAKE) -C $(CLIENT_GRAPHIC)

server:
	$(MAKE) -C $(SERVER_FILES)

graphic:
	$(MAKE) -C $(CLIENT_GRAPHIC)

ia:
	$(MAKE) -C $(CLIENT_FILES)

clean:
	$(MAKE) -C $(CLIENT_FILES) clean
	$(MAKE) -C $(SERVER_FILES) clean
	$(MAKE) -C $(CLIENT_GRAPHIC) clean

fclean:
	$(MAKE) -C $(CLIENT_FILES) fclean
	$(MAKE) -C $(SERVER_FILES) fclean
	$(MAKE) -C $(CLIENT_GRAPHIC) fclean

re:
	$(MAKE) -C $(CLIENT_FILES) re
	$(MAKE) -C $(SERVER_FILES) re
	$(MAKE) -C $(CLIENT_GRAPHIC) re
