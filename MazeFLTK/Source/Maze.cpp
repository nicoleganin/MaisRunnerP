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
vector<vector<int>> Maze::loadMaze(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open the file!" << endl;
        return maze;
    }

    string line;
    int row_number = 0;
    while (getline(infile, line)) {
        vector<int> row;
        int count = 0;

        for (char i : line) {
            if (isdigit(i)) {
                int val = i - '0';
                row.push_back(val);
                
                
                count++;

                if (count == 11) {
                    maze.push_back(row);
                    row_number++;
                    count = 0;
                    row.clear();
                }
            }
        }
    }
    infile.close();
    return maze;
}

int Maze::getElementAtPosition(int row, int col) const {
    if (row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size()) {
        return maze[row][col];
    }
    // Return a default value or handle out-of-bounds access as needed
    return -1;
}

void Maze::updateAgentPosition(const pair<int, int>& newPosition) const {
    
}
    
void Maze::displayMaze()  {
    for (size_t i = 0; i < maze.size(); ++i) {
        for (int cell : maze[i]) {
            if (cell == 2) {
                if (i== agentPos.first && cell == agentPos.second) {
                    //updateAgentPosition(agentPosition);
                    cout << "A ";  // Display 'A' for the agent's position
                }
            } else {
                cout << cell << " ";
            }
        }
        cout << "\n";
        }
    }
