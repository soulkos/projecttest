#pragma once
#include "stdafx.h"
#include "Vector.h"

class CActor
{
public:
	CVector ActorCurrentXYSpeed;
	CVector Center;
	float ActorMass,epsilon, ActorCurrentSpinSpeed,ActorInitialVerticalSpeed, ActorInitialSpinSpeed;
	// physics constants
	double sTimeConstant = 0.016;
	bool JumpFlag,SpinFlag, SlamFlag, DoubleJumpFlag, DoubleJumpRequestFlag;
	int JumpEvolutionTracer, SpinEvolutionTracer;

public:
	CActor();
	~CActor();

	void collision_responce(CActor &, CVector);
	CVector AirEvolution(CVector);
	float SpinEvolution(void);
	void Translate(float, float);

};

