#ifndef RENDERING_INCLUDED
#define RENDERING_INCLUDED
#include "variables.h"

struct renderBackground{
	int x, y;
} background[8];
renderBackground background2[8];
renderBackground background3[8];
void bgShow(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background[i].x, background[i].y, backGround1[i]);
}
void bgShow2(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background2[i].x, background2[i].y, backGround2[i]);
}
void bgShow3(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background3[i].x, background3[i].y, backGround3[i]);
}



void changeBackground()
{
	if (level == 1 && standPosition == false){
		for (int i = 0; i < 8; i++)
		{
			background[i].x -= backGroundSpeed;
			if (background[i].x < 0)
				background[i].x = screenWidth - 200;
		}
	}
	else if (level == 2 && standPosition == false){
		for (int i = 0; i < 8; i++)
		{
			background2[i].x -= backGroundSpeed;
			if (background2[i].x < 0)
				background2[i].x = screenWidth - 200;
		}
	}
	else if (level == 3 && standPosition == false){
		for (int i = 0; i < 8; i++)
		{
			background3[i].x -= backGroundSpeed;
			if (background3[i].x < 0)
				background3[i].x = screenWidth - 200;
		}
	}
}



void setbackground()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background[i].x = sum;
		background[i].y = 0;
		sum += 200;
	}
}
void setbackground2()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background2[i].x = sum;
		background2[i].y = 0;
		sum += 200;
	}
}
void setbackground3()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background3[i].x = sum;
		background3[i].y = 0;
		sum += 200;
	}
}
#endif