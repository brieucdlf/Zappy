##
## Makefile for Zappy in /home/delafo_b/tek2/repo/Zappy
##
## Made by Brieuc de La Fouchardiere
## Login   <delafo_b@epitech.net>
##
## Started on  Mon Jun  2 11:23:49 2014 Brieuc de La Fouchardiere
## Last update Mon Jun  2 11:34:51 2014 Brieuc de La Fouchardiere
##

CLIENT_FILES	=	src_client/client-ia/

SERVER_FILES	=	src_server/

CP		=	cp -f

RM		=	rm -f

all:
	$(MAKE) -C $(CLIENT_FILES)
	$(MAKE) -C $(SERVER_FILES)
	$(CP) $(CLIENT_FILES)client .
	$(CP) $(SERVER_FILES)server .

clean:
	$(MAKE) -C  $(CLIENT_FILES) clean
	$(MAKE) -C  $(SERVER_FILES) clean

fclean:
	$(MAKE) -C  $(CLIENT_FILES) fclean
	$(MAKE) -C  $(SERVER_FILES) fclean
	$(RM) client
	$(RM) server

re:
	$(MAKE) -C $(CLIENT_FILES) re
	$(MAKE) -C $(SERVER_FILES) re
