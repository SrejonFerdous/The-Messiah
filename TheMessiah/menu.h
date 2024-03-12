#ifndef MENU_INCLUDED
#define MENU_INCLUDED
#include"variables.h"
#include<iostream>


struct buttonCordinate{
	int x;
	int y;
}buttonCordinate[5];

void showButton(){

	int sum = 200;
	for (int i = 4; i >= 0; i--){
		buttonCordinate[i].x = 50;
		buttonCordinate[i].y = sum;
		sum += 100;
	}
}

void menuShow(){
	iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[0]));

	for (int i = 0; i < 5; i++){

		iShowBMP2(buttonCordinate[i].x, buttonCordinate[i].y, buttons[i], 255);
	}
}




#endif