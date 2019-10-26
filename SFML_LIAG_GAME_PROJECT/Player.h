#include"defineHead.h"
#include"ObjectWithEffect.h"

class Player
{
private:
	//testSwip animation 
	bool prees = false;

	// for player
	Sprite body;
	Texture texturePlayer[4];
	Vector2f sizeBody;
	int jumpState = 0;
	void jump_Action();
	float jumpP[4] = { 10,20,20,20 };
	double jump_Value = jumpP[0];
	bool isBaseHeight();
	bool isBaseFloor();
	//

	// for animation
	Clock clock;
	void control();
	void updata(float delta);
	int switchColumn = 0;
	double switchPic = 0.100; // <- time for switch
	double totalTime = 0;
	IntRect Rec;
	int _action = 1;
	int numPic[4] = {4,4,6,8};
	int floorBaby = 500;
	void updateRec(int action);
public:
	Player(); // load data
	void selectChalactor(int select);
	void DRAW(RenderWindow* window);
	void setJump(int state);
	int getJump();
	Vector2f getHalfSize() { return Vector2f(this->Rec.width / 2.0f-30, this->Rec.height /2.0f-30); }
	Vector2f getOriginPos() { return Vector2f(this->body.getPosition() + getHalfSize()); }
};

