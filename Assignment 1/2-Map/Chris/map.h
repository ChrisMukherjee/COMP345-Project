// Map Header File
// By: Christopher Mukherjee

#pragma once

class map {
// Public methods
public:
	// Constructor
	map(int w, int h);
	// Destructor
//	~map();
	bool setCell(int x, int y, char a);
	void output();
	bool validate();
	// Accessor Methods
	int getWidth();
	int getHeight();
// Private variables
private:
	// 2D array of characters
	char** mapArr;
	int height;
	int width;
	char onCell;
	bool hasS;
	bool hasE;
};