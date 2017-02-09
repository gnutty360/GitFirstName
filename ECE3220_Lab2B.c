/*
Marshall Lindsay
ECE 3220 Lab2b
2/8/17
*/


#include <stdio.h>
#include <stdlib.h>


int exitMessage();
void welcomeMessage();
int checkExitInput(int);
void arithmatic(unsigned short int);
void bitwise(unsigned short int);
int checkNumber(unsigned int);


int main(void){
	
		do{
			
			welcomeMessage();
			
		}while(exitMessage());
		
		
	return(EXIT_SUCCESS);
}

/*
	Prompts the user for a number input. If the number is too large,
	a error is sent and a new input is prompted for. Then it asks for
	a choice how they want to procede. 1 for the aritmatic and 2 for the
	bitwise. From there it goes to the respective functions.
*/

void welcomeMessage(){
		
		unsigned int input;
		int choice;
		do{
			
			printf("\nPlease enter a number:");
			scanf("%u", &input);
			
		}while(checkNumber(input));
		printf("\nWhich method would you like to use?\n1)Arithmatic\n2)Bitwise\n:");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1:
				arithmatic(input);
				return;
			case 2:
				bitwise(input);
				return;
			default:
				printf("\nInvalid Input!");
				return;
			
		}
	return;
		
}

/*
	Takes the modulus of the input and 2 and stores it as the msb. It then divides
	the input by 2 and repeats the process. Each remainder is stored in the integer 
	array in the order from msb to lsb.
*/

void arithmatic(unsigned short int input){
	int remainder[16] = {0};
	//int wha;
	int counter;
	printf("\nThe binary representation of %hu is:\n", input);
	for(counter = 0; counter < 16; counter++){
		
		//wha = input%2;
		
		remainder[counter] = input%2;
		printf("%d", counter);
		input = input / 2;
		
	}
	
	for(counter = 15; counter >=0; counter-=1){
		
		printf("%d", remainder[counter]);
	}
	
	return;
}

/*
	Uses a mask and the fact that all decimal integers are internally 
	stored as binary along with the and operation to determine where the 
	1's and 0's are in the input. By shifting the mask (essentially a testing '1')
	and anding with the input, we can determine if there was a 1 in that position
	or not. 
*/

void bitwise(unsigned short int input){
	
	int operator = 0b1000000000000000;
	int counter;
	int hold;
	
	printf("\nThe binary representation of %hu is:\n", input);
	
	for(counter = 0; counter < 16; counter++){
		
		hold = input & operator;
		if(hold == 0){
			printf("0");
		}else{
			printf("1");
		}
		operator = operator >> 1;
	}
	
	
	return;
}

/*
	Prompts the user if they want to continue or not. Sends their input to be 
	error checked and appropriate return value is sent.
*/	

int exitMessage(){
	int input;
	
	do{
		printf("\nWould you like to try again?(1 yes 2 no)\n:");
	
		scanf("%d", &input);
	}while(checkExitInput(input));
	
	if(input == 2)
	{
		return(0);
	}else{
		return(1);
	}
	
}

/*
	Checks to make sure the user's exitMessage input is a valid input for
	the given options. 
*/
int checkExitInput(int input){
	
	switch(input){
		case 1:
		return(0);
		case 2:
		return(0);
		default:
			printf("Invalid input!\n");
		return(1);
		
	}
	
}

int checkNumber(unsigned int input){
	
	if(input > 65535){
		printf("\nInvalid input!");
		return(1);
	}
	return(0);
	
}