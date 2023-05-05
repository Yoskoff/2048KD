#include "playField.h"



PlayField::PlayField(unsigned int size)
{
	this->_size = size;

	this->_numberOfCells = size * size;

	this->_field = new unsigned int*[size];

	for (int ii = 0; ii < size; ii++)
	{
		this->_field[ii] = new unsigned int[size];
		
		for (int ll = 0; ll < size; ll++)
		{
			this->_field[ii][ll] = _emptyValue;
		}
	}
}

void PlayField::AddRandomCell()
{
	unsigned int positionX;
	unsigned int positionY;

	bool cellIsCreated = false;

	do
	{

		positionX = rand() % (this->_size);

		positionY = rand() % (this->_size);


		if (this->_field[positionX][positionY] == _emptyValue)
		{
			this->_field[positionX][positionY] = _minimalValue;
			cellIsCreated = true;
		}

	} while (cellIsCreated == false);
}

bool PlayField::MoveCellsUp()
{
	bool result = false;
	for (int mm = 1; mm < this->_size; mm++)
	{
		for (int ii = 1; ii < this->_size; ii++)
		{
			for (int ll = 0; ll  < this->_size; ll ++)
			{
				if (_field[ii][ll] != _emptyValue && (_field[ii - 1][ll] == _field[ii][ll] ||
					_field[ii - 1][ll] == this->_emptyValue))
				{
					_field[ii - 1][ll] += _field[ii][ll];
					_field[ii][ll] = this->_emptyValue;
					result = true;
				}
			}
		}
	}
	return result;
}

bool PlayField::MoveCellsDown()
{
	bool result = false;
	for (int mm = 1; mm < this->_size; mm++)
	{
		for (int ii = this->_size - 2; ii >= 0; ii--)
		{
			for (int ll = 0; ll < this->_size; ll++)
			{
				
				if (_field[ii][ll] != _emptyValue && (_field[ii + 1][ll] == _field[ii][ll] ||
					_field[ii + 1][ll] == this->_emptyValue))
				{
					_field[ii + 1][ll] += _field[ii][ll];
					_field[ii][ll] = this->_emptyValue;
					result = true;
				}
			}
		}
	}
	return result;
}

bool PlayField::MoveCellsLeft()
{
	bool result = false;
	for (int mm = 1; mm < this->_size; mm++)
	{
		for (int ll = 1; ll < this->_size; ll++)
		{
			for (int ii = 0; ii < this->_size; ii++)
			{
				if (_field[ii][ll] != _emptyValue && (_field[ii][ll - 1] == _field[ii][ll] ||
					_field[ii][ll - 1] == this->_emptyValue))
				{
					_field[ii][ll - 1] += _field[ii][ll];
					_field[ii][ll] = this->_emptyValue;
					result = true;
				}
			}
		}
	}
	return result;
}


bool PlayField::MoveCellsRight()
{
	bool result = false;
	for (int mm = 1; mm < this->_size; mm++)
	{
		for (int ll = this->_size - 2; ll >= 0; ll--)
		{
			for (int ii = 0; ii < this->_size; ii++)
			{
				if (_field[ii][ll] != _emptyValue && (_field[ii][ll + 1] == _field[ii][ll] ||
					_field[ii][ll + 1] == this->_emptyValue))
				{
					_field[ii][ll + 1] += _field[ii][ll];
					_field[ii][ll] = this->_emptyValue;
					result = true;
				}
			}
		}
	}
	return result;
}

