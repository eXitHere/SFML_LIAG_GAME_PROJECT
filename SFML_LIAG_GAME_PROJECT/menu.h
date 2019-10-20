#include"defineHead.h"
#include"scrollBar.h"

class menu
{
public:
	menu(int* valMusic);
	void DRAW(RenderWindow* window,Event * event);
	bool holdOn(Sprite* btn,Window *window,Event* event,int index);
private:
	int* ValMusic;
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
	Texture RIGHT, LEFT;
	Sprite right, left;
	Texture _TOP, _DOWN;
	Sprite top, down;
	Clock clock;
	int R = -800, L = 1600;
	void cutSceen();
	bool cutSceenState = false;
	bool offCutSceenState = false;
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
};

