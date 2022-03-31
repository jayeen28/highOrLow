#include<stdio.h>
#include<stdlib.h>

/**
 * @brief This function is used for making the random number based on difficulty.
 * 
 * @param randomNumber The number user has to guess.
 * @param difficulity The difficulty level. 1-3.
 */
void makeRandomNumber(int *randomNumber,int difficulity){
	printf("%d",RAND_MAX);
};

int main(){
	int difficulity;//1-3(1 is easy 2 is medium 3 is hard)
	int randomNumber;//the number based on difficulity.
	printf("Welcome to high or low game!!\n");
	printf("Please select difficulty.\n 1.Easy (1-100)\n 2.Medium (1-1000)\n 3.Hard (1-10000)\n\n\nChoice: \n");
	scanf("%d", &difficulity);//take input from user for difficulity level.
	while(difficulity>3){//if user inputs more than 3, it will ask again.
		printf("Please select a valid difficulty from 1 to 3.\n");
		scanf("%d", &difficulity);
	};
	makeRandomNumber(&randomNumber,difficulity);
	return 0;
};
