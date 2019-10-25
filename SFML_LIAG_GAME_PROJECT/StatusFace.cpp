#include "StatusFace.h"

StatusFace::StatusFace(string path,Vector2f pos)
{
	//cout << pos.x << endl;
	this->texture.loadFromFile(path);
	this->texture.setSmooth(true);
	this->body.setTexture(this->texture);
	this->body.setPosition(pos.x,pos.y); // center X and rand Y
	this->body.setScale(1.5, 1.5);
}

void StatusFace::DRAW(RenderWindow* window)
{
	this->move();
	window->draw(this->body);
}

bool StatusFace::getDelete()
{
	return this->Del;
}

void StatusFace::move()
{
	totalTime += clock.restart().asSeconds();
	if (totalTime >= 2 || this->body.getPosition().y <= 130) this->Del = true;
	this->body.move(0, -A);
	A += 0.05;
}
