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
private:
    pair<int, int> position;
    int perceptiveField;
    int stepWidth;
    enum Direction {NORTH, EAST, SOUTH, WEST} direction;
public:
    // Constructor
    Agent(int row, int col);
    
    // Getters
    pair<int, int> getPosition() const;
    int getPerceptiveField() const;
    int getStepWidth() const;
    Direction getDirection() const;

    // Setters
    void setPosition(int row, int col);
    void setPerceptiveField(int value);
    void setStepWidth(int value);
    void setDirectionFromKey(char key);


    // Methods
    void turnLeft();
    void turnRight();
    void move(); // Declaration for move method

};
