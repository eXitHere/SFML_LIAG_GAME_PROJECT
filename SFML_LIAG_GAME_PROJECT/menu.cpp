#include "menu.h"
#define START_TOP -300
menu::menu(int* valMusic, int* valEffect)
{
	//test comment ///
	this->ValMusic = valMusic;
	this->ValEffect = valEffect;
	this->tempEffect = *valEffect;
	this->tempMusic = *valMusic;
	musicScrollBar.load(Vector2f(700, 300), *this->ValMusic);
	effectScrollBar.load(Vector2f(700, 400), *this->ValEffect);
	font.loadFromFile("font\\impact.ttf");
	scoreTexture.loadFromFile("texture\\menu\\scoreBackground.png");
	scoreBackground.setTexture(scoreTexture);
	scoreBackground.setPosition(600, 150);
	settingTexture.loadFromFile("texture\\menu\\settingBackground.png");
	settingBackground.setTexture(settingTexture);
	settingBackground.setPosition(600, 150);
	for (int i = 0; i < 5; i++)
	{
		score_Show[i].setFont(font);
		score_Show[i].setString("Name");
		score_Show[i].setCharacterSize(60);
		score_Show[i].setFillColor(Color::Red);
		score_Show[i].setStyle(sf::Text::Bold);
		score_Show[i].setPosition(700, position_Score[i]); // name_Show
	}
	for (int i = 0; i < 5; i++)
	{
		name_Show[i].setFont(font);
		name_Show[i].setString("Score");
		name_Show[i].setCharacterSize(60);
		name_Show[i].setFillColor(Color::Green);
		name_Show[i].setStyle(sf::Text::Bold);
		name_Show[i].setPosition(1200, position_Score[i]); // name_Show
	}
	//this->backgroundTexture.loadFromFile("texture\\menu\\bg_main.png");
	//this->background.setTexture(backgroundTexture);
	this->bgtx[0].loadFromFile("texture\\menu\\m1.png");
	this->bgtx[1].loadFromFile("texture\\menu\\m2.png");
	this->bgtx[2].loadFromFile("texture\\menu\\m3.png");
	this->bgtx[3].loadFromFile("texture\\menu\\m4.png");
	this->bgtx[4].loadFromFile("texture\\menu\\m5.png");

	for (int i = 0; i < 5; i++)
	{
		bgtx[i].setRepeated(true);
		bg[i].setTexture(bgtx[i]);	
	}
	this->rec[0].left = 0;
	this->rec[0].top = 0;
	this->rec[0].width = 20000;
	this->rec[0].height = 900;
	bg[2].setTextureRect(rec[0]);
	this->texture[0].loadFromFile("texture\\menu\\btn1.png");
	this->texture[1].loadFromFile("texture\\menu\\btn2.png");
	this->texture[2].loadFromFile("texture\\menu\\btn3.png");
	this->texture[3].loadFromFile("texture\\menu\\btn4.png");

	for (int i = 0; i < 4; i++)
	{
		this->button[i].setTexture(this->texture[i]);
		this->button[i].setPosition(200,START_TOP);
	}

	this->logoGame.loadFromFile("texture\\menu\\logogame.png");
	this->logoGameSprite.setTexture(logoGame);
	this->logoGameSprite.setPosition(850, 100);
	this->logoGameSprite.setRotation(1);

	//btn save cancel
	this->cancelTexture.loadFromFile("texture\\menu\\cancel.png");
	this->cancelHoldOnTexture.loadFromFile("texture\\menu\\cancelOn.png");
	this->saveHoldOnTexture.loadFromFile("texture\\menu\\saveOn.png");
	this->saveTexture.loadFromFile("texture\\menu\\save.png");
	this->cancelBtn.setTexture(cancelTexture);
	this->saveBtn.setTexture(saveTexture);
	this->saveBtn.setPosition(1270, 635);
	this->cancelBtn.setPosition(1380, 635);
}

void menu::DRAW(RenderWindow* window,Event *event)
{
	this->window = window;
	//cout << left.getPosition().x << " - " << left.getPosition().y << endl;
	mapPlayBack(window);
	display();
	for (int i = 0; i < 4; i++)
	{
		if (holdOn(&button[i], window, event, i))
		{
			///***  == != *** === <<= ==>
			this->stateSoundd = 1;
		}
		holdOn(&button[i], window, event, i);
		window->draw(button[i]);
	}
	moveButton();

	 if (statePage_ == 1)
	{
		window->draw(scoreBackground);
		for (int i = 0; i < 5; i++)
		{
			window->draw(score_Show[i]);
			window->draw(name_Show[i]);
		}
		
	}
	else if (statePage_ == 2)
	{
		window->draw(settingBackground);
		//tempVal = (tempVal < 100 ? tempVal + 1 : 0);
		//bar.setVal(tempVal);
		//valMusic = musicScrollBar.getVal();
		musicScrollBar.setName("Music");
		musicScrollBar.draw(window);
		effectScrollBar.setName("Effect");
		effectScrollBar.draw(window);	
		*(this->ValMusic) = musicScrollBar.getVal();
		*(this->ValEffect) = effectScrollBar.getVal();
		if (this->tempMusic != *(this->ValMusic) || this->tempEffect != *(this->ValEffect))
		{
			VALCHECAGE = true;
		}
		//this->soundManage->setVolMusic(musicScrollBar.getVal());
		//cout << tempVal << endl;
		if (effectScrollBar.checkClick())
		{
			this->stateSoundd = 2;
		}
		if (saveHold) saveBtn.setTexture(saveHoldOnTexture);
		else saveBtn.setTexture(saveTexture);
		if (cancelHold) cancelBtn.setTexture(cancelHoldOnTexture);
		else cancelBtn.setTexture(cancelTexture);
		checkSaveBtn();
		window->draw(saveBtn);
		window->draw(cancelBtn);
	}
	//window->draw(TEXT);
}

