#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

class AsciiImage
{
public:
	AsciiImage();

	bool LoadImage(ifstream &file);
	void PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL);

private:
	// Your private variables go here.
		//ifstream file;
		string title,name, image,categ, url, firstName, lastName,id;
		//string line;
		string picture[100];
		int size,widthSize;
	void PrintHorizontalBorder();
	void PrintWithVerticalBorders(string s);
};
