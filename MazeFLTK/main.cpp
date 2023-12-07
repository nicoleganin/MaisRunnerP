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
    
    // Initialize agent and maze
    Agent agent(0, 0);
    Maze myMaze;
    
    // Read string file
    string filename = "/Users/nicoleganin/Desktop/CSAI/Programming_with_C++/MazeFLTK/MazeFLTK/MazeGrid.json";
    myMaze.loadMaze(filename); // Load the maze from the file into a vector
    
    // Initialize gameplay
    initscr();
    noecho();             // Disable echoing of input
    curs_set(0);          // Hide cursor
    
    // Gameplay starts
    bool gameRunning = true;
    

    
    while (gameRunning) {
        clear();
        
        int gameRun = agent.getEndGame();
        int* gameRunPtr = &(gameRun); // Pointer to the endGame variable
                
        // Display agent in maze
        myMaze.playMaze(agent); // Display the maze
        printw("\n");
        printw("Enter a direction (W/A/S/D) to move the agent ('Q' to quit): \n");
        printw("Score: %d\n", agent.getStepsTaken());
        
        refresh();
        
        char input;
        cin >> input;
        
        // Press Q to quit the game
        if (input == 'Q' || input == 'q' || *gameRunPtr == 1) {
            gameRunning = false;
        } else {
            // If game is running, receive input and change and update agent position in maze
            agent.setDirectionFromKey(input);
            myMaze.playMaze(agent);
            

        }
    }

    // End gameplay mode
    endwin();

    return 0;
}