bool menu::holdOn(Sprite* btn, Window* window,Event* event,int index)
{
	
	if ((*event).type == Event::MouseMoved)
	{
		if (index != this->stateHold)
		{
			//cout << "Reset" << endl;
			(*btn).setScale(1.0f, 1.0f);
		}
	
		//cout << Mouse::getPosition(*window).x << endl;
		//cout << "Mouse : " << Mouse::getPosition(window).x << " Click " << testMouse.getPosition().x << endl;
		if (this->stateHold != index && Mouse::getPosition(*window).x <= (*btn).getPosition().x + 300 && Mouse::getPosition(*window).y <= (*btn).getPosition().y + 119
			&& Mouse::getPosition(*window).x >= (*btn).getPosition().x && Mouse::getPosition(*window).y >= (*btn).getPosition().y)
		{
			//this->stateSoundd++;
			//cout << "Set" << endl;
			//cout << "OnHold" << endl;
			//cout << this->stateSoundd << endl;
			//cout << "Check" << endl;
			(*btn).setScale(1.1f, 1.1f);
			this->stateHold = index;
			//cout << stateHold << endl;
			return 1;
		}
	}
	if (Mouse::isButtonPressed(Mouse::Left)  && Mouse::getPosition(*window).x <= (*btn).getPosition().x + 300 && Mouse::getPosition(*window).y <= (*btn).getPosition().y + 119
		&& Mouse::getPosition(*window).x >= (*btn).getPosition().x && Mouse::getPosition(*window).y >= (*btn).getPosition().y &&( statePage_ != index|| index==0))
	{
		this->statePage_ = index;
	//	cout << index << endl;
		//cout << "Click" << index << endl;
		if (index == 0)
		{
			this->__START = true;
			this->stateSoundd = 2;
		}
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && Mouse::getPosition(*window).x <= (*btn).getPosition().x + 300 && Mouse::getPosition(*window).y <= (*btn).getPosition().y + 119
		&& Mouse::getPosition(*window).x >= (*btn).getPosition().x && Mouse::getPosition(*window).y >= (*btn).getPosition().y)
	{
		this->stateSoundd = 2;
	}
	return 0;
}

int menu::stateSonud_OnHold()
{
	 return this->stateSoundd;
}

void menu::setStop()
{
	this->stateSoundd = 0;
	effectScrollBar.stopClick();
}

bool menu::gameStart()
{
	//cout << this->statePage_ << endl;
	return this-> __START;
}

void menu::changeSetting(bool* stateSave)
{
	this->valChange = stateSave;
}

void menu::onLoadButton()
{
	if (onLoadState)
	{
		for (int i = 0; i < 4; i++)
		{
			//cout << i << " " << this->upNid[i] << endl;
			if (!this->upNid[i] && !this->Change[i])
			{
				//cout << i << endl;
				A[i] -= 0.1;
				this->button[i].move(0, 20);
				//if(i==0 )cout << "Do1" << endl;
			}
			if (button[i].getPosition().y > 700 && !this->upNid[i] && !this->Change[i])
			{
				this->upNid[i] = true;		
				//if (i == 0)cout << "Do2" << endl;
			}
			if (upNid[i]&& !this->Change[i])
			{
				button[i].move(0, -30);
				if (button[i].getPosition().y < floor[i]-50)
				{
					//if (i == 0)cout << "Do3" << endl;
					this->Change[i] = true;
					this->upNid[i] = false;
					//this->onLoadState = false;
				}
			}
			if (Change[0] && Change[1] && Change[2] && Change[3])
			{
				this->onLoadState = false;
				//for (int i = 0; i < 4; i++) cout << button[i].getPosition().y << endl;
			}
		}	
	}
}

