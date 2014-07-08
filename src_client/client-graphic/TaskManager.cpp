//
// TaskManager.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 14:01:20 2014 Jeremy Peltier
// Last update Tue Jul  8 09:42:58 2014 Jeremy Peltier
//

#include	"TaskManager.hpp"
#include	<iostream>

TaskManager::TaskManager()
{
  this->buffer = "";
}

TaskManager::~TaskManager()
{
  this->sentTask.clear();
  this->receiveTask.clear();
}

void	TaskManager::parseReceiveCommand(std::string buffer)
{
  if (!buffer.empty())
    {
      std::string tmp = buffer;
      std::string delimiter = "\n";
      size_t pos = 0;
      std::string command;

      while ((pos = tmp.find(delimiter)) != std::string::npos)
	{
	  command = tmp.substr(0, pos);
	  tmp.erase(0, pos + 1);
	  Task	task(command);
	  this->receiveTask.push_back(command);
	}
    }
}

void	TaskManager::add(Task task)
{
  this->sentTask.push_back(task);
}

std::string	TaskManager::send()
{
  if (sentTask.size() > 0)
    {
      std::string tmp = ((Task)sentTask.front()).getCommand();
      sentTask.erase(sentTask.begin());
      return (tmp);
    }
  return ("");
}

std::string	TaskManager::get()
{
  if (receiveTask.size() > 0)
    {
      std::string tmp = ((Task)receiveTask.front()).getCommand();
      receiveTask.erase(receiveTask.begin());
      return (tmp);
    }
  return ("");
}

void	TaskManager::showAllSent()
{
  for (unsigned int i = 0; i < sentTask.size(); ++i)
    {
      std::cout << ((Task)sentTask[i]).getCommand() << std::endl;
    }
}

void	TaskManager::showAllReceive()
{
  for (unsigned int i = 0; i < receiveTask.size(); ++i)
    {
      std::cout << ((Task)receiveTask[i]).getCommand() << std::endl;
    }
}
