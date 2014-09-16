#include "Character.h"

#include <pm/PacDots.h>
using namespace PacDots;

using namespace std;

Character::Character(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(dest, renderer, sprite),
      _initialRow( dest["row"] ), _initialCol( dest["col"] ), _stepCounter(0),
      _goTo(-1), _back(false), _spriteFlag(-1),
      _velocity(1), _velocityX(0), _velocityY(0), _dead(false) {

    // Initialize positions on the screen
    int x = dest["col"] * 30 + AREAGAME_MARGIN;
    int y = dest["row"] * 30 + AREATOP_HEIGHT;
    initRect(&_position, 30, 30, x, y);

    _initialStateDest["x"] = dest["col"] * 30 + AREAGAME_MARGIN;
    _initialStateDest["y"] = dest["row"] * 30 + AREATOP_HEIGHT;

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
        // AND can move to up
        if( up && _directionsPossible[UP] ) {

            // Update position
            _position.y += _velocityY;

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                setStepCounter(UP, DOWN);

            }

            // If the character is centered in the square
            // AND can move up
            else if( _stepCounter == 0 ) {

                _goTo = UP;
                _stepCounter++;

            }

            return true;

        }
        // Else if move down
        // AND can move to down
        else if( !up && _directionsPossible[DOWN] ) {

            // Update position
            _position.y += _velocityY;

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                setStepCounter(DOWN, UP);

            }

            // If the character is centered in the square
            // AND can move down
            else if( _stepCounter == 0 ) {

                _goTo = DOWN;
                _stepCounter++;

            }

            return true;

        }

    }

    return false;

}

bool Character::moveHorizontally(bool left) {

    // Check if the character doesn't move in this two directions
    // If he moves for just 1 only pixel (left or right) > block this two directions
    if( _goTo != UP && _goTo != DOWN ) {

        // If move left
        // AND can move to the left
        if( left && _directionsPossible[LEFT] ) {

            // Update position
            _position.x += _velocityX;

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                setStepCounter(LEFT, RIGHT);

            }

            // If the character is centered in the square
            else if( _stepCounter == 0 ) {

                _goTo = LEFT;
                _stepCounter++;

            }

            return true;

        }
        // Else if move right
        // AND can move to the right
        else if( !left && _directionsPossible[RIGHT] ) {

            // Update position
            _position.x += _velocityX;

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                setStepCounter(RIGHT, LEFT);

            }

            // If the character is centered in the square
            // AND can move to the right
            else if( _stepCounter == 0 ) {

                _goTo = RIGHT;
                _stepCounter++;

            }

            return true;

        }

    }

    return false;

}

void Character::defaultValues() {

    resetValues();

    _col = _initialCol;
    _row = _initialRow;

    initRect( &_selection, 16, 20, _initialStateSrc["x"], _initialStateSrc["y"] );

    initRect( &_position, _position.w, _position.h, _initialStateDest["x"], _initialStateDest["y"] );

    _dead = false;

}

void Character::calculateDirection(vector<vector<int> > levelTable) {

    if(!_back) {

        // Check if the next positions are runnable by the character
        _directionsPossible[UP] = ( levelTable[_row-1][_col] <= PACDOTS_PATH ) ? true : false;
        _directionsPossible[DOWN] = ( levelTable[_row+1][_col] <= PACDOTS_PATH ) ? true : false;
        _directionsPossible[RIGHT] = ( levelTable[_row][_col+1] <= PACDOTS_PATH ) ? true : false;
        _directionsPossible[LEFT] = ( levelTable[_row][_col-1] <= PACDOTS_PATH ) ? true : false;

    }

}

bool Character::isCenteredInTheSquare() {

    // If the character is centered
    if( _stepCounter == 30 || (_back && _stepCounter == 0 ) ) {

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

void Character::updatePositionInTheGrid() {

    // If the character is not returned to his start point
    // If it is => no update for the coord
    if( !_back ) {

        // Update the x and y position in the grid
        switch(_goTo) {

        case UP:
            _row--;
            break;
        case DOWN:
            _row++;
            break;
        case RIGHT:
            _col++;
            break;
        case LEFT:
            _col--;
            break;
        }

    }

}

void Character::resetValues() {

    // If the character is returned to his start point
    if(_back) _back = false;

    // If the character is in the center of a square,
    // We reset the counter
    _stepCounter = 0;

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

        // Load new x and y
        initRect( &_selection, _selection.w, _selection.h, _spriteCoord[direction][_spriteFlag][0], _spriteCoord[direction][_spriteFlag][1] );

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

bool Character::isEatable() const {

    return _eatable;

}

void Character::setEatable() {

    _eatable = !_eatable;

}

void Character::setEatable( bool eatable ) {

    _eatable = eatable;

}
