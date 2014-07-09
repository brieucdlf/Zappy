#include	"Socket.hpp"
#include	"ClientGraphic.hpp"
#include	"TaskManager.hpp"
#include	"ExecCommand.hpp"
#include	"Map.hpp"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Socket	socket(av[1], ::atoi(av[2]));
      ClientGraphic client(1000, 1000);
      TaskManager	manager;
      ExecCommand	command;
      Map		map;

      while (client.isOpen() && socket.isConnected())
	{
	  client.getKey();
	  manager.parseReceiveCommand(socket.readSocket());
	  command.runTask(manager.getTask());
	  if (map.getWidth() != 0 && map.getHeight() != 0)
	    client.draw(map.getWidth(), map.getHeight());
	  else
	    client.loading();
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
