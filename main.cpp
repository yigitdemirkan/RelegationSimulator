#include "relegationsim.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Relegation r;
	string team;
	double scored, conceded, clean, point, win, speed, pps;
	cout << "Please enter the name of the team: ";
	cin >> team;
	cout << "How many points did this team win? ";
	cin >> point;
	cout << "How many goals did this team score? ";
	cin >> scored;
	cout << "How many goals did this team concede? ";
	cin >> conceded;
	cout << "What is the number of matches which the team didn't concede a goal? ";
	cin >> clean;
	cout << "How many matches did this team win? ";
	cin >> win;
	cout << "What was the average direct speed (m/s) of this team per 90 minutes? ";
	cin >> speed;
	cout << "What was the average passes in each open-play sequence per 90 minutes?";
	cin >> pps;
	r.GoalsScored(scored);
	r.GoalsConceded(conceded);
	r.CleanSheets(clean);
	r.Points(point);
	r.Wins(win);
	r.SpeedOf(speed);
	r.PassesPer(pps);
	double score = r.DisplayScore();
	cout << team << "'s probability of survival from relegation is " << score << "%";
	return 0;
}
