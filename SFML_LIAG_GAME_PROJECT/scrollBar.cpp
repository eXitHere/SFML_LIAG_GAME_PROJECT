#include "scrollBar.h"

scrollBar::scrollBar()
{
	font.loadFromFile("font\\impact.ttf");
	valString.setFont(font);
	valString.setString("100");
	valString.setCharacterSize(14);
	valString.setFillColor(Color::White);
	name.setFont(font);
	name.setString("TEST");
	name.setCharacterSize(24);
	name.setFillColor(Color::White);
}

void scrollBar::load(Vector2f body, int val)
{
	this->btn[0].loadFromFile("texture\\menu\\btn_ne.png");
	this->btn[1].loadFromFile("texture\\menu\\btn_ne_hold.png");
	this->btn[2].loadFromFile("texture\\menu\\btn_plus.png");
	this->btn[3].loadFromFile("texture\\menu\\btn_plus_hold.png");
	this->btn[4].loadFromFile("texture\\menu\\btnUn.png");
	this->btn[5].loadFromFile("texture\\menu\\btnUn_hold.png");
	this->btn[6].loadFromFile("texture\\menu\\btnMute.png");
	this->btn[7].loadFromFile("texture\\menu\\btnMute_hold.png");
	this->btnM.setTexture(btn[6]);
	this->btnN.setTexture(btn[1]);
	this->btnP.setTexture(btn[3]);
	this->texture.loadFromFile("texture\\menu\\scrollBar.png");
	this->textureDot.loadFromFile("texture\\menu\\scrollBTN.png");
	this->body.setTexture(this->texture);
	this->bodyDot.setTexture(this->textureDot);
	this->body.setPosition(body);
	this->positionBody = body;
	this->bodyDot.setOrigin(15.0f,15.0f);
	this->name.setPosition(body - Vector2f(0,35));
	this->btnN.setPosition(body - Vector2f(65,10) );
	this->btnP.setPosition(body + Vector2f(415+18,0) - Vector2f(0,5));
	this->btnM.setPosition(body + Vector2f(415 + 78, 0));
	valString.setPosition(bodyDot.getPosition());
	setVal(val);
	update();
}

int scrollBar::getVal()
{
	return this->val;
}

void scrollBar::setVal(int Val)
{
	if (Val == 0)
	{
		mute = true;
	}
	else mute = false;

	this->val = Val;
	update();
}

void scrollBar::update()
{
	this->bodyDot.setPosition(positionBody.x+30+((float)this->val/100*360),positionBody.y+25);
	valString.setPosition(bodyDot.getPosition()-Vector2f(10,8));
	valString.setString(to_string(this->val));
	//cout << this->val << endl;
}

void scrollBar::draw(RenderWindow* window)
{
	holdOn(window);
	window->draw(this->body);
	window->draw(this->bodyDot);
	window->draw(this->btnN);
	window->draw(this->btnP);
	window->draw(this->btnM);
	window->draw(this->valString);
	window->draw(this->name);
}

void scrollBar::setName(String name)
{
	this->name.setString(name);
}

void scrollBar::stopClick()
{
	this->click = false;
}

bool scrollBar::checkClick()
{
	return this->click;
}

void scrollBar::holdOn(RenderWindow* window) 
{
	mouseHoldOn(window);
	if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition(*window).x <= (this->bodyDot).getPosition().x + 15 && Mouse::getPosition(*window).y <= (this->bodyDot).getPosition().y + 15
		&& Mouse::getPosition(*window).x >= (this->bodyDot).getPosition().x-15 && Mouse::getPosition(*window).y >= (this->bodyDot).getPosition().y-15) // Click left on btn
	{
		this->clickOn = true;
		//cout << "Hold on" << endl;
		//cout << Mouse::getPosition(*window).y << endl;
		
	}
	//cout << temp << " "<< Mouse::isButtonPressed(Mouse::Left) << endl;
	if (!Mouse::isButtonPressed(Mouse::Left)) this->clickOn = false;

	if (this->clickOn)
	{
		float L = positionBody.x + 30;
		float R = positionBody.x + 30 + 360;
		//cout << ((Mouse::getPosition(*window).x - L) * 100 / (R - L)) << endl;
		if(Mouse::getPosition(*window).x+10<=R && Mouse::getPosition(*window).x+10>=L)
		this->setVal((int)(Mouse::getPosition(*window).x+10 - L) * 100 / (R - L));
		this->click = true;
	//	cout << "click" << endl;
	}
	
}

void scrollBar::mouseHoldOn(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x <= (this->btnN).getPosition().x + 50 && Mouse::getPosition(*window).y <= (this->btnN).getPosition().y + 50
		&& Mouse::getPosition(*window).x >= (this->btnN).getPosition().x && Mouse::getPosition(*window).y >= (this->btnN).getPosition().y) // Click left on btn
	{
		this->btnN.setTexture(btn[0]);
		this->totalTime += clock.restart().asSeconds();
		if(Mouse::isButtonPressed(Mouse::Left) && totalTime >= delta)
		{
			totalTime = 0;
			if (this->getVal() > 0)
			{
				setVal(--val);
				delta = (delta > 0.02 ? delta - 0.1 : 0.02);
			}
			this->click = true;
			//cout << "click" << endl;
		}
	}
	else if (Mouse::getPosition(*window).x <= (this->btnP).getPosition().x + 50 && Mouse::getPosition(*window).y <= (this->btnP).getPosition().y + 50
		&& Mouse::getPosition(*window).x >= (this->btnP).getPosition().x && Mouse::getPosition(*window).y >= (this->btnP).getPosition().y)
	{
		this->btnP.setTexture(btn[2]);
		this->totalTime += clock.restart().asSeconds();
		if (Mouse::isButtonPressed(Mouse::Left) && totalTime >= delta)
		{
			totalTime = 0;
			if (this->getVal() <100)
			{
				setVal(++val);
				delta = (delta > 0.02 ? delta - 0.1 : 0.02);
			}
			this->click = true;
		//	cout << "click" << endl;
		}
	}
	else if (Mouse::getPosition(*window).x <= (this->btnM).getPosition().x + 50 && Mouse::getPosition(*window).y <= (this->btnM).getPosition().y + 50
		&& Mouse::getPosition(*window).x >= (this->btnM).getPosition().x && Mouse::getPosition(*window).y >= (this->btnM).getPosition().y)
	{
		this->totalTime += clock.restart().asSeconds();
		if (Mouse::isButtonPressed(Mouse::Left) && totalTime >= 0.2)
		{
			totalTime = 0;
			mute = !mute;
			if (mute)
			{
				setVal(0);
			}
			else setVal(50);
			this->click = true;
			//cout << "click" << endl;
		}

		if (mute)
		{
			this->btnM.setTexture(btn[7]);
		}
		else
		{
			this->btnM.setTexture(btn[5]);
		}
		
	}
	else
	{
		this->btnN.setTexture(btn[1]);
		this->btnP.setTexture(btn[3]);
		delta = 0.7;
		if (mute)
		{
			this->btnM.setTexture(btn[6]);
		}
		else
		{
			this->btnM.setTexture(btn[4]);
		}
	}
	//cout << this->getVal() << endl;
}
