#include "Character.h"

using namespace std;

Character::Character(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(dest, renderer, sprite),
      _x( dest["x"] ), _y( dest["y"] ), _stepCounter(3), _offset(0), _offsetV(0), _offsetH(0),
      _goTo(-1), _back(false), _spriteFlag(-1), _velocity(1), _dead(false) {

    // Init the possible directions for the character
    _directionsPossible.push_back(false);
    _directionsPossible.push_back(false);
    _directionsPossible.push_back(false);
    _directionsPossible.push_back(false);

}

bool Character::moveVertically(bool up) {

    // Check if the character doesn't move in this two directions
    // If he moves for just 1 only pixel (up or down) > block this two directions
    if( _goTo != LEFT && _goTo != RIGHT ) {

        // If move up
        if( up ) {

            // If the character is not centered in the square
            if( _stepCounter > 3 ) {

                _position.y -= _velocity;
                setStepCounter(UP, DOWN);

            }

            // If the character is centered in the square
            // AND can move up
            else if( _stepCounter == 3 && _directionsPossible[UP] ) {

                _position.y -= _velocity;
                _goTo = UP;
                _stepCounter++;
                _offset = _offsetV;

            }

        }
        // Else if move down
        else if( !up ) {

            // If the character is not centered in the square
            if( _stepCounter > 3 ) {

                _position.y += _velocity;
                setStepCounter(DOWN, UP);

            }

            // If the character is centered in the square
            // AND can move down
            else if( _stepCounter == 3 && _directionsPossible[DOWN] ) {

                _position.y += _velocity;
                _goTo = DOWN;
                _stepCounter++;
                _offset = _offsetV;

            }

        }

        return true;

    }

    return false;

}

bool Character::moveHorizontally(bool left) {

    // Check if the character doesn't move in this two directions
    // If he moves for just 1 only pixel (left or right) > block this two directions
    if( _goTo != UP && _goTo != DOWN ) {

        // If move left
        if( left ) {

            // If the character is not centered in the square
            if( _stepCounter > 3 ) {

                _position.x -= _velocity;
                setStepCounter(LEFT, RIGHT);

            }

            // If the character is centered in the square
            // AND can move to the left
            else if( _stepCounter == 3 && _directionsPossible[LEFT] ) {

                _position.x -= _velocity;
                _goTo = LEFT;
                _stepCounter++;
                _offset = _offsetH;

            }

        }
        // Else if move right
        else if( !left ) {

            // If the character is not centered in the square
            if( _stepCounter > 3 ) {

                _position.x += _velocity;
                setStepCounter(RIGHT, LEFT);

            }

            // If the character is centered in the square
            // AND can move to the right
            else if( _stepCounter == 3 && _directionsPossible[RIGHT] ) {

                _position.x += _velocity;
                _goTo = RIGHT;
                _stepCounter++;
                _offset = _offsetH;

            }

        }

        return true;

    }

    return false;

}

void Character::defaultValues() {

    resetValues();

    _x = _initialX;
    _y = _initialY;

    _selection.x = _initialStateSrc["x"];
    _selection.y = _initialStateSrc["y"];
    _selection.w = 16;
    _selection.h = 20;

    _position.x = _initialStateDest["x"];
    _position.y = _initialStateDest["y"];

    _offset = 0;
    _offsetV = 0;
    _offsetH = 0;

    _dead = false;

}

void Character::calculateDirection(vector<vector<int> > levelTable) {

    if(!_back) {

        // Check if the next positions are runnable by the character
        _directionsPossible[UP] = ( levelTable[_y-1][_x] < 0 ) ? true : false;
        _directionsPossible[DOWN] = ( levelTable[_y+1][_x] < 0 ) ? true : false;
        _directionsPossible[RIGHT] = ( levelTable[_y][_x+1] < 0 ) ? true : false;
        _directionsPossible[LEFT] = ( levelTable[_y][_x-1] < 0 ) ? true : false;

    }

}

bool Character::isCenteredInTheSquare() {

    // If the character is centered
    if( _stepCounter == 33 - _offset || (_back && _stepCounter == 3 - _offset ) ) {

        return true;

    }

    return false;

}

void Character::setStepCounter(int direction1, int direction2) {

    if( _goTo == direction1 ) {
        _stepCounter++;
        _back = false;
    }
    else if(_goTo == direction2 ) {
        _stepCounter--;
        _back = true;
    }

}

void Character::calculateOffset(bool direction) {

    int value = (_back) ? 3 : 33;

    // Calculate vertical offset
    if(direction) {

        _offsetV = _stepCounter - value + _offsetV;

    }
    // Calculate horizontal offset
    else if(!direction) {

        _offsetH = _stepCounter - value + _offsetH;

    }

}

void Character::updatePositionInTheGrid() {

    // If the character is not returned to his start point
    // If it is => no update for the coord
    if( !_back ) {

        // Update the x and y position in the grid
        switch(_goTo) {

        case UP:
            _y--;
            break;
        case DOWN:
            _y++;
            break;
        case RIGHT:
            _x++;
            break;
        case LEFT:
            _x--;
            break;
        }

    }

}

void Character::resetValues() {

    // If the character is returned to his start point
    if(_back) _back = false;

    // If the character is in the center of a square,
    // We reset the counter
    _stepCounter = 3;

    // Reset goTo because the user has not choose a direction yet
    _goTo = -1;

}

void Character::nextSprite(int direction) {

    if( _stepCounter % 5 == 0 ) {

        // The character's animation has two parts
        // 0 = first part
        // 1 = second part
        if( _spriteFlag < _spriteCoord[direction].size() - 1 ) _spriteFlag++;
        else _spriteFlag = 0;

        // Load new x
        _selection.x = _spriteCoord[direction][_spriteFlag][0];
        // Load new y
        _selection.y = _spriteCoord[direction][_spriteFlag][1];

    }

}

bool Character::checkCollision( InteractiveElement* const& element ) const {

    if( (_position.x >= element->getPosition().x - 15
            && _position.x <= element->getPosition().x + 15)
         && (_position.y >= element->getPosition().y - 15
                && _position.y <= element->getPosition().y + 15) )  {

        // Collision detected
        return true;

    }

    return false;

}

bool Character::isDead() const {

    return _dead;

}

void Character::setDead() {

    _dead = !_dead;

}