#ifndef HEROMOVEMENT_INCLUDED
#define HEROMOVEMENT_INCLUDED
#include "variables.h"
#include<iostream>

void Jump(){
	
	if (firing){
	
			iShowBMP2(shurikenX, shurikenY - 50, shuriken[0], 255);
	}
	
	

	if (jumpUp)
	{

		if (reverseStand){

			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[0], 255);
			
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 255);
		} 
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[0], 255);
		}
	


	}


	else
	{
		if (reverseStand){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[1], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 255);
		}
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[1], 255);
		}
	}

}

void Character(){
	if (firing){
		iShowBMP2(shurikenX, shurikenY - 50, shuriken[0], 255);
	}

	if (!standPosition){
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herorevwalk[heroReverseIndex], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 255);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herowalk[heroIndex], 255);
		}

		standCounter++;
		if (standCounter >= 10){
			standCounter = 0;
			standPosition = true;
			heroIndex = 0;
		}
	}
	else
	{
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[1], 255);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 255);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[0], 255);
		}

	}
}


void jumpchange(){

	if (jump){

		if (jumpUp){

			heroCoordinateJump += 10;
			if (heroCoordinateJump >= JUMPLIMIT){

				jumpUp = false;

			}
		}
		else{
			heroCoordinateJump -= 10;

			if (heroCoordinateJump < 0){

				jump = false;

				heroCoordinateJump = 0;
			}
		}
	}


}


void fire_shuriken(){
	if (firing){
		for (int i = 0; i < 200; i++){
			shurikenX++;
			if (shurikenX>screenWidth){
				firing = false;
				shurikenX = heroCoordinateX + 100000000000000000;

			}
		}
	}
}
void fireCharacter(){
	if (heroFire){
		fireIndex++;
		if (fireIndex >= 4){
			fireIndex = 0;
			heroFire = false;
		}
	}

}

void levelChange(){
	if (heroCoordinateX >= screenWidth - 150 && heroCoordinateY <= 100 && level == 1){
	
		level = 2;
	}
	else if (heroCoordinateX >= screenWidth - 150 && heroCoordinateY>=110 && level == 2){
		roundPass = true;
		level = 3;
	}
	else if (heroCoordinateX >= screenWidth - 150 && heroCoordinateY <= 100 && level == 3){
		gameState = 6;
	}
}

#endif