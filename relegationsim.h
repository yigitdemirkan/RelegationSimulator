#pragma once

#include <iostream>
#include <string>
using namespace std;

class Relegation {
public:
	Relegation();
	void GoalsScored(double scored);
	void GoalsConceded(double conceded);
	void CleanSheets(double clean);
	void Points(double point);
	void Wins(double win);
	void SpeedOf(double speed);
	void PassesPer(double pps);
	double DisplayScore();

private:
	double score;
	double stat;
};
