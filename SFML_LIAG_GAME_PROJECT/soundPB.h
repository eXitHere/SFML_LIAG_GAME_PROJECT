#include"defineHead.h"

class soundPB
{
public:
	soundPB();
	void setVolMusic(int val);
	void setVolEffect(int val);
	void _holdOnPlay();
	void _clickPlay();
	void _clockPlay();
	void setSoundBG(int val);
private:
	Music musicBackground;
	SoundBuffer _holdOnBuffer;
	Sound _holdOnSound;
	SoundBuffer _clickBuffer;
	Sound _clickSound;
	SoundBuffer _clockBuffer;
	Sound _clockSound;
};

