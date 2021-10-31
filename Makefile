all : clean

clean :
	$(MAKE) -C aqueue clean
	$(MAKE) -C htable clean
	$(MAKE) -C queue  clean
	$(MAKE) -C string clean
