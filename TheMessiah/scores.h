#ifndef SCORES_INCLUDED
#define SCORES_INCLUDED
#include "variables.h"
#include<iostream>
using namespace std;
int score;
int sscore;


char* stringConverter(int killpoint)
{
	char *ch = new char[3000];
	itoa(killpoint, ch, 10);
	return ch;
}
void highscore()
{
	FILE *fp = fopen("images\\Button\\score.txt","r+");
	if (fp != NULL)
	{
		fscanf(fp, "%d", &score);
		fclose(fp);
	}
	if (killScore > score){
		score = killScore;
		fp = fopen("images\\Button\\score.txt", "w");
		if (fp != NULL){
			fprintf(fp, "%d", killScore);
			fclose(fp);
		}
	}
}
void showscore()
{
	FILE *fptr = fopen("images\\Button\\score.txt", "r+");
	if (fptr != NULL)
	{
		fscanf(fptr, "%d", &sscore);
		fclose(fptr);
	}
	iSetColor(0, 0, 0);
	iText(750, 630, stringConverter(sscore), GLUT_BITMAP_TIMES_ROMAN_24);
}

void scorecounter()
{
	iSetColor(255, 0, 0);
	iText(1380, 850, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1480, 850,stringConverter(killScore) , GLUT_BITMAP_TIMES_ROMAN_24);
}
#endif