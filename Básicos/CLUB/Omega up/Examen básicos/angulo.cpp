#include<stdio.h>
#include<math.h>
const double pi = 4. * atan(1.);
int main(){
	int P[2], Q[2], R[2],V1[2],V2[2];
	scanf("%d %d",&P[0],&P[1]);
	scanf("%d %d",&Q[0],&Q[1]);
	scanf("%d %d",&R[0],&R[1]);

	//QP
	V1[0] = P[0]-Q[0];
	V1[1] = P[1]-Q[1];

	//QR
	V2[0] = R[0]-Q[0];
	V2[1] = R[1]-Q[1];

	//(X,Y) = C1 && V2(X,Y) = C1;
	//(-X,Y) = C2
	//(-X,-Y) = C3
	//(X,-Y) = C4


	//C1
	if(V1[0]>=0 && V1[1]>=0 && V2[0] >= 0 && V2[1] >= 0)
		printf("%.3f\n", (acos(((V1[0]*V2[0])+(V1[1]*V2[1]))/(sqrt((V1[0]*V1[0]) + (V1[1]*V1[1])) * sqrt((V2[0]*V2[0]) + (V2[1]*V2[1]))))) * (180/pi));
	else if(V1[0]<=0 && V1[1]>=0 && V2[0] >= 0 && V2[1] >= 0)
		printf("%.3f\n", (acos(((V1[0]*V2[0])+(V1[1]*V2[1]))/(sqrt((V1[0]*V1[0]) + (V1[1]*V1[1])) * sqrt((V2[0]*V2[0]) + (V2[1]*V2[1]))))) * (180/pi));
	return 0;
}