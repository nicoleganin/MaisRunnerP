//
//  Agent.cpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//

#include "../Header/Agent.hpp"
#include "../Header/Maze.hpp"

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
    if (direction == NORTH) direction = WEST;
    else direction = static_cast<Direction>(direction - 1);
}

void Agent::turnRight() {
    if (direction == WEST) direction = NORTH;
    else direction = static_cast<Direction>(direction + 1);
}

void Agent::move(const Maze &maze) {
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

    // Check for walls and adjust position accordingly
    while (newRow >= 0 && newRow < 11 && newCol >= 0 && newCol < 11 && maze.getElementAtPosition(newRow, newCol) != 1) {
        // Adjust positions based on the agent's direction
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
    }

    // Update the agent's position if within bounds
    if (newRow >= 0 && newRow < 11 && newCol >= 0 && newCol < 11 &&
        maze.getElementAtPosition(newRow, newCol)) {
        position.first = newRow;
        position.second = newCol;
        maze.updateAgentPosition(position);
    }
    // Handle any out-of-bounds scenario if necessary
}
