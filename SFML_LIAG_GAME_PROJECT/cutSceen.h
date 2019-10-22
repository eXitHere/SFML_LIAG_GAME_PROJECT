#include"defineHead.h"
class cutSceen
{
public:
	cutSceen();
	void DRAW(RenderWindow* window);
	void update();
	void onCutSceen();
	int getState();
private:
	int __StateForMain = 0;
	Texture RIGHT, LEFT;
	Sprite right, left;
	Texture _TOP, _DOWN;
	Sprite top, down;
	Clock clock;
	int R = -800, L = 1600;
	bool cutSceenState = false;
	bool offCutSceenState = false;
};

