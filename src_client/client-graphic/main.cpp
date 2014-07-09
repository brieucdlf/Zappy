//
// main.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:55:43 2014 Jeremy Peltier
// Last update Wed Jul  9 12:04:58 2014 Remi Hillairet
//

#include	"Socket.hpp"
#include	"ClientGraphic.hpp"
#include	"TaskManager.hpp"
#include	"ExecCommand.hpp"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Socket	socket(av[1], ::atoi(av[2]));
      ClientGraphic client(1000, 1000);
      TaskManager	manager;
      ExecCommand	command;
      // int		mapWidth = 0;
      // int		mapHeight = 0;

      while (client.isOpen() && socket.isConnected())
	{
	  client.getKey();
	  client.draw(100, 100);
	  manager.parseReceiveCommand(socket.readSocket());
	  command.runTask(manager.getTask());
	  // if (mapWidth != 0 && mapHeight != 0)
	  //   client.draw(mapWidth, mapHeight);
	  // else
	  //   client.loading();
	  /*
	  ** This is to send a task to the server.
	  ** Normally it's work but I can't test with our actually server. 08/07/2014
	  */
	  // Task t("titi\n");
	  // manager.add(t);
	  // socket.writeOnSocket(manager.send());
	}
    }
  else
    std::cout << "Usage: ./graphic-client host port" << std::endl;
  return (0);
}