void menu::moveButton()
{
		if (stateMove)
		{
			this->button[0].move(0.5, 0);
			this->button[1].move(0.5, 0);
			this->button[2].move(0.5, 0);
			this->button[3].move(0.5, 0);
		}
		else
		{
			this->button[0].move(-0.5, 0);
			this->button[1].move(-0.5, 0);
			this->button[2].move(-0.5, 0);
			this->button[3].move(-0.5, 0);
		}
		//cout << button[i].getPosition().x << " STATE : " << this->stateMove << endl;
		if (this->button[0].getPosition().x == 250 && this->stateMove) this->stateMove = false;
		if (this->button[0].getPosition().x == 150 && !this->stateMove) this->stateMove = true;
}

void menu::logoMovement()
{
	//cout << logoGameSprite.getRotation() << endl;
	//logoGameSprite.setRotation(340);
	if (clockLogo.getElapsedTime().asSeconds() > 2.5 && this->logoRota == -1)
	{
		this->logoRota = 0;
	//	cout << "go !!" << endl;
	}
	if (logoGameSprite.getRotation() < 35 && this->logoRota ==0 )
	{
		//cout << "M1";
		logoGameSprite.setRotation(logoGameSprite.getRotation() + 0.25);
		if (logoGameSprite.getRotation() == 35)
		{
			this->logoRota = 1;
			//cout << "Move 1" << endl;
		}
	}
	else if (logoGameSprite.getRotation() > 0 && this->logoRota == 1 )
	{
		logoGameSprite.setRotation(logoGameSprite.getRotation() - 0.25 );
		if (logoGameSprite.getRotation() == 0)
		{
			this->logoRota = 0;

		}
	}
	
	//if(logoGameSprite.getRotation())
}

void menu::usePage0()
{
	//cout << "Statepage : " << statePage_ << " 2: " << statePage[0] << endl;
	
	if(this->statePage_ != 0 && statePage[0])// Hide
	{
		statePage[0] = false;
		//cout << "Hide page 0" << endl;
		this->logoGameSprite.setPosition(850, 100);
		this->logoGameSprite.setRotation(1);
		this->logoRota == -1;
	}
	else if (statePage[0] || statePage_==0) // show on!
	{
		//cout << "Show page 0 " << endl;
		logoMovement();
		this->window->draw(logoGameSprite);
	}
}

void menu::usePage1()
{
	if (this->statePage_ != 1 && statePage[1])// Hide
	{
		statePage[1] = false;
	//	cout << "Hide page 1" << endl;
		
	}
	else if (statePage[1] || statePage_ == 1) // show on!
	{
	//	cout << "Show page 1 " << endl;
	}
}

void menu::usePage2()
{
	if (this->statePage_ != 2 && statePage[2])// Hide
	{
		statePage[2] = false;
	//	cout << "Hide page 2" << endl;

	}
	else if (statePage[2] || statePage_ == 2) // show on!
	{
		//cout << "Show page 2 " << endl;
	}
}

void menu::usePage3()
{
	if (statePage_ == 3)
	{
		this->window->close();
		//cout << "close" << endl;
	}
	
}

void menu::mapPlayBack(RenderWindow* window)
{
	//window->draw(background);

	this->bg[2].move(-0.3, 0);
	//cout << bg[2].getPosition().x << endl;
	if (this->bg[2].getPosition().x < -19000)
	{
		this->bg[2].setPosition(0, 0);
	}
	//this->bg[3].move(-1, 0);
	for (int i = 0; i < 5; i++)
	{
		window->draw(bg[i]);
	}
	this->onLoadButton();
	//logoMovement();
	
}

void menu::checkSaveBtn()
{
	if (statePage_ == 2)
	{
		if (Mouse::getPosition(*window).x <= (saveBtn).getPosition().x + 100 && Mouse::getPosition(*window).y <= (saveBtn).getPosition().y + 50
			&& Mouse::getPosition(*window).x >= (saveBtn).getPosition().x && Mouse::getPosition(*window).y >= (saveBtn).getPosition().y)
		{
			if (Mouse::isButtonPressed(Mouse::Left) && VALCHECAGE)
			{
				*this->valChange = false;
				VALCHECAGE = false;
				// update temp
				this->tempEffect = *ValEffect;
				this->tempMusic = *ValMusic;
			//	cout << "save" << endl;
				//
			}
			this->saveHold = true;
			
		}
		else if (Mouse::getPosition(*window).x <= (cancelBtn).getPosition().x + 100 && Mouse::getPosition(*window).y <= (cancelBtn).getPosition().y + 50
			&& Mouse::getPosition(*window).x >= (cancelBtn).getPosition().x && Mouse::getPosition(*window).y >= (cancelBtn).getPosition().y)
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->VALCHECAGE)
			{
				VALCHECAGE = false;
				*ValEffect = this->tempEffect;
				*ValMusic = this->tempMusic;
				this->musicScrollBar.setVal(*ValMusic);
				this->effectScrollBar.setVal(*ValEffect);
				//cout << "cancel Click" << endl;
			}
			this->cancelHold = true;
			//cout << "cancel" << endl;
		}
		else this->saveHold = this->cancelHold = false;
	}
}

void menu::display()
{
	usePage0();
	usePage1();
	usePage2();
	usePage3();
}
