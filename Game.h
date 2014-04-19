#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Const.h"

class Game {

public:
    Game( int const& lifesNbr, int const& bubblesNbr, int const& highScore );
    ~Game();
    int getBubblesNbr() const;
    void setBubblesNbr(int const& nbr);
    int getLifesNbr() const;
    void incLifesNbr();
    void decLifesNbr();
    std::vector<int> getCollectibles() const;
    int getCollectible(int const& key) const;
    void setCollectibles(int const& key, int const& nbr);
    void resetCollectibles();
    int getScoreP1() const;
    void setScoreP1(int const& score);
    int getScoreP2() const;
    void setScoreP2(int const& score);
    int getHighScore() const;
    void setHighScore(int const& score);
    bool isTwoPlayersGame() const;
    void setTwoPlayersGame(bool const& solo);

private:
    int _lifesNbr;
    int _bubblesNbr;
    std::vector<int> _collectibles;
    int _comboSuperPower;
    int _scoreP1;
    int _scoreP2;
    int _highScore;
    bool _paused;
    bool _twoPlayersGame;

};

#endif
