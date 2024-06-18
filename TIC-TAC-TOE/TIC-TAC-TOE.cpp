#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <Windows.h>

using namespace std;

/*
* 3 difficulties : Easy , Normal , Hard , each one has a specific formula
* main menu : the title , select the character , select the difficulty , the nickname of the user , the grid of the game
* each player has his own score
* when one of the players win the score is incremented by 1
* when they draw the score still the same
* when the game end a message pop out and says "Do you want to play again (Y/N) ?"
* after the move of the player and the computer the grid will display
* the functions of the game : drawBoard , PlayerMove , ComputerMove Based On The Difficulty , CheckWinner , CheckTie , DisplayMenu
* the game will run until the user exit by himself
* Easy Difficulty: The computer makes random moves.
* Normal Difficulty: The computer attempts to win if possible; otherwise, it blocks the player's winning move if they are about to win. If neither condition is met, it makes a random move.
* Hard Difficulty: The computer uses the Minimax algorithm to play optimally.
*/

void drawBoard(char* spaces, char player, char computer , string name , int playerScore , int computerScore)
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
	do
	{
		cout << "Enter Your Move(1-9): ";
		cin >> move;
	} while (move < 1 || move > 9 || spaces[move] != ' ');
	move--;
	spaces[move] = player;
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

void normalMove(char* spaces, char computer)
{

}

void hardMove(char* spaces, char computer)
{

}

void computerMove(char* spaces, char computer, int difficulty)
{
	if (difficulty == 1) easyMove(spaces, computer);
	else if (difficulty == 2) normalMove(spaces, computer);
	else if (difficulty == 3) hardMove(spaces, computer);
}

bool checkWinner(char* spaces, char player, char computer)
{
	return 0;
}

bool checkTie(char* spaces, char player, char computer)
{
	return 0;
}

void loadingScreen()
{
	
}

int main()
{
	char spaces[9] = { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
	char player , computer;
	int difficulty , playerScore = 0 , computerScore = 0;
	string name;

	cout << "\t\tTIC-TAC-TOE-V1.00\n\n";

	cout << "Enter Name: ";
	cin >> name;
	
	cout << "Select Difficulty(Easy = 1 , Normal = 2 , Hard = 3): ";
	cin >> difficulty;

	do
	{
		cout << "Choose[X | O]: ";
		cin >> player;
		if (player == 'X') computer = 'O';
		else if(player == 'O') computer = 'X';
	} while (player != 'X' && player != 'O');

	playerMove(spaces, player);
	drawBoard(spaces, player, computer, name, playerScore, computerScore);
	computerMove(spaces, computer, difficulty);
	drawBoard(spaces, player, computer, name, playerScore, computerScore);

	system("pause>0");
	return 0;
}