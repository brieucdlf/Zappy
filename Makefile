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
