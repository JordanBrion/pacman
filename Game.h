#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {

public:
    Game();
    ~Game();
    int getNbrLifes() const;
    void incNbrLifes();
    void decNbrLifes();
    int getScoreP1() const;
    void setScoreP1();
    int getScoreP2() const;
    void setScoreP2();
    int getHighScore() const;
    void setHighScore();
    bool isTwoPlayersGame() const;
    void setTwoPlayersGame(bool const& solo);

private:
    int _nbrBubbles;
    int _nbrLifes;
    std::vector<int> _fruits;
    int _comboSuperPower;
    int _score;
    int _highscore;
    bool _paused;
    bool _twoPlayersGame;

};

#endif
