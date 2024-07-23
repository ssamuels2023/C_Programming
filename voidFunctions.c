/*
Sophie Samuels
Program 3
Programmer defined functions
A simple program to convert pounds to kilos and kilos to pounds
COP2220 2.06.2024
*/

#include<stdio.h> //for printf and scanf
#include<math.h> //for floor and ceil

//function prototypes here
//greeting message
void SamuelsGreeting(); 
void SamuelsGreetingTwo();

//input: double value (pounds)
//declare, ask, and get value in pounds
//convert value to kilos 
//print value in pounds and in kilos
void PoundsToKilos(); 

//input: double value (pounds)
//declare, ask, and get value in kilos 
//convert value to pounds
//print value in kilos and in pounds 
void KilosToPounds();

//main function 
int main()
{
    double pounds, kilos;
    
    //call functions
    SamuelsGreeting();
    PoundsToKilos();
    SamuelsGreetingTwo();
    KilosToPounds();
    
return 0;
}

//function definitions here
void SamuelsGreeting()
{
    printf("Welcome, my name is Sophie Samuels");
    printf("\nMy birthday is in September and I will convert pounds to kilograms.\n");
}

void PoundsToKilos()
{
    //declare variables
    double pounds, kilos;
    
    
    printf("\nEnter weight in pounds: ");
    scanf("%lf", &pounds);
    
    kilos = pounds * 0.453592;
    printf("%.3lf pounds is %.3lf kilograms\n", pounds, kilos);
    printf("\n---------------------------------------------------------------");
    //ceiling
    printf("\nRounded to the ceiling:\n");
    kilos = ceil(pounds *0.453592); 
    printf("%.3lf pounds is %.3lf kilograms\n", pounds, kilos);
    
    printf("\n*************************************************************\n");
}

void SamuelsGreetingTwo()
{
   printf("\nWelcome, my name is Sophie Samuels");
    printf("\nMy birthday is in September and I will convert kilograms to pounds.\n");
} 

void KilosToPounds()
{
    double pounds, kilos;
    
    printf("\nEnter weight in kilograms:");
    scanf("%lf", &kilos);
    
    pounds = kilos * 2.20462;
    printf("%.3lf kilograms is %.3lf pounds\n", kilos, pounds);
    printf("\n---------------------------------------------------------------");
    //floor
    printf("\nRounded to the floor:\n");
    pounds = floor(kilos *0.453592); 
    printf("%.3lf kilograms is %.3lf pounds\n", kilos, pounds);
}
