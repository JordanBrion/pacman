#include "Character.h"

#include <pm/PacDots.h>
using namespace PacDots;
#include <pm/Directions.h>
using namespace Directions;

using namespace std;

Character::Character(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(dest, renderer, sprite),
      _initialRow( dest["row"] ),
      _initialCol( dest["col"] ),
      _step( -1 ),
      _stepCounter( 0 ),
      _goTo( -1 ),
      _goToBackUp( -1 ),
      _back( false ),
      _spriteFlag( 1 ),
      _velocity( 1 ),
      _velocityX( 0 ),
      _velocityY( 0 ),
      _dead( false ) {

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

bool Character::moveVertically( bool up ) {

    // Check if the character doesn't move in this two directions
    // If he moves for just 1 only pixel (up or down) > block these two directions
    if( _goTo != LEFT && _goTo != RIGHT ) {

        // If move up
        if( up ) {

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                // Update position
                _position.y += _velocityY;

                setStepCounter(UP, DOWN);

                return true;

            }

            // If the character is centered in the square
            // AND can move up
            else if( _stepCounter == 0 && _directionsPossible[UP] ) {

                // Update position
                _position.y += _velocityY;

                _goTo = UP;
                _stepCounter++;

                return true;

            }

        }

        // Else if move down
        else if( !up ) {

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                // Update position
                _position.y += _velocityY;

                setStepCounter(DOWN, UP);

                return true;

            }

            // If the character is centered in the square
            // AND can move down
            else if( _stepCounter == 0 && _directionsPossible[DOWN] ) {

                // Update position
                _position.y += _velocityY;

                _goTo = DOWN;
                _stepCounter++;

                return true;

            }

        }

    }

    else
        cout << "Impossible move: the character is already moving to LEFT or RIGHT " << endl;

    return false;

}

bool Character::moveHorizontally(bool left) {

    // Check if the character doesn't move in this two directions
    // If he moves for just 1 only pixel (left or right) > block this two directions
    if( _goTo != UP && _goTo != DOWN ) {

        // If move left
        if( left ) {

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                // Update position
                _position.x += _velocityX;

                setStepCounter(LEFT, RIGHT);

                return true;

            }

            // If the character is centered in the square
            // AND can move to the left
            else if( _stepCounter == 0 && _directionsPossible[LEFT] ) {

                // Update position
                _position.x += _velocityX;

                _goTo = LEFT;
                _stepCounter++;

                return true;

            }

        }

        // Else if move right
        else if( !left  ) {

            // If the character is not centered in the square
            if( _stepCounter > 0 ) {

                // Update position
                _position.x += _velocityX;

                setStepCounter(RIGHT, LEFT);

                return true;

            }

            // If the character is centered in the square
            // AND can move to the right
            else if( _stepCounter == 0 && _directionsPossible[RIGHT] ) {

                // Update position
                _position.x += _velocityX;

                _goTo = RIGHT;
                _stepCounter++;

                return true;

            }

        }

    }

    else
        cout << "Impossible move: the character is already moving to UP or DOWN" << endl;

    return false;

}

