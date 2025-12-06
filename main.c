#include <stdio.h>
#include <string.h>

  /* Constants */#include <stdio.h>
#include <string.h>
  /* Constants */

#define MAX_TRANSACTION 500
void enter() {
    printf("Press Enter to return to the Menu...");
    getchar();
} // function to return to menu

char getMembershipInput() {
    char member;
    printf("\nAre you a member of our car club? (y/n): ");
    scanf(" %c", &member);
    while ((getchar()) != '\n'); // Clear input buffer
    while (member != 'y' && member != 'Y' && member != 'n' && member != 'N') {
        printf("\nInvalid input. Please select y or n\n");
        printf("\nAre you a member of our car club? (y/n): ");
        scanf(" %c", &member);
        while ((getchar()) != '\n'); // Clear input buffer
    }
    return member;
} // Function to validate membership input

void handleCustomerReviews(char customerReviews[][300], int *totalReviews) {
    int reviewChoice;
    printf("\nCustomer Reviews Menu:\n"
           "1. Add a review\n"
           "2. View reviews\n");
    printf("Please select an option: ");
    scanf(" %d", &reviewChoice);
    while ((getchar()) != '\n'); // Clear input buffer


    if (reviewChoice == 1) { // Add a review
        if (*totalReviews < MAX_TRANSACTION) {
            printf("Enter your review (max 300 characters): ");
            fgets(customerReviews[*totalReviews], 300, stdin);
            printf("Thank you for your review!\n");
            (*totalReviews)++; // Increment the number of reviews
        } else {
            printf("Sorry, we cannot accept more reviews at the moment.\n");
        }
    } else if (reviewChoice == 2) { // View reviews
        printf("\n*** Customer Reviews ***\n");
        for (int i = 0; i < *totalReviews; i++) {
            printf("%d. %s", i + 1, customerReviews[i]);
        }
        if (*totalReviews == 0) {
            printf("No reviews available yet.\n");
        }
    } else {
        printf("Invalid option! Returning to the main menu.\n");

    }
}

// Function to save sales data to a file
void saveSalesData(char customername[][200], unsigned short typeOfCarsPerSale[],
                   unsigned short carAmountPerSale[], float saleshistory[],
                   char discountGivenText[][4], int numberoftransaction, char brandOfCars[][30]) {
    FILE *file = fopen("sales_data.txt", "w"); // Open file in write mode
    if (file) {
        fprintf(file, "***** Sales History *****\n\n");
        for (int i = 0; i < numberoftransaction; i++) {
            fprintf(file, "Customer Name: %s\n", customername[i]);
            fprintf(file, "Car Type: %s\n", brandOfCars[typeOfCarsPerSale[i]]);
            fprintf(file, "Number of Cars: %hd\n", carAmountPerSale[i]);
            fprintf(file, "Sale Amount: %.2f GBP\n", saleshistory[i]);
            fprintf(file, "Discount Given: %s\n", discountGivenText[i]);
            fprintf(file, "--------------------------\n");
        }
        fclose(file);
        printf("\nSales data saved successfully!\n");
    } else {
        printf("\nError: Could not save sales data.\n");
    }
}
// Function to load sales data from a file
void loadSalesData(char customername[][200], unsigned short typeOfCarsPerSale[],
                   unsigned short carAmountPerSale[], float saleshistory[],
                   char discountGivenText[][4], int *numberoftransaction, char brandOfCars[][30]) {
    FILE *file = fopen("sales_data.txt", "r"); // Open file in read mode
    if (file) {
        printf("\nLoading Previous Sales Data...\n");
        char temp[300]; // Temporary buffer for reading lines
        while (fgets(temp, sizeof(temp), file)) {
            if (strstr(temp, "Customer Name: ")) {
                sscanf(temp, "Customer Name: %[^\n]", customername[*numberoftransaction]);
            } else if (strstr(temp, "Car Type: ")) {
                char carType[30];
                sscanf(temp, "Car Type: %[^\n]", carType);
                for (int i = 0; i < sizeof(brandOfCars) / sizeof(brandOfCars[0]); i++) {
                    if (strcmp(carType, brandOfCars[i]) == 0) {
                        typeOfCarsPerSale[*numberoftransaction] = i;
                        break;
                    }
                }
            } else if (strstr(temp, "Number of Cars: ")) {
                sscanf(temp, "Number of Cars: %hd", &carAmountPerSale[*numberoftransaction]);
            } else if (strstr(temp, "Sale Amount: ")) {
                sscanf(temp, "Sale Amount: %f GBP", &saleshistory[*numberoftransaction]);
            } else if (strstr(temp, "Discount Given: ")) {
                sscanf(temp, "Discount Given: %s", discountGivenText[*numberoftransaction]);
                (*numberoftransaction)++;
            }
        }
        fclose(file);
        printf("\nPrevious sales data loaded successfully!\n");
    } else {
        printf("\nNo previous sales data found.\n");
    }
}



