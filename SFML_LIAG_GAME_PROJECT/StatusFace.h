#include"defineHead.h"
#include"face.h"

class StatusFace
{
public:
	StatusFace(string path,Vector2f pos);
	void DRAW(RenderWindow* window);
	bool getDelete();
private:
	bool Del = false;
	Sprite body;
	Texture texture;
	float totalTime = 0;
	Clock clock;
	float A = 0;
	void move();
};

