#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

void drawBoard(char* spaces , string name , int playerScore , int computerScore)
{
	cout << "\t\t" << name << ": " << playerScore << "\t" << "Computer: " << computerScore << "\n\n";
	cout << "\t\t     |" << "     |" << "     " << "\n";
	cout << "\t\t  " << spaces[0] << "  |" << "  " << spaces[1] << "  |" << "  " << spaces[2] << "  " << "\n";
	cout << "\t\t_____|" << "_____|" << "_____" << "\n";
	cout << "\t\t     |" << "     |" << "     " << "\n";
	cout << "\t\t  " << spaces[3] << "  |" << "  " << spaces[4] << "  |" << "  " << spaces[5] << "  " << "\n";
	cout << "\t\t_____|" << "_____|" << "_____" << "\n";
	cout << "\t\t     |" << "     |" << "     " << "\n";
	cout << "\t\t  " << spaces[6] << "  |" << "  " << spaces[7] << "  |" << "  " << spaces[8] << "  " << "\n";
	cout << "\t\t     |" << "     |" << "     " << "\n\n";
}

void playerMove(char* spaces, char player)
{
	int move;
	while (true)
	{
		do
		{
			cout << "Enter Your Move(1-9): ";
			cin >> move;
			move--;
		} while (move < 0 || move > 8);
		if (spaces[move] == ' ')
		{
			spaces[move] = player;
			break;
		}
	}
}

void easyMove(char* spaces, char computer)
{
	srand(time(0));
	int move;
	do
	{
		move = rand() % 9;
	} while (spaces[move] != ' ');
	spaces[move] = computer;
}

bool canWin(char* spaces, char computer)
{
	int winCombos[8][3] = { {0 , 1 , 2} , {3 , 4 , 5} , {6 , 7 , 8} , {0 , 3 , 6} , {1 , 4 , 7} , {2 , 5 , 8} , {0 , 4 , 8} , {2 , 4 , 6} };

	for (int i = 0; i < 8; i++)
	{
		if (spaces[winCombos[i][0]] == computer && spaces[winCombos[i][1]] == computer && spaces[winCombos[i][2]] == ' ')
		{
			spaces[winCombos[i][2]] = computer;
			return true;
		}
		if (spaces[winCombos[i][0]] == computer && spaces[winCombos[i][1]] == ' ' && spaces[winCombos[i][2]] == computer)
		{
			spaces[winCombos[i][1]] = computer;
			return true;
		}
		if (spaces[winCombos[i][0]] == ' ' && spaces[winCombos[i][1]] == computer && spaces[winCombos[i][2]] == computer)
		{
			spaces[winCombos[i][0]] = computer;
			return true;
		}
	}

	return false;
}

bool canBlock(char* spaces, char player, char computer)
{
	int winCombos[8][3] = { {0 , 1 , 2} , {3 , 4 , 5} , {6 , 7 , 8} , {0 , 3 , 6} , {1 , 4 , 7} , {2 , 5 , 8} , {0 , 4 , 8} , {2 , 4 , 6} };

	for (int i = 0; i < 8; i++)
	{
		if (spaces[winCombos[i][0]] == player && spaces[winCombos[i][1]] == player && spaces[winCombos[i][2]] == ' ')
		{
			spaces[winCombos[i][2]] = computer;
			return true;
		}
		if (spaces[winCombos[i][0]] == player && spaces[winCombos[i][1]] == ' ' && spaces[winCombos[i][2]] == player)
		{
			spaces[winCombos[i][1]] = computer;
			return true;
		}
		if (spaces[winCombos[i][0]] == ' ' && spaces[winCombos[i][1]] == player && spaces[winCombos[i][2]] == player)
		{
			spaces[winCombos[i][0]] = computer;
			return true;
		}
	}

	return false;
}

void normalMove(char* spaces , char player , char computer)
{
	if (canWin(spaces, computer)) return;
	if (canBlock(spaces, player, computer)) return;
	easyMove(spaces, computer);
}

void hardMove(char* spaces, char computer)
{

}

void computerMove(char* spaces, char player, char computer, int difficulty)
{
	if (difficulty == 1) easyMove(spaces, computer);
	else if (difficulty == 2) normalMove(spaces, player, computer);
	else if (difficulty == 3) hardMove(spaces, computer);
}

