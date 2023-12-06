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
    vector<std::vector<int>> loadMaze(const string& filename);
    int getElementAtPosition(int row, int col) const;
    void displayMaze(Agent& agent);
    void updateAgentPosition(const std::pair<int, int>& newPosition) const;

    
private:
    std::vector<std::vector<int>> maze;
    std::pair<int, int> agentPosition;
};
