//
//  Maze.hpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//
#pragma once

#include <vector>
#include <string>
#include "Agent.hpp"

using namespace std;

class Maze {
public:
    Maze();
    // Load maze file
    vector<std::vector<int>> loadMaze(const string& filename);
    
    // Display agent in maze
    void playMaze(Agent& agent);
    // Display maze without agent
    void displayMaze();

private:
    std::vector<std::vector<int>> maze;
    std::pair<int, int> agentPosition;

};
