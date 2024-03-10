//File Name : CS112_A1_T5_20230419.cpp.
// Program: Each player picks a number between 1 and 9 and take turns ,the winner who reaches 15 first with sum of only 3 digits.
//Game : Game2 , Scrabble game
// Author: Malak NourElhussien Samir Ali , 20230419.
// Version: 2.0
// Date: 28/2/2024.

#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> scrabble_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //setting scrabble list
vector<int> player_1; //setting empty 2 lists to inset on them what players pick.
vector<int> player_2;

int player1() {
    int elements1;  //to insert the user number on it.
    bool flag1 = true;
    while (flag1) {
        cout << "Player 1: Enter your number" <<endl;
        string input;  //take the input as a string first to check it easily.
        getline(cin, input);  // Read the entire input as a string

        if (input.find_first_not_of("0123456789") != string::npos){       // Check if the input contains only digits.
            cout << "Invalid input. Please enter a valid number." <<endl;
            continue;   //This line causes the loop to skip the rest of the current iteration and start a new one if the input is invalid.
        }
        //check validation.
        try {
            elements1 = stoi(input); // convert input to an integer
            if (find(scrabble_numbers.begin(), scrabble_numbers.end(), elements1) == scrabble_numbers.end()) {
                cout << "Unfound Number, please enter a valid number" << endl;
                continue;
            } else {
                flag1 = false;  //This line sets the flag to false once a valid number is entered, terminating the loop.
            }
        }
        catch (const invalid_argument &e){ //to prevent error when the user click enter without write anything
            cout << "Invalid input. Please enter a valid number." <<endl;
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const out_of_range &e) {   //to prevent error when the user input a very big ranged number.
            cout << "Input out of range. Please enter a valid number within the range." <<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return elements1;
}

int player2() {
    int elements2;
    bool flag2 = true;
    while (flag2) {
        cout << "Player 2: Enter your number" << endl;
        string input;
        getline(cin, input);

        if (input.find_first_not_of("0123456789") != string::npos) {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        try {
            elements2 = stoi(input);
            if (find(scrabble_numbers.begin(), scrabble_numbers.end(), elements2) == scrabble_numbers.end()) {
                cout << "Unfound Number, please enter a valid number" << endl;
                continue;
            } else {
                flag2 = false;
            }
        } catch (const invalid_argument &e) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } catch (const out_of_range &e) {
            cout << "Input out of range. Please enter a valid number within the range." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return elements2;
}

void main_game() {
    cout << "____________________________________________________________________________________________________" << endl;
    cout << "Welcome to scrabble game, Each player takes a number from this list: "<<endl;
    for (int num : scrabble_numbers) {
        cout << num << " ";
    }
    cout << "Numbers cannot be chosen twice. The winner is the one who has only 3 numbers whose sum equals 15 first." << endl;
    cout << "____________________________________________________________________________________________________" << endl;
    int flag = 0;
    while (scrabble_numbers.size() > 0) {
        flag = 0;
        int elements1 = player1();
        player_1.push_back(elements1);
        auto iter1 = find(scrabble_numbers.begin(), scrabble_numbers.end(), elements1);
            scrabble_numbers.erase(iter1);   //removes inputs as it cannot be choosen twice
        if (player_1.size() >= 3) {         //check the sum of diffrent 3 numbers
            for (int i = 0; i < player_1.size(); i++) {
                for (int j = 0; j < player_1.size(); j++) {
                    for (int k = 0; k < player_1.size(); k++) {
                        if (player_1[i] != player_1[j] && player_1[j] != player_1[k] && player_1[k] != player_1[i]) {
                            if (player_1[i] + player_1[j] + player_1[k] == 15) {
                                flag = 1;
                                break;   //breaking from the 3 nested loops
                            }
                        }
                    }
                    if (flag==1){ //breaking from the 3 nested loops
                        break;
                    }
                }
                if (flag==1){//breaking from the 3 nested loops
                    break;
                }
            }
            if (flag==1){//breaking from the 3 nested loops
                break;
            }// else : continue taking turns between players
        }
        if (scrabble_numbers.size() == 0) {
            break;
        }
        cout << "========================================================" << endl;
        cout << "Player2 choose a number from this list: ";
        for (int num : scrabble_numbers) {
            cout << num << " ";
        }
        cout << endl;
        int elements2 = player2();
        player_2.push_back(elements2);
        auto iter2 = find(scrabble_numbers.begin(), scrabble_numbers.end(), elements2);
            scrabble_numbers.erase(iter2);   //removes inputs as it cannot be choosen twice
        if (player_2.size() >= 3) {     //check the sum of diffrent 3 numbers
            for (int i = 0; i < player_2.size(); i++) {
                for (int j = 0; j < player_2.size(); j++) {
                    for (int k = 0; k < player_2.size(); k++) {
                        if (player_2[i] != player_2[j] && player_2[j] != player_2[k] && player_2[k] != player_2[i]) {
                            if (player_2[i] + player_2[j] + player_2[k] == 15) {
                                flag = 2;//breaking from the 3 nested loops
                                break;
                            }
                        }
                    }
                    if (flag==2){//breaking from the 3 nested loops
                        break;
                    }
                }
                if (flag==2){//breaking from the 3 nested loops
                    break;
                }
            }
            if (flag==2){//breaking from the 3 nested loops
                break;
            }// else : continue taking turns between players
        }
        if (scrabble_numbers.size() == 0) {
            break;
        }
        cout << "========================================================" << endl;
        cout << "Player1 choose a number from this list: ";
        for (int num : scrabble_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
    if (flag == 1) {//checking winner
        cout << "Player1 is the winner" << endl;
        for (int num : player_1) {
            cout << num << " ";
        }
    } else if (flag == 2) {
        cout << "Player2 is the winner" << endl;
        for (int num : player_2) {
            cout << num << " ";
        }
    } else {
        cout << "Player1: ";
        for (int num : player_1) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Player2: ";
        for (int num : player_2) {
            cout << num << " ";
        }
        cout << endl;
        cout << "It is a draw. There is no winner." << endl;
    }
}
int main() {
    main_game();
    return 0;
}
