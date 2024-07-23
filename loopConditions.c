/*
Sophie Samuels
COP 2220
Program 5
Expanding phone selection purchasing app to include loops
which allow the user to choose between options: 
select phone, update budget, checkout, and quit program
February 28, 2024
*/

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes HERE

void Greeting(void);
//welcome the user to the phone purchasing app

double GetBudget();//SAME AS PROGRAM 4
//declare, ask, get, and return the budget amount

int DisplayPhones(); //SAME AS PROGRAM 4
//display the phones available, the price, and related item number
//declare, ask, get the item number
//return the item number

double SetPrice(int itemNumber);//SAME AS PROGRAM 4
//input: item number
//use the item number to identify the price
//display the name of the phone and return the price

void DisplayBalance(double balance);//SAME AS PROGRAM 4
//input: the remaining balance
//display the remaining balance
//ADD THE DOUBLE RETURN TYPE

double TryToCheckout(double budget, double price);
//input budget amount and phone price
//"purchase" phone - returns remaining budget
//subtracts price from budget if purchase was made
//Lets user know if price of phone is greater than budget

//NEW FUNCTION FOR PROGRAM 5
char DisplayAndGetChoice();
//declare a character
//display the menu options(s, c, u, or q)
//get and return the user's choice

int main()
{
//declare variables
    double budget;
    double balance;
    double price;
    int itemNumber = 0;
    char choice; //NEW variable for program 5
    
    //function calls HERE
    
	//greet the user
	Greeting();

	//get budget
	budget = GetBudget();
	//print budget
    printf("\nThe balance(budget) is $%.2f\n", budget);
    
    //display menu for user choices
    choice = DisplayAndGetChoice();
    
    while (toupper(choice) != 'Q') 
    {
        //display phones, select phone
        if (toupper(choice) == 'S')
        { 
            printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", budget, price);
            printf("\nSelect the phone\n");
            itemNumber = DisplayPhones();
            price = SetPrice(itemNumber);
        }
        //update budget
        else if (toupper(choice) =='U')
        {
            printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", budget, price);
            printf("\nUpdate your budget\n");
            budget = GetBudget();
            printf("\nThe balance(budget) is $%.2f\n", budget);
        }
        //checkout with selected phone
        else if (toupper(choice) == 'C')
        {
            if (itemNumber != 0)
            {
                printf("\nYour budget is $%.2lf and price of the phone (printed in main) is $%.2lf\n", budget, price);
                balance = TryToCheckout(budget, price);
                itemNumber = 0; //reset item number after selection/checkout
            }
            else
            {   //if user did not make selection and attempts checkout
                printf("\nPlease select a phone before checking out.\n");
            }
        }
        //prompt user to choose from menu
        else if (toupper(choice) != 'Q')
        {
            printf("\nInvalid choice. Please enter S, U, or Q.\n");
        }
        //allow a new user input
        choice = DisplayAndGetChoice();
    }
    //quit program 
    printf("\n\nHave a great day!\n");

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
        printf("\nYou selected iPhone 14 Plus 128GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 2)
    {
        price = 429.99;
        printf("\nYou selected iPhone SE 64GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 3)
    {
        price = 1,419.99;
        printf("\nYou selected Samsung Galaxy S24 512GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 4)
    {
        price = 499.99;
        printf("\nYou selected Motorola Razr 2023 128GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 5)
    {
        price = 374.00;
        printf("\nYou selected Google Pixel 7a 128GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 6)
    {
        price = 899.00;
        printf("\nYou selected Google Pixel 7Pro 128GB, the price is $%.2lf\n", price);
    }
    else if (itemNum == 7)
    {
        price = 89.99;
        printf("\nYou selected Nokia 2780 Flip, the price is $%.2lf\n", price);
    }
   else if (itemNum == 8)
    {
        price = 139.99;
        printf("\nYou selected Nokia C300 32GB, the price is $%.2lf\n", price);
    }
    return price;
}
double TryToCheckout(double budget, double price)
//input budget amount and phone price
//"purchase" the phone
//subtracts price from budget if purchase was made
//Lets the user know if price of phone is greater than budget
{
    if (budget >= price)
    {
        printf("\nLet's try to checkout\n");
        printf("\nThe price is $%.2lf and your budget is $%.2lf\n", price, budget);
        budget = budget - price;
        DisplayBalance(budget);
    }
    else
    {
        printf("\nLet's try to checkout\n");
        printf("\nThe price is $%.2lf and your budget is $%.2lf", price, budget);
        printf("\n\nYou cannot buy this phone, you will need to select a different phone OR update your budget\n");
        
    }
}
char DisplayAndGetChoice()
{
    //declare NEW variable
    char chosen;
    
    //menu options
    printf("\n*************************\n");
    printf("\nEnter (s or S) to select a phone");
    printf("\nEnter (u or U) to update your budget");
    printf("\nEnter (c or C) to Checkout");
    printf("\nEnter (q or Q) to Quit");
    printf("\n\n*************************\n");
    
    //get user choice, convert to toupper to catch all entries of lettering
    printf("\nEnter your choice: ");
    scanf(" %c", &chosen);
    chosen = toupper(chosen);
    return chosen;
}
void DisplayBalance(double balance)
//display remaining balance which is calculated within TryToCheckout function
{
    printf("\nThe remaining balance(budget) is $%.2lf\n", balance);
}
