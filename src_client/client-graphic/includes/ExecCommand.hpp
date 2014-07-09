#ifndef __EXEC_COMMAND_HPP__
# define __EXEC_COMMAND_HPP__

# include <vector>
# include <string>
# include <iostream>

class ExecCommand
{
public:
  ExecCommand();
  virtual ~ExecCommand();

public:
  std::vector<std::string> splitTask(std::string);
  void runTask(std::string);

private:
  std::vector<std::string> commands;
};

#endif /* !__EXEC_COMMAND_HPP__ */
