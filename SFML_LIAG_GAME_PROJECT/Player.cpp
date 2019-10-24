#include "Player.h"

void Player::jump_Action()
{
	if (getJump() == 1) // Jump Up
	{
		//cout << isBaseHeight() << endl;
		//cout << "Jump!!!!!!" << endl;
		this->body.move(0, -jump_Value);
		if (isBaseHeight()) setJump(2);
		jump_Value -= 0.2;
	}
	else if (getJump() == 2)
	{
		this->body.move(0, jump_Value);
		if (isBaseFloor()) setJump(0);
		jump_Value -= 0.2;
	}
}


bool Player::isBaseHeight()
{
	return this->body.getPosition().y< TOP+50;
}

bool Player::isBaseFloor()
{
	return this->body.getPosition().y>= baseFloor - Rec.height + 45;
}

void Player::control()
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		//cout << "Jump!" << endl;
		if (!getJump())
		{
			setJump(1);
			//cout << "Jump Up!" << endl;
		}
	}
}

void Player::updata(float delta)
{
	//debug animation | can play all action? -> Yes! | 8.32pm 16/10
	//cout << "numPic : " << this->numPic[this->_action] << " switchCol : " << switchColumn << endl;
	//
	this->totalTime += delta;
	if (this->totalTime >= this->switchPic)
	{
		this->totalTime = 0;
		this->switchColumn++;
		if (switchColumn >= this->numPic[this->_action])
		{
			switchColumn = 0;
		}
		this->Rec.top = 0;
		this->Rec.left = switchColumn * Rec.width;
	}
}
void Player::updateRec(int action)
{
	//cout << numPic[action] << endl;
	//cout << "Update !! : " << this->action << endl;
	

	// debug animation 8.22pm 16/10
	//cout<< "Action" << action << " width : " << this->Rec.width << " height : " << this->Rec.height << " Switch : " << switchColumn << endl;
	//
	this->body.setTexture(texturePlayer[action]);
	this->_action = action;
	this->totalTime = 0;
	this->switchColumn = 1;
	this->Rec.width = texturePlayer[action].getSize().x / this->numPic[action];
	this->Rec.height = texturePlayer[action].getSize().y;
	Rec.left = 0;
	this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 45));
}
Player::Player() // for load data to player
{
	//cout << "Open class player";
	this->texturePlayer[0].loadFromFile("texture\\player\\run-01.png");
	this->texturePlayer[1].loadFromFile("texture\\player\\jump.png");
	for (int i = 0; i < 2; i++)
	{
		this->texturePlayer[i].setSmooth(true);
		this->texturePlayer[i].setRepeated(true);
	}
	this->body.setTexture(texturePlayer[0]);
	//this->body.setPosition(Vector2f(100.0f, 100.0f));
	this->Rec.width = texturePlayer[0].getSize().x / this->numPic[0];
	this->Rec.height = texturePlayer[0].getSize().y / 1;
	this->body.setPosition(Vector2f(100,baseFloor - Rec.height+45));
	this->sizeBody = Vector2f(Rec.width, Rec.height);
}

void Player::DRAW(RenderWindow* window)
{
	control();
	jump_Action();
	this->updata(clock.restart().asSeconds());
	this->body.setTextureRect(this->Rec);
	window->draw(this->body);
}

void Player::setJump(int state)
{
	this->jumpState = state;
	this->jump_Value = jumpP;
	if(state==0) updateRec(0);
	else if(state == 1) updateRec(1);
}

int Player::getJump()
{
	return this->jumpState;
}
