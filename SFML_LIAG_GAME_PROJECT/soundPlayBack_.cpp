#include "soundPB.h"

soundPB::soundPB()
{
	musicBackground.openFromFile("music\\menu\\bg_menu.ogg");
	musicBackground.setLoop(true);
	musicBackground.play();
}

void soundPB::setVolMusic(int val)
{
	this->musicBackground.setVolume(val);
	cout << val << endl;
}
