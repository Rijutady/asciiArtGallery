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
	// get rid of empty line
	while (getline(file, title))
	{
		if (title != " ")
		{
			break;
		}
	}

	// Load title
	getline(file, title);
	
	// Get ID
	file >> id;

	// Read image 
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
	widthSize = 80;

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
	// print boarder
	AsciiImage::PrintHorizontalBorder();

	cout << "" << endl;

	// Print the image with the board and options
	if (showTitle == true)
		AsciiImage::PrintWithVerticalBorders(title);

	if (showID == true)
		AsciiImage::PrintWithVerticalBorders(id);

	for (int i = 0; i < size; i++)
	{
		AsciiImage::PrintWithVerticalBorders(picture[i]);
	}

	// one empty line
	AsciiImage::PrintWithVerticalBorders(" ");

	if (showURL == true)
		AsciiImage::PrintWithVerticalBorders(url);

	if (showCateg == true)
		AsciiImage::PrintWithVerticalBorders(categ);

	if (showName == true)
	{
			stringstream strst(name);
			strst >> firstName >> lastName; // stores “first name” in val1 and “last name” in val2
			if (lastName != " ")
			{
				name = firstName + " " + lastName;
			}
			else if (firstName != " ")
			{
				name = firstName + " Unknown";
			}
			else
			{
				name = "Unknown Unknown";
			}
			AsciiImage::PrintWithVerticalBorders(name);

	}

	// print boarder
	AsciiImage::PrintHorizontalBorder();
	cout << "" << endl; 
}

void AsciiImage::PrintHorizontalBorder()
{
	cout << setfill ('=') << setw (4 + widthSize);
}

void AsciiImage::PrintWithVerticalBorders(string s)
{
	// Print the string s with "|" on both sides
	cout << "|";
	cout << "  ";
	cout << s;
	cout << setfill (' ') << setw (widthSize - s.length());
	cout << "  ";
	cout << "|" << endl;
}