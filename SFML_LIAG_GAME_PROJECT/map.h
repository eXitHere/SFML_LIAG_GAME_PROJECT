#include"defineHead.h"

class Map
{
public:
	Map(string texture);
	void DRAW(RenderWindow* window);
	bool loadNewMap();
private:
	Texture map1;
	Sprite mapMain;
	void moveMap();
};