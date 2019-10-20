#include "Items.h"
//loadFromFile("texture\\map\\map1.jpg");
Items::Items()
{
	this->texture[0].loadFromFile("texture\\items\\bear.png");
	this->REC.width = texture[0].getSize().x / 4;
	this->REC.height = texture[0].getSize().y;
	this->REC.top = 0;
	this->REC.left = 0;
}

void Items::setPosition_Items(Vector2f Pos)
{
	this->item.setPosition(Pos);
}

void Items::DRAW(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::U))
	{
		//cout << "ADD!!" << endl;
		Add();
		//cout << "Size List : " << Items_List.size() << endl;
	}
	for (list<Sprite>::iterator n = this->Items_List.begin(); n != this->Items_List.end(); n++)
	{
		n->move(-5, 0);
		window->draw(*n);
		if (n->getPosition().x < 0) Items_List.erase(n);
		cout << n->getPosition().x << endl;
	}
}

void Items::update(float delta)
{
	
}

void Items::Add()
{
	this->item.setTexture(texture[0]);
	this->item.setPosition(2000.0f, 200.0f);
	this->Items_List.push_back(item);
}
