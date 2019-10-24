#include "map.h"

Map::Map(string texture)
{
	//this->map1.loadFromFile("texture\\map\\map0-01.jpg");
	this->map1.loadFromFile(texture);
	this->map1.setSmooth(true);
	//this->map1.setRepeated(true);
	this->mapMain.setTexture(map1);
	this->mapMain.setPosition(1800, 0);
}

void Map::DRAW(RenderWindow* window)
{
	//cout << this->map1.getSize().x - abs(mapMain.getPosition().x) << endl;
	moveMap();
	window->draw(this->mapMain);
}

bool Map::loadNewMap()
{	
	return this->map1.getSize().x - abs(mapMain.getPosition().x) == 1800;
}

void Map::moveMap()
{
	this->mapMain.move(game_Speed, 0);
}
