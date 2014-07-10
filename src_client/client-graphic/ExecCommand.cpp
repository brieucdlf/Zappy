#include "ExecCommand.hpp"

ExecCommand::ExecCommand()
{
  _functions["msz"] = &ExecCommand::runMsz;
  _functions["bct"] = &ExecCommand::runBct;
  _functions["tna"] = &ExecCommand::runTna;
  // _functions["pnw"] = &ExecCommand::runPnw;
  // _functions["ppo"] = &ExecCommand::runPpo;
  // _functions["plv"] = &ExecCommand::runPlv;
  // _functions["pin"] = &ExecCommand::runPin;
  // _functions["pex"] = &ExecCommand::runPex;
  // _functions["pbc"] = &ExecCommand::runPbc;
  // _functions["pic"] = &ExecCommand::runPic;
  // _functions["pie"] = &ExecCommand::runPie;
  // _functions["pfk"] = &ExecCommand::runPfk;
  // _functions["pdr"] = &ExecCommand::runPdr;
  // _functions["pgt"] = &ExecCommand::runPgt;
  // _functions["pdi"] = &ExecCommand::runPdi;
  // _functions["enw"] = &ExecCommand::runEnw;
  // _functions["eht"] = &ExecCommand::runEht;
  // _functions["ebo"] = &ExecCommand::runEbo;
  // _functions["edi"] = &ExecCommand::runEdi;
  // _functions["sgt"] = &ExecCommand::runSgt;
  // _functions["seg"] = &ExecCommand::runSeg;
  // _functions["smg"] = &ExecCommand::runSmg;
  // _functions["suc"] = &ExecCommand::runSuc;
  // _functions["sbp"] = &ExecCommand::runSbp;
}

ExecCommand::~ExecCommand(){}

std::vector<std::string> ExecCommand::splitTask(std::string task)
{
  std::vector<std::string> param;
  std::string delimiter = " ";
  size_t pos = 0;

  while ((pos = task.find(delimiter)) != std::string::npos)
    {
      param.push_back(task.substr(0, pos));
      task.erase(0, pos + 1);
    }
  if (!task.empty())
    param.push_back(task);
  return param;
}

void	ExecCommand::runTask(std::string task, ClientData & data)
{
  std::vector<std::string> param;
  void (ExecCommand::*ptr)(std::vector<std::string> & param, ClientData & data);

  if (task.empty())
    return ;
  param = splitTask(task);
  if (_functions[param[0]] == NULL)
    return ;
  ptr = _functions[param[0]];
  (this->*ptr)(param, data);
}

/*
** COMMANDS
*/

void	ExecCommand::runMsz(std::vector<std::string> & param, ClientData & data)
{
  int	width;
  int	height;

  if (param.size() != 3)
    return ;
  std::istringstream(param[1]) >> width;
  std::istringstream(param[2]) >> height;
  data.getMap().setWidth(width);
  data.getMap().setHeight(height);
}

void		ExecCommand::runBct(std::vector<std::string> & param, ClientData & data)
{
  static int	nbBlock = 0;
  int		x;
  int		y;
  Inventory	invent;

  if (param.size() != 10 || data.getMap().getWidth() == 0
      || data.getMap().getHeight() == 0)
    return ;
  std::istringstream(param[1]) >> x;
  std::istringstream(param[2]) >> y;
  std::istringstream(param[3]) >> invent[FOOD];
  std::istringstream(param[4]) >> invent[LINEMATE];
  std::istringstream(param[5]) >> invent[DERAUMERE];
  std::istringstream(param[6]) >> invent[SIBUR];
  std::istringstream(param[7]) >> invent[MENDIANE];
  std::istringstream(param[8]) >> invent[PHIRAS];
  std::istringstream(param[9]) >> invent[THYSTAME];
  data.getMap().add(invent, x, y);
  nbBlock++;
  if (data.getMap().getPercentageLoaded() >= 99)
    {
      data.getMap().setPercentageLoaded(100);
      return ;
    }
  if (nbBlock <= (data.getMap().getWidth() * data.getMap().getHeight()) && data.getMap().getPercentageLoaded() < 100)
    data.getMap().setPercentageLoaded((nbBlock * 100) / (data.getMap().getWidth() * data.getMap().getHeight()));
}

void	ExecCommand::runTna(std::vector<std::string> & param, ClientData & data)
{
  if (param.size() != 2)
    return ;
  data.addTeam(param[1]);
}

// void	ExecCommand::runPnw(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPpo(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPlv(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPin(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPex(std::vector<std::string> param)
// {

// }
// void	ExecCommand::runPbc(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPic(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPie(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPfk(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPdr(std::vector<std::string> param)
// {

// }
// void	ExecCommand::runPgt(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runPdi(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runEnw(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runEht(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runEbo(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runEdi(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runSgt(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runSeg(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runSmg(std::vector<std::string> param)
// {

// }
// void	ExecCommand::runSuc(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runSbp(std::vector<std::string> param)
// {

// }
