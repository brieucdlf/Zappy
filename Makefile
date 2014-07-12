##
## Makefile for Zappy in /home/delafo_b/tek2/repo/Zappy
##
## Made by Brieuc de La Fouchardiere
## Login   <delafo_b@epitech.net>
##
## Started on  Mon Jun  2 11:23:49 2014 Brieuc de La Fouchardiere
## Last update Fri Jul 11 11:42:40 2014 Remi Hillairet
##

CLIENT_GRAPHIC	=	src_client/client-graphic/

SERVER_FILES	=	src_server/

all:
	@echo "\033[32m"
	@echo "#####################################"
	@echo "##     COMPILING SERVER FILES      ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(SERVER_FILES)
	@echo "\033[0m"
	@echo "\033[32m"
	@echo "#####################################"
	@echo "##  COMPILING GRAFIK CLIENT FILES  ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(CLIENT_GRAPHIC)
	@echo "\033[0m"

server:
	$(MAKE) -C $(SERVER_FILES)

graphic:
	$(MAKE) -C $(CLIENT_GRAPHIC)


clean:
	@echo "\033[31m"
	@echo "#####################################"
	@echo "##     CLEANING SERVER FILES      ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(SERVER_FILES) clean
	@echo "\033[0m"
	@echo "\033[31m"
	@echo "#####################################"
	@echo "##   CLEANING GRAFIK CLIENT FILES  ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(CLIENT_GRAPHIC) clean
	@echo "\033[0m"

fclean:
	@echo "\033[31m"
	@echo "#####################################"
	@echo "##     FCLEANING SERVER FILES      ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(SERVER_FILES) fclean
	@echo "\033[0m"
	@echo "\033[31m"
	@echo "#####################################"
	@echo "##   CLEANING GRAFIK CLIENT FILES  ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(CLIENT_GRAPHIC) fclean
	@echo "\033[0m"

re:
	@echo "\033[32m"
	@echo "#####################################"
	@echo "##   RECOMPILING SERVER FILES      ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(SERVER_FILES) re
	@echo "\033[0m"
	@echo "\033[32m"
	@echo "#####################################"
	@echo "## RECOMPILING GRAFIK CLIENT FILES ##"
	@echo "#####################################"
	@echo "\033[0m"
	@echo "\033[33m"
	$(MAKE) -C $(CLIENT_GRAPHIC) re
	@echo "\033[0m"
