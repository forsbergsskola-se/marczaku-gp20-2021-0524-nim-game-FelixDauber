// nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class game { //Cries in OOP

public: bool player1turn = true;
	  int sticksRemaining = 24;

	  void playGame() {
		  while (sticksRemaining > 0)
		  {
			  doRound();
		  }
		  displayWinner();
	  }

	  void doRound() {
		  displaySticks();
		  displayPlayerTurn();
		  getInput();
		  clearConsole();
	  }

	  void displayWinner() {
		  std::cout << displayCurrentPlayer << " wins!" << endl;
	  }

	  void getInput() {
		  int input;
		  std::cout << "Choose how many sticks (1-3?)";
		  std::cin >> input;
		  if (checkIfViableInput(input)) {
			  player1turn = !player1turn;
			  sticksRemaining -= input;
		  }
		  else {
			  std::cout << "Too many / too few" << endl;
			  getInput();
		  }
	  }

	  bool checkIfViableInput(int value) {
		  return (value <= 3 && value >= 1);
	  }

	  void displaySticks() {
		  for (int i = 0; i < sticksRemaining; i++)
		  {
			  std::cout << "|";
		  }
		  std::cout << endl;
	  }

	  void displayPlayerTurn() {
		  displayCurrentPlayer();
		  std::cout << "'s Turn" << endl;
	  }

	  void displayCurrentPlayer() {
		  if (player1turn) {
			  std::cout << "Player 1";
		  }
		  else {
			  std::cout << "Player 2";
		  }
	  }

	  void clearConsole() {
		  cout << system("cls");
	  }
};

int main(){
	game currentGame;
	currentGame.playGame();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
