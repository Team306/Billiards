// Copyright (C) 2014 Team306

#ifndef PLAYER_H
#define PLAYER_H 

#include "Ball.h"

enum PLAYER_FLAG { LOCAL, GUEST};
enum EIGHTBALL_TYPE { NOTDEF, SMALL, BIG};
enum SONKER_BALLTYPE {RED,COLOR};

class Player
{
public:
	Player();
	~Player();
    void Goon();
    void Exchange();
    void init();
    std::string getFirsthit() const;

    std::vector<std::string> getOnpocketlist() const;
    void setOnpocketlist(std::string);

    EIGHTBALL_TYPE getBalltype() const;
    void setBalltype(int);

    PLAYER_FLAG getPlayerflag() const;
    void setPlayerflag(int);

    int getCueball_in() const;
    void setCueball_in(int);

    int getScore() const;
    void scoreAdd(int);

private:
    PLAYER_FLAG player_flag;
    EIGHTBALL_TYPE eightball_type;
    SONKER_BALLTYPE toHit_balltype;
    int hit_flag;
    std::string first_hit;
    std::vector<std::string>  on_pocket_list;
    int cueball_in;
    int score;
};


#endif
