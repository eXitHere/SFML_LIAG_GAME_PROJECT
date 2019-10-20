#include "map.h"

Map::Map()
{
	this->map1.loadFromFile("texture\\map\\map1.jpg");
	this->map1.setSmooth(true);
	//this->map1.setRepeated(true);
	this->mapMain.setTexture(map1);
}

void Map::DRAW(RenderWindow* window)
{
	moveMap();
	window->draw(this->mapMain);
}

void Map::moveMap()
{
	this->mapMain.move(speedMap, 0);
}
