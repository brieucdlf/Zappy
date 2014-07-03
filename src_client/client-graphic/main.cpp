//
// main.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:55:43 2014 Jeremy Peltier
// Last update Thu Jul  3 18:24:55 2014 Jeremy Peltier
//

#include	"Socket.hpp"
#include	"ClientGraphic.hpp"

int	main(void)
{
  Socket	socket("127.0.0.1", 65510);
  ClientGraphic client(1000, 1000);

  while (client.isOpen() && socket.isConnected())
    {
      client.getKey();
      client.draw(100, 100);
    }
  return (0);
}
