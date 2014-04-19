#ifndef BUBBLE_H
#define BUBBLE_H

#include "InteractiveElement.h"

class Bubble: public InteractiveElement {

public:
    Bubble( std::map<std::string, int> dest, int type, int x, int y, SDL_Renderer* const& renderer, SDL_Surface* const& sprite);
    ~Bubble();
    bool isEaten() const;
    void setEaten( int const& state );
    int getCaseType() const;
    void setCaseType( int const& type );
    int show( SDL_Renderer* const& renderer );

private:
    bool _eaten;
    int _caseType;

};

#endif
