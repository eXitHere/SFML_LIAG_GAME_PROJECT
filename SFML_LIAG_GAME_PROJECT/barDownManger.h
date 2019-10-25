#include"defineHead.h"
#define delay 20
class barDownManger
{
public:
	barDownManger();
	void setNoActive();
	void setActive();
	void setData(int *O1,bool *O2,bool *O3,int *D,int *I1,int *I2,int *I3,int *I4,int *I5,int *I6);
	void DRAW(RenderWindow* window);
	void updateCount();
private:
	int *pointerCount[6];
	Font font;
	Text countItem[6];
	Sprite object[3], itemCount[6],onload[3], grid[3];
	Sprite listItem[1],FriendSprite,FamilySprite;
	Texture item[4],textureGrid[2],friendTexture[2],FamilyTexture[2],I[6];
	bool IHide[6];
	Texture objectT, itemCountT,onloadT[3];
	IntRect Rec;
	int RecHeigh;
	bool active[3];
	bool switcH = false;
	bool onLoad = true;
	float timeLoad = delay / 0.2;
	void Active();
	void OnLoad();
	Clock clock;
	float totalTime = 0, totalTimeLoad = 0;
};

