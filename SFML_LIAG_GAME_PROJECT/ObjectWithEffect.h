#include"defineHead.h"
class kickBall
{
private:
	Sprite obj;
	Texture texture;
	Sprite ball;
	Texture Ball;
	IntRect Area = IntRect(0, 0, 0, 100);
	bool haveEffect = false;
	bool haveBall = false;
	bool waitForHide = false;
	float Counter = 0.0f;
	int A = 100;
	float B = 25;
	Clock clock;
public:
	kickBall();
	void DRAW(RenderWindow *window);
};

