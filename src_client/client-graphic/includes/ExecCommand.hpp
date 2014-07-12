#ifndef __EXEC_COMMAND_HPP__
# define __EXEC_COMMAND_HPP__

# include <map>
# include <string>
# include <sstream>
# include <iostream>

#include "Map.hpp"
#include "ClientData.hpp"
#include "Character.hpp"

class ExecCommand
{
public:
  ExecCommand();
  virtual ~ExecCommand();

public:
  std::vector<std::string> splitTask(std::string);
  void runTask(std::string task, ClientData &data);
  void runMsz(std::vector<std::string> & param, ClientData & data);
  void runBct(std::vector<std::string> & param, ClientData & data);
  void runTna(std::vector<std::string> & param, ClientData & data);
  void runPnw(std::vector<std::string> & param, ClientData & data);
  void runPpo(std::vector<std::string> & param, ClientData & data);
  void runPlv(std::vector<std::string> & param, ClientData & data);
  void runPex(std::vector<std::string> & param, ClientData & data);
  void runPdr(std::vector<std::string> & param, ClientData & data);
  void runPgt(std::vector<std::string> & param, ClientData & data);
  void runPdi(std::vector<std::string> & param, ClientData & data);

private:
  std::map<std::string, void (ExecCommand::*)(std::vector<std::string> & param, ClientData & data)> _functions;
};

#endif /* !__EXEC_COMMAND_HPP__ */
