// Copyright (C) 2014 Team306

#ifndef CUE_H
#define CUE_H 


#include "Vector2.h"

// user controls it
class Cue
{
private:
	Vector2 position; // the position the cue points to

public:
	Cue();
	~Cue();

	// update and draw
	void Update();
	void Draw();	
};


#endif
