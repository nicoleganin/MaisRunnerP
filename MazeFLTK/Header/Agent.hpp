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
    // Enum for direction
    enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    // Constructor
    Agent(int row, int col);

    // Getters
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getPerceptiveField() const;
    int getStepWidth() const;
    int getEndGame() const;
    int getStepsTaken() const;

    // Setters
    void setPosition(int row, int col);
    void setDirection(Direction newDirection);
    void setPerceptiveField(int value);
    void setStepWidth(int value);
    void setEndGame(int value);
    void setStepsTaken(int value);

    // Methods
    void setDirectionFromKey(char input);
    void move(int* pointerValue);

private:
    std::pair<int, int> position;
    Direction direction;
    int perceptiveField;
    int stepWidth;
    int endGame;
    int stepsTaken;
};

