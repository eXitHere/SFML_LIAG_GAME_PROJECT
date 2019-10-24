#include"defineHead.h"
#include"NameItems.h"

#define time_Items 0.2
class Items
{
public:
	Items(string path,Vector2f pos); // need texture and position!!
	void setPosition_Items(Vector2f Pos);
	void DRAW(RenderWindow* window);
	float xPos() { return this->item.getPosition().x;}
	Vector2f getHalfSize() { return Vector2f(this->REC.width / 2.0f-10, this->REC.height / 2.0f-10); }
	Vector2f getOriginPos() { return Vector2f(this->item.getPosition() + getHalfSize()); }
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

