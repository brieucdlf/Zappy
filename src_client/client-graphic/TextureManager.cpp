//
// ImageManager.cpp for ClientGraphic in /home/peltie_j/Desktop/Epitech/Tek2/unix/Zappy/src_client/client-graphic
//
// Made by Jeremy Peltier
// Login   <peltie_j@epitech.net>
//
// Started on  Tue Jul  1 20:02:37 2014 Jeremy Peltier
// Last update Tue Jul  1 22:06:35 2014 Jeremy Peltier
//

#include	"TextureManager.hpp"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
  clear();
}

sf::Texture	*TextureManager::getTexture(std::string &name)
{
  std::map<std::string, sf::Texture>::iterator it = this->textures.find(name);
  if (it == this->textures.end())
    {
      sf::Texture texture;
      texture.loadFromFile(name);
      this->textures.insert(std::pair<std::string, sf::Texture>(name, texture));
      it = this->textures.find(name);
    }
  return &(it->second);
}

void		TextureManager::clear()
{
  this->textures.clear();
}