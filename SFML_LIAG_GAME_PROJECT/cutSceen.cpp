#include "cutSceen.h"

cutSceen::cutSceen()
{
	this->RIGHT.loadFromFile("texture\\menu\\cut_L.png");
	this->LEFT.loadFromFile("texture\\menu\\cut_R.png");
	this->right.setTexture(RIGHT);
	this->left.setTexture(LEFT);
	this->right.setPosition(-800, 0);
	this->left.setPosition(1600, 0);
	this->top.setPosition(0, -450);
	this->down.setPosition(0, 900);
	this->_DOWN.loadFromFile("texture\\menu\\cut_down-01.png");
	this->_TOP.loadFromFile("texture\\menu\\cut_top-01.png");
	this->top.setTexture(_TOP);
	this->down.setTexture(_DOWN);
}

void cutSceen::DRAW(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::C) && !cutSceenState)
	{
		this->cutSceenState = true;
		//cout << "CutSceenState " << this->cutSceenState << endl;
	}
	update();
	window->draw(right);
	window->draw(left);
	window->draw(top);
	window->draw(down);
}

void cutSceen::update()
{
	if (right.getPosition().x < 0 && cutSceenState && !offCutSceenState) {

		right.setPosition(R, 0);
		left.setPosition(L, 0);
		R += 20;
		L -= 20;
		if (right.getPosition().x >= 0)
		{
			clock.restart();
			offCutSceenState = true;
			right.setPosition(-800, 0);
			left.setPosition(1600, 0);
			top.setPosition(0, 0);
			down.setPosition(0, 450);
			R = 0;
			L = 450;
			this->__StateForMain = 2;
			//cout << "Clear " << endl;
		}
	}
	else if (offCutSceenState && cutSceenState)
	{	
		if (clock.getElapsedTime().asSeconds() > 1.8)
		{
			top.setPosition(0, R);
			down.setPosition(0, L);
			R -= 20;
			L += 20;
		}
		//cout << down.getPosition().y << endl;
		if (down.getPosition().y > 900)
		{
			//cout << "STOP" << endl;
			R = -800;
			L = 1600;
			cutSceenState = false;
			offCutSceenState = false;
			this->__StateForMain = 3;
		}
	}
}

void cutSceen::onCutSceen()
{
	this->cutSceenState = true;
	this->__StateForMain = 1;
	//cout << "CutSceen On ! " << endl;
}

int cutSceen::getState()
{
	return this-> __StateForMain;
}
