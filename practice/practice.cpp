// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	ifstream file;
	file.open("practice.txt");
	vector<string> image;
	string title, tmp, id, url, categ, author;
	
	while (!file.eof())
	{
	//get Title
		getline(file, title); 
		//cout << title << endl;
	//get id
		getline(file, id);
		//cout << id << endl;
	//get image
		while (tmp != "=====")
		{
			getline(file, tmp);
			//if (!tmp.empty())
			image.push_back(tmp);
		}
	// get url
		getline(file, url);
		//cout << url << endl;
	// get Category
		getline(file, categ);
		//cout << categ << endl;
	// get Author
		getline(file, author);
		//cout << author << endl;
	}

	cout << title << endl;
	cout << id << endl;
	for (const auto&image : image)
		cout << image << endl;
	cout << url << endl;
	cout << categ << endl;
	cout << author << endl;


	file.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
