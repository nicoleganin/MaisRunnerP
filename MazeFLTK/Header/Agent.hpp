//
//  Agent.hpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//

#pragma once
#include <iostream>
#include <vector>
#include <curses.h>
//#include "Maze.hpp"

using namespace std;

class Agent {
public:
    // Constructor
    Agent(int row, int col);

    // Getters
    std::pair<int, int> getPosition() const; // Get coordinates of agent position
    enum Direction { NORTH, SOUTH, EAST, WEST }; // List of possible diretions agent is facing

    int getPerceptiveField() const; // Get the range of cells agent can view
    int getStepWidth() const; // Get amount of steps agent takes within one move
    //int getCell(int row, int col) const;
    Direction getDirection() const; // Get direction agent faces

    
    // Setters
    void setPosition(int row, int col); // Set coordinates of the agent position
    void setDirection(Direction newDirection); // Set direction agent faces
    void setPerceptiveField(int value); // Set range of blocks agent can view
    void setStepWidth(int value); // Set amount of steps agent can take within one move
    void setDirectionFromKey(char key); // Set direction agent is facing based on keybaord input

    // Methods
    void move(int* pointerValue); // Move agent towards a direction based on direction. Needs a input value, this is the cell value it is positioned at
    
private:
    std::pair<int, int> position;
    std::pair<int, int> nextPosition;
    int perceptiveField;
    int stepWidth;
    Direction direction;
    
};
