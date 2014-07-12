#include "ClientData.hpp"

ClientData::ClientData(){}

ClientData::~ClientData(){}

void ClientData::addTeam(std::string & teamName)
{
  teamNames.push_back(teamName);
}

void ClientData::addPlayer(int nbPlayer, Character & player)
{
  players[nbPlayer] = player;
}

const std::vector<std::string> & ClientData::getTeams() const
{
  return teamNames;
}

Map & ClientData::getMap()
{
  return map;
}

Character & ClientData::getPlayer(int nbPlayer)
{
  return players[nbPlayer];
}

std::map<int, Character> & ClientData::getAllPlayers()
{
  return players;
}
