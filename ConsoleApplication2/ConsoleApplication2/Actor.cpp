#include "stdafx.h"



CActor::CActor()
{

	ActorCurrentSpinSpeed = 0;
	epsilon = 0;
	ActorMass = 0;
	ActorInitialVerticalSpeed = 0;
	JumpEvolutionTracer = 0;
	JumpFlag = false;
	DoubleJumpFlag = false;
	DoubleJumpRequestFlag = false;
	SlamFlag = false;
	SpinEvolutionTracer = 0;
	SpinFlag = false;


}



CActor::~CActor()
{
}

void CActor::collision_responce(CActor & B, CVector CollisionCenter)
{
	float LocEpsi = (epsilon + B.epsilon) / 2.0;
	float AXTemp, AYTemp;
	// Calculating Actor A speed after collision
	AXTemp = ((ActorMass*ActorCurrentXYSpeed.xv + B.ActorMass*B.ActorCurrentXYSpeed.xv) + (LocEpsi*B.ActorMass*(B.ActorCurrentXYSpeed.xv - ActorCurrentXYSpeed.xv))) / (ActorMass + B.ActorMass);
	AYTemp = ((ActorMass*ActorCurrentXYSpeed.yv + B.ActorMass*B.ActorCurrentXYSpeed.yv) + (LocEpsi*B.ActorMass*(B.ActorCurrentXYSpeed.yv - ActorCurrentXYSpeed.yv))) / (ActorMass + B.ActorMass);
	// Calculating and Updating Actor B speed after collision
	B.ActorCurrentXYSpeed.xv = ((ActorMass*ActorCurrentXYSpeed.xv + B.ActorMass*B.ActorCurrentXYSpeed.xv) + (LocEpsi*ActorMass*(ActorCurrentXYSpeed.xv - B.ActorCurrentXYSpeed.xv))) / (ActorMass + B.ActorMass);
	B.ActorCurrentXYSpeed.yv = ((ActorMass*ActorCurrentXYSpeed.yv + B.ActorMass*B.ActorCurrentXYSpeed.yv) + (LocEpsi*ActorMass*(ActorCurrentXYSpeed.yv - B.ActorCurrentXYSpeed.yv))) / (ActorMass + B.ActorMass);
	// Updating Actor A speed
	ActorCurrentXYSpeed.xv = AXTemp;
	ActorCurrentXYSpeed.yv = AYTemp;

	//Calculating resulting rotation speed inducted by collision on actor A
	ActorCurrentSpinSpeed = 1;
	//Calculating resulting rotation speed inducted by collision on actor A
	B.ActorCurrentSpinSpeed = 1;
}
void CActor::Translate(float dx, float dy)
{
	Center.xv += dx;
	Center.yv += dy;

}

CVector CActor::AirEvolution(CVector ActorLocalGravity)
{
	float JumpTime = 0;
	CVector DeltaActorCoordinate;
	// Jump routine
	if (JumpFlag == true) 
	{ 
		if ((DoubleJumpFlag == false) && (DoubleJumpRequestFlag == true))// Reinit for actor double jump
		{
			//validating double jump
			DoubleJumpFlag = true;
			DoubleJumpRequestFlag = false;
			//
			JumpEvolutionTracer = 0;
		}
		// Calculate jump statut in time scale
		JumpTime = float(JumpEvolutionTracer)*float(sTimeConstant);// Calculate jump statut in time scale

		// Evolution of  Actor vectical speed
		ActorCurrentXYSpeed.yv = ActorInitialVerticalSpeed*exp((-1 * JumpTime) / ActorMass);


		// Calculating Actor deltaX coordinate
		DeltaActorCoordinate.xv += ActorLocalGravity.xv*ActorMass ;// + ActorControllerXMouvement 
		// Calculating Actor deltaY coordinate
		DeltaActorCoordinate.yv = float(10.0 * (sTimeConstant*((ActorCurrentXYSpeed.yv*ActorLocalGravity.yv*ActorMass) - (ActorLocalGravity.yv*ActorMass)))); // Calculating Player deltaY coordinate 
		

		// Incrementing jump statut
		JumpEvolutionTracer++;
	}
	


	return DeltaActorCoordinate;
}
float CActor::SpinEvolution(void)
{
	float DeltaActorAngularSpin = 0;
	float SpinTime = 0;

	if (SpinFlag == true)
	{
		// Calculating spin statut in timescale
		SpinTime = float(SpinEvolutionTracer)*float(sTimeConstant);
		// Calculating Actor Spin speed evolution
		ActorCurrentSpinSpeed = ActorInitialSpinSpeed*exp((-1 * SpinTime) / ActorMass);
		// Calculation Actor DeltaR
		DeltaActorAngularSpin = sTimeConstant* ActorCurrentSpinSpeed;
	}
	return	DeltaActorAngularSpin;
}