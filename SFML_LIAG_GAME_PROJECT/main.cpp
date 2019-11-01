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
#include"barDownManger.h"
#include"StatusFace.h"
#include"face.h"
#include <malloc.h>
//#include<vector> // this-> test load Items!
#include<vector>  // this-> use for load items!

int testttt;
/*Global variable*/
int boxForFace[6] = { -100,50,0,-50,100 }, indexFaceX = 0, indexFaceY = 2; // <-->
Player player;

//
Texture bear_Texture;
Texture candy_Texture;
Texture food_Texture;
Texture food2_Texture;
Texture milk_Texture;
Texture money_Texture;

void load()
{
	bear_Texture.loadFromFile(BEAR_);
	candy_Texture.loadFromFile(CANDY_);
	food_Texture.loadFromFile(FOOD_);
	food2_Texture.loadFromFile(FOOD2_);
	milk_Texture.loadFromFile(MILK_);
	money_Texture.loadFromFile(MONEY_);
}

void loadSetting(string data,int *valMusic,int *valEffect)
{
	int stateSetting = 0;
	string temp1;
	int temp;
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == '|' || data[(i+1)] == '\0')
		{
			if (data[(i + 1)] == '\0') temp1 += data[i];
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
void loadScore(string data,string* name,int* Score)
{
	int temp_int = 0;
	string temp_string;
	string temp2_string;
	string temp3_string;
	int state_score = 0;
	for (int i = 0; i<data.length(); i++)
	{
		if (data[i] == '|' || data[(i + 1)] == '\0')
		{
			if (data[(i + 1)] == '\0') temp_string += data[i];
			temp_string += '\0';
			for (int j = 0; j < temp_string.length() ; j++)
			{
				//cout << j << " ";
				if (temp_string[j] == '_') {
					//cout << "size temp : " << temp_string.length() << endl;
					//cout << "J: " << j << endl;
					for (int k = j + 1; k < temp_string.length(); k++)
					{
						//cout << " K " << k << endl;
						temp3_string += temp_string[k];
					}
					break;
				}
				else
				{
					temp2_string += temp_string[j];
				}
			}
			//cout << temp_string << endl;
			//cout << temp2_string << " " << temp3_string << endl;
			*name = temp2_string;
			*Score = stoi(temp3_string);
			name++;
			Score++;
			temp2_string = "";
			temp3_string = "";
			temp_string = "";
		}
		else temp_string += data[i];
	}
}
void manageMap()
{

}
bool colision(Items* I)
{
	return (I->getOriginPos().x>0 &&abs(player.getOriginPos().x - I->getOriginPos().x) <= player.getHalfSize().x + I->getHalfSize().x &&
		abs(player.getOriginPos().y - I->getOriginPos().y) <= player.getHalfSize().y + I->getHalfSize().y);
}

StatusFace addFace(const char* path)
{
	StatusFace* T;
	T = new StatusFace(path, player.getOriginPos() + Vector2f(boxForFace[indexFaceX], boxForFace[indexFaceY]));
	indexFaceX = (indexFaceX > 4 ? 0 : indexFaceX + 1);
	indexFaceY = (indexFaceY > 4 ? 0 : indexFaceY + 1);
	return *T;
	/*
	
	bar.reduceHappy(1);
	bar.reduceHp(1);
	*/
}
void main()
{	
	load();
	RenderWindow window(VideoMode(size_Width, size_Height), name_Title, Style::Close);
	window.setFramerateLimit(frameRateLimit);
	hpAndHappyBar bar;
	Event event;
	Biker biker;
	kickBall test;
	Map map1(map1Load);
	Map map2(map2Load);
	barDownManger barDown;
	int Object = 3, Status[6] = { 0,0,0,0,0,0 }, ID[6] = { 1,2,3,4,0,0 };
	bool Object2[2] = { true,false };
	barDown.setData(&Object,&Object2[0],&Object2[1],&ID[0], &Status[0],&Status[1], &Status[2], &Status[3], &Status[4], &Status[5]);
	bool map2LOAD = false;
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
	string temp;
	bool saveSetting=false;
	menu Menu(&musicVal, &effectVal);
	Menu.changeSetting(&saveSetting);
	string name_Score[5];
	int int_Score[5];
	loadScore(scoreFile.Read(), name_Score, int_Score);
	Menu.updateScore(name_Score, int_Score);

	/*for (int i = 0; i < 5; i++) // debug load score complete!
	{
		cout << name_Score[i] << " " << int_Score[i] << endl;
	}*/

	soundPB PLAY;

	// 
	bar.show();

	int *_countHoldOn;
	cutSceen cutsceen;
	Clock clock;
	float timeDelay = 0;
	float timeDelay_Countdown =0 ;
	int __StateMain = 0;
	
	// test Items
	vector<Items> items;
	vector<Items>::iterator it;
	vector<Items>::iterator tempit;
	Items* TT;
	bool haveDel = false;
	/*TT = new Items(BEAR_, Vector2f(800, 600), BEAR_ID);
	items.push_back(*TT);
	TT = new Items(CANDY_, Vector2f(950, 600), CANDY_ID);
	items.push_back(*TT);
	TT = new Items(FOOD_, Vector2f(1100, 600), FOOD_ID);
	items.push_back(*TT);
	TT = new Items(FOOD2_, Vector2f(1150, 600), FOOD2_ID);
	items.push_back(*TT);
	TT = new Items(TEACHER_, Vector2f(1250, 600), TEACHER_ID);
	items.push_back(*TT);
	TT = new Items(FOOTBALL_, Vector2f(1350, 600), FOOTBALL_ID);
	items.push_back(*TT);
	TT = new Items(MILK_, Vector2f(1450, 600), MILK_ID);
	items.push_back(*TT);
	TT = new Items(MONEY_, Vector2f(1700, 600), MONEY_ID);
	items.push_back(*TT);
	TT = new Items(PAINTER_, Vector2f(1800, 600), PAINTER_ID);
	items.push_back(*TT);
	TT = new Items(WRENCH_, Vector2f(1200, 600), WRENCH_ID);
	items.push_back(*TT);
	for (int i = 0; i < 3; i++)
	{
		TT = new Items(PAINTER_, Vector2f(1800 + i*200, 600), PAINTER_ID);
		items.push_back(*TT);
	}
	for (int i = 0; i < 3; i++)
	{
		TT = new Items(TEACHER_, Vector2f(2400 + i * 200, 600), TEACHER_ID);
		items.push_back(*TT);
	}
	for (int i = 0; i < 3; i++)
	{
		TT = new Items(WRENCH_, Vector2f(3000 + i * 200, 600), WRENCH_ID);
		items.push_back(*TT);
	}
	for (int i = 0; i < 3; i++)
	{
		TT = new Items(FOOTBALL_, Vector2f(3800 + i * 200, 600), FOOTBALL_ID);
		items.push_back(*TT);
	}
	for (int i = 0; i < 3; i++)
	{
		TT = new Items(BEAR_, Vector2f(4500 + i * 200, 600), BEAR_ID);
		items.push_back(*TT);
	}*/
	//
	//Menu.manageSound(&mediaPlay);

	vector<StatusFace> faceList;
	vector<StatusFace>::iterator itf = faceList.begin();
	vector<StatusFace>::iterator tempf = faceList.begin();
	StatusFace* P;
	bool delFace = false;
	
	//Clock T_Clock;
	//float T_time = 0;
	//bool pressE = false;
	int PosTemp = 100;
	Clock clockT;
	float T=0;
	while (window.isOpen())
	{
		T += clockT.restart().asSeconds();
		if(T > 3.0f)
		{
			T = 0;
			TT = new Items(bear_Texture, Vector2f(PosTemp, 200), BEAR_ID);
			PosTemp += 120;
			items.push_back(*TT);
			//cout << "Added !!" << " size of :: " << items.size() << endl;
		}
		/*T_time += T_Clock.restart().asSeconds();
		if (Keyboard::isKeyPressed(Keyboard::E) && !pressE)
		{
			T_time = 0;
			pressE = true;
			cout << faceList.size() << endl;
			P = new StatusFace(path_happyp, player.getOriginPos());
			faceList.push_back(*P);
		}
		if (T_time >= 1) pressE = false;*/

		if (map1.loadNewMap())
		{
			//cout << "Load map mai I sas !" << endl;
			map2LOAD = true;
		}
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
		

		window.clear(); // debug Items
		
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
			map1.DRAW(&window);
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
			map1.DRAW(&window);
			bar.DRAW(&window);
			cutsceen.DRAW(&window);
			__StateMain = cutsceen.getState();
			PLAY.setSoundBG(true);
			//cout << __StateMain << endl;
		}
		else if (__StateMain == 3) // playGame !!
		{
			if (map2LOAD) map2.DRAW(&window);
			map1.DRAW(&window);
			bar.DRAW(&window);
			barDown.DRAW(&window);
			test.DRAW(&window);
			biker.Draw(&window);
			player.DRAW(&window);
			for (it = items.begin(); it != items.end(); ++it)
			{
				//cout << "Check Items" << endl;
				if (colision(&(*it)))
				{
					/*
					bar.reduceHappy(1);
				    bar.reduceHp(1);
					*/
					switch (it->getType())
					{
						case FOOTBALL_ID: 
						{ 
							Status[0]++;
							faceList.push_back(addFace(path_happyp));
							break; 
						}
						case PAINTER_ID: 
						{ 
							Status[1]++; 
							faceList.push_back(addFace(path_happyp));
							break; 
						}
						case TEACHER_ID: 
						{
							Status[2]++; 
							faceList.push_back(addFace(path_happyp));
							break; 
						}
						case WRENCH_ID: 
						{ 
							Status[3]++; 
							faceList.push_back(addFace(path_happyp));
							break; 
						}
						case BEAR_ID: 
						{
							faceList.push_back(addFace(path_hpdown));
							faceList.push_back(addFace(path_moneyd));
							bar.reduceHp(-5);
							break; 
						};
						case CANDY_ID: 
						{ 
							faceList.push_back(addFace(path_happyp));
							faceList.push_back(addFace(path_hpdown));
							faceList.push_back(addFace(path_moneyd));
							bar.reduceHp(-1);
							bar.reduceHappy(3);
							break; 
						};
						case FOOD_ID: 
						{ 
							faceList.push_back(addFace(path_happyp));
							faceList.push_back(addFace(path_moneyd));
							bar.reduceHappy(3);
							break; 
						};
						case FOOD2_ID: 
						{ 
							faceList.push_back(addFace(path_happyp));
							faceList.push_back(addFace(path_moneyd));
							bar.reduceHappy(3);
							break; 
						}
						case MILK_ID: 
						{ 
							faceList.push_back(addFace(path_happyp));
							bar.reduceHappy(3);
							break; 
						}
						case MONEY_ID: 
						{
							faceList.push_back(addFace(path_happyp));
							bar.reduceHappy(3);
							break;  
						}
					}
					//faceList.push_back(*P);
					barDown.updateCount();
					tempit = it;
					haveDel = true;
				}
				if (it->xPos() < -100)
				{
					tempit = it;
					haveDel = true;
				}
				it->DRAW(&window);
			}
			for (itf = faceList.begin(); itf != faceList.end(); ++itf)
			{
				itf->DRAW(&window);
				if (itf->getDelete())
				{
					delFace = true;
					tempf = itf;
				}
			}
			if (delFace)
			{
				faceList.erase(tempf);
				delFace =false;
			}
			if (haveDel)
			{
				cout << "Delete !!" << endl;
				items.erase(tempit);
				haveDel = false;
			}
			//cout << items.size() << endl;
		}
		else Menu.DRAW(&window, &event);
		//cout << Menu.gameStart() << endl;
		//Menu.DRAW(&window, &event);
		window.display();
	}
}
