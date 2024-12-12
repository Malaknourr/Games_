# File:CS112_A1_T2_2_20230419.py.
# Purpose:Each player picks a number between 1 and 9 and take turns ,the winner who reaches 15 first.
# author: Malak NourElhussien Samir Ali
# ID: 20230419
scrabble_numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
player_1 = []
player_2 = []
def player1():
    global elements1
    flag1 = True
    while flag1:  # check the vaildation of the numbers of player1
        try:
            elements1 = int(input("Player1 : Enter your number "))
            if elements1 not in scrabble_numbers: #limit user input between 1 and 9
                print("Unfound Number , please enter a valid number ")
                flag1 = True
            else:
                break
        except:
            print("Please enter a valid number")
            return player1()    #take input again until it is valid
    return elements1
def player2():
    global elements2
    flag2 = True
    while flag2:             # check the validation of the numbers of player2
        try:
            elements2 = int(input("Player2 : Enter your number "))
            if elements2 not in scrabble_numbers:
                print("Unfound Number , please enter a valid number ")
                flag2 = True
            else:
                break
        except:
            print("Please enter a valid number")
            return player2()
    return elements2

def main():
 print("____________________________________________________________________________________________________")
 print("Welcome to scrabble game , Each player takes a number from this list", scrabble_numbers)
 print("Numbers cannot be chosen twice , The one who has only 3 numbers their sum = 15 first , is the winner")
 print("____________________________________________________________________________________________________")
 flag = 0
 while len(scrabble_numbers) > 0:
    flag = 0
    elements1 = player1()
    player_1.append(elements1)
    scrabble_numbers.remove(elements1)             #removes inputs as it cannot be choosen twice
    if len(player_1) >= 3:                         # check the sum of diffrent 3 numbers
        for i in range(len(player_1)):
            for j in range(len(player_1)):
                for k in range(len(player_1)):
                    if player_1[i] != player_1[j] and player_1[j] != player_1[k] and player_1[k] != player_1[i]:
                        if player_1[i] + player_1[j] + player_1[k] == 15:
                            flag = 1
                            break
                if flag == 1:   #allowing the player to choose another number even if he picked 3 numbers , if needed
                 break
            if flag ==1:
             break
        if flag ==1:
           break
    if len(scrabble_numbers) == 0:
        break
    print("========================================================")
    print("Player2 choose a number from this list", scrabble_numbers)
    elements2 = player2()
    player_2.append(elements2)
    scrabble_numbers.remove(elements2)
    if len(player_2) >= 3:  # check the sum of diffrent 3 numbers
        for i in range(len(player_2)):
            for j in range(len(player_2)):
                for k in range(len(player_2)):
                    if player_2[i] != player_2[j] and player_2[j] != player_2[k] and player_2[k] != player_2[i]:
                        if player_2[i] + player_2[j] + player_2[k] == 15:
                            flag = 2
                            break
                if flag == 2:  #allowing the player to choose another number even if he picked 3 numbers , if needed
                    break
            if flag == 2:
                break
        if flag == 2:
            break
    print("========================================================")
    print("Player1 choose a number from this list", scrabble_numbers)
    if len(scrabble_numbers) == 0:
        break

 if flag == 1:
    print("Player1 is the winner",player_1)
 elif flag == 2:
    print("Player2 is the winner",player_2)
 else:
    print("Player1: ",player_1,'\n',"player2: ",player_2,'\n'+"It is a draw , There is no winner")

main()