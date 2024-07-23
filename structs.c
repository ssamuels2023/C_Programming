/* 
Sophie Samuels
COP2220 Program 8 Structs
04.16.2024
This program creates a structure called 'bird' which represents birds including
attributes of name, color, and average weight. 
The name and color attributes are strings, the average weight is stored
as a double. 
FillBird() prompts user to enter details for an individual bird,
returns the filled bird structure
FillBirdPtr(bird *birdptr) fills the bird structure by directly modifying
the memory location pointed to by the argument using pass by reference 
FillBirdArray(bird arrayB[], int *size) Fills an array of birds by asking
for the number of birds, then user is prompted to input details for each
bird in the array
DisplayBird(bird anyBird) displays details of an individual bird
*/
#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct{
    char name[20];
    char color[20];
    double weight;
}bird;

//Function Prototypes
// fills the data fields of a bird instance
//returns the filled bird
bird FillBird();

//fills the data fields of a bird instance
//by reference using a pointer to a bird
void FillBirdPtr(bird *birdptr);

//fills an array of bird
void FillBirdArray(bird arrayB[], int *size);

//displays one bird
void DisplayBird(bird anyBird);


int main()
{
    
    //Declare variables
    bird Bird, Bird1, Bird2;
    bird birdList[20];
    int bSize;
    int i;
    
    //Fill structures with a function
    Bird = FillBird();
    Bird1 = FillBird();
    
    //print using display function
    printf("\n---------Display Bird\n");
    DisplayBird(Bird);
    printf("\n---------Display Bird1\n");
    DisplayBird(Bird1);
    
    //Fill structure using pointers and dispay it
    FillBirdPtr(&Bird2);
    printf("\n---------Display Bird2\n");
    DisplayBird(Bird2);
    
    //Fill the array with the function
    printf("\n---------Fill array birdList\n");
    FillBirdArray(birdList, &bSize);
    
    //display an array of birds
    printf("\n---------Display array birdList\n");
    for(i=0;i<bSize; i++)
    {
        DisplayBird(birdList[i]);
    }
    
    return 0;
}

//Function Definitions

// fills the data fields of a bird instance
//returns the filled bird
bird FillBird()
{
    //Declare local variables
    bird tempB;
    //prompt and get information
    printf("\nplease enter the name of the bird: ");
    scanf("%s", tempB.name);
    //print to check
    printf("name: %s\n", tempB.name);

    //prompt and get information
    printf("\nplease enter the color of the bird: ");
    scanf("%s", tempB.color);
    //print to check
    printf("color: %s\n", tempB.color);
    
    //prompt and get information
    printf("\nplease enter the average weight of the bird: ");
    scanf("%lf", &tempB.weight);
    printf("average weight: %lf\n", tempB.weight);
    return tempB;
}

//displays one card
void DisplayBird(bird anyBird)
{
    printf("\n\nname: %s\n", anyBird.name);
    printf("color: %s\n", anyBird.color);
    printf("average weight: %lf\n", anyBird.weight);
}

//fills the data fields of a bird instance
//by reference using a pointer to a bird
void FillBirdPtr(bird *birdptr)
{
    //prompt and get information
    printf("\nplease enter the name of the bird: ");
    scanf("%s", (*birdptr).name);

    //prompt and get information
    printf("\nplease enter the color of the bird: ");
    scanf("%s", birdptr->color);
    
    //prompt and get information
    printf("\nplease enter the average weight of the bird: ");
    scanf("%lf", &(*birdptr).weight);
}


//fills an array of cards
void FillBirdArray(bird arrayB[], int *size)
{
    int i;
    
    //prompt the user
    printf("\nenter the number of birds: ");
    scanf("%d", size);
    
    //print to check
    printf("size: %d\n", *size);
    
    for (i=0; i < *size; i++)
    {
        printf("enter name: ");
        scanf("%s", arrayB[i].name);

        printf("enter color: ");
        scanf("%s", arrayB[i].color);

        printf("enter average weight: ");
        scanf("%lf", &arrayB[i].weight);
    }
}
