#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_FLAVORS 8
#define MAX_NAME_LENGTH 20
#define MAX_LENGTH 50

struct IceCream
{
    char name[MAX_NAME_LENGTH];
    float price;
};

struct Order
{
    struct IceCream flavor;
    int quantity;
};

struct Order orders[MAX_FLAVORS]; // Array to store orders
int numOrders = 0; // Number of orders currently stored

// Array to store ice cream flavors and their prices
struct IceCream flavors[MAX_FLAVORS] =
{
    {"Vanilla", 25},
    {"Chocolate", 30},
    {"Strawberry", 35},
    {"Chocolate Chip", 40},
    {"Butter Pecan", 45},
    {"Matcha (no sugar)", 45},
    {"Eggnog", 50},
    {"Teaberry", 55}
};
void placeOrder()
{
    int choice;
    printf("\nSelect Ice Cream Flavor:\n");
    for (int i = 0; i < MAX_FLAVORS; i++)
    {
        printf("%d. %s Ice Cream (%.2f Taka)\n", i+1, flavors[i].name, flavors[i].price);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_FLAVORS)
    {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    struct IceCream selectedFlavor = flavors[choice-1];
    struct Order newOrder;
    newOrder.flavor = selectedFlavor;
    printf("Enter Quantity (scoop): ");
    scanf("%d", &newOrder.quantity);

    orders[numOrders++] = newOrder;
    printf("Order placed successfully.\n");
}
void viewOrders()
{
    if (numOrders == 0)
    {
        printf("No orders found.\n");
        return;
    }

    printf("\nOrder Details:\n");
    printf("Flavor\t\tQuantity\tPrice\n");
    float total = 0;
    for (int i = 0; i < numOrders; i++)
    {
        float price = orders[i].flavor.price * orders[i].quantity;
        printf("%s \t%d scoop \t%.2f Taka\n", orders[i].flavor.name, orders[i].quantity, price);
        total += price;
    }
    printf("Total Amount: %.2f Taka\n", total);
}

int login(const char* username, const char* password)
{
    char inputUsername[MAX_LENGTH];
    char inputPassword[MAX_LENGTH];

    printf("-> Login\n");
    printf("Username: ");
    scanf("%s", inputUsername);
    printf("Password: ");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0)
    {
        return 1; // Successful login
    }

    return 0; // Invalid login
}

int main(void)
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("\t\tWelcome to Ice Cream Shop\n\n");
    printf("-> Sign up first\n");
    printf("Set username: ");
    scanf("%s", username);
    printf("Set password: ");
    scanf("%s", password);

    int loggedIn = login(username, password);
    if (loggedIn)
    {
        printf("Login successful!\n");
        int choice;
        while (1)
        {
            printf("\n1. Place Order\n");
            printf("2. View Orders\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                placeOrder();
                break;
            case 2:
                viewOrders();
                break;
            case 3:
                printf("Thank you for ordering ice cream.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    else
    {
        printf("Invalid username or password.\n");
    }
    return 0;
}
