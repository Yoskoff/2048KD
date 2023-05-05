#include "game.h"

bool Game::CheckFiles()
{
	std::ifstream file;
	bool winFileResult;
	bool failFileResult;

	bool result;

	file.open(this->_winMessageFile);
	if (file.is_open())
	{
		winFileResult = true;
	}
	else
	{
		winFileResult = false;
	}
	file.close();
	
	file.open(this->_failMessageFile);
	if (file.is_open())
	{
		failFileResult = true;
	}
	else
	{
		failFileResult = false;
	}
	file.close();

	if (winFileResult && failFileResult)
		result = true;
	else
		result = false;

	return result;
}

Game::Game(unsigned int size)
{
	this->_size = size;
	this->LaunchGame();
	this->_currentGameField = nullptr;
}

void Game::LaunchGame()
{
	if (!this->CheckFiles())
		std::cout << "The lack of files detected. Upload game again." << std::endl;
	else
	{
		std::cout << "Welcome Message" << std::endl;
	
		this->OpenMainMenu();
	}


}

void Game::StartGame()
{
	this->_currentGameField = new PlayField(this->_size);
	this->_currentGameField->AddRandomCell();
	this->_currentGameField->AddRandomCell();

	this->_currentGameField->PrintPlayField();

	this->PrintInGameMenu();

	bool gameIsGoing = true;

	do 
	{
		switch (this->GetInGameCommand())
		{
			case Game::_inGameMenuCommands::TURN_UP:
				if (this->_currentGameField->MoveCellsUp())
					this->_currentGameField->AddRandomCell();

				system("cls");
				this->_currentGameField->PrintPlayField();
				this->PrintInGameMenu();
				break;

			case Game::_inGameMenuCommands::TURN_DOWN:
				if (this->_currentGameField->MoveCellsDown())
					this->_currentGameField->AddRandomCell();

				system("cls");
				this->_currentGameField->PrintPlayField();
				this->PrintInGameMenu();
				break;

			case Game::_inGameMenuCommands::TURN_LEFT:
				if (this->_currentGameField->MoveCellsLeft())
					this->_currentGameField->AddRandomCell();

				system("cls");
				this->_currentGameField->PrintPlayField();
				this->PrintInGameMenu();
				break;

			case Game::_inGameMenuCommands::TURN_RIGHT:
				if (this->_currentGameField->MoveCellsRight())
					this->_currentGameField->AddRandomCell();

				system("cls");
				this->_currentGameField->PrintPlayField();
				this->PrintInGameMenu();
				break;

			case Game::_inGameMenuCommands::GO_TO_MAIN_MENU:
				gameIsGoing = false;
				break;
		}


	} while (!this->_currentGameField->CellsAreFull() && 
		!this->_currentGameField->WinNumberReached() && gameIsGoing == true);

	system("cls");
	
	if (this->_currentGameField->CellsAreFull())
	{
		this->PrintFailMessage();
		Sleep(5000);
		system("cls");
	}
	else if (this->_currentGameField->WinNumberReached())
	{
		this->PrintWinMessage();
		Sleep(5000);
		system("cls");
	}

	delete this->_currentGameField;
	this->OpenMainMenu();
}

void Game::OpenMainMenu()
{
	PrintMainMenu();

	switch (GetMainMenuCommand())
	{
	case NEW_GAME:
		system("cls");
		StartGame();
		break;

	case CLOSE_GAME:
		system("cls");
		std::cout << "GOOD BYE";
		break;
	}

}

int Game::GetInGameCommand()
{
	int result;
	do
	{
		result = _getch();
		if (result == 224)
		{
			result = _getch();
		}

	} while (result != Game::_inGameMenuCommands::TURN_UP
		&& result != Game::_inGameMenuCommands::TURN_DOWN
		&& result != Game::_inGameMenuCommands::TURN_LEFT
		&& result != Game::_inGameMenuCommands::TURN_RIGHT
		&& result != Game::_inGameMenuCommands::GO_TO_MAIN_MENU);

	return result;
}

int Game::GetMainMenuCommand()
{
	int result;
	do
	{
		result = _getch();

	} while (result != Game::_mainMenuCommands::NEW_GAME 
		&& result != Game::_mainMenuCommands::CLOSE_GAME);

	return result;
}

void Game::PrintMainMenu()
{
	std::cout << "\t\tMAIN MENU\n" <<
		"\tPRESS \"" << char(Game::_mainMenuCommands::NEW_GAME) << "\" TO START NEW GAME\n" <<
		"\tPRESS \"" << char(Game::_mainMenuCommands::CLOSE_GAME) << "\" TO CLOSE APPLICATION\n";
}

void Game::PrintInGameMenu()
{
	std::cout << "\t\tMAIN MENU\n" <<
		"\tPRESS \"" << char(Game::_inGameMenuCommands::TURN_UP) << "\" TO TURN UP\n" <<
		"\tPRESS \"" << char(Game::_inGameMenuCommands::TURN_DOWN) << "\" TO TURN DOWN\n" <<
		"\tPRESS \"" << char(Game::_inGameMenuCommands::TURN_LEFT) << "\" TO TURN LEFT\n" <<
		"\tPRESS \"" << char(Game::_inGameMenuCommands::TURN_RIGHT) << "\" TO TURN RIGHT\n" <<
		"\tPRESS \"" << char(Game::_inGameMenuCommands::GO_TO_MAIN_MENU) << "\" TO END GAME\n";
}

void Game::PrintWinMessage()
{
	std::list <std::string> messageText;
	std::ifstream file;
	file.open(this->_winMessageFile);

	while (!file.eof())
	{
		std::string buffer;
		std::getline(file, buffer);

		messageText.push_back(buffer);
	}

	file.close();
	std::list <std::string> ::iterator stringNumber;

	for (stringNumber = messageText.begin(); stringNumber != messageText.end(); stringNumber++)
	{
		std::cout << *stringNumber << std::endl;
	}
}

void Game::PrintFailMessage()
{
	std::list <std::string> messageText;
	std::ifstream file;
	file.open(this->_failMessageFile);

	while (!file.eof())
	{
		std::string buffer;
		std::getline(file, buffer);

		messageText.push_back(buffer);
	}

	file.close();
	std::list <std::string> ::iterator stringNumber;
	
	for (stringNumber = messageText.begin(); stringNumber != messageText.end(); stringNumber++)
	{
		std::cout << *stringNumber << std::endl;
	}
}
