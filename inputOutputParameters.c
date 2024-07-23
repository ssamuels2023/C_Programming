/*
Sophie Samuels
COP 2220
Program 6
This program builds on the features learned to implement programs 4 and 5. 
The program welcomes the user including program instructions;
ask, get, return budget; prompt user to select choice (S, C, U, Q):
'S' to select phone, displays ONLY phones in budget, price based on item number,
can select -1 if user does not want to purchase a phone in budget
'C' to checkout, if phone in budget is selected, if phone NOT in budget the
purchase will NOT be made, if -1 is selected price = 0.00 and error message 
displayed if user tries to check out
'U' to update budget, can change budget if not enough money to purchase phone of 
choice
'Q' to quit, user may purchase more than one phone and will select Q when
ready to quit program
This program implements the use of pointers and loops per course material.  
March 25, 2024
*/

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes

//NEW function for program 6
void ProcessChoice(char choice, double* budgetPtr, int* numPtr, double*
pricePtr);
//input: choice by value, budget by reference(input/output),
//item number by reference(input/output), price by reference(input/output)
//process and call the function for the selection

void DisplayChoices(char* choice);//NEW function for program 6
//character input/output (reference) parameter
//display and get the choice (s, c, u, or q)

void Greeting(void); //same function, update the message
//welcome the user to the phone purchasing app

double GetBudget();//same function as PRGRAM 4 and PROGRAM 5
//declare, ask, get, and return the budget amount

int DisplayPhones(double budget); //add the budget for program 6
//input: budget value (amount)
//display the phones available within the budget, the price, and related item number
//declare, ask, get the item number
//return the item number
//the user should enter (-1) if they do not want to select any of the available phones

double SetPrice(int itemNumber); // same function as PRGRAM 4 and PROGRAM 5
//input: item number
//use the item number to identify the price
//return the price

void TryToCheckout(double* budget, double price); //new function for program 6
//input the budget amount (input/output parameter) and the phone price by value
//"purchase" the phone - subtracts the price from the "value at" budget if the purchase was made
//Lets the user know if the phone price is greater than the budget

void DisplayBalance(double balance); // same function as PRGRAM 4 and PROGRAM 5
//display the balance


int main()
{
    //declare variables
    double budget = 0.0, price = 0.0; //#9 from STEP BY STEP
    int itemNum = 0;
    char choice; 

    //Greeting //#8 from STEP BY STEP
    Greeting();

    //get budget
    //display budget
    //#10 & #11 from STEP BY STEP
    budget = GetBudget();
    printf("\nYour balance (budget) is $%.2f\n", budget);
    
    DisplayChoices(&choice); //NEW function for program 6 //INITIALIZE
    //character input/output (reference) parameter
    //display and get the choice (s, c, u, or q)
    
    while (toupper(choice) != 'Q') //TEST
    {
        ProcessChoice(choice, &budget, &itemNum, &price);
        DisplayChoices(&choice);
    
        if (toupper(choice) == 'S')
        {
            //itemNum = DisplayPhones(budget);
            //price = SetPrice(itemNum);//calling from main to TEST
            printf("\nThe price is $%.2f\n", price);
        }
        //update budget
        else if (toupper(choice) =='U')
        {
            //printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", budget, price);
            printf("\nUpdate your budget\n");
            budget = GetBudget();
            ////printf("\nYour budget (printed in main) is $%.2f\n", budget);
            DisplayChoices(&choice);
        }
        //checkout with selected phone
        else if (toupper(choice) == 'C' && itemNum!= 0)
        {
            if (itemNum != 0)
            {
                ////printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", budget, price);
                TryToCheckout(&budget, price);
                itemNum = 0;
                price = 0;
                DisplayChoices(&choice);
            }
        }

    }
    printf("\nHave a great day!\n\n");

    return 0;

}
//function definitions
void Greeting(void)
//welcome the user to the phone purchasing app
//#7 from STEP BY STEP
{
    printf("\nWelcome to the FANTASTIC PHONE purchasing app");
    printf("\nYou will enter your budget for your phone purchase");
    printf("\nYou will be presented with a list of phones available for purchase (within your budget)");
    printf("\nPlease select the number for the PHONE you wish to purchase");
    printf("\nIf you do not like any of the available phones select (-1)");
    printf("\nYou will checkout (purchase the phone, if you have enough in your budget)");
    printf("\nYou will have the opportunity to update your budget if needed");
    printf("\nYou will have the opportunity to purchase more than one phone, until you select 'Q' to QUIT\n");
}

double GetBudget() 
//declare, ask, get, and return the budget amount
//#10 & #11 from STEP BY STEP
{
    double funds;
    printf("\nHow much money can you spend on your new phone?\t $");
    scanf("%lf", &funds);
    return funds;
}

void DisplayChoices(char* choice) //NEW function for program 6
//character input/output (reference) parameter
//display and get the choice (s, c, u, or q)
//#12 from STEP BY STEP
{
    //display menu choices
    printf("\n*************************\n");
    printf("\nEnter (s or S) to select a phone");
    printf("\nEnter (u or U) to update your budget");
    printf("\nEnter (c or C) to Checkout");
    printf("\nEnter (q or Q) to Quit");
    printf("\n\n*************************\n");
    
    //get choice
    printf("\nEnter your choice: ");
    scanf(" %c", choice);
}

