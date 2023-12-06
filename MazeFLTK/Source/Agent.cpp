//
//  Agent.cpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//

#include "../Header/Agent.hpp"
//#include "../Header/Maze.hpp"

// Constructor
Agent::Agent(int row, int col)
    : position(row, col), perceptiveField(1), stepWidth(1), direction(EAST) {}

// Getters
std::pair<int, int> Agent::getPosition() const {
    return position;
}

int Agent::getPerceptiveField() const {
    return perceptiveField;
}

int Agent::getStepWidth() const {
    return stepWidth;
}

Agent::Direction Agent::getDirection() const {
    return direction;
}

// Setters
void Agent::setPosition(int row, int col) {
    position.first = row;
    position.second = col;
}

void Agent::setPerceptiveField(int value) {
    perceptiveField = value;
}

void Agent::setStepWidth(int value) {
    stepWidth = value;
}

// Methods
void Agent::turnLeft() {
    switch (direction) {
        case NORTH:
            direction = WEST;
            break;
        case EAST:
            direction = NORTH;
            break;
        case SOUTH:
            direction = EAST;
            break;
        case WEST:
            direction = SOUTH;
            break;
    }
}

void Agent::turnRight() {
    switch (direction) {
        case NORTH:
            direction = EAST;
            break;
        case EAST:
            direction = SOUTH;
            break;
        case SOUTH:
            direction = WEST;
            break;
        case WEST:
            direction = NORTH;
            break;
    }
}


void Agent::setDirectionFromKey(char input) {
    switch (input) {
        case 'W':
        case 'w':
            if (direction != SOUTH) {
                direction = NORTH;
            }
            break;
        case 'A':
        case 'a':
            if (direction != EAST) {
                direction = WEST;
            }
            break;
        case 'S':
        case 's':
            if (direction != NORTH) {
                direction = SOUTH;
            }
            break;
        case 'D':
        case 'd':
            if (direction != WEST) {
                direction = EAST;
            }
            break;
        //default:
            // Invalid input; do nothing or handle error
            //break;
    }
}


void Agent::move() {
    int newRow = position.first;
    int newCol = position.second;

    // Update positions based on the agent's direction
    switch (direction) {
        case NORTH:
            newRow--;
            break;
        case EAST:
            newCol++;
            break;
        case SOUTH:
            newRow++;
            break;
        case WEST:
            newCol--;
            break;
    }

    // Check if the new position is within bounds and not a wall (considering maze.getElementAtPosition())
    if (newRow >= 0 && newRow < 11 && newCol >= 0 && newCol < 11) {
        //if () {
            position.first = newRow;
            position.second = newCol;
            // Update the agent's position in the maze using maze.updateAgentPosition(position);
            //}
    }
        // Handle any out-of-bounds scenario if necessary
    }
