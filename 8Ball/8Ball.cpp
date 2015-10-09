// 8Ball.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
int halbe [7];
int volle[7];
bool sp1 = NULL;
bool sp2 = NULL;
int turn;
int ansage;
bool match;

/* 
*	erster Schlag Funktion
*	in:		count = Anzahl der Kugeln die eine Bande berührt haben (-1 wenn nur eine versenkt wurde)
*			hit   = wurde eine Kugel getroffen
*			elBall = pointer auf Array mit Kugeln die versenkt wurden
*	out:	wert welcher Spieler an der reihe ist und wie
*
*/
int firstHit(int count, bool hit, int* elBall) {
	turn = 3;
	/* wenn keine getroffen ist der nächste Spieler mit Ball in Hands dran */
	if (hit == false) {
		turn = 6;
	}
	else 
	{
		/*wurde eine Kugel versenkt? */
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

/* Schlag Funktion
*	in:		count = Anzahl der Kugeln die eine Bande berührt haben 
*			elBall = pointer auf Array mit Kugeln die versenkt wurden
*	out : wert welcher Spieler an der reihe ist und wie
*
*/

int stoss(int count; int *eBall) {
	match = false;
	if (count == 0 && *eBall != NULL) {
		turn = (turn % 2) + 5;
	}
	else {

		if (*eBall != NULL) {
			int length = sizeof(*elBall) / sizeof(*elBall + 0);
			for (int i = 0; i < length; i++) {
				int ball = *elBall + i;
				/* 8 wurde eingelocht */
				if (ball == 8) {
					int p = turn % 2;
					if (p == 0) {
						if (sp2 == true) {
							if (sizeof(volle) / sizeof(volle + 0) == 7) {
								turn = 2;
							}
							else
							{
								turn = 1;
							}
						}
						else {
							if (sizeof(halbe) / sizeof(halbe + 0) == 7) {
								turn = 2;
							}
							else
							{
								turn = 1;
							}
						}
					}
					else {
						if (p == 1) {
							if (sp1 == true) {
								if (sizeof(volle) / sizeof(volle + 0) == 7) {
									turn = 1;
								}
								else
								{
									turn = 2;
								}
							}
							else {
								if (sizeof(halbe) / sizeof(halbe + 0) == 7) {
									turn = 1;
								}
								else
								{
									turn = 2;
								}
							}
						}
						else {
							turn = p + 1;
						}
					}
				}
				else {
					/* erste Kugel des Spiels ist gefallen */
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
					
					else {
						/* jede weitere Kugel */
						if (ball == ansage) {
							match = true;
						}
						if (ball < 8) {
							volle[ball - 1] = ball;
						}
						else {
							halbe[ball - 9] = ball;
						}

					}
				}
			}
				
				if (match == true) {
					turn = (turn % 2) + 2;
				}
				else {
					turn = (turn % 2) + 3;
				}

			}
		else {
			turn = (turn % 2) + 3;
		}
	}
}

void setAnsage(int ansageTemp) {
	ansage = ansageTemp;
}