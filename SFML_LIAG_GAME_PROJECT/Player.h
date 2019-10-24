#include"defineHead.h"
#include"ObjectWithEffect.h"
#define jumpP 15
class Player
{
private:
	// for player
	Sprite body;
	Texture texturePlayer[2];
	Vector2f sizeBody;
	int jumpState = 0;
	void jump_Action();
	double jump_Value = jumpP;
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
	int _action = 0;
	int numPic[2] = {6,8};
	void updateRec(int action);
	//
public:
	Player(); // load data
	void DRAW(RenderWindow* window);
	void setJump(int state);
	int getJump();
	Vector2f getHalfSize() { return Vector2f(this->Rec.width / 2.0f-30, this->Rec.height /2.0f-30); }
	Vector2f getOriginPos() { return Vector2f(this->body.getPosition() + getHalfSize()); }
};

