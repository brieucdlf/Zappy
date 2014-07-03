//
// main.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:55:43 2014 Jeremy Peltier
// Last update Wed Jul  2 18:25:02 2014 Jeremy Peltier
//

//#include	"Socket.hpp"
#include	"ClientGraphic.hpp"

int	main(void)
{
  //Socket	socket("127.0.0.1", 65510);
  ClientGraphic client(600, 600);

  while (client.isOpen() /*&& socket.isConnected()*/)
    {
      client.getKey();
      client.generateMap(300, 300);
      //      std::cout << socket.getCommand() << std::endl;
    }
  return (0);
}
