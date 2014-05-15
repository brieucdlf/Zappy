/*
** socket_functions.c for zappy in /home/delafo_b/Projets/Zappy/server/src
** 
** Made by Brieuc
** Login   <delafo_b@epitech.net>
** 
** Started on  Tue May 13 17:12:16 2014 Brieuc
** Last update Thu May 15 10:45:27 2014 Brieuc
*/

#include "server.h"

int             xsocket(int domain, int type, int protocol)
{
  int           ret;

  ret = socket(domain, type, protocol);
  if (ret == -1)
    {
      printf("Socket error\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int             xaccept(int sockfd, struct sockaddr *addr,
                        socklen_t *addrlen)
{
  int           ret;

  ret = accept(sockfd, addr, addrlen);
  if (ret == -1)
    {
      printf("Accpet error\n");
      close(sockfd);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int             xlisten(int sockfd, int backlog)
{
  int           ret;

  ret = listen(sockfd, backlog);
  if (ret == -1)
    {
      printf("Listen error\n");
      close(sockfd);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int             xbind(int sockfd, const struct sockaddr *addr,
                      socklen_t addrlen)
{
  int           ret;

  ret = bind(sockfd, addr, addrlen);
  if (ret == -1)
    {
      printf("Bind error\n");
      close(sockfd);
      exit(EXIT_FAILURE);
    }
  return (ret);
}
