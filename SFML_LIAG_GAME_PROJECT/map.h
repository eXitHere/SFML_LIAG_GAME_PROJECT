#include"defineHead.h"
#define speedMap -3

class Map
{
public:
	Map();
	void DRAW(RenderWindow* window);
private:
	Texture map1;
	Sprite mapMain;
	void moveMap();
};