#include "Game.h"

using namespace std;

Game::Game( int const& lifesNbr, int const& bubblesNbr, int const& highScore )
    : _lifesNbr(lifesNbr), _bubblesNbr(bubblesNbr), _comboSuperPower(0),
      _scoreP1(0), _scoreP2(0), _highScore(highScore), _paused(false) {

    _lifesNbr = 3;

    // Initialize the collectibles value
    for( int i(0); i < COLLECTIBLES_NBR; i++ ) {
        _collectibles.push_back(0);
    }

}

Game::~Game() {
}

int Game::getBubblesNbr() const {

    return _bubblesNbr;

}

void Game::setBubblesNbr(int const& nbr) {

    _bubblesNbr = nbr;

}

int Game::getLifesNbr() const {

    return _lifesNbr;

}

void Game::incLifesNbr() {

    _lifesNbr++;

}

void Game::decLifesNbr() {

    _lifesNbr--;

}

std::vector<int> Game::getCollectibles() const {

    return _collectibles;

}

int Game::getCollectible(int const& key) const {

    return _collectibles[key];

}

void Game::setCollectibles(int const& key, int const& nbr) {

    _collectibles[key] = nbr;

}

void Game::resetCollectibles() {

    for(int i(0); i < _collectibles.size(); i++) {

        _collectibles[i] = 0;

    }

}

int Game::getScoreP1() const {

    return _scoreP1;

}

void Game::setScoreP1(int const& score) {

    _scoreP1 = score;

}

int Game::getScoreP2() const {

    return _scoreP2;

}

void Game::setScoreP2(int const& score) {

    _scoreP2 = score;

}

int Game::getHighScore() const {

    return _highScore;

}

void Game::setHighScore(int const& score) {

    _highScore = score;

}

bool Game::isTwoPlayersGame() const {

    return _twoPlayersGame;

}

void Game::setTwoPlayersGame(bool const& solo) {

    _twoPlayersGame = solo;

}


