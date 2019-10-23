#include"defineHead.h"
#include"NameItems.h"

#define time_Items 0.2
class Items
{
public:
	Items(string path,Vector2f pos); // need texture and position!!
	void setPosition_Items(Vector2f Pos);
	void DRAW(RenderWindow* window);
private:
	void move();
	float forSin = 20;
	RectangleShape Grid;
	Texture texture;
	Sprite item;
	IntRect REC;
	void update();
	Clock clock;
	int X = 0;
	float timeTotal = 0;
};

