# About my two Projects
## File Name : CS112_A1_T5&6_20230419.md
## Game : Scrubble Game & Twoo squares game
### Author : Malak Nour-Elhussien Samir
### ID : 20230419
#### Description for the first game : Each player picks a number between 1 and 9 and take turns ,the winner who reaches 15 first with sum of only 3 digits.
##### How to play scrubble game : 
1.Set a scrabble list between 1 and 9.

2. Check the validation of their inputs.
 
3. players take turns until one of them both has 3 distincit number their sum = 15.

4. if there wasn't any winner so it is a draw.

###### The Algorithm:
1. Print welcome and explain the game to the players.                                                                                                                                                                                                    
2. Set a scrabble list between 1 and 9.                                                                                                                                                                                                  
3. Check the validation of their inputs by:                                                                                                                                                                                                                     
3.1 setting 2 functions for the 2 players to check.                                                                                                                                                                    
3.2 check if the number is not on the list or has been removed.                                                                                                                                                                                                                      
3.3 check if the input was not a number like characters or special ones.                                                                                                                                                                                                                                                                                              
3.4 if any case from the previous happened, a message will be displayed to the player to enter a valid choice and ask again for input until it is okay.                                                                                                                                                                                                
3.5 if there is no problem with the input, insert the chosen numbers from each player in their own lists called player_1 [] &player_2[].                                                                                                                                                                                                            
4. Then, remove players’ inputs one by one from scrabble list as the number cannot be chosen twice.                                                                                                                                                                      
5. Players will take their first two numbers with no effort.                                                                                                                                                              
6. When the first player reaches 3 numbers in his own list we start to check if their sum = 15.                                                                                                                                                         
7. (we check the sum of every three different numbers only)

7.1 If their sum = 15; Finish the game and the first player is the winner.

7.2 If not; we allow second player to choose his third number and start to check the same way as the first player.       

7.3 Until the scrabble list is empty, there will be a draw If it’s got empty and there is no winner.
   
#### how to play two squares game:
==> each player choose two neighbours squares to make a triangle and the check if the last player's two square neighbours or not 
NOTE : i didn't make the program end before player 2 enters his last 2 choices ..it's ended when he enters them.
