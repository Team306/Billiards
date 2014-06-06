#include "Player.h"

Player::Player(){
    hit_flag = 0;
    cueball_in = 0;
    eightball_type = NOTDEF;
    on_pocket_list.clear();
}

Player::~Player(){

}

void Player::update(){
    hit_flag = 0;
    cueball_in = 0;
    on_pocket_list.clear();
    first_hit = "";
}

int Player::getHitflag() const{
    return hit_flag;
}

void Player::setHitflag(int value){
    hit_flag = value;
}

std::string Player::getFirsthit() const{
    return first_hit;
}

void Player::setFirsthit(std::string _first_hit){
    first_hit = _first_hit;
}

std::vector<std::string> Player::getOnpocketlist() const{
    return on_pocket_list;
}

void Player::setOnpocketlist(std::string _onpocket){
    on_pocket_list.push_back(_onpocket);
}

EIGHTBALL_TYPE Player::getBalltype() const {
    return eightball_type;
}

void Player::setBalltype(int type){
    eightball_type = (EIGHTBALL_TYPE)type;
}

PLAYER_FLAG Player::getPlayerflag() const{
    return player_flag;
}

void Player::setPlayerflag(int player){
    player_flag = (PLAYER_FLAG)player;
}


void Player::init(){
    eightball_type = NOTDEF;
    hit_flag = 0;
    cueball_in = 0;
    on_pocket_list.clear();
    first_hit = "";
}

int Player::getCueball_in() const {
    return cueball_in;
}

void Player::setCueball_in(int _cueball_in){
    cueball_in = _cueball_in;
}

