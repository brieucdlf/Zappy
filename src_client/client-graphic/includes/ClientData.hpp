#ifndef __CLIENT_DATA_HPP__
# define __CLIENT_DATA_HPP__

# include <string>
# include <map>

# include "Character.hpp"
# include "Map.hpp"

class ClientData
{
public:
  ClientData();
  virtual ~ClientData();

public:
  void addTeam(std::string & teamName);
  void addPlayer(int nbPlayer, Character & player);

public:
  std::vector<std::string> getTeams() const;
  Character getPlayer(int nbPlayer);
  Map  getMap() const;

private:
  std::vector<std::string> teamNames;
  std::map<int, Character> players;
  Map map;
};

#endif /* !__CLIENT_DATA_HPP__ */
