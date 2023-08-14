# Snakes_and_Ladders

The snakes and ladders repo is a simple build of snakes and ladders. 

Simple overview:
The program takes in 2 text files (included in the repo). Board.txt reads in the size of the board, then any snakes or ladders that are to be placed on the board.
Rules.txt includes the rules for the game. Players take it in turns to automatically move around a board until one player wins.

Board.txt
First value - Board size
Other values - start + end points of any movement on the board.

Rules.txt
First value - Players on the boar
Second value - Number of dice used
Third value - Game mode. 0 for normal rules (snakes and ladders, 100 and over = win) 1 for cruel (all snakes, exactly 100 = win. Over 100 = move back X spaces over)

Ensure when editing the files for play that it matches the above config, especially for Rules.txt