void Character::startValues() {

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
        // AND check if we are not at out of range of the grid

        _directionsPossible[UP] = ( _row-1 > -1 && levelTable[_row-1][_col] <= PACDOTS_PATH  ) ? true : false;
        _directionsPossible[DOWN] = ( _row+1 < levelTable.size() && levelTable[_row+1][_col] <= PACDOTS_PATH ) ? true : false;
        _directionsPossible[RIGHT] = ( _col+1 < levelTable[0].size() && levelTable[_row][_col+1] <= PACDOTS_PATH ) ? true : false;
        _directionsPossible[LEFT] = ( _col-1 > -1 && levelTable[_row][_col-1] <= PACDOTS_PATH ) ? true : false;

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

vector<int> Character::checkTeleportation( map<string, vector<int> > teleportationLocationsCoord ) {

    vector<int> location;

    for( map<string, vector<int> >::iterator it = teleportationLocationsCoord.begin();
         it != teleportationLocationsCoord.end();
         ++it ) {

        location = it->second;

        if( location[0] == _row && location[1] == _col ) {

            string key = to_string( _row ) + "_" + to_string( _col );
            return teleportationLocationsCoord[ key ];

        }

        // Clear the vector for the return value
        location.clear();

    }

    return location;

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
    _goToBackUp = _goTo;
    _goTo = -1;

}

int Character::move() {

    bool vertical = isStepVertical();
    bool horizontal = isStepHorizontal();

    // Check if the previous direction ( before the reset ) is a vertical direction
    if( _goToBackUp == UP || _goToBackUp == DOWN ) {

        // First we check if the user is holding LEFT or RIGHT
        // If yes, We move in one of these directions first
        // => That way the player can press two key together
        if( horizontal && moveHorizontally( isStepLeft() ) ) {

            _goToBackUp = -1;
            return _step = ( isStepLeft() ) ? LEFT : RIGHT;

        }

        else if( vertical && moveVertically( isStepUp() ) ) {

            _goToBackUp = -1;
            return _step = ( isStepUp() ) ? UP : DOWN;

        }

    }

    // Check if the previous direction ( before the reset ) is an horizontal direction
    else if( _goToBackUp == LEFT || _goToBackUp == RIGHT ) {

        // First we check if the user is holding UP or DOWN
        // If yes, We move in one of these directions first
        // => That way the player can press two key together
        if( vertical && moveVertically( isStepUp() ) ) {

            _goToBackUp = -1;
            return _step = ( isStepUp() ) ? UP : DOWN;

        }

        else if( horizontal && moveHorizontally( isStepLeft() ) ) {

            _goToBackUp = -1;
            return _step = ( isStepLeft() ) ? LEFT : RIGHT;

        }

    }

    // Default behavior
    else {

        // Not else because the user can hold for example UP and LEFT, or DOWN and RIGHT
        // So we need to move vertically AND horizontally !
        // The authorized moves are checked in the methods

        if( vertical && moveVertically( isStepUp() )) {
            return _step = ( isStepUp() ) ? UP : DOWN;
        }

        if( horizontal && moveHorizontally( isStepLeft() ) ) {
            return _step = ( isStepLeft() ) ? LEFT : RIGHT;
        }

    }

    // No move
    return -1;

}

bool Character::isStepVertical() const {

    return ( _velocityY != 0 );

}

bool Character::isStepHorizontal() const {

    return ( _velocityX != 0 );

}

bool Character::isStepUp() const {

    return ( _velocityY < 0 );

}

bool Character::isStepDown() const {

    return ( _velocityY > 0 );

}

bool Character::isStepLeft() const {

    return ( _velocityX < 0 );

}

bool Character::isStepRight() const {

    return ( _velocityX > 0 );

}

void Character::nextSprite() {

    if( _step != -1 && _stepCounter % 5 == 0 ) {

        // The character's animation has two parts
        // 0 = first part
        // 1 = second part
        if( _spriteFlag < _spriteCoord[ _step ].size() - 1 ) _spriteFlag++;
        else _spriteFlag = 0;

        // Load new x and y
        initRect( &_selection,
                  _selection.w,
                  _selection.h,
                  _spriteCoord[_step][_spriteFlag][0],
                  _spriteCoord[_step][_spriteFlag][1] );

    }

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

void Character::teleport( vector<int> to, vector<vector<int> > levelTable ) {

    // Position in the grid
    _row = to[0];
    _col = to[1];

    // In case pacman turns back after a teleportation
    // Without this, impossible to calculate the new possible direction in Character::calculateDirection()
    _back = false;

    // Put stepCounter to 5 => Character is not centered in the square after the teleportation. We consider he made a 5-pixel move
    // If we had put the value 0 => impossible to turn around in the opposite direction after the teleportation
    // And _stepCounter % 5 has to be 0 => Otherwise, impossible to load the sprite
    _stepCounter = 5;

    // Calculate the possible directions
    calculateDirection( levelTable );

    // Coordinates on the screen
    int x( 0);
    int y( 0 );

    // Initialize positions on the screen
    // And initialize _goTo direction because _stepCounter values 1 now
    if( _directionsPossible[ UP ] ) {

        x = _col * 30 + AREAGAME_MARGIN;
        y = _row * 30 + AREATOP_HEIGHT - _stepCounter;
        _goTo = UP;
        _step = UP;

    }

    else if( _directionsPossible[ DOWN ] ) {

        x = _col * 30 + AREAGAME_MARGIN;
        y = _row * 30 + AREATOP_HEIGHT + _stepCounter;
        _goTo = DOWN;
        _step = DOWN;

    }

    else if( _directionsPossible[ LEFT ] ) {

        x = _col * 30 + AREAGAME_MARGIN - _stepCounter;
        y = _row * 30 + AREATOP_HEIGHT;
        _goTo = LEFT;
        _step = LEFT;

    }

    else if( _directionsPossible[ RIGHT ] ) {

        x = _col * 30 + AREAGAME_MARGIN + _stepCounter;
        y = _row * 30 + AREATOP_HEIGHT;
        _goTo = RIGHT;
        _step = RIGHT;

    }

    // Initialize SDL_Rect position
    initRect( &_position, 30, 30, x, y );

    // We made a 1-pixel move => _gotoToBackUp is useless => -1
    _goToBackUp = -1;

}
