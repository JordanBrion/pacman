#ifndef AREA_H
#define AREA_H

class Area {

public:
    ~Area();
    void free();

protected:
    virtual void drawArea (SDL_Renderer* const& pRenderer) = 0;

private:
    SDL_Texture* _texture;
    SDL_Rect _position;
    SDL_Rect _selection;

};

#endif
