// Copyright (C) 2014 Team306

#ifndef PLAYER_H
#define PLAYER_H 

#include "Ball.h"

enum PLAYER_FLAG {LOCAL, GUEST};
enum EIGHTBALL_TYPE {NOTDEF,SMALL, BIG};

class Player
{
public:
	Player();
	~Player();
    void update();
    std::string getFirsthit() const;
    std::vector<std::string> getOnpocketlist() const;
    void setBalltype(int);
    EIGHTBALL_TYPE getBalltype() const;
    void setPlayerflag(int);
    PLAYER_FLAG getPlayerflag() const;


private:
    PLAYER_FLAG player_flag;
    EIGHTBALL_TYPE eightball_type;
    int hit_flag;
    std::string first_hit;
    std::vector<std::string>  on_pocket_list;
};


#endif
