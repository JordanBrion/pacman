#include "Game.h"
#include "InteractiveElements/Fruit.h"
#include "InteractiveElements/PowerPellet.h"

using namespace std;

Game::Game( int const& lifesNbr, int const& pacDotsNbr, int const& highScore )
    : _lifesNbr(lifesNbr), _pacDotsNbr(pacDotsNbr), _comboPowerPellet(0),
      _scoreP1(0), _scoreP2(0), _highScore(highScore) {

    _lifesNbr = 3;

    // Initialize the fruit value
    for( int i(0); i < FRUIT_NBR; i++ ) {
        _fruit.push_back(0);
    }

}

Game::~Game() {
}

int Game::getPacDotsNbr() const {

    return _pacDotsNbr;

}

void Game::setPacDotsNbr(int const& nbr) {

    _pacDotsNbr = nbr;

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

void Game::setLifesNbr( int const& nbr ) {

    _lifesNbr = nbr;

}

std::vector<int> Game::getAllFruitNbr() const {

    return _fruit;

}

int Game::getFruitNbr(int const& key) const {

    return _fruit[key];

}

void Game::setFruitNbr(int const& key, int const& nbr) {

    _fruit[key] = nbr;

}

void Game::resetAllFruitNbr() {

    for(int i(0); i < _fruit.size(); i++) {

        _fruit[i] = 0;

    }

}

int Game::getComboPowerPellet() const {

    return _comboPowerPellet;

}

void Game::incComboPowerPellet() {

    switch( _comboPowerPellet ) {

    case 0:
        _comboPowerPellet = 200;
        break;

    default:
        _comboPowerPellet *= POWERPELLET_MULTIPLICATOR;
        break;

    }

}

void Game::resetComboPowerPellet() {

    _comboPowerPellet = 0;

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


