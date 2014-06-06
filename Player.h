// Copyright (C) 2014 Team306

#ifndef PLAYER_H
#define PLAYER_H 

#include "Ball.h"

enum PLAYER_FLAG { LOCAL, GUEST};
enum EIGHTBALL_TYPE { NOTDEF, SMALL, BIG};

class Player
{
public:
	Player();
	~Player();
    void update();
    void init();
    std::string getFirsthit() const;
    void setFirsthit(std::string);

    int getHitflag() const;
    void setHitflag(int);

    std::vector<std::string> getOnpocketlist() const;
    void setOnpocketlist(std::string);

    EIGHTBALL_TYPE getBalltype() const;
    void setBalltype(int);

    PLAYER_FLAG getPlayerflag() const;
    void setPlayerflag(int);

    int getCueball_in() const;
    void setCueball_in(int);

private:
    PLAYER_FLAG player_flag;
    EIGHTBALL_TYPE eightball_type;
    int hit_flag;
    std::string first_hit;
    std::vector<std::string>  on_pocket_list;
    int cueball_in;
};


#endif
