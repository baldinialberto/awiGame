#include "map.hpp"

me::map::map(const char *filename, sf::Vector2i mDims, sf::RenderWindow &parentWindow)
	: me::sprite{
		  me::filePath(string(filename).append(".png").c_str(), fm::pokekit_type::PROP).c_str(),
		  parentWindow}
{
	priority(0); // lowest priority
	set_textRect(0, 0, mDims.x, mDims.y);
	_sprite.move(-mDims.x / 2, -mDims.y / 2);
}

me::map::~map() {}