// main function
int main() {
    printf("\nHello!Welcome to the car sales office\n\n");
    /* Variables */
    unsigned short available=500,quantity=0,totalsold=0,carType;
    // this array will hold the number of tickets sold each sale
    unsigned short carAmountPerSale[MAX_TRANSACTION];
    // this array will hold the type of the tickets sold each sale; this relates to the ticket price
    unsigned short typeOfCarsPerSale[MAX_TRANSACTION];
    //here available means how many cars available and quantity means how many customer needed//
    char member,menu,customername[MAX_TRANSACTION][200];
    char brandOfCars[][30]={"AUDI","MERCEDES","BMW","PORSCHE","LAMBORGHINI"};
    // this array to show types of cars
    char customerReviews[MAX_TRANSACTION][300]; // Each review can hold up to 300 characters
    int totalReviews = 0; // Tracks the number of reviews

    char discountGivenText[MAX_TRANSACTION][4];
    //this array to show
    float cost=0,totalsales=0,saleshistory[MAX_TRANSACTION];
    float carPrices[]={20000.00,30000.00,40000.00,50000.00,60000.00};

    // here cost means the total amount after the user purchase and total sales means total amount of car sales
    int numberoftransaction=0,validInput;
    // this array will hold the transaction number records

    // Load previous sales data
    loadSalesData(customername, typeOfCarsPerSale, carAmountPerSale, saleshistory, discountGivenText, &numberoftransaction, brandOfCars);




    printf("\nThere are %hd cars available at the moment.\n\n", available);

    printf("\nPress enter to view the price of the cars....");
    getchar();

    for (int i = 0; i < sizeof(carPrices) / sizeof(carPrices[0]); i++) {
        printf("%d- %s costs %.2f gbp\n",i,brandOfCars[i],carPrices[i]);
    }

    printf("\nPress enter to view the menu....");
    getchar();
    //do-while loop to allow multiple selection...
    do {
        //showing menu

        printf("\nmenu:\n"
               "a. Buy cars\n"
               "b. View stats\n"
               "c. Add/View reviews\n"
               "x. Exit\n");
        printf("the menu is listed above.Please choose one:");
        scanf(" %c",&menu);
        while ((getchar()) != '\n'); // Clear input buffer
        // now doing tasks according to the users selection in menu
        switch(menu) {
            case 'a':
                if (available<=0) {
                    printf("\nSorry we have no more cars available at the moment\n");
                    //if no more cars available
                    enter();//calling the function
                } else {
                    printf("\nWhat's your name-");
                    fgets(customername[numberoftransaction],200,stdin);
                    printf("\n        ***TYPES OF CARS***\n");
                    //Showing types of cars using loop......
                    for (int i = 0;i< sizeof(brandOfCars) / sizeof(brandOfCars[0]);i++) {
                        printf("%d - %s\n",i,brandOfCars[i]);
                    }
                    printf("\nWhich brand of cars you want to buy?Choose from above-");
                    validInput = scanf(" %hd",&carType);
                    while ((getchar()) != '\n'); // Clear input buffer
                    while (validInput != 1 || (carType < 0 || carType > 4)) {
                        printf("\nwrong choice.Please choose a valid option\n");
                        printf("\nWhich brand of cars you want to buy?Choose from above-");
                        scanf(" %hd",&carType);
                        while ((getchar()) != '\n'); // Clear input buffer
                    }
                    //this loop will keep asking for right input to the user if user entered invalid choice

                    typeOfCarsPerSale[numberoftransaction]=carType;

                        printf("\nhow many cars you want to buy:");
                        scanf(" %hd",&quantity);
                        while ((getchar()) != '\n'); // Clear input buffer



                        if (available>=quantity) {  //checking if we have the number of cars customer needs
                            //checking if the user is eligible for discount
                            member = getMembershipInput();
                            // calling the funtion to check membership input
                            if (member=='y' || member=='Y') {
                                strcpy(discountGivenText[numberoftransaction],"YES");
                                //giving 20% discount if the user is a member of car club.
                                printf("\nCongratulations!!!You will get 20 percent discount\n\n");
                                cost = carPrices[carType]*quantity*(1.00-20.00/100.00);
                            } else if (member=='n'|| member=='N') {
                                strcpy(discountGivenText[numberoftransaction],"NO");
                                printf("\nsorry you are not eligible for discount.\n\n");
                                cost =carPrices[carType]*quantity;
                                // and no discount will be applied if the user is not a member of car club.
                            }
                            printf("Purchase Completed.Thank you.You have bought %u cars\n\n",quantity);
                            printf("the total cost is:%.2f gbp\n\n",cost);


                            // record the price in the totalSales array
                            saleshistory[numberoftransaction] = cost;
                            totalsales+=cost;
                            available-=quantity;
                            totalsold+=quantity;
                            carAmountPerSale[numberoftransaction] = quantity;
                            numberoftransaction++;
                            //keeping record of total amount of sales and total available cars
                        } else {
                            printf("\nSorry we have less cars than you require. \n");
                            //if we do not have the number of cars customer needs
                        }
                    }
                    enter();
                    break;
            // showing sales data if the user choose option b
            case 'b':
                if (numberoftransaction > 0) {
                    printf("\n                **Sales History**\n");
                    totalsold = 0;    // Reset totalsold
                    totalsales = 0;   // Reset totalsales
                    for (int i = 0; i < numberoftransaction; i++) {
                        // Display all transactions with car type
                        printf("Sale Index: %d | Sale Amount: %.2f GBP | Customer Name: %s | Car Type: %s | Number of Cars: %hd | Discount Given: %s\n",
                               i + 1, saleshistory[i], customername[i], brandOfCars[typeOfCarsPerSale[i]],
                               carAmountPerSale[i], discountGivenText[i]);

                        // Recalculate totals
                        totalsold += carAmountPerSale[i];
                        totalsales += saleshistory[i];
                    }
                    printf("\n%u cars have been sold", totalsold);
                    printf("\nNow there are %u cars available\n", available - totalsold);
                    printf("The total amount of sales is: %.2f GBP\n\n", totalsales);
                } else {
                    printf("\nNo sales have been made yet.\n");
                }
            enter(); // Return to menu
            break;
            case 'c':
                    handleCustomerReviews(customerReviews, &totalReviews); // Pass review data and counter to the function
                    enter();
                    break;


                    case 'x':
                        printf("\nyou have exited from the car sales.\n\n");
            // Save sales data before exiting
            saveSalesData(customername, typeOfCarsPerSale, carAmountPerSale, saleshistory, discountGivenText, numberoftransaction, brandOfCars);

                     break;
                    //exit from the site if user choose x
                    default: // Invalid input
                    printf("\nInvalid choice! Please select a valid option.\n");
                    enter();
                    break;
                }




        }
        while (menu!='x');
        printf("\nThank you for visiting.Have a great day\n");
        //thanks the user.....
        return 0;
    }





