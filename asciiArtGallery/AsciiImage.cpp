#include "AsciiImage.h"

AsciiImage::AsciiImage()
{
	// Add defaults here
	title = "";
	id = "";
	name = ""; 
	image = "";
	categ = ""; 
	url = "";
}

bool AsciiImage::LoadImage(ifstream &file)
{
	// Load title
	while (getline(file, title))
	{
		if (title != " ")
		{
			break;
		}
	}
	//cout << title << endl;
	
	// Get ID
	file >> id;

	// Read image 
	file.ignore();
	while (getline(file, image))
	{
		if (image == "=====")
		{
			break;
		}
		else
		{
			picture[size] = image;
			size++;
		}


	} 
	
	// Read URL
	file >> url;
	widthSize = url.length();

	//Read Catagory
	file >> categ;

	// Maybe read a name
	file.ignore();
	getline(file, name);


	
	
	//check if you reached the end of the file by using the eof() function:

	if (file.eof())
		cout << "End of the file!Nothing left to read!" << endl;

	return true;
}

void AsciiImage::PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL)
{
	AsciiImage::PrintHorizontalBorder();
	// Print the image with the board and options
	if (showTitle == true)
		//cout << title << endl;
		AsciiImage::PrintWithVerticalBorders("Title"+ title);
	cout << endl;
	if (showID == true)
		//cout << id << endl;
		AsciiImage::PrintWithVerticalBorders("ID" + id);

	for (int i = 0; i < size; i++)
	{
		AsciiImage::PrintWithVerticalBorders("Image"+ image);
	}

	cout << endl;
	if (showURL == true)
		//cout << url << endl;
		AsciiImage::PrintWithVerticalBorders("URL"+ url);
	if (showCateg == true)
		//cout << categ << endl;
		AsciiImage::PrintWithVerticalBorders("Category"+categ);
	if (showName == true)
	{
		stringstream strSt(name);
		string firstName, lastName;
		strSt >> firstName >> lastName; // stores “First name” in val1 and “last name” in val2

		if (name == " ")
		{
			firstName = "Unknown";
			lastName = "Unknown";
		}
		else if (lastName == " ")
		{
			lastName = "Unknown";
		}

		AsciiImage::PrintWithVerticalBorders(firstName + " " + lastName);

		AsciiImage::PrintHorizontalBorder();
	}	
}

void AsciiImage::PrintHorizontalBorder()
{
	// Print the horizontal border
	//string hori_border[1][100];
	//int hori_size;
	//for (int j = 0; j < (2 + widthSize); j++)
	//{
	//	hori_border[0][j] == "=";
	//	cout << hori_border[0][j];
	//}
	cout << setfill ('=') << setw (2 + widthSize);
	//cout << ("=" * (2 + widthSize));
}

void AsciiImage::PrintWithVerticalBorders(string s)
{
	// Print the string s with "|" on both sides
	cout << "|";
	cout << "  ";
	cout << s;

	cout << setfill (' ') << setw (widthSize - s.length());
	cout << "  ";
	//cout << ((widthSize - s.length()) * " ") + "  ";
	cout << "|";
}