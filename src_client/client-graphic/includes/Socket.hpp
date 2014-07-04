//
// Socket.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  2 16:22:01 2014 Jeremy Peltier
// Last update Fri Jul  4 15:44:30 2014 Jeremy Peltier
//

#ifndef		CLIENT_HPP_
# define	CLIENT_HPP_

# include	<sys/types.h>
# include	<sys/socket.h>
# include	<sys/time.h>
# include	<sys/wait.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>
# include	<string.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<signal.h>
# include	<dirent.h>
# include	<errno.h>
# include	<time.h>
# include	<ext/stdio_filebuf.h>
# include	<iostream>
# include	<fstream>
# include	<string>
# include	<sstream>

class		Socket
{
public:
  Socket();
  Socket(const std::string &, int);
  virtual ~Socket();

public:
  int	connectSocket();
  bool	isConnected();

public:
  void			setHost(std::string &);
  void			setPort(int);
  std::string		readSocket();
  void			writeOnSocket(std::string &);

private:
  std::string		host;
  int			port;
  int			fd;
  fd_set		readFd;
  fd_set		writeFd;
  struct sockaddr_in	sinServer;
  bool			connected;
  std::string		read;
};

#endif		/* CLIENT_HPP_ */
