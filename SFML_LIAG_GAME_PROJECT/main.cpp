#include"defineHead.h"
#include"Player.h"
#include"map.h"
#include"Biker.h"
#include"Items.h"
#include"hpAndHappyBar.h"
#include"linklist.h"
#include"soundPB.h"
#include"menu.h"
#include"cutSceen.h"

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
	cutSceen cutsceen;
	Clock clock;
	float timeDelay = 0;
	float timeDelay_Countdown;
	int __StateMain = 0;
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
		
		if (Menu.gameStart() && __StateMain==0)
		{
			PLAY.setSoundBG(false);
			timeDelay_Countdown += clock.restart().asSeconds();
			if (timeDelay_Countdown >= 1)
			{
				PLAY._clockPlay();
				timeDelay_Countdown = 0;
			}
			
			/*timeDelay += clock.restart().asSeconds();
			cutsceen.onCutSceen();
			if (timeDelay < 5)
			{
				map.DRAW(&window);
				bar.DRAW(&window);
				Menu.DRAW(&window, &event);
			}
			else
			{
				map.DRAW(&window);
				bar.DRAW(&window);
				item.DRAW(&window);
				test.DRAW(&window);
				biker.Draw(&window);
				player.DRAW(&window);
			}
			*/
			cutsceen.onCutSceen();
			__StateMain = 1;
			
		}
		else if (__StateMain == 1)
		{
			timeDelay_Countdown += clock.restart().asSeconds();
			if (timeDelay_Countdown >= 1)
			{
				PLAY._clockPlay();
				timeDelay_Countdown = 0;
			}
			map.DRAW(&window);
			bar.DRAW(&window);
			Menu.DRAW(&window, &event);
			cutsceen.DRAW(&window);
			__StateMain = cutsceen.getState();
			//cout << __StateMain << endl;
			//cout << "Error!" << endl;
		}
		else if (__StateMain == 2)
		{
			timeDelay_Countdown += clock.restart().asSeconds();
			if (timeDelay_Countdown >= 1)
			{
				PLAY._clockPlay();
				timeDelay_Countdown = 0;
			}
			map.DRAW(&window);
			bar.DRAW(&window);
			cutsceen.DRAW(&window);
			__StateMain = cutsceen.getState();
			PLAY.setSoundBG(true);
			//cout << __StateMain << endl;
		}
		else if (__StateMain == 3) // playGame !!
		{
			map.DRAW(&window);
			bar.DRAW(&window);
			item.DRAW(&window);
			test.DRAW(&window);
			biker.Draw(&window);
			player.DRAW(&window);
		}
		else Menu.DRAW(&window, &event);
		//cout << Menu.gameStart() << endl;
		window.display();
	}
}
