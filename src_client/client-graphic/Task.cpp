//
// Task.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 13:35:21 2014 Jeremy Peltier
// Last update Fri Jul  4 15:51:37 2014 Jeremy Peltier
//

#include	"Task.hpp"

Task::Task(std::string command)
{
  this->sending = false;
  this->characterSent = 0;
  this->command = command;
}

Task::~Task() {}

bool	Task::isSending() const
{
  return this->sending;
}

int	Task::nbCharacterSent() const
{
  return this->characterSent;
}

void	Task::setSending(bool sending)
{
  this->sending = sending;
}

void	Task::setCharacterSent(int characterSent)
{
  this->characterSent = characterSent;
}

std::string	Task::getCommand()
{
  return this->command;
}
