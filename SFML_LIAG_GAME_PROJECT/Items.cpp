#include "Items.h"
//loadFromFile("texture\\map\\map1.jpg");
Items::Items(Texture texture,Vector2f pos,int ID)
{
	this->ID = ID;
	this->texture = texture;
	this->REC.width = this->texture.getSize().x / 4;
	this->REC.height = this->texture.getSize().y;
	this->REC.top = 0;
	this->REC.left = 0;
	this->item.setTexture(this->texture);
	this->item.setPosition(pos);

	/*
	this Need to show girb for debug only!! 23.
	*/
	this->Grid.setOutlineThickness(2.0f);
	this->Grid.setOutlineColor(Color::Red);
	this->Grid.setSize(Vector2f(this->REC.width, this->REC.height));
}

void Items::setPosition_Items(Vector2f Pos)
{
	this->item.setPosition(Pos);
}

void Items::DRAW(RenderWindow* window)
{
	//this->Grid.setPosition(this->item.getPosition());
	this->update(); // call function
	this->move(); // call move!
	//window->draw(this->Grid);
	window->draw(this->item);
}

int Items::getType()
{
	
	return this->ID;
}

void Items::move()
{
	this->item.move(game_Speed-2, sin(forSin));
	forSin -= 0.1;
}

void Items::update()
{
	this->timeTotal += clock.restart().asSeconds();
	if (timeTotal >= time_Items) // in items.h >> define !!
	{
		timeTotal = 0;
		X = (X == 3 ? 0 : X + 1); // next or reset
	}
	this->REC.left = X * this->REC.width;
	this->item.setTextureRect(this->REC);
}

