#include"defineHead.h"
#include<fstream>

class ReadWriteFile
{
public:
	ReadWriteFile(string path);
	string Read();
	void Write(string txt);
private:
	string path;
	fstream myFile;
	string temp;
};

