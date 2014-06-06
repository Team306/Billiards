#include "Player.h"

Player::Player(){
    hit_flag = 0;
    eightball_type = NOTDEF;
    on_pocket_list.clear();
}

Player::~Player(){

}

void Player::update(){
    hit_flag = 0;
    on_pocket_list.clear();
    first_hit = "";
}

std::string Player::getFirsthit() const{
    return first_hit;
}

std::vector<std::string> Player::getOnpocketlist() const{
    return on_pocket_list;
}

void Player::setBalltype(int type){
    eightball_type = (EIGHTBALL_TYPE)type;
}

EIGHTBALL_TYPE Player::getBalltype() const {
    return eightball_type;
}

void Player::setPlayerflag(int player){
    player_flag = (PLAYER_FLAG)player;
}

PLAYER_FLAG Player::getPlayerflag() const{
    return player_flag;
}
