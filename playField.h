#pragma once


#include <list>
#include <iostream>


class PlayField
{
private:

	unsigned int _size;

	unsigned int** _field;

	unsigned int _numberOfCells;

	unsigned const int _minimalValue = 2;

	unsigned const int _maxValue = 2048;

	unsigned const int _emptyValue = 0;

public:

	PlayField(unsigned int size);

	void AddRandomCell();

	bool MoveCellsDown();

	bool MoveCellsUp();

	bool MoveCellsLeft();

	bool MoveCellsRight();

	void PrintPlayField();

	bool WinNumberReached();

	bool CellsAreFull();
};

