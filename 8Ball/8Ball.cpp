// 8Ball.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
int halbe [7];
int volle[7];
bool sp1 = NULL;
bool sp2 = NULL;
int turn;
int ansage;


int firstHit(int count, bool hit, int* elBall) {
	turn = 3;
	if (hit == false) {
		turn = 6;
	}
	else 
	{
		
		if (*eBall != NULL) {
			int length = sizeof(*elBall) / sizeof(*elBall + 0);
			for (int i = 0; i < length; i++) {
				int ball = *elBall + i;

				if (ball == 8) {
					turn = 2;
				}
				else 
				{
					if (ball < 8) {
						volle[ball - 1] = ball;
					}
					else {
						halbe[ball - 9] = ball;
					}
				}
			}
		}
		else
		{
			if (count >= 4) {
				turn = 4;
			}
			else {
				turn = 6;
			}
		}
	}
	return turn;
}


int stoss(int count; int *eBall) {
	if (count == 0) {
		turn = (turn % 2) + 5;
	}
	else {

		if (*eBall != NULL) {
			int length = sizeof(*elBall) / sizeof(*elBall + 0);
			for (int i = 0; i < length; i++) {
				int ball = *elBall + i;
				if (sp1 && sp2 == NULL) {
					if (ball < 8) {
						if (turn % 2 == 0) {
							sp2 = true;
						}
						else {
							sp1 = true;
						}
					}
					else {
						if (turn % 2 == 0) {
							sp2 = false;
						}
						else {
							sp1 = false;
						}
					}
				}
			}
		}
	}
	else {
		turn = (turn % 2) + 3;
	}
}

