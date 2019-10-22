#include"defineHead.h"
#include"scrollBar.h"

class menu
{
public:
	//testcommandasd
	menu(int* valMusic,int *valEffect);
	void DRAW(RenderWindow* window,Event * event);
	bool holdOn(Sprite* btn,Window *window,Event* event,int index);
	int stateSonud_OnHold();
	void setStop();
	bool gameStart();
	void changeSetting(bool* stateSave);
private:
	int temp_HoldOn = -1;
	Clock _time_Clock;
	int stateSoundd=-1;
	int* ValMusic;
	int* ValEffect;
	int tempVal;
	scrollBar musicScrollBar, effectScrollBar;
	RenderWindow* window;
	Text TEXT;
	Text name_Show[5];
	int position_Name[5] = { 260,340,430,520,610 };
	Text score_Show[5];
	int position_Score[5] = { 260,340,430,520,610 };
	Font font;
	Sprite testbutton;
	Texture testTexture;
	void onLoadButton();
	float A[4] = {20,20,20,20};
	bool onLoadState = true;
	bool upNid[4] = {false,false,false,false};
	int floor[4] = { 200,350,500,650 };
	bool Change[4] = { false,false,false,false };
	int stateHold = -1;
	Sprite button[4];
	Texture texture[4];
	Sprite bg[5];
	Texture bgtx[5];
	IntRect rec[1];
	Sprite background;
	Texture backgroundTexture;
	bool stateMove = false;
	void moveButton();
	Texture logoGame;
	Sprite logoGameSprite;
	void logoMovement();
	int logoRota = 1;
	Clock clockLogo;
	int statePage_ = 0;
	void display();
	bool statePage[4] = { true,false,false,false };
	void usePage0();
	void usePage1();
	void usePage2();
	void usePage3();
	void mapPlayBack(RenderWindow *window);
	Sprite scoreBackground;
	Texture scoreTexture;
	Sprite settingBackground;
	Texture settingTexture;
	Texture saveHoldOnTexture;
	Texture saveTexture;
	Texture cancelHoldOnTexture;
	Texture cancelTexture;
	Sprite saveBtn;
	Sprite cancelBtn;
	bool saveHold = false;
	bool cancelHold = false;
	bool saveState = false;
	bool* valChange = false;
	bool VALCHECAGE = false;
	void checkSaveBtn();
	int tempMusic;
	int tempEffect;
	bool __START = false;
};

