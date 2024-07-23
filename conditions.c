/*
Sophie Samuels
Program 4c
DisplayPhones function for ordering a phone and determining if within budget
compile, build, and execute code after completing the algorithm for prog 4
The purpose of this program is to establish skills with use of math in C, 
conditions, a while loop, and programmer defined functions
COP2220 2.20.2024
*/


#include<stdio.h> //for printf and scanf

//function prototypes

void Greeting(void);
//welcome the user to the phone purchasing app

double GetBudget();
//declare, ask, get, and return the budget amount 

int DisplayPhones();
//display the phones available, the price, and related item number
//declare, ask, get the item number
//return the item number

double SetPrice(int itemNumber);
//input: item number
//use the item number to identify the price 
//display the name of the phone and return the price 

void TryToCheckout(double budget, double price);
//input budget amount and phone price
//"purchase" the phone
//subtracts price from budget if purchase was made
//Lets the user know if price of phone is greater than budget

void DisplayBalance(double balance);
//input: remaining balance
//display remaining balance
//this function will be called from the TryToCheckout function

int main()
{
	//declare variables here
    double budget;
    double balance;
    double price;
    double itemPrice;
    int itemNumber;
    
	//greet the user
	Greeting();

	//get the budget- function call - GetBudget
	budget = GetBudget();
	//print the budget - use printf
    printf("\nThat is great news, your budget is $%.2f\n", budget);
    
	//get the item number - function call - DisplayPhones
    itemNumber = DisplayPhones();
	//print the item number - use printf
    printf("\nThe number of the item (printed in main) you selected was: %d\n", itemNumber);

	//get the price - function call - SetPrice
    itemPrice = SetPrice(itemNumber);
	//print the price - use printf
	printf("\nThe price of the phone (printed in main) is $%.2lf", itemPrice);

	//try to buy the phone - function call - TryToCheckout
    TryToCheckout(budget, itemPrice);

	//say goodbye to the user
	printf("\n\nHave a great day!");

	return 0;
}


//function definitions HERE
void Greeting()
//greet the user and provide general instructions for the program
{
    printf("\nWelcome to the FANTASTIC PHONE purchasing app");
    printf("\nYou will enter your budget for your phone purchase");
    printf("\nYou will be presented with a list of phones available for purchase");
    printf("\nPlease select the number for the PHONE you wish to purchase");
    printf("\nYou will checkout, purchase the phone - (only if you have enough in your budget)");
    printf("\nAfter checkout the remining balance of your budget will be displayed\n");
}
double GetBudget()
//declare, ask, get, and return the budget amount
{
    double availableFunds;
    printf("\nHow much money can you spend on your new phone?\t $");
    scanf("%lf", &availableFunds);
    return availableFunds;
}
int DisplayPhones( )
//display phones available with prices and item numbers
//declare, ask, get item numbers
//return chosen item number
{
    int item;
    do{
        printf("\n-------------------------------------------");
        printf("\nHere are your phone options:\n");
        printf("\n1. iPhone 14 Plus 128GB..........$829.99");
        printf("\n2. iPhone SE 64GB................$429.99");
        printf("\n3. Samsung Galaxy S24 512GB......$1,419.99");
        printf("\n4. Motorola Razr 2023 128GB......$499.99");
        printf("\n5. Google Pixel 7a 128GB.........$374.00");
        printf("\n6. Google Pixel 7Pro 128GB.......$899.00");
        printf("\n7. Nokia 2780 Flip...............$89.99");
        printf("\n8. Nokia C300 32GB...............$139.99");
        //code to manage values outside of parameters
        printf("\n\nEnter your selection (1-8): ");
        scanf("%d", &item);
        }while(item < 1 || item > 8);
        
    return item;
}
double SetPrice(int itemNumber)
//input: item number
//use item number to identify price
//display name of phone and return price
{
    int itemNum;
    //set value for price 
    double price = 0.00;
    
    if (itemNum == 1)
    {
        price = 829.99;
        printf("\nYou selected iPhone 14 Plus 128GB, the price is $%.2lf", price);
    }
    else if (itemNum == 2)
    {
        price = 429.99;
        printf("\nYou selected iPhone SE 64GB, the price is $%.2lf", price);
    }
    else if (itemNum == 3)
    {
        price = 1,419.99;
        printf("\nYou selected Samsung Galaxy S24 512GB, the price is $%.2lf", price);
    }
    else if (itemNum == 4)
    {
        price = 499.99;
        printf("\nYou selected Motorola Razr 2023 128GB, the price is $%.2lf", price);
    }
    else if (itemNum == 5)
    {
        price = 374.00;
        printf("\nYou selected Google Pixel 7a 128GB, the price is $%.2lf", price);
    }
    else if (itemNum == 6)
    {
        price = 899.00;
        printf("\nYou selected Google Pixel 7Pro 128GB, the price is $%.2lf", price);
    }
    else if (itemNum == 7)
    {
        price = 89.99;
        printf("\nYou selected Nokia 2780 Flip, the price is $%.2lf", price);
    }
   else if (itemNum == 8)
    {
        price = 139.99;
        printf("\nYou selected Nokia C300 32GB, the price is $%.2lf", price);
    }
    return price;
}
void TryToCheckout(double budget, double price)
//input budget amount and phone price
//"purchase" the phone
//subtracts price from budget if purchase was made
//Lets the user know if price of phone is greater than budget
{
    printf("\nThe price of the phone is $%.2lf and your budget is $%.2lf\n", price, budget);
    
    if (budget >= price)
    {
        printf("\nYour purchase was successful. Enjoy your new phone!\n");
        budget = budget - price;
        DisplayBalance(budget);
    }
    else
    {
        printf("\n\nYou do not have enough funds to complete this purchase.");
        printf("\n\nThe price is $%.2lf and your budget is only $%.2lf", price, budget);
    }
}
void DisplayBalance(double balance)
//display remaining balance which is calculated within TryToCheckout function
{
    printf("\nThe remaining balance in your budget is $%.2lf", balance);
}