int DisplayPhones(double budget) //add the budget for program 6
//input: budget value (amount)
//display the phones available within the budget, the price, and related item number
//declare, ask, get the item number
//return the item number
//the user should enter (-1) if they do not want to select any of the available phones
{
int itemNum;
    printf("\n------------------------------------------\n");
    printf("Here are your options (within your budget):\n");
    if (budget >= 1419.99)
    {
        printf("1. Samsung Galaxy S24 512GB . . . . . . . $1,419.99\n");
    }
    if (budget >= 899.00)
    {
        printf("2. iPhone SE 64GB . . . . . . . . . . . . $899.00\n");
    }
    if (budget >= 829.99)
    {
        printf("3. iPhone 14 Plus 128GB . . . . . . . . . $829.99\n");
    }
    if (budget >= 499.99)
    {
        printf("4. Motorola Razr 2023 128GB . . . . . . . $499.99\n");
    }
    if (budget >= 429.99)
    {
        printf("5. iPhone SE 64GB . . . . . . . . . . . . $429.99\n");
    }
    if (budget >= 374.00)
    {
        printf("6. Google Pixel 7a 128GB . . . . . . . . $374.00\n");
    }
    if (budget >= 139.99)
    {
        printf("7. Nokia C300 32GB . . . . . . . . . . . $139.99\n");
    }
    if (budget >= 89.99)
    {
        printf("8. Nokia 2780 Flip . . . . . . . . . . . $89.99\n");
    }
    printf("\nEnter your selection, if you enter a number that is not listed you will not be able to make a purchase:\n");
    printf("If you do not want any of the options listed, enter -1\n");
    scanf("%d", &itemNum);
    return itemNum;
}

double SetPrice(int itemNumber)
//input: item number
//use item number to identify price
//display name of phone and return price
{
    int itemNum;
    int choice;
    //set value for price 
    double price = 0.00;
    
    if (itemNumber == 1)
    {
        price = 1419.99;
    }
    else if (itemNumber == 2)
    {
        price = 899.00;
    }
    else if (itemNumber == 3)
    {
        price = 829.99;
    }
    else if (itemNumber == 4)
    {
        price = 499.99;
    }
    else if (itemNumber == 5)
    {
        price = 429.99;
    }
    else if (itemNumber == 6)
    {
        price = 374.00;
    }
    else if (itemNumber == 7)
    {
        price = 139.99;
    }
    else if (itemNumber == 8)
    {
        price = 89.99;
    }
    return price;
}

void DisplayBalance(double balance)
    {
        printf("Your remaining balance is $%.2f\n", balance);
    }
    
void TryToCheckout(double* budget, double price) //new function for program 6
//input the budget amount (input/output parameter) and the phone price by value
//"purchase" the phone - subtracts the price from the "value at" budget if the purchase was made
//Lets the user know if the phone price is greater than the budget
{
    if (price > *budget)
    {
        printf("\nLet's try to checkout\n");
        printf("\nThe price is $%.2lf and your budget is $%.2lf", price, *budget);
        printf("\n\nYou cannot buy this phone, you will need to select a different phone OR update your budget\n");
    }
    else
    {
        printf("\nLet's try to checkout\n");
        printf("\nThe price is $%.2lf and your budget is $%.2lf\n", price, *budget);
        printf("\nThe purchase was successful!\n\n");
        *budget -= price;
        DisplayBalance(*budget);
    }
}

void ProcessChoice(char choice, double* budgetPtr, int* numPtr, double*
pricePtr)
//input: choice by value, budget by reference(input/output),
//item number by reference(input/output), price by reference(input/output)
//process and call the function for the selection
{
    if (toupper(choice) == 'S')
    {
        printf("\nSelect the phone\n");
        *numPtr = DisplayPhones(*budgetPtr);
        if (*numPtr != -1)
        {
            *pricePtr = SetPrice(*numPtr);
            printf("\nThe price is $%.2f\n", *pricePtr);
        }
        else
        {
            *numPtr = 0; //reset selection if -1 is selected
        }
    }
    //update budget
    else if (toupper(choice) =='U')
    {
        printf("\nUpdate your budget\n");
        *budgetPtr = GetBudget();
        printf("\nYour budget is $%.2f\n", *budgetPtr);
    }
    //checkout with selected phone
    else if (toupper(choice) == 'C')
    {
        if (*numPtr != 0)
        {
            printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", *budgetPtr, *pricePtr);
            TryToCheckout(budgetPtr, *pricePtr);
            *numPtr = 0; //reset itemNum to prevent looping in purchase function
        }
        else
        {   //if user did not make selection and attempts checkout
            printf("\nLet's try to checkout\n");
            printf("\nThe price is $%.2lf and your budget is $%.2lf\n", *pricePtr, *budgetPtr);
            printf("\nThe price is $%.2lf, you have not selected a phone!", *pricePtr);
        }
    }
    //prompt user to choose from menu
    else 
    {
        printf("\nInvalid choice. Please enter S, U, or Q.\n");
    }
    
}
