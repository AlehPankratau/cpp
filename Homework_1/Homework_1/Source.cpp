#include <iostream>
using namespace std;

class String
{
private:
	char* newString;
	int sizeString = 0;

public:
	String(const char* myString)
	{
		sizeString = strlen(myString) + 1;
		newString = new char[sizeString];
		strcpy_s(newString, sizeString, myString);
	}

	void changeString(const char* myString)
	{
		sizeString = strlen(myString) + 1;
		newString = new char[sizeString];
		strcpy_s(newString, sizeString, myString);
	}

	char* getString()
	{
		return newString;
	}

	int lengthString()
	{
		return strlen(newString);
	}

	void operationPlusString(const char* myString)
	{
		sizeString = strlen(newString) + strlen(myString) + 1;
		char* buffString = newString;
		newString = new char[sizeString];
		strcpy_s(newString, sizeString, buffString);
		delete[] buffString;
		strcat_s(newString, sizeString, myString);
	}

	void pastePositionStringElement(int index, char symbol)
	{
		if (index < 0 || index >= sizeString) {
			cout << "Alarm! Your index is invalid" << endl;
			return;
		}
		char* buffString = newString;
		++sizeString;
		newString = new char[sizeString];
		newString[index] = symbol;
		for (int i = 0; i < sizeString; ++i)
		{
			if (i == index)
				continue;
			if (i > index)
				newString[i] = buffString[i - 1];
			else
				newString[i] = buffString[i];
		}
		delete[] buffString;
	}

	void convertStringToASCII()
	{
		cout << "ASCII table code: ";
		for (int i = 0; i < sizeString; ++i) {
			if (newString[i] == '\0')
				break;
			if ((int)newString[i] == 32)
				cout << "Space" << " = " << (int)newString[i] << "  ";
			else
				cout << newString[i] << " = " << (int)newString[i] << "  ";
		}
		cout << endl;
	}
	void highRegisterString()
	{
		strupr(newString);
	}

	void lowRegisterString()
	{
		strlwr(newString);
	}
	~String()
	{
		delete[] newString;
	}
};


int main()
{
	String firstString("Hello World!");
	cout << "Initialization: " << firstString.getString() << endl;
	cout << "String length: " << firstString.lengthString() << endl;
	firstString.operationPlusString(" Hello All!");
	cout << "String Connection: " << firstString.getString() << endl;
	cout << "Connection String length: " << firstString.lengthString() << endl;
	firstString.pastePositionStringElement(4, '&');
	cout << "Insert symbol: " << firstString.getString() << endl;
	firstString.convertStringToASCII();
	firstString.highRegisterString();
	cout << "High register string: " << firstString.getString() << endl;
	firstString.lowRegisterString();
	cout << "Low register string: " << firstString.getString() << endl;
	cout << endl;
	cout << "Thanks for review !!!" << endl;
	return 0;
}