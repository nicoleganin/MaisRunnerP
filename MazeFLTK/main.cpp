//
//  main.cpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 27/11/2023.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Header/Maze.hpp"
#include "Header/Agent.hpp"
#include <curses.h>
#define BOARD_DIM 11

using namespace std;


int main() {
    
    Agent agent (0,0);
    Maze myMaze;

    std::string filename = "/Users/nicoleganin/Desktop/CSAI/Programming_with_C++/MazeFLTK/MazeFLTK/MazeGrid.json";

    myMaze.loadMaze(filename); // Load the maze from the file into a vector
    
    // Initialize curses
    initscr();
    //keypad(stdscr, TRUE); // Enable keypad for arrow keys
    noecho();             // Disable echoing of input
    curs_set(0);          // Hide cursor

     
    bool gameRunning = true;
    
     
     while (gameRunning) {
         clear();
                  
         myMaze.displayMaze(agent); // Display the maze
         printw("Enter a direction (W/A/S/D) to move the agent ('Q' to quit): \n");

         
         refresh();
         
         char input;
         cin >> input;

         if (input == 'Q' || input == 'q') {
             gameRunning = false;
         } else {
             agent.setDirectionFromKey(input); // Set agent's direction based on key input
             agent.move(); // Move the agent based on the direction
         }
     }

     // End curses mode
     endwin();

     return 0;
 }
