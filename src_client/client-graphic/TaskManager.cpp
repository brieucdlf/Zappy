//
// TaskManager.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 14:01:20 2014 Jeremy Peltier
// Last update Fri Jul  4 15:54:34 2014 Jeremy Peltier
//

#include	"TaskManager.hpp"

TaskManager::TaskManager(Socket &socket)
{
  this->socket = socket;
  this->buffer = "";
}

TaskManager::~TaskManager()
{
  this->sentTask.clear();
  this->receiveTask.clear();
}

void	TaskManager::updateBuffer()
{
  this->buffer += this->socket.readSocket();

  char	*parse;
  char	*command;

  parse = (char *)this->buffer.c_str();
  for (int i = 0; i < (int)this->buffer.length(); ++i)
    {
      if (parse[i] == '\n')
	{
	  for (int j = 0; j < (int)this->buffer.length() && parse[j] != '\n'; ++j)
	    {
	      command[j] = parse[j];
	      this->buffer = &parse[j];
	    }
	  Task task(command);
	  this->receiveTask.push_back(task);
	  command = '\0';
	}
    }
}

void	TaskManager::add(Task task)
{
  task = task;
}

std::string	TaskManager::getTask()
{
  Task		task = receiveTask.front();
  std::string	tmp = task.getCommand();
  receiveTask.erase(receiveTask.begin());
  return (tmp);
}
