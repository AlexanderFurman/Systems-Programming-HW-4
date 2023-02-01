<!-- # Systems-Programming-HW-4

basic version of munchkin card game,
implementation includes classes, inheritance, unique and shared pointers, and exceptions.
use of abstract classes and virtual functions.






 -->
# Custom Implementation of Munchkin Card Game
This project implements a card game similar to Munchkin, that combines elements of role-playing games with traditional card game mechanics. Players take on the role of characters that try to level up and defeat monsters. 

## Implementation Includes

- Classes
- Inheritance
- Unique and Shared Pointers
- Exception Handling
- Abstract Classes
- Virtual Functions

## Usage
Start by compiling the code by running the following in the terminal:
Run the following in the terminal:
```bash
g++ --std=c++11 -o mtmchkin -Wall -pedantic-errors -Werror
-DNDEBUG *.cpp Cards/*.cpp Players/*.cpp 
```
To begin the game, run the following:
```bash
./mtmchkin
```
The terminal will prompt for the number of users (2-6). After this is entered, the terminal will also ask for the players' names and player-types. This should be entered for each player as follows:
```bash
<name> <player-type>
```

```<name>``` - any english name, no spaces, 15 characters or under.

```<player-type>``` - players may choose ```Ninja```, ```Warrior```, or ```Healer```. These player-types all have their own advantages during the game.
