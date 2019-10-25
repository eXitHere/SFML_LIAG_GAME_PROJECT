#include "barDownManger.h"

barDownManger::barDownManger()
{
	font.loadFromFile("font\\impact.ttf"); // load Font

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
	this->item[0].loadFromFile("texture\\bardown\\f.png");
	this->item[1].loadFromFile("texture\\bardown\\p.png");
	this->item[2].loadFromFile("texture\\bardown\\t.png");
	this->item[3].loadFromFile("texture\\bardown\\w.png");
	//this->listItem[0].setTexture(item[0]);
	this->listItem[0].setPosition(118, 783);
	this->friendTexture[0].loadFromFile("texture\\bardown\\friend.png");
	this->friendTexture[1].loadFromFile("texture\\bardown\\friend_black.png");
	//this->FriendSprite.setTexture(this->friendTexture[0]);
	this->FriendSprite.setPosition(268, 783);
	this->FamilyTexture[0].loadFromFile("texture\\bardown\\family.png");
	this->FamilyTexture[1].loadFromFile("texture\\bardown\\family_black.png");
	//this->FamilySprite.setTexture(this->FamilyTexture[0]);
	this->FamilySprite.setPosition(418,783);
	this->I[0].loadFromFile("texture\\bardown\\i1.png");
	this->I[1].loadFromFile("texture\\bardown\\i2.png");
	this->I[2].loadFromFile("texture\\bardown\\i3.png");
	this->I[3].loadFromFile("texture\\bardown\\i4.png");
	this->I[4].loadFromFile("texture\\bardown\\i5.png");

	countItem[0].setFont(font);
	countItem[0].setString("0/10");
	countItem[0].setCharacterSize(20);
	countItem[0].setFillColor(Color::White);
	countItem[0].setPosition(680, 780);

	countItem[1].setFont(font);
	countItem[1].setString("0/10");
	countItem[1].setCharacterSize(20);
	countItem[1].setFillColor(Color::White);
	countItem[1].setPosition(680, 845);

	countItem[2].setFont(font);
	countItem[2].setString("0/10");
	countItem[2].setCharacterSize(20);
	countItem[2].setFillColor(Color::White);
	countItem[2].setPosition(880, 780);

	countItem[3].setFont(font);
	countItem[3].setString("0/10");
	countItem[3].setCharacterSize(20);
	countItem[3].setFillColor(Color::White);
	countItem[3].setPosition(880, 845);

	countItem[4].setFont(font);
	countItem[4].setString("0/10");
	countItem[4].setCharacterSize(20);
	countItem[4].setFillColor(Color::White);
	countItem[4].setPosition(1080, 845);

	countItem[5].setFont(font);
	countItem[5].setString("0/10");
	countItem[5].setCharacterSize(20);
	countItem[5].setFillColor(Color::White);
	countItem[5].setPosition(1080, 845);
	//this->I[5].loadFromFile("texture\\bardown\\i6.png");
}

void barDownManger::setNoActive()
{
	onLoad = false;
}

void barDownManger::setActive()
{
	this->onLoad = true;
}

void barDownManger::setData(int* O1, bool* O2, bool* O3, int* D, int* I1, int* I2, int* I3, int* I4, int* I5, int* I6)
{
	//setPointer!
	this->pointerCount[0] = I1;
	this->pointerCount[1] = I2;
	this->pointerCount[2] = I3;
	this->pointerCount[3] = I4;
	this->pointerCount[4] = I5;
	this->pointerCount[5] = I6;
	// set Active
	if (*O1) this->active[0] = true;
	else this->active[0] = false;
	if (*O2) { this->active[1] = true; this->FamilySprite.setTexture(this->FamilyTexture[1]); }
	else { this->active[1] = false; this->FamilySprite.setTexture(this->FamilyTexture[0]); }
	if (*O3) { this->active[2] = true; this->FriendSprite.setTexture(this->friendTexture[1]); }
	else { this->active[2] = false; this->FriendSprite.setTexture(this->friendTexture[0]); }
	//for object 1
	switch (*O1)
	{ // f p t w // listItem
	case 1: this->listItem[0].setTexture(this->item[0]); break;
	case 2: this->listItem[0].setTexture(this->item[1]); break;
	case 3: this->listItem[0].setTexture(this->item[2]); break;
	case 4: this->listItem[0].setTexture(this->item[3]); break;
	}
	for (int i = 0; i < 6; i++)
	{
		if (*(D + i) != 0)
		{
			switch (*(D+i))
			{
			case 1: this->itemCount[i].setTexture(this->I[0]); break;
			case 2: this->itemCount[i].setTexture(this->I[1]);; break;
			case 3: this->itemCount[i].setTexture(this->I[2]);; break;
			case 4: this->itemCount[i].setTexture(this->I[3]);; break;
			}
			IHide[i] = true;
		}
		else
		{
			IHide[i] = false;
		}
	}
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
		if (IHide[i])
		{
			window->draw(this->itemCount[i]);
			window->draw(this->countItem[i]);
		}
	}
	window->draw(this->listItem[0]);
	window->draw(this->FriendSprite);
	window->draw(this->FamilySprite);
	if (this->onLoad)
	{
		for (int i = 0; i < 3; i++)
		{
			if(active[i]) window->draw(this->onload[i]);
		}
	}
	for (int i = 0; i < 3; i++) window->draw(this->grid[i]);
}

void barDownManger::updateCount() // call from main
{
	for (int i = 0; i < 6; i++)
	{
		countItem[i].setString(to_string(*pointerCount[i])+"/10");
	}
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
			timeLoad = delay / 0.2;
		}
		//cout << Rec.height << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		this->onload[i].setTextureRect(this->Rec);
	}
}
