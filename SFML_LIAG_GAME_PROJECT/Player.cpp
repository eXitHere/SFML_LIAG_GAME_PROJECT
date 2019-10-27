#include "Player.h"

void Player::jump_Action()
{
	if (getJump() == 1) // Jump Up
	{
		//cout << isBaseHeight() << endl;
		//cout << "Jump!!!!!!" << endl;
		this->body.move(0, -jump_Value);
		if (isBaseHeight()) setJump(2);
		jump_Value -= 0.1;
		//cout << "Up" << endl;
	}
	else if (getJump() == 2)
	{
		//cout << this->jump_Value << endl;
		this->body.move(0, jump_Value);
		if (isBaseFloor()) setJump(0);
		jump_Value -= 0.1;
		//cout << "Down" << endl;
	}
}


bool Player::isBaseHeight()
{
	if (_action == 0) return this->body.getPosition().y < 500;
	else return this->body.getPosition().y< TOP+50;
}

bool Player::isBaseFloor()
{
	if(_action==0) return this->body.getPosition().y >= (baseFloor - Rec.height +30);
	else if(_action == 1) return this->body.getPosition().y >= (baseFloor - Rec.height + 30);
	else return this->body.getPosition().y >= baseFloor - Rec.height + 45;
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
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		if (!this->prees)
		{
			_action = 1;
			this->prees = true;
			updateRec(_action);
			setJump(2);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (this->prees)
		{
			this->prees = false;
			_action = 0;
			updateRec(_action);
			setJump(2);
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
	//cout << action << endl;
	this->body.setTexture(texturePlayer[action]);
	this->_action = action;
	this->totalTime = 0;
	this->switchColumn = 1;
	this->Rec.width = texturePlayer[action].getSize().x / this->numPic[action];
	this->Rec.height = texturePlayer[action].getSize().y;
	Rec.left = 0;
	if (_action == 0)
	{
		//this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 30));
	}
	else
	{
		this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 45));
	}
}
Player::Player() // for load data to player
{
	//cout << "Open class player";
	this->texturePlayer[0].loadFromFile("texture\\player\\baby-01.png");
	this->texturePlayer[1].loadFromFile("texture\\player\\baby+S-01.png");
	this->texturePlayer[2].loadFromFile("texture\\player\\run-01.png");
	this->texturePlayer[3].loadFromFile("texture\\player\\jump.png");
	for (int i = 0; i < 4; i++)
	{
		this->texturePlayer[i].setSmooth(true);
		this->texturePlayer[i].setRepeated(true);
	}
	this->body.setTexture(texturePlayer[0]);
	//this->body.setPosition(Vector2f(100.0f, 100.0f));
	this->Rec.width = texturePlayer[0].getSize().x / this->numPic[this->_action];
	this->Rec.height = texturePlayer[0].getSize().y / 1;
	if (_action == 0)
	{
		this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 30));
	}
	else if (_action == 1)
	{
		this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 10));
	}
	else
	{
		this->body.setPosition(Vector2f(100, baseFloor - Rec.height + 45));
	}
	
	this->sizeBody = Vector2f(Rec.width, Rec.height);
}

void Player::selectChalactor(int select)
{
	this->_action = select;
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
	this->jump_Value = jumpP[_action];
	if (this->_action == 0 || this->_action ==1)
	{
		//updateRec(0);
	}
	else
	{
		if (state == 0) updateRec(2);
		else if (state == 1) updateRec(3);
	}
}

int Player::getJump()
{
	return this->jumpState;
}