bool checkWinner(char* spaces, char player)
{
	bool isWinning = false;

	for (int i = 0; i < 3; i++)
	{
		if (spaces[i * 3] == player && spaces[i * 3 + 1] == player && spaces[i * 3 + 2] == player)
		{
			isWinning = true;
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (spaces[i] == player && spaces[i + 3] == player && spaces[i + 6] == player)
		{
			isWinning = true;
			break;
		}
	}

	if ((spaces[0] == player && spaces[4] == player && spaces[8] == player) || (spaces[2] == player && spaces[4] == player && spaces[6] == player))
	{
		isWinning = true;
	}

	return isWinning;
}

bool checkLose(char* spaces , char computer)
{
	bool isLosing = false;

	for (int i = 0; i < 3; i++)
	{
		if (spaces[i * 3] == computer && spaces[i * 3 + 1] == computer && spaces[i * 3 + 2] == computer)
		{
			isLosing = true;
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (spaces[i] == computer && spaces[i + 3] == computer && spaces[i + 6] == computer)
		{
			isLosing = true;
			break;
		}
	}

	if ((spaces[0] == computer && spaces[4] == computer && spaces[8] == computer) || (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer))
	{
		isLosing = true;
	}

	return isLosing;
}

bool checkTie(char* spaces)
{
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i] == ' ') return false;
	}
	return true;
}

void setBoard(char* spaces)
{
	for (int i = 0; i < 9; i++) spaces[i] = ' ';
}

void loadingScreen()
{
	cout << "Loading";
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(500);
	}
	cout << "\n";
	system("cls");
}

int main()
{
	char spaces[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	char player, computer{} , playingAgain{};
	int difficulty , playerScore = 0 , computerScore = 0;
	string name;
	bool isRunning = true;

	cout << "\t\tTIC-TAC-TOE-V1.00\n\n";

	cout << "Enter Name: ";
	cin >> name;
	
	cout << "Select Difficulty(Easy = 1 , Normal = 2 , Hard = 3): ";
	cin >> difficulty;

	do
	{
		cout << "Choose(X/O): ";
		cin >> player;
		if (player == 'X') computer = 'O';
		else if(player == 'O') computer = 'X';
	} while (player != 'X' && player != 'O');

	loadingScreen();

	drawBoard(spaces, name, playerScore, computerScore);
	
	while (true)
	{
		while (isRunning)
		{
			playerMove(spaces, player);
			drawBoard(spaces, name, playerScore, computerScore);
			if (checkWinner(spaces, player))
			{
				cout << "WINNER WINNER CHICKEN DINNER!" << "\n";
				playerScore++;
				isRunning = false;
				setBoard(spaces);
				break;
			}
			else if (checkLose(spaces, computer))
			{
				cout << "YOU LOSE!" << "\n";
				computerScore++;
				isRunning = false;
				setBoard(spaces);
				break;
			}
			else if (checkTie(spaces))
			{
				cout << "Draw!" << "\n";
				isRunning = false;
				setBoard(spaces);
				break;
			}

			computerMove(spaces, player, computer, difficulty);
			drawBoard(spaces, name, playerScore, computerScore);
			if (checkWinner(spaces, player))
			{
				cout << "WINNER WINNER CHICKEN DINNER!" << "\n";
				playerScore++;
				isRunning = false;
				setBoard(spaces);
				break;
			}
			else if (checkLose(spaces, computer))
			{
				cout << "YOU LOSE!" << "\n";
				computerScore++;
				isRunning = false;
				setBoard(spaces);
				break;
			}
			else if (checkTie(spaces))
			{
				cout << "Draw!" << "\n";
				isRunning = false;
				setBoard(spaces);
				break;
			}
		}

		cout << "Do you want to play again(Y/N): ";
		cin >> playingAgain;
		if (playingAgain == 'Y' || playingAgain == 'y')
		{
			isRunning = true;
			loadingScreen();
			drawBoard(spaces , name , playerScore , computerScore);
		}
		else if (playingAgain == 'N' || playingAgain == 'n')
		{
			system("cls");
			cout << "THANKS FOR PLAYING!" << "\n";
			break;
		}
		else
		{
			system("cls");
			cout << "INVALID INPUT, PLEASE TRY AGAIN!" << "\n";
		}
	}
	return 0;
}