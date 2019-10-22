#include "ReadWriteFile.h"

ReadWriteFile::ReadWriteFile(string path)
{
	//this->myFile.open(fileName, ios::in);
	this->path = path;
}

string ReadWriteFile::Read()
{
	this->myFile.open(this->path, ios::in);
	if (this->myFile.is_open())
	{
		getline(this->myFile, this->temp);
		//cout << this->temp << endl;
		this->myFile.close();
	}
	else cout << "Can't open file" << endl;
	return temp;
}

void ReadWriteFile::Write(string txt)
{
	this->myFile.open(this->path, ios::out);
	if (this->myFile.is_open())
	{
		this->myFile << txt;
		this->myFile.close();
		cout << txt << endl;
	}
	else cout << "Can't open file!" << endl;
	
}
