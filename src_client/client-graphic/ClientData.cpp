#include "ClientData.hpp"

ClientData::ClientData(){}

ClientData::~ClientData(){}

void ClientData::addTeam(std::string & teamName)
{
  teamNames.push_back(teamName);
}

void ClientData::addPlayer(int nbPlayer, Character & player)
{
  (void)nbPlayer;
  (void)player;
  //players[nbPlayer] = player;
}

std::vector<std::string> ClientData::getTeams() const
{
  return teamNames;
}

Map ClientData::getMap() const
{
  return map;
}

Character ClientData::getPlayer(int nbPlayer)
{
  return players[nbPlayer];
}
