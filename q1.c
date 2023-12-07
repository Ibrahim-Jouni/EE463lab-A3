#include<stdio.h>

// Function to generate passwords recursively
void generatepasswords(char password[], int used[], int index) {

	static char letters[] = "abcdefghijklmnopqrstuvwxyz"; // Array of lowercase letters
	int i ;
	
	if (index == 4 ) {  // Base case: If the password length is 4, print the password and return

		printf("%s\n",password);
		return;


	}

	for( i=0; i<26;i++) { // Iterate through each letter

		if (!used[i]){ // Check if the letter is already used

			password[index] = letters[i]; // Add the letter to the password
			used[i] = 1;  // Mark the letter as used
			generatepasswords(password, used, index + 1 ); // Recursive call to generate the next character
			used[i]=0;// Backtrack: Mark the letter as unused for the next iteration

		}
	}
}

int main () {
	char password[5];// Array to store the generated password
	int used[26] = {0};// Array to keep track of used letters, initialized to 0

	generatepasswords(password, used,0);// Call the function to generate passwords 
	return 0;
} 
