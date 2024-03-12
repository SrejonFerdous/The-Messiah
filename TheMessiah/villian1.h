#ifndef VILLIAN1_INCLUDED
#define VILLIAN1_INCLUDED
#include "variables.h"
#include "scores.h"

villian villian1[numbersOfVillian];
villian villian12[numbersOfVillian];

void villian1Movement(){
	for (int i = 0; i < numbersOfVillian; i++){
		if (villian1[i].villian_show){
			iShowBMP2(villian1[i].villianX, villian1[i].villianY, level_1_villianattack[villian1[i].villian_index], 255);

		}
	}
}

void villian12Movement(){
	for (int i = 0; i < numbersOfVillian; i++){
		if (villian12[i].villian_show){
			iShowBMP2(villian12[i].villianX, villian12[i].villianY, level_1_villianattack[villian12[i].villian_index], 255);

		}
	}
}



void setVillianVariables1(){
	int sum = 350;
	for (int i = 0; i < numbersOfVillian; i++){
		villian1[i].villianX = screenWidth + sum;
		villian1[i].villianY = rand()%100;
		villian1[i].villian_index = rand() % 4;
		villian1[i].villian_show = true;
		sum += 300;
	}
}

void setVillianVariables12(){
	int sum = 350;
	for (int i = 0; i < numbersOfVillian; i++){
		villian12[i].villianX = screenWidth + sum;
		villian12[i].villianY = rand() % 100;
		villian12[i].villian_index = rand() % 4;
		villian12[i].villian_show = true;
		sum += 350;
	}
}
void villian1Show(){
	if (level == 1){
		if (!pause){
			for (int i = 0; i < numbersOfVillian; i++){
				villian1[i].villianX -= 25;
				int sum = 0;
				if (villian1[i].villianX <= 0){
					villian1[i].villianX = screenWidth + sum;
					sum += 300;
				}
				villian1[i].villian_index++;

				if (villian1[i].villian_index >= 3){
					villian1[i].villian_index = 0;
				}
				if (shurikenX >= villian1[i].villianX && shurikenX <= villian1[i].villianX + 100 && shurikenY >= villian1[i].villianY&&shurikenY <= villian1[i].villianY + 100){
					villian1[i].villian_show = false;
					killScore++;
					stringConverter(killScore);
					highscore();
				}
				if (villian1[i].villian_show){
					if (villian1[i].villianX >= heroCoordinateX&&villian1[i].villianX <= heroCoordinateX + 174)
					{
						attacked++;
						if (attacked == 10)
						{
							life++;
							attacked = 0;
						}
						if (!pause){
							if (life >= 6){
								life = 0;
								//level = 0;
								//gameState = 5;
							}
						}
					}
				}
			}
		}
	}
}
void villian1Show1(){
	if (level == 1){
		if (!pause){
			for (int i = 0; i < numbersOfVillian; i++){
				villian12[i].villianX -= 35;
				int sum = 0;
				if (villian12[i].villianX <= 0){
					villian12[i].villianX = screenWidth + sum;
					sum += 350;
				}
				villian12[i].villian_index++;

				if (villian12[i].villian_index >= 3){
					villian12[i].villian_index = 0;
				}
				if (shurikenX >= villian12[i].villianX && shurikenX <= villian12[i].villianX + 100 && shurikenY >= villian12[i].villianY&&shurikenY <= villian12[i].villianY + 100){
					
						villian12[i].villian_show = false;
						killScore++;
						stringConverter(killScore);
						highscore();
				}
				if (villian12[i].villian_show){
					if (villian12[i].villianX >= heroCoordinateX&&villian12[i].villianX <= heroCoordinateX + 174)
					{
						attacked++;
						if (attacked == 10)
						{
							life++;
							attacked = 0;
						}
						if (!pause){
							if (life >= 6){
								level = 0;
								//life = 0;
								gameState = 5;
							}
						}
					}
				}
			}
		}
		
	}
}


#endif