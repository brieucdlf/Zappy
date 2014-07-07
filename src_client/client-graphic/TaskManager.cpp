//
// TaskManager.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 14:01:20 2014 Jeremy Peltier
// Last update Mon Jul  7 14:39:36 2014 Jeremy Peltier
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

void	TaskManager::updateBuffer(std::string buffer)
{
  if (buffer.c_str() != NULL) {

    std::cout << buffer << std::endl;

    // char	*parse;
    // std::stringstream	command;
    // std::string	string;

    // parse = (char *)this->buffer.c_str();
    // std::cout << parse << std::endl;
    // for (int i = 0; i < (int)this->buffer.length(); ++i)
    //   {
    // 	if (parse[i] == '\n')
    // 	  {
    // 	    for (int j = 0; j < (int)this->buffer.length() && parse[j] != '\n'; ++j)
    // 	      command << parse[j];
    // 	    string = command.str();
    // 	    command.clear();
    // 	    ++i;
    // 	    // this->buffer = "";
    // 	    // Task task(string);
    // 	    // this->receiveTask.push_back(task);
    // 	  }
    // 	std::cout << string << std::endl;
    //   }
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

void	TaskManager::showAll()
{
  for (unsigned int i = 0; i < receiveTask.size(); ++i)
    {
      std::cout << ((Task)receiveTask[i]).getCommand() << std::endl;
    }
}
