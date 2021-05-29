// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class game
{
public:
    int squares[9] = {0,0,0,0,0,0,0,0,0};
    bool player2turn = false;
    int playerWon = 0;

    void startGame() {
        while (true)
        {
            while (playerWon == 0) {
                doRound();
            }
            displayGameField();
            displayWinner();
            if (!rematch()) break;
            resetGame();
        }
    }

    void resetGame() {
        for (int i = 0; i < 9; i++)
        {
            squares[i] = 0;
        }
        playerWon = 0;
    }
   
    bool rematch() {
        int i = 0;
        cout << "Rematch? 0=No, 1=Yes";
        cin >> i;
        if (i == 0) {
            return false;
        }
        if (i == 1) {
            return true;
        }
        return rematch();
    }

    void doRound() {
        displayGameField();
        doInput(); 
        checkForWin();
    }

    void displayGameField() {
        for (int i = 0; i < 9; i++)
        {
            displayIcon(squares[i]);
            if (i == 2 || i == 5) {
                std::cout << endl;
            }
        }
        std::cout << endl;
    }

    void displayIcon(int i) {
        if (i == 1)
        {
            std::cout << "X";
        }
        else if (i == 2)
        {
            std::cout << "O";
        }
        else
        {
            std::cout << "#";
        }
    }

    void doInput() {
        int x = 0, y = 0;
        cout << "Input X cordinate: ";
        cin >> x;

        cout << "Input Y cordinate: ";
        cin >> y;

        if (checkIfValidCordinate(x, y)) {
            cout << "SquarePos " << x << " " << y <<  " " << getSquareOnPosition(x, y) << endl;
            squares[getSquareOnPosition(x,y)] = player2turn + 1;
            player2turn = !player2turn;
        }
    }

    bool checkIfInside(int i) {
        return (i > 0 && i < 4);
    }

    bool checkIfValidCordinate(int x, int y) {
        return checkIfInside(x) && checkIfInside(y) && checkIfSquareAvailable(x, y);
    }

    int getSquareOnPosition(int x, int y) {
        int returnValue = x - 1;
        returnValue += (y - 1) * 3;
        return returnValue;
    }

    bool checkIfSquareAvailable(int x, int y) {
        return squares[getSquareOnPosition(x, y)] == 0;
    }

    bool checkForWin() {
        if (checkWinningRows())
        {
            playerWon = !player2turn + 1;
            return true;
        }
        return false;
    }

    bool checkWinningRows()
    {
        return (
            //Horizontal
            checkThreeSquares(0, 1, 2) ||
            checkThreeSquares(3, 4, 5) ||
            checkThreeSquares(6, 7, 8) ||

            //Vertical
            checkThreeSquares(0, 3, 6) ||
            checkThreeSquares(1, 4, 7) ||
            checkThreeSquares(2, 5, 8) ||

            //Diagonal
            checkThreeSquares(0, 4, 8) ||
            checkThreeSquares(2, 4, 6)
            );
    }

    bool checkThreeSquares(int one, int two, int three)
    {
        return (squares[one] != 0 && squares[one] == squares[two] && squares[two] == squares[three]);
    }

    void displayWinner() {
        cout << "Player " << !player2turn + 1 << " has won!";
    }
};

int main()
{
    std::cout << "Welcome to Tic-Tac-Toe!\n\n";
    game currentGame;
    currentGame.startGame();
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
