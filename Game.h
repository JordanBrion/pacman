#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {

public:
    Game();
    ~Game();
    int getBubblesNbrInit() const;
    void setBubblesNbrInit(int const& nbr);
    int getBubblesNbr() const;
    void setBubblesNbr(int const& nbr);
    int getLifesNbr() const;
    void incLifesNbr();
    void decLifesNbr();
    int getScoreP1() const;
    void setScoreP1(int const& score);
    int getScoreP2() const;
    void setScoreP2(int const& score);
    int getHighScore() const;
    void setHighScore(int const& score);
    bool isTwoPlayersGame() const;
    void setTwoPlayersGame(bool const& solo);

private:
    int _bubblesNbrInit;
    int _bubblesNbr;
    int _lifesNbr;
    std::vector<int> _fruits;
    int _comboSuperPower;
    int _scoreP1;
    int _scoreP2;
    int _highScore;
    bool _paused;
    bool _twoPlayersGame;

};

#endif
