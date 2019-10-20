#include"defineHead.h"
class scrollBar
{
public:
	scrollBar();
	void load(Vector2f body,int val);
	int getVal();
	void setVal(int Val);
	void update();
	void draw(RenderWindow *window);
	void setName(String name);
private:
	Text name;
	Font font;
	Text valString;
	bool mute = false;
	Clock clock;
	float delta = 0.7;
	float totalTime = 0;
	Texture btn[8];
	Sprite btnN, btnP,btnM;
	Texture texture;
	Sprite body;
	Texture textureDot;
	Sprite bodyDot;
	int val;
	Vector2f positionBody;
	void holdOn(RenderWindow *window);
	bool clickOn = false;
	void mouseHoldOn(RenderWindow* window);
};

