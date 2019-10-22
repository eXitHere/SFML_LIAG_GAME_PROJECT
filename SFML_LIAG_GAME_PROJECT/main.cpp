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
#include"ReadWriteFile.h"

void loadSetting(string data,int *valMusic,int *valEffect)
{
	int music, effect;
	int stateSetting = 0;
	string temp1;
	int temp;
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == '|' || data[i+1] == '\0')
		{
			if (data[i + 1] == '\0') temp1 += data[i];
			temp = stoi(temp1);
			switch (stateSetting)
			{
			case 0:
				*valMusic = temp;
				break;
			case 1:
				*valEffect = temp;
				break;
			}
			temp1 = "";
			stateSetting++;
		//	cout << temp << endl;
		}
		else
		{
			temp1 += data[i];
		}	
	}
	//cout << temp;
}

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

	// ReadWriteFile
	ReadWriteFile scoreFile(scoreTxt),settingFile(settingTxt);
	//scoreFile.Write("Test555555");
	//cout << scoreFile.Read();
	//cout << settingFile.Read();
	//


	// Sound

	int musicVal = 100;
	int effectVal = 100;
	loadSetting(settingFile.Read(), &musicVal,&effectVal);
	//menu
	String temp;
	bool saveSetting=false;
	menu Menu(&musicVal, &effectVal);
	Menu.changeSetting(&saveSetting);
	soundPB PLAY;

	// 
	bar.show();

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
		if (saveSetting)
		{
			temp = to_string(musicVal) + "|" + to_string(effectVal);
			settingFile.Write(temp);
			//cout << temp << endl;
			saveSetting = false;
			//cout << "save!" << endl;
		}
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
		else if (__StateMain == 1) // Step 1
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
		//Menu.DRAW(&window, &event);
		window.display();
	}
}
