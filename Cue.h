// Copyright (C) 2014 Team306

#ifndef CUE_H
#define CUE_H 


#include "Vector2.h"
#include "Referee.h"

// user controls it
class Cue
{
private:
	Vector2 position; // the position the cue points to
	// the position of the cue-ball 
	float ballRadius;
	float cueLength;

public:
	Cue();
	~Cue();

	// init method
	void init(Referee &);

	// update and draw
	void Update();
	void Draw(QPainter &, Vector2, Ball &);	
};


#endif
