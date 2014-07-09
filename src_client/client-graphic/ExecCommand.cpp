#include "ExecCommand.hpp"

ExecCommand::ExecCommand()
{
  commands.push_back("msz");
  commands.push_back("bct");
  commands.push_back("tna");
  commands.push_back("pnw");
  commands.push_back("ppo");
  commands.push_back("plv");
  commands.push_back("pin");
  commands.push_back("pex");
  commands.push_back("pbc");
  commands.push_back("pic");
  commands.push_back("pie");
  commands.push_back("pfk");
  commands.push_back("pdr");
  commands.push_back("pgt");
  commands.push_back("pdi");
  commands.push_back("enw");
  commands.push_back("eht");
  commands.push_back("ebo");
  commands.push_back("edi");
  commands.push_back("sgt");
  commands.push_back("seg");
  commands.push_back("smg");
  commands.push_back("suc");
  commands.push_back("sbp");
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

void	ExecCommand::runTask(std::string task)
{
  std::vector<std::string> param;

  if (task.empty())
    {
      std::cout << "Task is empty" << std::endl;
      return ;
    }
  param = splitTask(task);
  for (std::vector<std::string>::iterator it = commands.begin() ; it != commands.end()
	 ; ++it)
    {
      if (param[0] == *it)
	{
	  std::cout << "Run Task : " << param[0] << " with params : ";
	  for (std::vector<std::string>::iterator it2 = param.begin()
		 ; it2 != param.end() ; ++it2)
	    {
	      std::cout << *it2 << " ";
	    }
	  std::cout << std::endl;
	}
    }
}

/*
** COMMANDS
*/

// void	ExecCommand::runMsz(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runBct(std::vector<std::string> param)
// {

// }

// void	ExecCommand::runTna(std::vector<std::string> param)
// {

// }

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
