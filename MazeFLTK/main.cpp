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

using namespace std;


int main() {
    
    Agent agent (0,0);
    Maze myMaze;

    std::string filename = "/Users/nicoleganin/Desktop/CSAI/Programming_with_C++/MazeFLTK/MazeFLTK/MazeGrid.json";

    myMaze.loadMaze(filename); // Load the maze from the file into a vector
    
    // Initialize curses
    initscr();
    keypad(stdscr, TRUE); // Enable keypad for arrow keys
    noecho(); // Don't echo user input to the screen
    curs_set(0); // Hide the cursor

    
    bool gameRunning = true;
    
    while (gameRunning) {
        myMaze.displayMaze(); // Display the maze
        refresh();
        int input = getch(); // Get the pressed key
        agent.getPosition(); // Set agent's direction based on key input
        agent.move(myMaze); // Move the agent based on the direction

        // Redraw the maze after the agent's movement
        clear(); // Clear the screen
        myMaze.displayMaze(agent); // Display the maze with updated agent position
        refresh(); // Refresh the screen
    }

    // End curses mode
    endwin();

    return 0;
}
