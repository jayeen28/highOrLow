#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
 * @brief This function is used to decide the random number range.
 * 
 * @param range The pointer of the variable range.
 * @param difficulty The level of difficulty.
 */
void decideRange(int *range ,int difficulty){
	switch(difficulty){
		case 1:
			*range=100;
			break;
		case 2:
			*range=1000;
			break;
		case 3:
			*range=10000;
			break;
		default:
			*range=100;
			break;
	};
};

/**
 * @brief This function is used for making the random number based on difficulty.
 * 
 * @param randomNumber The number user has to guess.
 * @param difficulity The difficulty level. 1-3.
 */
void makeRandomNumber(int *randomNumber,int difficulty){
	int range;
	decideRange(&range,difficulty);
	srand(time(NULL));
	*randomNumber=rand()%range;
};

int main(){
	int difficulty;//1-3(1 is easy 2 is medium 3 is hard)
	int randomNumber;//the number based on difficulity.
	int guessNumber;//the number user guess.
	int playAgain=0;//0-1(0 is no 1 is yes)
	int tried=0;//the number of tries.

	printf("Welcome to high or low game!!\n");
	printf("Please select difficulty.\n 1.Easy (1-100)\n 2.Medium (1-1000)\n 3.Hard (1-10000)\n\n\nChoice: ");
	scanf("%d", &difficulty);//take input from user for difficulity level.
	while(difficulty<=0 || difficulty>3){//if user inputs more than 3, it will ask again.
		printf("Please select a valid difficulty from 1 to 3.\n");
		scanf("%d", &difficulty);
	};
	makeRandomNumber(&randomNumber,difficulty);
	printf("Guess: ");
	scanf("%d",&guessNumber);//take input from user for guessed number.
	while(guessNumber!=randomNumber){//if user guess wrong, it will ask again.
		tried++;//increase the number of tries.
		if(guessNumber>randomNumber){
			printf("Too high!\n");
		}else{
			printf("Too low!\n");
		};
		printf("Guess: ");
		scanf("%d",&guessNumber);
	};
	printf("You have won after trying %d times.\nDo you want to play again?\n1.Yes\n2.No\n",tried);
	printf("Choice: ");
	scanf("%d",&playAgain);//take input from user for play again.
	if(playAgain==1){//if user want to play again, it will ask again.
		main();
	}else{
		printf("Thank you for playing!\n");
	};
	int choice;
	return 0;
};
