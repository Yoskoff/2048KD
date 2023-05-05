#pragma once

#include <iostream>
#include <string>
#include "playField.h"
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <list>
#include <iterator>




class Game
{
private:

	const std::string _inGameMenu =
		"IN GAME MENU";

	const std::string _winMessageFile = "winMessage.txt";
	
	const std::string _failMessageFile = "failMessage.txt";

	static enum _mainMenuCommands {NEW_GAME = 110, CLOSE_GAME = 99};

	enum _inGameMenuCommands {TURN_UP = 72, TURN_DOWN = 80, TURN_LEFT = 75, TURN_RIGHT = 77, GO_TO_MAIN_MENU = 109 };

	int _size;

	PlayField* _currentGameField;

	bool CheckFiles();

public:
	
	Game(unsigned int size);

	void LaunchGame();

	void OpenMainMenu();

	void StartGame();

	int GetInGameCommand();

	int GetMainMenuCommand();

	void PrintMainMenu();

	void PrintInGameMenu();

	void PrintWinMessage();

	void PrintFailMessage();



};
