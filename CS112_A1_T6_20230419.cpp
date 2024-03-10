//File Name : CS112_A1_T6_20230419.cpp.
// Program: each player inputs two moves , the winning is checked in the last 2 moves of player2 if they can shape a rectangle , he is winner; else player1 wins.
//Game : Two squares game.
// Author: Malak NourElhussien Samir Ali , 20230419.
// Version: 10.0
// Date: 29/2/2024.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int board[4][4] = {//setting the 4×4 board to display it to the user.
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
};

int selectedNumbers[16] = {0};  // Array to track selected numbers to prevent the user from choosing a selected number as when you choose a number , it puts on its index 1.

// validation check to avoid users' wrong inputs.
int check_validation() {
    int value;
    // Keep asking the user until enters a valid input.
    while (true) {
        cout << "Enter your number: ";
        // Read the entire line of input
        string input;
        getline(cin, input);
        // Use a stringstream to attempt to extract an integer from the input.
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            // Check if the entered number is within the valid range and not already selected.
            if (value > 0 && value <= 16 && selectedNumbers[value - 1] == 0) {
                // Valid input, break out of the loop
                break;
            } else {
                cout << "Invalid input !" <<endl;
                if (selectedNumbers[value - 1] != 0) {
                    cout << "Number already selected. ";
                }
                cout << "Please enter a valid number within the range (1-16)." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
    }

    return value;
}

int move_1() {
    int flag = 0;
    cout << "ENTER YOUR FIRST MOVE " << endl;
    int value = check_validation();
    selectedNumbers[value - 1] = 1;  // Mark the selected number
    for (int i = 0; i < 4; i++) {
        for (int n = 0; n < 4; n++) {
            if (value == board[i][n]) {
                board[i][n] = 0;// Mark the selected number
                flag = 1;//breaking
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return value;
}

int move_2() {
    int move1 = move_1();
    int flag = 0;
    while (true) {
        cout << "ENTER YOUR SECOND MOVE " << endl;
        int move2 = check_validation();
        int empty_count = 0;    //counting empty cells

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (board[j][k] == 0) {
                    empty_count++;
                }
            }
        }

        // Check if the two moves form a rectangle on the board
        if (move1 == move2) {
            cout << "It's not a rectangle, choose proper numbers." << endl;
            continue;
        }
        //NUMBER 2
        int row1 = (move1 - 1) / 4; //2-1 = 1 /4 = 0
        int col1 = (move1 - 1) % 4; // 2-1 = 1 % 4 = 1 (reminder)
        int row2 = (move2 - 1) / 4;
        int col2 = (move2 - 1) % 4;

        // Check if the two selected numbers are adjacent
        if ((abs(row1 - row2) == 1 && col1 == col2) || (row1 == row2 && abs(col1 - col2) == 1)) {
            // Check if it's a rectangle
            if (empty_count > 14 && empty_count < 17) { //LAST TWO MOVES
                if (row1 == row2 || col1 == col2) {
                    cout << "PLAYER 2 IS THE WINNER" << endl;
                    return 0;
                } else {
                    cout << "PLAYER 1 IS THE WINNER" << endl;
                    return 0;
                }
            }
            // Check if the two moves form a rectangle on the board
            if (empty_count < 14) {
                selectedNumbers[move2 - 1] = 1;  // Mark the selected number
                for (int i = 0; i < 4; i++) {
                    for (int n = 0; n < 4; n++) {
                        if (move2 == board[i][n]) {
                            board[i][n] = 0;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                        break;
                }
                cout << "It's a rectangle" << endl;
                return move2;
            }
        } else {
            cout << "Selected numbers are not adjacent, choose proper numbers." << endl;
        }
    }
}

int main() {
    cout << "===============================================TWO SQUARES GAME====================================================" << endl;
    cout << "WELCOME! Each player should select 2 moves to create a rectangle. The last player to shape a rectangle is the winner." << endl;
    cout << "====================================================================================================================" << endl;
    int player_turn = 1; //TO TAKE TURNS
    for (int empty_count = 0; empty_count < 14; empty_count++) {
        if (player_turn == 1) {
            cout << "PLAYER ONE'S TURN , CHOOSE FROM A NUMBER FROM THIS BOARD :" << endl;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if(board[j][k] == 0) {
                        cout << setw(4) << 'X' << setw(4) << " | ";
                    }
                    else{
                        cout << setw(4) << board[j][k] << setw(4) << " | ";
                    }
                }
                cout << endl; // Move to the next line for the next row
            }
            int moveResult = move_2();
            if (moveResult == 0) {
                break;  // Exit the game if there's a winner
            }
        } else if (player_turn == 2) {
            cout << "PLAYER TWO'S TURN , CHOOSE FROM A NUMBER FROM THIS BOARD :" << endl;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if(board[j][k] == 0) {
                        cout << setw(4) << 'X' << setw(4) << " | ";
                    }
                    else{
                        cout << setw(4) << board[j][k] << setw(4) << " | ";
                    }
                }
                cout << endl; // Move to the next line for the next row
            }
            int moveResult = move_2();
            if (moveResult == 0) {
                break;  // Exit the game if there's a winner
            }
        }
        player_turn = 3 - player_turn; // Switch turns between player 1 and player 2
    }
}