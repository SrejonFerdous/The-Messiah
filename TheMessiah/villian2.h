#ifndef VILLIAN2_INCLUDED
#define VILLIAN2_INCLUDED
#include "variables.h"

villian villian21[numbersOfVillian2];
villian villian22[numbersOfVillian2];

void villian21Movement(){
	for (int i = 0; i < numbersOfVillian2; i++){
		if (villian21[i].villian_show){
			iShowBMP2(villian21[i].villianX, villian21[i].villianY, level_2_villianattack[villian21[i].villian_index], 255);

		}
	}
}

void villian22Movement(){
	for (int i = 0; i < numbersOfVillian2; i++){
		if (villian22[i].villian_show){
			iShowBMP2(villian22[i].villianX, villian22[i].villianY, level_2_villianattack[villian22[i].villian_index], 255);

		}
	}
}



void setVillianVariables21(){
	int sum = 350;
	for (int i = 0; i < numbersOfVillian2; i++){
		villian21[i].villianX = screenWidth + sum;
		villian21[i].villianY = rand()%100;
		villian21[i].villian_index = rand() % 3;
		villian21[i].villian_show = true;
		sum += 500;
	}
}

void setVillianVariables22(){
	int sum = 350;
	for (int i = 0; i < numbersOfVillian2; i++){
		villian22[i].villianX = screenWidth + sum;
		villian22[i].villianY = rand() % 100;
		villian22[i].villian_index = rand() % 3;
		villian22[i].villian_show = true;
		sum += 550;
	}
}
void villian21Show(){
	if (level == 2){
		if (!pause){
			for (int i = 0; i < numbersOfVillian2; i++){
				villian21[i].villianX -= 55;
				int sum = 0;
				if (villian21[i].villianX <= 0){
					villian21[i].villianX = screenWidth + sum;
					sum += 500;
				}
				villian21[i].villian_index++;

				if (villian21[i].villian_index >= 3){
					villian21[i].villian_index = 0;
				}
				if (shurikenX >= villian21[i].villianX && shurikenX <= villian21[i].villianX + 180 && shurikenY >= villian22[i].villianY&&shurikenY <= villian22[i].villianY +180){
					
					villian21[i].villian_show = false;
					killScore++;
					stringConverter(killScore);
					highscore();
				}
				if (villian21[i].villian_show){
					if (villian21[i].villianX >= heroCoordinateX&&villian21[i].villianX <= heroCoordinateX + 174)
					{
						attacked++;
						if (attacked >= 15)
						{
							life1++;
							attacked = 0;
						}
						if (!pause){
							if (life1 >= 6){
								//life1 = 0;
								level = 0;
								gameState = 5;
							}
						}
					}
				}
			}
		}
	}
}
void villian22Show(){
	if (level == 2){
		if (!pause){
			for (int i = 0; i < numbersOfVillian2; i++){
				villian22[i].villianX -= 55;
				int sum = 0;
				if (villian22[i].villianX <= 0){
					villian22[i].villianX = screenWidth + sum;
					sum += 550;
				}
				villian22[i].villian_index++;

				if (villian22[i].villian_index >= 3){
					villian22[i].villian_index = 0;
				}
				if (shurikenX >= villian22[i].villianX && shurikenX <= villian22[i].villianX + 180 && shurikenY >= villian22[i].villianY&&shurikenY <= villian22[i].villianY + 180){
				
					villian22[i].villian_show = false;
					killScore++;
					stringConverter(killScore);
					highscore();
				
				}
				if (villian22[i].villian_show){
					if (villian22[i].villianX >= heroCoordinateX&&villian22[i].villianX <= heroCoordinateX + 174)
					{
						attacked++;
						if (attacked >= 15)
						{
							life1++;
							attacked = 0;
						}
						if (!pause){
							if (life1 >= 6){
								//life1 = 0;
								level = 0;
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