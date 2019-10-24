#include "barDownManger.h"

barDownManger::barDownManger()
{
	//cout << timeLoad << endl;
	this->objectT.loadFromFile("texture\\bardown\\active.png");
	//this->objectT[1].loadFromFile("texture\\bardown\\active1.png");
	
	this->onloadT[0].loadFromFile("texture\\bardown\\onload.png");
	this->onloadT[1].loadFromFile("texture\\bardown\\onload.png");
	this->onloadT[2].loadFromFile("texture\\bardown\\onload.png");
	this->itemCountT.loadFromFile("texture\\bardown\\itemCount.png");
	this->textureGrid[0].loadFromFile("texture\\bardown\\Grid.png");
	this->textureGrid[1].loadFromFile("texture\\bardown\\GridActive.png");
	this->Rec = IntRect(0,0,this->onloadT[0].getSize().x,this->onloadT[0].getSize().y);
	this->RecHeigh = onloadT[0].getSize().x;
	this->object[0].setTexture(this->objectT);
	this->object[1].setTexture(this->objectT);
	this->object[2].setTexture(this->objectT);
	for (int i = 0; i < 6; i++) this->itemCount[i].setTexture(this->itemCountT);
	for (int i = 0; i < 3; i++)
	{
		this->onload[i].setTexture(this->onloadT[i]);
		this->grid[i].setTexture(this->textureGrid[0]);
	}

	// manageposition//
	this->object[0].setPosition(100,765);
	this->object[1].setPosition(250, 765);
	this->object[2].setPosition(400, 765);
	this->onload[0].setPosition(103, 765);
	this->onload[1].setPosition(253, 765);
	this->onload[2].setPosition(403, 765);
	this->itemCount[0].setPosition(600, 760);
	this->itemCount[1].setPosition(600, 825);
	this->itemCount[2].setPosition(800, 760);
	this->itemCount[3].setPosition(800, 825);
	this->itemCount[4].setPosition(1000, 760);
	this->itemCount[5].setPosition(1000, 825);
	this->grid[0].setPosition(98, 763);
	this->grid[1].setPosition(248, 763);
	this->grid[2].setPosition(398, 763);
	this->item[0].loadFromFile("texture\\bardown\\football.png");
	this->listItem[0].setTexture(item[0]);
	this->listItem[0].setPosition(118, 783);
}

void barDownManger::DRAW(RenderWindow* window)
{
	if (this->onLoad) OnLoad();
	else Active();
	for (int i = 0; i < 3; i++)
	{
		window->draw(this->object[i]);
	}
	for (int i = 0; i < 6; i++)
	{
		window->draw(this->itemCount[i]);
	}
	window->draw(this->listItem[0]);
	if (this->onLoad)
	{
		for (int i = 0; i < 3; i++)
		{
			window->draw(this->onload[i]);
		}
	}
	for (int i = 0; i < 3; i++) window->draw(this->grid[i]);
}

void barDownManger::Active()
{
	totalTime += clock.restart().asSeconds();
	if (totalTime >= 0.2)
	{
		totalTime = 0;
		for (int i = 0; i < 3; i++)
		{	
			if (active[i])
			{
				cout << "Active!" << endl;
				grid[i].setTexture(textureGrid[switcH]);
			}	
		}
		switcH = !switcH;
	}
}

void barDownManger::OnLoad()
{
	//cout << "onLoadState !" << endl;
 	this->totalTimeLoad += this->clock.restart().asSeconds();
	if (this->totalTimeLoad > 0.2)
	{
		this->Rec.height = float(this->timeLoad/100*this->RecHeigh);
		this->timeLoad--;
		this->totalTimeLoad = 0;
		if (this->timeLoad < 0)
		{
			this->onLoad = false;
			for (int i = 0; i < 3; i++)
			{
				this->active[i] = true;
			}
		}
		//cout << Rec.height << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		this->onload[i].setTextureRect(this->Rec);
	}
}
