#include "hpAndHappyBar.h"
#define D 200.0
hpAndHappyBar::hpAndHappyBar() // load data
{
	this->texture.loadFromFile("texture\\effect\\hp_happy_bar.png");
	

	// Load color All !!
	this->G1.loadFromFile("texture\\effect\\G1.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G2.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G3.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G4.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G5.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G6.png");
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\G7.png");
	list_Texture.push_back(G1);
	list_Texture.push_back(G1);
	this->G1.loadFromFile("texture\\effect\\E.png");
	this->lop.setTexture(G1);
	this->lop2.setTexture(G1);
	//
	this->valHP.setPosition(90.0f, -58.5f);
	this->valHappy.setPosition(520.0f, -59.0f);
	this->hpHappyBar.setPosition(10.0f, -100.0f);
	//this->hpHappyBar.setPosition(10.0f, -15.0f);
	this->lop2.setPosition(90.0f, -58.5f);
	this->lop.setPosition(520.0f, -59.0f);

	this->hpHappyBar.setTexture(texture);
	this->valHappy.setTexture(list_Texture[0]);
	this->valHP.setTexture(list_Texture[0]);
	
	forHp = IntRect(0, 0, 330, 35);
	forHappy = IntRect(0, 0, 330, 35);

	Grid.loadFromFile("texture\\effect\\gridTOP.png");
	gridTop.setTexture(Grid);
	Grid.loadFromFile("texture\\effect\\gridDown.png");
	gridDown.setTexture(Grid);
	gridDown.setPosition(0, 900);
	gridTop.setPosition(0, -120);
	onSlide = true;
}

void hpAndHappyBar::reduceHp(int val) // -- hp
{
	this->hpVal -= val;
}

void hpAndHappyBar::reduceHappy(int val) // -- happy
{
	this->happyVal -= val;
}

void hpAndHappyBar::reset() // this function for restart game!!
{
	this->hpVal = 70;
	this->happyVal = 70;
}

void hpAndHappyBar::DRAW(RenderWindow* window)
{
	if (this->onSlide) show();
	window->draw(gridTop);
	window->draw(gridDown);
	update();
	window->draw(valHP);
	window->draw(valHappy);
	window->draw(lop);
	window->draw(lop2);
	window->draw(hpHappyBar);
}

void hpAndHappyBar::show()
{
	if (this->onSlide)
	{
		//cout << gridTop.getPosition().y << endl;
		//cout <<gridDown.getPosition().y << endl;
		//cout << lop2.getPosition().y << endl;
		this->gridTop.move(0, 120.0/ D);
		this->gridDown.move(0, -150.0/ D);
		//this->valHP.move(0, 58.5/(D / 2));
		//this->valHappy.move(0, 59.0/ (D / 2));
		//this->hpHappyBar.move(0, 15.0/ (D / 2));
		//this->lop2.move(0, 58.5/ (D / 2));
		//this->lop.move(0, 59.0/ (D / 2));
		if (gridDown.getPosition().y == 750) 
		{
			onSlide = false;
			this->valHP.setPosition(90.0f, 58.5f);
			this->valHappy.setPosition(520.0f, 59.0f);
			this->hpHappyBar.setPosition(10.0f, 15.0f);
			//this->hpHappyBar.setPosition(10.0f, -15.0f);
			this->lop2.setPosition(90.0f, 58.5f);
			this->lop.setPosition(520.0f, 59.0f);
		}
	}
}

void hpAndHappyBar::hide()
{
}

void hpAndHappyBar::update()
{
	if (hpVal > 0 && happyVal > 0)
	{
		this->forHp.width = ((hpVal * 330) / 70);
		this->forHappy.width = ((happyVal * 330) / 70);
		this->valHP.setTextureRect(forHp);
		this->valHappy.setTextureRect(forHappy);
		//cout << 7 - round(hpVal / 10) << endl; // for debug color
		this->valHP.setTexture(list_Texture[7 - round(hpVal / 10)]);
		this->valHappy.setTexture(list_Texture[7 - round(happyVal / 10)]);
		if (this->lop.getPosition().x + 14 > this->valHappy.getPosition().x + (happyVal * 330) / 70)
		{
			this->lop.setPosition(520.0f, 58.5f);
		}
		
		if (this->lop2.getPosition().x + 14 > this->valHP.getPosition().x + (hpVal * 330) / 70)
		{
			this->lop2.setPosition(90.0f, 58.5f);
		}
		if (!this->onSlide)
		{
			this->lop.move(2, 0);
			this->lop2.move(2, 0);
		}
		
	}	
}
