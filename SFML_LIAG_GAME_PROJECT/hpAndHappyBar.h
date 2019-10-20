#include"defineHead.h"
#include<vector>
class hpAndHappyBar
{
public:
	hpAndHappyBar();
	void reduceHp(int val);
	void reduceHappy(int val);
	void reset();
	void update();
	void DRAW(RenderWindow *window);
	void show(); // Slid
	void hide();
private:
	int hpVal = 70;
	int happyVal = 70;
	Sprite hpHappyBar;
	Sprite lop;
	Sprite lop2;
	Texture texture;
	Texture G1;
	vector<Texture> list_Texture;
	Sprite valHP;
	Sprite valHappy;
	IntRect forHp, forHappy;
	Texture Grid;
	Sprite gridTop;
	Sprite gridDown;
	bool onSlide = false;
};

