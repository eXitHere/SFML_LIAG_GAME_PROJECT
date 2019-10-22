#include "soundPB.h"

soundPB::soundPB()
{
	musicBackground.openFromFile("music\\menu\\bg_menu.ogg");
	musicBackground.setLoop(true);
	musicBackground.play();
	this->_holdOnBuffer.loadFromFile("music\\effect\\click.wav");
	this->_holdOnSound.setBuffer(_holdOnBuffer);
	this->_clickBuffer.loadFromFile("music\\effect\\beep.ogg");
	this->_clickSound.setBuffer(_clickBuffer);
	this->_clockBuffer.loadFromFile("music\\effect\\clock.wav");
	this->_clockSound.setBuffer(_clockBuffer);
}

void soundPB::setVolMusic(int val)
{
	
	this->musicBackground.setVolume(val);
	//cout << val << endl;
}

void soundPB::setVolEffect(int val)
{
	this->_holdOnSound.setVolume(val);
	this->_clickSound.setVolume(val);
}

void soundPB::_clickPlay()
{
	while (_clickSound.getStatus() != Sound::Status::Playing)
	{
		_clickSound.play();
		//	cout << "Click" << endl;
	}
}

void soundPB::_clockPlay()
{
	while (_clockSound.getStatus() != Sound::Status::Playing)
	{
		this->_clockSound.play();
		//	cout << "Click" << endl;
	}
}

void soundPB::setSoundBG(int val)
{
	if (val)
	{
		this->musicBackground.play();
	}
	else
	{
		this->musicBackground.pause();
	}
}

void soundPB::_holdOnPlay()
{
	while (_holdOnSound.getStatus() != Sound::Status::Playing)
	{
		_holdOnSound.play();
	//	cout << "Click" << endl;
	}
}
