#include"defineHead.h"
#define delay 20
class barDownManger
{
public:
	barDownManger();
	void DRAW(RenderWindow* window);
private:
	Sprite object[3], itemCount[6],onload[3], grid[3];
	Sprite listItem[1];
	Texture item[1],textureGrid[2];
	Texture objectT, itemCountT,onloadT[3];
	IntRect Rec;
	int RecHeigh;
	bool active[3] = { true,false,true };
	bool switcH = false;
	bool onLoad = true;
	float timeLoad = delay / 0.2;
	void Active();
	void OnLoad();
	Clock clock;
	float totalTime = 0, totalTimeLoad = 0;
};

