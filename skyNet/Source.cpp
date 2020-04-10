#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
		//gets the number of areas it takes the skynet to scan before finding the enemy
	int pingNum = 1;
		//the predicted location on a grid decided by dviding in halves
	int targetLocationPrediction;
		//the next two are the numbers used to find the target loaction prediction
	int searchGridHighNumber;
	int searchGridLowNumber;
		//this number is part of the hard coding that sets the size of the area to search
	int gridXY = 8;
		//the next two get random numbers between 1 and 8 to set the enemy in a random location as a simulation
	int randNum1 = ((rand() % 8) + 1);
	int randNum2 = ((rand() % 8) + 1);
		//sets the initial starting points for the algorithm used to search the area
	searchGridHighNumber = gridXY * gridXY;
	searchGridLowNumber = 0;
		//sets the enemy location
	int enemy = randNum1 * randNum2;
		//initial prediction locked in
	targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	cout << "The Enemy is in block #" << enemy << endl;
	cout << "Skynet will now begin searching for the enemy..." << endl;
		//once the simulation runs it won't stop until it finds the enemy
	while (targetLocationPrediction != enemy)
	{
			//if the enemy is higher than the prediction then the area searched will be cut in half and searched in the higher half
		if (enemy > targetLocationPrediction)
		{
			cout << "Getting Ping #" << pingNum << endl;
			cout << "Scanning Area..." << endl;
			cout << "Target not found in grid #" << targetLocationPrediction << endl;
			searchGridLowNumber = targetLocationPrediction;
			targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			pingNum += 1;
		}
			//if the enemy is lower than the prediction then the area searched will be cut in half and searched in the lower half
		if (enemy < targetLocationPrediction)
		{
			cout << "Getting Ping #" << pingNum << endl;
			cout << "Scanning Area..." << endl;
			cout << "Target not found in grid #" << targetLocationPrediction << endl;
			searchGridHighNumber = targetLocationPrediction;
			targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			pingNum += 1;
		}
			//once the location prediction matches the enemy location, it will alert the location of the enemy and how many attempts it took the AI to find the enemy
		if (targetLocationPrediction == enemy)
		{
			cout << "Enemy Location: Block #: " << enemy << endl;
			cout << "Area's searched: " << pingNum << endl;

		}

	}
		//pauses the console window, allowing the user to view the data output from the AI
	system("pause");
	return 0;
}