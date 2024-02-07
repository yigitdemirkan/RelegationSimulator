#include "relegationsim.h"

Relegation::Relegation() {
	// Each stat's contribution to overall score: 14.2857142857%
	stat = 14.285714285;
	score = 0;
}

// These threshold statistics were determined from the examination of Premier League teams dealt with relegation battle

// The average threshold for goals scored to stay in league is taken as 38
void Relegation::GoalsScored(double scored) {
	double threshold = 38;
	if (scored >= threshold) {
		score += stat;
	}
	else {
		score += (stat * scored / threshold);
	}
}

// The average threshold for goals conceded to stay in league is taken as 60
void Relegation::GoalsConceded(double conceded) {
	double threshold = 60;
	if (conceded <= threshold) {
		score += stat;
	}
	else {
		score += (stat * threshold / conceded);
	}
}

// The average threshold for number of clean sheets to stay in league is taken as 11.5
void Relegation::CleanSheets(double clean) {
	double threshold = 11.5;
	if (clean >= threshold) {
		score += stat;
	}
	else {
		score += (stat * clean / threshold);
	}
}

// The average threshold for points earned to stay in league is taken as 35
void Relegation::Points(double point) {
	double threshold = 35;
	if (point >= threshold) {
		score += stat;
	}
	else {
		score += (stat * point / threshold);
	}
}

// The average threshold for number of wins to stay in league is taken as 11
void Relegation::Wins(double win) {
	double threshold = 11;
	if (threshold >= 11) {
		score += stat;
	}
	else {
		score += (stat * threshold / 11);
	}
}

//Direct speed: Metres per second progressed upfield in open-play sequences (indicates fast & direct play)
//The optimal interval for direct speed was determined as [1.4,1.6]
void Relegation::SpeedOf(double speed) {
	double threshold_below = 1.4;
	double threshold_above = 1.6;
	if (speed >= threshold_below && speed <= threshold_above) {
		score += 14.2857142857;
	}
	else if (speed > threshold_above) {
		score += (threshold_above * 14.2857142857 / speed);
	}
	else if (speed < threshold_below) {
		score += (14.2857142857 * speed / threshold_below);
	}
}

//Passes per sequence: Average passes in each open-play sequence (indicates slow & intricate play)
//The optimal interval for passes per sequence was determined as [2.4,3]
void Relegation::PassesPer(double pps) {
	double threshold_below = 2.4;
	double threshold_above = 3;
	if (pps >= threshold_below && pps <= threshold_above) {
		score += 14.2857142857;
	}
	else if (pps > threshold_above) {
		score += (threshold_above * 14.2857142857 / pps);
	}
	else if (pps < threshold_below) {
		score += (14.2857142857 * pps / threshold_below);
	}
}

double Relegation::DisplayScore() {
	return score;
}
