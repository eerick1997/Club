#include<iostream>

using namespace std;

int main(){

	/*
	H = height of the well
	U = distance that snail climbs during the day
	D = distance that snail slides down during the night
	F = fatigue factor expressed as a percentage

	Constraints
	1. The snail never climbs a negative distance
	2. The fatigue factor drops the snail's climbing distance below zero 
	   the snail doesn't climb at all that day.
	3. Regardless of how far the snail climbed, it always slides D feet at night.
	*/
	float H = 0, U = 0, D = 0, day = 1;
	float distance_climbed = 0, F = 0, to_rest = 0;

	//Getting data and evaluating if it isn't the end of the program
	while(cin>>H>>U>>D>>F && H != 0){
		to_rest = F/100 * U;
		day = 1;
		distance_climbed = 0;
		while(true){
			//During the day we add the distance
			distance_climbed += U;
			//if the distance is more than the size of the wall
			if(distance_climbed > H) 
				break;
			//We substract the distance during the night
			distance_climbed -= D;
			//The distance climbed is negative
			if(distance_climbed < 0)
				break;

			//If the fatigue is more than zero we substract the fatigue to the distance
			//that the snail need to travel
			if(U > 0)
				U -= to_rest;
			day++;
		}
		//If the distance is negative
		if(distance_climbed < 0)
			cout<<"failure ";
		else 
			cout<<"success ";
		cout<<"on day "<<day<<endl;

	}

	return 0;
}