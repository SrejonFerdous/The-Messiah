#include "iGraphics.h"
#include "bitmap_loader.h"
#include"variables.h"
#include "menu.h"
#include "heroMovement.h"
#include "villian1.h"
#include"villian2.h"
#include "villian3.h"
#include "scores.h"
#include "rendering.h"
#include<iostream>



void iDraw()
{
	iClear();
	if (gameState == -1){
		menuShow();
	}
	else if (gameState == 0 && frameShowed)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(frames[frameIndex]));
	}
	else if (gameState == 0 && level==1){
		if (!pause){
				levelChange();
				bgShow();
				iShowBMP2(600, screenHeigth - 250, "images\\levels\\level1.bmp", 0);
				lifeBar();
				villian1Movement();
				villian12Movement();
				scorecounter();
				if (jump){
					Jump();
				}
				else{
					Character();
				}
				
			}
		
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
}
	else if (gameState == 0 && level == 2)
{
		if (!pause){
			levelChange();
			bgShow2();
			iShowBMP2(600, screenHeigth - 250, "images\\levels\\level2.bmp", 0);
			lifeBar2();
			villian21Movement();
			villian22Movement();
			scorecounter();
			if (jump){
				Jump();
			}
			else{
				Character();
			}
		}
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
	}
	else if (gameState == 0 && level == 3)
	{
		if (!pause){
			bgShow3();
			iShowBMP2(550, screenHeigth - 250, "images\\levels\\level3.bmp", 0);
			lifeBar3();

			villian31Movement();
			bossMovement();

			scorecounter();
			if (jump){
				Jump();
			}
			else{
				Character();
			}
		}
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
	}
	else if (gameState == 1)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[2]));
	}
	else if (gameState == 2)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[3]));
		showscore();
	}
	else if (gameState == 3)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[4]));
	}
	else if (gameState == 4)
	{
		exit(0);
	}
	else if (gameState == 5){
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[6]));
	}
	else if (gameState == 6){
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[7]));
	}
	
}




void iPassiveMouse(int x, int y){;}
void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		for (int i = 0; i < 5; i++){
			if (mx >= buttonCordinate[i].x && mx <= buttonCordinate[i].x + 434 && my >= buttonCordinate[i].y && my <= buttonCordinate[i].y + 104)
			{
				gameState = i;
				if (gameState == 0){
					frameShowed = true;
				}
			}
		}
	}


}
void iKeyboard(unsigned char key){

	if (key =='\t' )
	{
		if (level!=1 ||level!=2 || level!=3){
			gameState = -1;
		}
	}
	else if (key == ' '){
		if (!jump){
			jump = true;
			jumpUp = true;
		}
	}
	else if (key == 'd' || key == 'D'){
		standPosition = false;
		reverseStand = false;
		//front = true;
		heroCoordinateX += 20;
		if (heroCoordinateX >= screenWidth){
			heroCoordinateX = 0;
		}
		heroIndex++;
		if (heroIndex >= 8)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth-120)
			heroCoordinateX = 0;
	}
	else if (key == 'a' || key == 'A'){
		standPosition = false;
		heroCoordinateX -= 10;
		reverseStand = true;
		//front = false;
		if (heroCoordinateX <= 20){
			heroCoordinateX = 10;
		}
		heroReverseIndex++;
		if (heroReverseIndex >= 8)
		{
			heroReverseIndex = 0;
		}
	}
	else if (key == 's' || key == 'S'){
		standPosition = false;
		heroCoordinateY -= 15;
		//front = true;
		if (heroCoordinateY <=0){
			heroCoordinateY = 0;
		}
		heroIndex++;
		if (heroIndex >= 8) 
		{
			heroIndex = 0;
		}
	}
	else if (key == 'w' || key == 'W'){
		standPosition = false;
		reverseStand = false;
		//front = true;
		heroCoordinateY += 15;
		if (heroCoordinateY >= 110){
			heroCoordinateY = 110;
		}
		heroIndex++;
		if (heroIndex >= 8)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth - 150)
			heroCoordinateX = screenWidth - 150;
	}
	else if (key == 'e' || key == 'E'){
		heroFire = true;
		if (!firing){
			firing = true;
				shurikenX = heroCoordinateX;
				if (jumpUp) shurikenY = heroCoordinateY + heroCoordinateJump + 100;
				else 
					shurikenY = heroCoordinateY + 100;
		}
	}
	else if (key == 'p' || key == 'P'){
		if (!pause){
			pause = true;
		}
		else
		{
			pause = false;
		}
	}
	else if (key == 'm' || key == 'M'){
		
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0,0,0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\level3.wav", NULL, SND_LOOP | SND_ASYNC);
		}

	}
}
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_F2){

		if (frameShowed){
			frameIndex++;
			if (frameIndex ==13){
			level = 1;
			frameIndex = 0;
			frameShowed = false;
			//roundPass = true;
		}
		}
	}
}




int main()
{   
	setbackground();
	setbackground2();
	setbackground3();
	setVillianVariables1();
	setVillianVariables12();
	setVillianVariables21();
	setVillianVariables22();
	setVillianVariables31();
	setBossVariables();




	iSetTimer(400, changeBackground);
	iSetTimer(20, fire_shuriken);
	iSetTimer(100, villian1Show);
	iSetTimer(100, villian1Show1);
	iSetTimer(100, villian21Show);
	iSetTimer(100, villian22Show);
	iSetTimer(100, villian31Show);
	iSetTimer(100, bossShow);
	iSetTimer(20, fireCharacter);
	iSetTimer(20, jumpchange);


	showButton();


	if (musicOn)
	{
		PlaySound("music\\level3.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iInitialize(screenWidth, screenHeigth, projectName);




	iStart(); // it will start drawing

	return 0;
}

