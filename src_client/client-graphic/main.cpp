//
// main.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:55:43 2014 Jeremy Peltier
// Last update Mon Jul  7 19:26:32 2014 Jeremy Peltier
//

#include	"Socket.hpp"
#include	"ClientGraphic.hpp"
#include	"TaskManager.hpp"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Socket	socket(av[1], ::atoi(av[2]));
      ClientGraphic client(1000, 1000);
      TaskManager	manager;

      while (client.isOpen() && socket.isConnected())
	{
	  client.getKey();
	  client.draw(100, 100);
	  manager.updateBuffer(socket.readSocket());
	  std::string task;
	  task = manager.getTask();
	  if (!task.empty())
	    std::cout << manager.getTask() << std::endl;
	}
    }
  else
    std::cout << "Usage: ./graphic-client host port" << std::endl;
  return (0);
}
