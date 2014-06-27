//
// main.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 09:55:43 2014 Jeremy Peltier
// Last update Tue Jul  1 10:13:12 2014 Jeremy Peltier
//

#include	"ClientGraphic.hpp"

int	main(void)
{
  ClientGraphic client(500, 500);

  while (client.isOpen())
    {
      client.getKey();
    }
  return (0);
}
