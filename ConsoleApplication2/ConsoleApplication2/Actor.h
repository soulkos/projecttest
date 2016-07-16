#pragma once
#include "Vector.h"

class CActor
{
public:
	CVector Speed;
	CVector Center;
	float mass,epsilon, Vr;
	bool JumpFlag,SpinFlag;
	int JumpEvolutionTracer, SpinEvolutionTracer;

public:
	CActor();
	~CActor();
	void collision_responce(CActor &, CVector);
	void Translate(float, float);

};

