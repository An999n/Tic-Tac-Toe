# Title: Tic Tac Toe
## Video Demo:  https://www.youtube.com/watch?v=hvPlfAcfjxI
## Description: a Command line playing Tic Tac Toe with the user

## Functions:-
So.. It's buildid using 8 functions

### 1- print_board:
Function args (*board*)
Given the board as an argument & it'll just print it as 3x3 Grid in the terminal.
returning type ** Void **.
Just printing the board.


### 2- play:
Function args (*number* AKA Input, *board*, *player*)
It'll modify the cell number in the board to To 'O' or 'X' based on the player.
returning type ** char[3][3] **
return the ***board*** itself with the modification.


### 3- is_digit:
Function args (*number*)
It checks if the inputted value is a number between 1-9.
returning type ** bool **
return ***true*** if the number is between 1-9, or ***false*** if isn't.


### 4- validate_input:
Function args (*number*, *board*)
It checks if the inputted value is Entered before & inputted number is valid using ***is_digit*** function.
returning type ** bool **
return ***true*** if input is valid, or ***false*** if isn't.


### 5- remain_number:
Function args (*board*)
Checks the board to see how many Cells are left. we will need this later when using (***remain_char***).
returning type ** int **
returning the ***number*** of lefted Cells.

### 6- remain_char:
Function args (*board*, *number: remain_number*)
using ***remain_number*** as an argument to this function to allocate the length of returned string, it checks the values lifted & put it inside specific string.
returning type *** char[remain_number] ***
returning not used ***valus***.

### 7- check_winner:
Function args (*board*)
checking if there is some Pattern Vertically, Horizontally, Diagonally & pass it to ***winner*** function.
returning type *** bool ***
returning ***false*** if there is a Pattern & winner, or ***true*** if not.

### 8- winner:
Function args (*score_v*, *score_h*)
Using both *score_v*, *score_h* to determine the winner if there is & printing it's name.
returning type *** bool ***
returning ***true*** if there is a winner, or ***false*** if isn't.


## procedures:-

## 1- Initializing the board
-Creating the board itself ,Give it the Grid number's from 1 to 9.

## 2- Introduction to the game
-Printing a small Introduction & the board for visual understanding.

## 3- Initializing variables
-Assigning some variables that we going to use.

## 4- Start playing
-Start the game loop Until we found a winner or draw.
-The user will play first.
-Initializing Counter = 1 (Auto increment when someone play).

### User play
-This step happin if counter is even number.
-Taking the user input.
-Check if input is valid (repeat the process if not valid).

### PC play
-This step happin if counter is odd number.
-Check lefted values.
-Pick a random value from lefted values.

## 5-The Game interaction
-Change the board.
-Printing the modified board.
-Increment the counter.

## 6- Winner Checking
-Check if there is winner or Draw.
-Print the result then end the Game, or repeat starting from Step:4.

#### The End.
