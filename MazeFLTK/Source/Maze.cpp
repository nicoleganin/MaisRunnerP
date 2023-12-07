//
//  Maze.cpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//

#include "../Header/Maze.hpp"
#include "../Header/Agent.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Maze::Maze() {

}
// Open the file
vector<vector<int>> Maze::loadMaze(const string& filename) {
    ifstream infile(filename); //
    if (!infile.is_open()) {
        cerr << "Failed to open the file!" << endl;
        return maze;
    }

// Loop through lines of the file
    string line;
    int row_number = 0;
    while (getline(infile, line)) {
        vector<int> row;
        int count = 0; // Keep track of the loops / amount of rows

        for (char i : line) {
            if (isdigit(i)) {
                int val = i - '0'; // If the character in the file is a digit
                row.push_back(val); // Add value to the row of the maze
                
                
                count++;

                if (count == 11) { // If the row is filled
                    maze.push_back(row); // Add row into maze
                    row_number++; // Go to next row of maze
                    count = 0;
                    row.clear();
                }
            }
        }
    }
    infile.close();
    return maze;
}


// Display maze without agent if needed (So you can see the entire maze)
void Maze::displayMaze() {
    for (size_t i = 0; i < maze.size(); ++i) {
        for (int cell : maze[i]) {
                cout << cell << " ";
            }
        }
        cout << "\n";
    }

// Display maze with agent. Here, the maze is only displayed partially (depending on perceptive field)
void Maze::playMaze(Agent &agent) {
    // Get perceptive field
    int perceptualField = agent.getPerceptiveField();
    // Get initial agent position
    pair<int, int> agentPos = agent.getPosition();

    // Determine the bounds of the field around the agent
    int minRow = max(agentPos.first - perceptualField, 0);
    int maxRow = min(agentPos.first + perceptualField, static_cast<int>(maze.size()) - 1);
    int minCol = max(agentPos.second - perceptualField, 0);
    int maxCol = min(agentPos.second + perceptualField, static_cast<int>(maze[0].size()) - 1);

    // Display maze in agent view within the bounds of the maze
    for (int i = max(0, minRow); i <= min(11, maxRow); ++i) {
        for (int j = max(0, minCol); j <= min(11, maxCol); ++j) {
            
            // Get cell values from the loop
            int cellValue = maze[i][j]; // Get cell value from coordinates

            // Calculate the coordinates of the maze values for the game window
            int x = j; // Cast size_t to int
            int y = i; // Cast size_t to int

            // Print maze in game window
            if (i == agentPos.first && j == agentPos.second) {
                mvprintw(y, x, "A");
            } else {
                mvprintw(y, x, "%d ", cellValue);
            }
        }
        cout << "\n";
    }

    // Communicate the value agent is taking at its coordinates. Give it as input to the agent using a pointer, to not include the class completely
    int cellValueAtCurPos = maze[agentPos.first][agentPos.second];
    agent.move(&cellValueAtCurPos);
    
}

