#include"defineHead.h"
#include"Player.h"
#include"map.h"
#include"Biker.h"
#include"Items.h"
#include"hpAndHappyBar.h"
#include"linklist.h"
#include"menu.h"
#include"soundPB.h"

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
	menu Menu(&musicVal);
	soundPB PLAY;
	
	
	//Menu.manageSound(&mediaPlay);
	while (window.isOpen())
	{
		PLAY.setVolMusic(musicVal);
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