void PlayField::PrintPlayField()
{
	std::cout << '\t' << char(201);

	
	for (int mm = 0; mm < this->_size; mm++)
	{

		for (int ii = 0; ii < 7; ii++)
		{
			std::cout << char(205);
		}

		if (mm < this->_size - 1)
			std::cout << char(203);
		else
			std::cout << char(187) << '\n';
	}


	for (int ii = 0; ii < this->_size; ii++)
	{

		int cellIndexY = 0;

		for (int ll = 0; ll <= this->_size; ll++)
		{
			std::cout << '\t' << char(186);
		}

		std::cout << '\n';
		std::cout << '\t' << char(186);

		for (int ll = 0; ll < this->_size; ll++)
		{
			std::cout << "  ";
			switch (this->_field[ii][cellIndexY])
			{
			case 2:
				std::cout << "\u001b[38;5;112m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 4:
				std::cout << "\u001b[38;5;113m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 8:
				std::cout << "\u001b[38;5;114m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 16:
				std::cout << "\u001b[38;5;115m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 32:
				std::cout << "\u001b[38;5;116m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 64:
				std::cout << "\u001b[38;5;117m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 128:
				std::cout << "\u001b[38;5;118m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 256:
				std::cout << "\u001b[38;5;119m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 512:
				std::cout << "\u001b[38;5;120m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 1024:
				std::cout << "\u001b[38;5;121m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			case 2048:
				std::cout << "\u001b[38;5;122m" << this->_field[ii][cellIndexY] << "\u001b[0m";
				break;
			}

			std::cout << '\t' << char(186);
			cellIndexY++;
		}

		std::cout << '\n';

		for (int ll = 0; ll <= this->_size; ll++)
		{
			std::cout << '\t' << char(186);
		}

		std::cout << '\n';



		if (ii < this->_size - 1)
			std::cout << '\t' << char(204);
		else
			std::cout << '\t' << char(200);


		for (int mm = 0; mm < this->_size; mm++)
		{
			for (int ll = 0; ll < 7; ll++)
			{
				std::cout << char(205);
			}

			if (ii == this->_size - 1)
			{
				if (mm < this->_size - 1)
					std::cout << char(202);
				else
					std::cout << char(188) << '\n';
			}
			else
			{
				if (mm < this->_size - 1)
					std::cout << char(206);
				else
					std::cout << char(185) << '\n';
			}
		}


	}

}

bool PlayField::WinNumberReached()
{
	bool result = false;

	for (int ii = 0; ii < this->_size; ii++)
	{
		for (int ll = 0; ll < this->_size; ll++)
		{
			if (this->_field[ii][ll] == this->_maxValue)
			{
				result = true;
			}
		}
	}
	return result;
}

bool PlayField::CellsAreFull()
{
	bool result = true;

	for (int ii = 0; ii < this->_size; ii++)
	{
		for (int ll = 0; ll < this->_size; ll++)
		{
			if (this->_field[ii][ll] == this->_emptyValue)
			{
				result = false;
				break;
			}
		}
	}

	if (result == true)
	{
		for (int ii = 0; ii < this->_size; ii++)
		{
			for (int ll = 0; ll < this->_size; ll++)
			{
				if (ii == 0)
				{
					if (ll == 0)
					{
						if (this->_field[ii][ll] == this->_field[ii + 1][ll] || 
							this->_field[ii][ll] == this->_field[ii][ll+1])
						{
							result = false;
							break;
						}
					}
					else if (ll == this->_size - 1)
					{
						if (this->_field[ii][ll] == this->_field[ii + 1][ll] ||  
							this->_field[ii][ll] == this->_field[ii][ll - 1])
						{
							result = false;
							break;
						}
					}
					else
					{
						if (this->_field[ii][ll] == this->_field[ii + 1][ll] || 
							this->_field[ii][ll] == this->_field[ii][ll + 1] || 
							this->_field[ii][ll] == this->_field[ii][ll - 1] )
						{
							result = false;
							break;
						}
					}
				}
				else if (ii == this->_size - 1)
				{
					if (ll == 0)
					{
						if (this->_field[ii][ll] == this->_field[ii - 1][ll] ||
							this->_field[ii][ll] == this->_field[ii][ll + 1])
						{
							result = false;
							break;
						}
					}
					else if (ll == this->_size - 1)
					{
						if (this->_field[ii][ll] == this->_field[ii - 1][ll] ||
							this->_field[ii][ll] == this->_field[ii][ll - 1])
						{
							result = false;
							break;
						}
					}
					else
					{
						if (this->_field[ii][ll] == this->_field[ii - 1][ll] ||
							this->_field[ii][ll] == this->_field[ii][ll + 1] ||
							this->_field[ii][ll] == this->_field[ii][ll - 1])
						{
							result = false;
							break;
						}
					}
				}
				
			}
		}
	}

	return result;
}



