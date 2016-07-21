// ConsoleApplication2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"



static float sPlayerOBB[10] = { 0,0,10,10,-10,10,-10,-10,10,-10 };

static CActor Act_A;
static CActor Act_B;



void Rotation(float XCenter, float YCenter, float DeltaAngular) {
	//float tab[10] = { 0,0,10,10,-10,10,-10,-10,10,-10};
	//float deltaXY[10] = { 0,0,0,0,0,0,0,0,0,0};
	//float deltaXY2[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int iteration = 0;
	float XTemp = 0, YTemp = 0,l = 0,ln1 = 0,dl = 0,Beta = 0,dh = 0,a = 0,Alpha = 0 ;

	Alpha = DeltaAngular;

	for(iteration = 0; iteration <= 4; iteration++){
		XTemp = sPlayerOBB[2*iteration];
		YTemp = sPlayerOBB[2*iteration+1];

		//l = sqrt(pow(XTemp - XCenter, 2) + pow(YTemp - YCenter, 2));
		//ln1 = l*cos(Alpha);
		//dh = l*sin(Alpha);
		//dl = l-ln1;
		//if (dh) { Beta = atan(dl / dh); }
		//a = sqrt(pow(dl, 2) + pow(dh, 2));
		//deltaXY[2 * iteration] = copysign(a*cos(Beta), 1);// (YTemp - YCenter));
		//deltaXY[2 * iteration + 1] = copysign(a*sin(Beta), 1);// XCenter - XTemp);

		float s = sin(Alpha);
		float c = cos(Alpha);
		XTemp -= XCenter;
		YTemp -= YCenter;
		float dx = (XTemp * c - YTemp * s) + XCenter;
		float dy = (XTemp * s + YTemp * c) + YCenter;
		sPlayerOBB[2 * iteration] = dx;
		sPlayerOBB[2 * iteration + 1] = dy;
	}
	int hj = 15;
	// test
}
void Translation(double DX, double DY) {
	int iteration = 0;
	for (iteration = 0; iteration <= 4; iteration++) {
		sPlayerOBB[2 * iteration] += DX;
		sPlayerOBB[2 * iteration + 1] += DY;

	}
}



int main()
{
	int iteration = 0;
	double t = 0;
	float dxa, dxb, dya, dyb;
	CVector col_pts;

	Act_A.Center.xv = 0;
	Act_A.Center.yv = 0;
	Act_A.ActorCurrentXYSpeed.xv = 1;
	Act_A.ActorCurrentXYSpeed.yv = 0;
	Act_A.ActorMass = 1;
	Act_A.ActorCollisionRestitutionCoefficient = 0.8;

	Act_B.Center.xv = 2;
	Act_B.Center.yv = 0;
	Act_B.ActorCurrentXYSpeed.xv = 0;
	Act_B.ActorCurrentXYSpeed.yv = 0;
	Act_B.ActorMass = 1;
	Act_B.ActorCollisionRestitutionCoefficient = 0.8;


	while (1) {
		
		//Rotation(sPlayerOBB[0], sPlayerOBB[1], (0 * 3.14 / 180));
		//Translation(0.05, 0.01*cos(t*3.14));

		//for (iteration = 0; iteration < 10;iteration++){
		//	std::cout << sPlayerOBB[iteration] << "/";
		//}
		dxa = Act_A.ActorCurrentXYSpeed.xv *0.016;
		dya = Act_A.ActorCurrentXYSpeed.yv *0.016;
		dxb = Act_B.ActorCurrentXYSpeed.xv *0.016;
		dyb = Act_B.ActorCurrentXYSpeed.yv *0.016;

		Act_A.Translate(dxa, dya);
		Act_B.Translate(dxb, dyb);


		std::cout << "XA : "<< Act_A.Center.xv ;
		std::cout << " // YA : " << Act_A.Center.yv << std::endl;
		std::cout << "XB : " << Act_B.Center.xv;
		std::cout << " // YB : " << Act_B.Center.yv << std::endl;

		if ((Act_B.Center.xv - Act_A.Center.xv <0.01)&& (Act_A.Center.yv - Act_B.Center.yv < 0.01))
		{
			std::cout << "Collision" << std::endl;

			col_pts.xv = Act_A.Center.xv;
			col_pts.yv = Act_B.Center.yv;
			Act_A.DynamicDynamicCollisionResponce(Act_B, col_pts);
		}
		Sleep(DWORD(500));
		//t += 0.01;
	}
    return 0;
}

