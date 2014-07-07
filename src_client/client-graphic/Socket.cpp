//
// Socket.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Wed Jul  2 16:23:46 2014 Jeremy Peltier
// Last update Mon Jul  7 11:41:27 2014 Jeremy Peltier
//

#include	"Socket.hpp"

Socket::Socket()
{
  this->host = "";
  this->port = 0;
  this->read = "";
}

Socket::Socket(const std::string &host, int port)
{
  this->host = host;
  this->port = port;
  this->read = "";
  connectSocket();
}

Socket::~Socket()
{
  std::cout << "Socket: Graphic Client connexion close" << std::endl;
  close(this->fd);
}

int			Socket::connectSocket()
{
  struct hostent	*server;

  if ((server = gethostbyname(this->host.c_str())) == NULL)
    {
      std::cout << "Socket: Server " << this->host << " not found" << std::cout;
      return (EXIT_FAILURE);
    }
  memcpy(&(sinServer.sin_addr), server->h_addr_list[0], server->h_length);
  sinServer.sin_port = htons(this->port);
  sinServer.sin_family = AF_INET;
  if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      std::cout << "Socket: Error in socket creation" << std::endl;
      return (EXIT_FAILURE);
    }
  if (connect(this->fd, (const struct sockaddr *)&(this->sinServer), sizeof(this->sinServer)) == -1)
    {
      std::cout << "Socket: Error in connect" << std::endl;
      close(this->fd);
      return (-1);
    }
  return (0);
}

bool	Socket::isConnected()
{
  int	returnSelect;

  FD_ZERO(&(this->readFd));
  FD_ZERO(&(this->writeFd));
  FD_SET(this->fd, &(this->readFd));
  FD_SET(this->fd, &(this->writeFd));

  if ((returnSelect = select(this->fd + 1, &(this->readFd), &(this->writeFd), NULL, NULL)) > 0)
    {
      if (FD_ISSET(this->fd, &(this->readFd)))
	{
	  this->read = "";
	  char buff[2048];
	  ::memset(buff, 0, 2048);

	  if ((::read(this->fd, buff, 2047)) <= 0)
	    this->connected = true;
	  this->read = buff;
	}
      if (FD_ISSET(this->fd, &(this->writeFd)))
	{
	  static bool toto = true;
	  if (toto)
	    {
	      ::write(this->fd, "GRAPHIC\n", 8);
	      toto = false;
	    }
	}
    }
  if (returnSelect == EBADF)
    std::cout << "error" << std::endl;
  return this->connected;
}

void	Socket::setHost(std::string &host)
{
  this->host = host;
}

void	Socket::setPort(int port)
{
  this->port = port;
}

std::string	Socket::readSocket()
{
  return this->read;
}

void	Socket::writeOnSocket(std::string &string)
{
  this->read = string;
}
