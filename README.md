# Game Projects Portfolio

## Project 1: Scrubble Game
**File:** `CS112_A1_T5&6_20230419.md`  
**Author:** Malak Nour-Elhussien Samir  
**ID:** 20230419  

### Game Description
A mathematical strategy game where players compete to be the first to select 3 distinct numbers (1-9) that sum to 15.

### How to Play
1. Initialize a number pool of digits 1 through 9
2. Players alternate turns selecting numbers
3. Validate all inputs:
   - Must be an available number (1-9)
   - Cannot select previously chosen numbers
   - Must be numeric input
4. First player to collect any 3 numbers that sum to 15 wins
5. If all numbers are chosen without a winner, the game is a draw

### Game Algorithm 
1. Initialize scrabble list [1,2,3,4,5,6,7,8,9]
2. While numbers remain:
   a. Player 1 selects valid number
   b. Add to player_1 list
   c. Remove from scrabble list
   d. Check if player_1 has 3 numbers summing to 15
   e. Repeat for Player 2
3. If scrabble list empties without winner → Draw

## Project 2: Two Squares Game
**File:** `CS112_A1_T5&6_20230419.md`

### Game Description
A spatial strategy game where players connect adjacent squares to form triangles.

### How to Play
1. Players alternate selecting two adjacent squares
2. Each selection must:
   - Consist of neighboring squares
   - Not reuse previously selected pairs
3. Game continues until all possible moves are made
4. Final move determines the winner

### Current Implementation Notes
- Game concludes after Player 2's final move
- Adjacency validation is enforced
- End-game detection needs refinement

### Development Details
| Aspect               | Scrubble Game | Two Squares Game |
|----------------------|---------------|------------------|
| Input Validation     | ✓             | ✓                |
| Win Condition        | ✓             | Partial          |
| Draw Detection       | ✓             | ✗                |
| Turn Management      | ✓             | ✓                |
| End-Game Handling    | Complete      | Needs Improvement|
