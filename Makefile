##
## Makefile for  in /home/chatea_s/project/rush/rush/rush
## 
## Made by remi robert
## Login   <robert_r@epitech.net>
## 
## Started on  Sat Mar  8 02:41:05 2014 remi robert
## Last update Sat Apr  5 12:50:09 2014 remi robert
##

all:
	$(MAKE) -C client/client-ia
	$(MAKE) -C server

clean:
	$(MAKE) -C client/client-ia clean
	$(MAKE) -C server clean

fclean:
	$(MAKE) -C client/client-ia fclean
	$(MAKE) -C server fclean

re:
	$(MAKE) -C client/client-ia re
	$(MAKE) -C server re
