//
//  Agent.cpp
//  MazeFLTK
//
//  Created by Nicole Ganin on 04/12/2023.
//

#include "../Header/Agent.hpp"

// Constructor
Agent::Agent(int row, int col)
: position(row, col), perceptiveField(1), stepWidth(1) {}

// Getters
std::pair<int, int> Agent::getPosition() const {
    return position;
}

Agent::Direction Agent::getDirection() const {
    return direction;
}

int Agent::getPerceptiveField() const {
    return perceptiveField;
}

int Agent::getStepWidth() const {
    return stepWidth;
}


// Setters
void Agent::setPosition(int row, int col) {
        position.first = row;
        position.second = col;
}

void Agent::setDirection(Direction newDirection) {
    direction = newDirection; // Set direction from four possible values it can take
}

void Agent::setPerceptiveField(int value) {
    perceptiveField = value;
}

void Agent::setStepWidth(int value) {
    stepWidth = value;
}

void Agent::setDirectionFromKey(char input) {
    // Get the current agent direction
    Direction currentDirection = getDirection();

    switch (input) {
        case 'W':
        case 'w': // If you input W (North)
            if (currentDirection != SOUTH) { // And you direction is not South
                setDirection(NORTH); // Turn 90 degrees up / North or remain direction
            }
            break;
        case 'A':
        case 'a': // If input A (West)
            if (currentDirection != EAST) { // And you're not turned backward (East in this case)
                setDirection(WEST); // Turn 90 degrees West or remain direction
            }
            break;
        case 'S':
        case 's': // If input S (South)
            if (currentDirection != NORTH) { // And you're not turned backward (North in this case)
                setDirection(SOUTH); // Turn 90 degrees to the South or remain direction
            }
            break;
        case 'D':
        case 'd': // If input D (East)
            if (currentDirection != WEST) { // And you're not turned backward (West in this case)
                setDirection(EAST); // Turn 90 degrees East or remain direction
            }
            break;
        default: // Invalid input; do nothing
            setDirection(currentDirection); // Remain direction if you pressed an opposite key
    }
}


void Agent::move(int* pointerValue) {
    pair<int, int> agentPos = getPosition(); // Get agent coordinates on maze
    
    // Creating pointers to agentPos.first and agentPos.second
    int* ptrAgentRow = &(agentPos.first);
    int* ptrAgentCol = &(agentPos.second);

    int newRow = *ptrAgentRow; // Assigning value using pointer
    int newCol = *ptrAgentCol; // Assigning value using pointer
    
    // We use pointers to not change the position directly if the move is not valid (it's a wall for instance).

    // Update positions based on the agent's direction and stepwidth
    switch (direction) {
        case NORTH:
            newRow -= stepWidth;
            break;
        case EAST:
            newCol += stepWidth;
            break;
        case SOUTH:
            newRow += stepWidth;
            break;
        case WEST:
            newCol -= stepWidth;
            break;
    }

    // Check if the new position is within bounds of the maze and if the position is not a wall (1)
    bool isValidMove = (newRow >= 0 && newRow < 11 && newCol >= 0 && newCol < 11 && *pointerValue != 1);

    if (isValidMove) {
        // Store the new position in temporary variables
        int tempRow = newRow;
        int tempCol = newCol;

        // Check for pointer values and update agent properties accordingly
        switch (*pointerValue) {
            case 4: // Goggles
                if (perceptiveField < 3) { // Max. view of 3
                    perceptiveField += 1; // Min. view of 1
                }
                break;
            case 6: // Fog
                if (perceptiveField > 1) { // Min. view of 1
                    perceptiveField -= 1; // Min. view of 1
                }
                break;
            case 5: // Speed potion
                if (stepWidth < 3) { // Max. range of 3
                    stepWidth += 1; // Min. range of 1
                }
                break;
            case 7: // Slow potion
                if (stepWidth > 1) { // Max. range of 3
                    stepWidth -= 1; // Min. range of 1
                }
                break;
            default:
                break;
        }

        // Update the agent's position only if the move is valid
        setPosition(tempRow, tempCol);

    } else {
        // Handle invalid move: Do not change position or direction
    }
}
