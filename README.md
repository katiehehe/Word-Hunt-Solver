<H1> COP3530 - Project 3 - Word Hunt Solver </h1>
This is the instructions for running our project, Word Hunt Solver. It includes all the information for input and output, along with certain requirements.

### Requirements
- C++ Version of **11 or higher**
- Basic command-line usage

### words.txt Information
- `words.txt` serves as the word bank for the solver. It contains approximately **100,000 English words**, all of which are loaded into a **Trie data structure** at runtime.
- The solver will search the input grid for all valid words that also appear in `words.txt`.

### Instructions
1. Running the program will begin by asking the user to input the size of the square grid. The following input should consist of a positive integer which represents the number of rows(and similarly, columns) the square grid has.
2. Then, the program will ask the user to input the grid. The grid should be entered one line at a time, with each line representing a row of the grid. **There should be no extra whitespace between letters**. Additionally, **it does not matter if letters are uppercase or lowercase**. For example, when inputting a 4 by 4 grid, an example correct input is as following:
DONT
CARE
DONT
CARE

This will work as well:
dont
care
dont
care
4. Then, the program will output words found first by DFS and then the same words found with BFS. Finally, durations for both will print, and our program will terminate. Thus, using the program, a user will be able to find a solutions list based upon words both in words.txt and the grid.
