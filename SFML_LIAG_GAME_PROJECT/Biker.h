#include"defineHead.h"
class Biker
{
private:
	Texture texture;
	Sprite body;
	Texture smoke;
	Sprite Smoke;
	bool BIKE = false;
	bool SMOKE = false;
	Clock clock;
	float A = 5;
	float B = 2;
public:
	void Draw(RenderWindow* window);
	Biker();
};

