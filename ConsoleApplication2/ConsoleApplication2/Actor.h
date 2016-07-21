#pragma once
#include "stdafx.h"
#include "Vector.h"

class CActor
{
public:
	CVector ActorCurrentXYSpeed;
	CVector Center;
	float ActorMass,ActorCollisionRestitutionCoefficient, ActorCurrentSpinSpeed,ActorInitialVerticalSpeed, ActorInitialSpinSpeed;
	// physics constants
	double sTimeConstant = 0.016;
	bool JumpFlag,SpinFlag, SlamFlag, DoubleJumpFlag, DoubleJumpRequestFlag;
	int JumpEvolutionTracer, SpinEvolutionTracer;

public:
	CActor();
	~CActor();

	void DynamicDynamicCollisionResponce(CActor &, CVector);
	void StaticDynamicCollisionResponce(CActor, CVector CollisionCenter);
	CVector AirEvolution(CVector);
	float SpinEvolution(void);
	void Translate(float, float);

};

