/*
 * Roni Fultheim, ID: 313465965
 * Player.cpp
 */

#include "Player.h"

Player::Player(const std::string& name, const Color& c): name_(name), color_(c) {
	possibleMoves_ = std::vector<Location>();
}


//empty destructor
Player::~Player() {}


Color Player::getColor() const {
	return color_;
}


const std::string& Player::getName() const {
	return name_;
}


const std::vector<Location>& Player::getPossibleMoves() const {
	return possibleMoves_;
}


bool Player::hasPossibleMoves() const {
	//check if vector is empty - and return the opposite answer: true if possible moves exist, meaning vector is non-empty
	return !possibleMoves_.empty();
}


void Player::updatePossibleMoves(const std::vector<Location>& locs) {
	//use copy constructor to copy the given vector to data member
	//vector copies its internal elements as well - allows
	possibleMoves_ = locs;
}



