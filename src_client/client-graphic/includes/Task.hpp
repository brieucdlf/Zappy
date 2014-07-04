//
// Task.hpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Fri Jul  4 13:33:29 2014 Jeremy Peltier
// Last update Fri Jul  4 15:50:32 2014 Jeremy Peltier
//

#ifndef		TASK_HPP_
# define	TASK_HPP_

# include	<string>

class		Task
{
public:
  Task(std::string);
  virtual ~Task();

public:
  bool	isSending() const;
  int	nbCharacterSent() const;
  void	setSending(bool);
  void	setCharacterSent(int);
  std::string	getCommand();

private:
  bool		sending;
  int		characterSent;
  std::string	command;
};

#endif		/* !TASK_HPP_ */
