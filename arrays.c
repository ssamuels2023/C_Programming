/*
Sophie Samuels
COP 2220
Program 7
This project was completed by one student (there was a group option available).
The project objective is to implement 4 programmer defined functions 
with use of loops, arrays, and c- style strings.
The program declares character arrays (inputWord, upperWord, hashWord, and originalWord) 
to hold original and modified versions of the input word. 
It then implements a do/while loop: prompts user to input a word, makes a copy of it, and modifies it.
After displaying the original and modified input, it asks if user wants to enter another word or quit program.
SophieGetInput Function: Asks user to input a word, without spaces, stores it in inputWord.
SophieMakeUpper Function: Takes user's input, creates all-uppercase version of it.
SophieHashtag Function: Converts uppercase word so all vowels are # and consonants are ~.
SophieCompund Function: Concatenates original input word, all-uppercase word, and #/~ word into one string. 
    Uses strcat function to append upperWord and hashWord to inputWord, storing result in inputWord. 
After processing, original input word, uppercase version, #/~ version, and the final concatenated result are printed.
*/

#include <stdio.h>
#include <ctype.h> //for toupper and tolower
#include <string.h> //for strlen and strcat and strcpy

//STUDENT 1

//input character
//ask and get a word from the user
void SophieGetInput(char inputWord[]);

//input 2 character arrays
//create an all uppercase version of the input word and store in the second parameter(upperWord)
void SophieMakeUpper(char inputWord[], char upperWord[]);

//input 2 character arrays (one all uppercase)
//create a hashtag/ tilde version of the uppercase word and store in the second parameter(hashWord)
void SophieHashtag(char upperWord[], char hashWord[]);

//input 3 character arrays
//concatenate all three together and store the result in the FIRST parameter (inputWord)
//add (upperWord) to (inputWord) then add (hashWord) to (inputWord) use strcat
void SophieCompund(char inputWord [], char upperWord [], char hashWord []);

int main()
{
//declare 3 character arrays size 100
char inputWord[100], upperWord[100], hashWord[100];
char originalWord[100];

char again;

//do {
do {
    //call all funcitons form here
    SophieGetInput(inputWord);
    //make a copy of inputWord as 'originalWord' to maintain the word 
    strcpy(originalWord, inputWord);
    SophieMakeUpper(inputWord, upperWord);
    SophieHashtag(upperWord, hashWord);
    SophieCompund(inputWord, upperWord, hashWord);
    
    //printf the results here
    printf("\n-------------------------\n");
    printf("\nThe 3 words are \n");
    printf("(1)input:\t %s\n", originalWord);
    printf("(2)uppercase:\t %s\n", upperWord);
    printf("(3)hash:\t %s\n", hashWord);
    printf("\n\nAll together (1,2,3):\t %s\n", inputWord);
    printf("\n-------------------------\n");

    //again?
    printf("Do you want to enter another word? (y/n): ");
    scanf(" %c", &again);
    //} while (again == 'y' || again == 'Y');
    } while (again == 'y' || again == 'Y');

printf("\nHave a great day!\n");

return 0;
}

//input character
//ask and get a word from the user
void SophieGetInput(char inputWord[])
{
    printf("\n-STUDENT ONE-\n");
    printf("\nEnter a word do not include any spaces in the word: ");
    scanf(" %s", inputWord);
}

//input 2 character arrays
//create an all uppercase version of the input word and store in the second parameter(upperWord)
void SophieMakeUpper(char inputWord[], char upperWord[])
{
    //copy input word into upperword (use strcpy)
    strcpy(upperWord, inputWord);
    //get the length
    int length = strlen(upperWord);
    //use a loop to change the characters one by one to uppercase
    for (int i = 0; i < length; i++)
    {
        upperWord[i] = toupper(upperWord[i]);
    }
}

void SophieHashtag(char upperWord[], char hashWord[])
{
    //copy input word into lowerword (use strcpy)
    strcpy(hashWord, upperWord);
    //get the length
    int length = strlen(hashWord);
    //search through and replace the characters in the hashtag word
    for (int i = 0; i < length; i++)
    {
        // Check if the character is a vowel
        if (upperWord[i] == 'A' || upperWord[i] == 'E' || upperWord[i] == 'I' || upperWord[i] == 'O' || upperWord[i] == 'U')
        {
            hashWord[i] = '#';
        }
        else
        {
            hashWord[i] = '~';
        }
    }
}

//input 3 character arrays
//concatenate all three together and store the result in the FIRST parameter (inputWord)
//add (upperWord) to (inputWord) then add (hashWord) to (inputWord)
void SophieCompund(char inputWord [], char upperWord [], char hashWord [])
{
    //use strcat - two function calls to strcat
    strcat(inputWord, upperWord);
    strcat(inputWord, hashWord);
}
