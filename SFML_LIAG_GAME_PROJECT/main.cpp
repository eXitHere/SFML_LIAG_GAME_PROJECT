#include"defineHead.h"
#include"Player.h"
#include"map.h"
#include"Biker.h"
#include"Items.h"
#include"hpAndHappyBar.h"
#include"linklist.h"
#include"soundPB.h"
#include"menu.h"


int main()
{
	RenderWindow window(VideoMode(size_Width, size_Height), name_Title, Style::Close);
	window.setFramerateLimit(frameRateLimit);
	Clock testDownhp;
	hpAndHappyBar bar;
	Player player;
	Event event;
	Map map;
	Biker biker;
	kickBall test;
	Items item;
	bar.show();

	int musicVal = 100;
	int effectVal = 100;
	menu Menu(&musicVal,&effectVal);
	soundPB PLAY;
	int *_countHoldOn;
	
	//Menu.manageSound(&mediaPlay);
	while (window.isOpen())
	{
		PLAY.setVolMusic(musicVal);
		PLAY.setVolEffect(effectVal);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			
		}
		if (testDownhp.getElapsedTime().asSeconds() >0.5)
		{
			bar.reduceHappy(1);
			bar.reduceHp(1);
			testDownhp.restart();
		}

		switch (Menu.stateSonud_OnHold())
		{
		case 1 : PLAY._holdOnPlay();
			Menu.setStop();
			//cout << "Click in main!" << endl;
			break;
		case 2: PLAY._clickPlay();
			Menu.setStop();
			break;
		default:
			break;
		}
		

		window.clear();
		//map.DRAW(&window);
		//bar.DRAW(&window);
		//item.DRAW(&window);
		//test.DRAW(&window);
		//biker.Draw(&window);
		//player.DRAW(&window);
		Menu.DRAW(&window, &event);
		window.display();
	}
}
