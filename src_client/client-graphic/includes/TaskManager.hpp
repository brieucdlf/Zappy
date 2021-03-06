//
// TaskManager.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 13:39:08 2014 Jeremy Peltier
// Last update Wed Jul  9 12:15:48 2014 Remi Hillairet
//

#ifndef		TASK_MANAGER_HPP_
# define	TASK_MANAGER_HPP_

# include	<vector>
# include	<sstream>
# include	"Socket.hpp"
# include	"Task.hpp"

class		TaskManager
{
public:
  TaskManager();
  ~TaskManager();

public:
  void		add(Task);
  std::string	send();
  std::string	getTask();
  void		parseReceiveCommand(const std::string);
  void		showAllSent();
  void		showAllReceive();

private:
  Socket		socket;
  std::vector<Task>	sentTask;
  std::vector<Task>	receiveTask;
  std::string		buffer;
};

#endif		/* !TASK_MANAGER_HPP_ */
