#include "Biker.h"

void Biker::Draw(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Y)&&!BIKE)
	{
		BIKE = true;
	}
	if (BIKE)
	{
		if(SMOKE)window->draw(this->Smoke);
		window->draw(this->body);
		if(clock.getElapsedTime().asSeconds()>0.9) SMOKE = true;
		this->Smoke.move(A-B,0);
		//this->Smoke.rotate(-0.2);
		this->body.move(A, 0.3);
		this->body.rotate(-0.2);
		A += 0.1;
		B -= 0.1;
		if (B < 0) B = 0;
		if (body.getPosition().x > 1600)
		{
			A = 5;
			BIKE = false;
			SMOKE = false;
			this->body.setPosition(Vector2f(200, 430));
			this->body.setRotation(0);
			this->Smoke.setPosition(Vector2f(140, 620));
			this->Smoke.setRotation(0);
			clock.restart();
		}
	}
}

Biker::Biker()
{
	this->texture.loadFromFile("texture\\effect\\bike.png");
	this->smoke.loadFromFile("texture\\effect\\bike_smoke.png");
	//this->texture.setSmooth(true);
	this->Smoke.setTexture(smoke);
	this->Smoke.setPosition(Vector2f(140, 620));
	this->Smoke.setScale(2, 2);
	this->body.setTexture(texture);
	this->body.setScale(0.8, 0.8);
	this->body.setPosition(Vector2f(200, 430));
}
