#include"defineHead.h"

class soundPB
{
public:
	soundPB();
	void setVolMusic(int val);
	void setVolEffect(int val);
	void _holdOnPlay();
	void _clickPlay();
private:
	Music musicBackground;
	SoundBuffer _holdOnBuffer;
	Sound _holdOnSound;
	SoundBuffer _clickBuffer;
	Sound _clickSound;
};

