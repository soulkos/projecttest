#include "stdafx.h"
#include "Actor.h"


CActor::CActor()
{
	Vr = 0;
	epsilon = 0;
	mass = 0;
	JumpEvolutionTracer = 0;
	JumpFlag = false;
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

	AXTemp = ((mass*Speed.xv + B.mass*B.Speed.xv) + (LocEpsi*B.mass*(B.Speed.xv - Speed.xv))) / (mass + B.mass);
	AYTemp = ((mass*Speed.yv + B.mass*B.Speed.yv) + (LocEpsi*B.mass*(B.Speed.yv - Speed.yv))) / (mass + B.mass);

	B.Speed.xv = ((mass*Speed.xv + B.mass*B.Speed.xv) + (LocEpsi*mass*(Speed.xv - B.Speed.xv))) / (mass + B.mass);
	B.Speed.yv = ((mass*Speed.yv + B.mass*B.Speed.yv) + (LocEpsi*mass*(Speed.yv - B.Speed.yv))) / (mass + B.mass);

	Speed.xv = AXTemp;
	Speed.yv = AYTemp;

	Vr = 1;
	B.Vr = 1;
}
void CActor::Translate(float dx, float dy)
{
	Center.xv += dx;
	Center.yv += dy;

}