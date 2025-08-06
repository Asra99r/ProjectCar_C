#include <stdio.h>
#include <string.h>

// Size of arrays
#define MAX_CUSTOMERS 100
#define MAX_VEHICLES 100

// Customer struct
struct Customer {
    int ID;
    char name[50];
    char phone[20];
};

// Vehicle struct 
struct Vehicle {
    int modelYear;
    char make[50];
    char modelName[50];
    char licensePlate[20];
    int customerNumber;
};

// Arrays to store customer and vehicle data
struct Customer customers[MAX_CUSTOMERS];
struct Vehicle vehicles[MAX_VEHICLES];

int customerCount = 0;
int vehicleCount = 0;

// Function to display the menu
void printMenu() {
    printf("\n\t<<<<Car Rental>>>>\n");
    printf("\nChoose one of the following options:\n");
    printf("1 - Add a new customer\n");
    printf("2 - Add a new vehicle\n");
    printf("3 - Print all customers' information\n");
    printf("4 - Print all vehicles' information\n");
    printf("5 - Quit\n\n");
}

// Function to add a new customer
void addCustomer() {
    printf("\n______________________________________\n");
    struct Customer newCustomer;
    printf("Enter customer ID, name, and phone number: \n");
    scanf("%d %s %s", &newCustomer.ID, newCustomer.name, newCustomer.phone);
    customers[customerCount++] = newCustomer;
    printf("\n______________________________________\n");
}

// Function to check if a customer ID exists
int customerExists(int customerID) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].ID == customerID) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new vehicle
void addVehicle() {
    struct Vehicle newVehicle;
    int isValidCustomer = 0;

    while (!isValidCustomer) {
        printf("\n***********************************\n");
        printf("Enter vehicle model year, make, model name, license plate number, and customer number: \n");
        scanf("%d %s %s %s %d", &newVehicle.modelYear, newVehicle.make, newVehicle.modelName, newVehicle.licensePlate, &newVehicle.customerNumber);
        
        // Check if the customer ID exists
        if (customerExists(newVehicle.customerNumber)) {
            isValidCustomer = 1;
        } else {
            printf("Error: Customer ID does not exist. Please try again.\n");
        }
    }

    vehicles[vehicleCount++] = newVehicle;
    printf("\n***********************************\n");
}

// Function to print customer information
void printCustomers() {
    printf("\n______________________________________\n");
    printf("\nCustomer Information:\n");
    printf("%s%25s%25s%25s\n", "NO.", "Customer ID", "Customer Name", "Customer Phone");
    for (int i = 0; i < customerCount; i++) {
        printf("%-17d%-28d%-24s%s\n", i + 1, customers[i].ID, customers[i].name, customers[i].phone);
    }
    printf("\n______________________________________\n");
}

// Function to print vehicle information
void printVehicles() {
    printf("\n***********************************\n");
    printf("\nVehicle Information:\n");
    printf("%s%20s%15s%20s%30s%20s\n", "NO.", "Model year", "Make", "Model name", "License plate number", "Customer number");

    for (int i = 0; i < vehicleCount; i++) {
        printf(" %-13d%-21d%-14s %-20s %-25s  %d\n", i + 1,
            vehicles[i].modelYear, vehicles[i].make, vehicles[i].modelName, vehicles[i].licensePlate, vehicles[i].customerNumber);
    }
    printf("\n***********************************\n");
}

int main() {
    int choice = 0;
    // Repeat menu until user enters 5
    do {
        printMenu();
        printf("Enter your choice: \t");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            addVehicle();
            break;
        case 3:
            printCustomers();
            break;
        case 4:
            printVehicles();
            break;
        case 5:
            printf("Exiting program. Thank you.\n");
            break;
        default:
            printf("Wrong choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
