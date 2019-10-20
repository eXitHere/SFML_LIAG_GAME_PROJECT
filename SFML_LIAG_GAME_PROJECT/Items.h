#include"defineHead.h"
#include<list>
#define countItems 1
class Items
{
public:
	Items();
	void setPosition_Items(Vector2f Pos);
	void DRAW(RenderWindow* window);
private:
	Texture texture[countItems];
	Sprite item;
	IntRect REC;
	void update(float delta);
	list<Sprite> Items_List;
	void Add();
};

