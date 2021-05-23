#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int ask(); //function for asking the user to choose the option.
int generate(); //function for auto generate random option for computer choice.
int checkWins(int userChoiceAsInt, int ComputerChoice); ////function for comparing between both choice.
void total(int previous); //function for determind the result after comparing.


int main()
{
	int wins = 0;
	int computerWins = 0;
	int rounds;
	int finalresult = 0;

	srand(time(0));

	printf("\t\t*  *  *  Welcome to Rock Paper Scissors Game!!  *  *  *\n\n");
	printf("\tHow Many Rounds you wishes to play??\n");
	scanf("%d", &rounds);

	for (int i = 1; i <= rounds; i++)
	{
		int userChoiceAsInt =ask();
		int ComputerChoice = generate();
		int result = checkWins(userChoiceAsInt, ComputerChoice);
		finalresult += result;
	}
	printf("The Final Result of Total Rounds (%d) is %d\n", rounds, finalresult);
	total(finalresult);
	printf("\n\n* * * * * The Game Ends * * * * *");
}


int ask()
{
	char userChoiceAsChar;
	int userChoiceAsInt;
	do
	{
		printf("Please enter your Choice: R/rock , P/paper, S/scissors: \n");
		scanf(" %c", &userChoiceAsChar);

		printf("You Have Entered: %c\n", userChoiceAsChar);

		if (userChoiceAsChar == 'r' || userChoiceAsChar == 'R')  //after getting the input from user leveling it 
																 //to rock paper scissor in both ways
		{
			userChoiceAsInt = 1;
			printf("User Choice is Rock \n");
			break;
		}
		else if (userChoiceAsChar == 'p' || userChoiceAsChar == 'P')
		{
			userChoiceAsInt = 2;
			printf("User Choice is Paper \n");
			break;
		}
		else if (userChoiceAsChar == 's' || userChoiceAsChar == 'S')
		{
			userChoiceAsInt = 3;
			printf("User Choice is Scissor \n");
			break;
		}
		else
		{
			printf("Wrong Input!\n");
		}

	} while (1);
	return userChoiceAsInt; //return user choice for final calculation
}

int generate()
{
	int ComputerChoice = 0;
	ComputerChoice = rand() % 3 + 1; //auto generate randon number and store it in ComputerChoice
									 //and  level it with rock paper scissor

	if (ComputerChoice == 1)
	{
		printf("Computer has choosen Rock !!\n");
	}
	else if (ComputerChoice == 2)
	{
		printf("Computer has choosen Paper !!\n");
	}
	else if (ComputerChoice == 3)
	{
		printf("Computer has choosen Scissor !!\n");
	}

	return ComputerChoice; ////return random computer choice for final calculation
}

int checkWins(int userChoiceAsInt, int ComputerChoice) //calculation from user input and computer output
{
	int result = 0;

	if (userChoiceAsInt == 1 && ComputerChoice == 3 || userChoiceAsInt == 2 && ComputerChoice == 1 || userChoiceAsInt == 3 && ComputerChoice == 2)
	{
		printf("Congratulations!! You Have WON this round !!\n\n");
		result = result++;
	}
	else if (userChoiceAsInt == ComputerChoice)
	{
		printf("OH hoo !! It's a DRAW ! \n\n");
		result = result + 0;
	}
	else
	{
		printf("Computer Wins , Better Luck Next Time!!\n\n");
		result = result--;
	}
	return result; // each user win is +1,lost -1 and draw 0; this return final output.
}

void total(int previous) // if +ve user win, -ve pc win, 0 draw
{
	if (previous > 0 )
	{
		printf("So, User Wins\n");
	}
	else if (previous < 0)
	{
		printf("So, Computer Wins\n");
	}
	else
	{
		printf("So, Its a Draw\n");
	}
}
