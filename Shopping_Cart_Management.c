
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product getProductDetail(int id);
void showMenu();
void Checkout(int count);
void showInventory();
void showCart(int count);
int UpdateQuantity(int id, int qty);

struct Product
{
    int id;
    char name[20];
    float price;
    int quantity;
};
struct Product inventory[4] = {{1, "shampoo", 30.00, 100}, {2, "soap", 20.00, 100}, {3, "comb", 15.00, 200}, {4, "brush", 10.00, 200}};
struct Product cart[4];

int main()
{
    int option, id, qty, count = 0;
    while (1)
    { // choose your interest
        showMenu();
        scanf("%d", &option);
        switch (option)
        {
        case 1: // purchase product
            while (1)
            {
                showInventory(); // products detail

                printf("Please Enter Product ID\n"); // choose product
                scanf("%d", &id);
                struct Product p = getProductDetail(id);
                if (p.id == 0)
                {
                    printf("wrong product Id!!\nPlease input a valid ID\n");
                    continue;
                }
                printf("%d - %s - %f - %d\n", p.id, p.name, p.price, p.quantity);
                printf("Please Enter Product Quantity\n");
                scanf("%d", &qty);

                // 3. add into cart
                struct Product p1;
                p1.id = p.id;
                p1.name[10] = malloc(20);
                strcpy(p1.name, p.name);
                p1.price = p.price;
                p1.quantity = malloc(qty);
                p1.quantity = qty;
                printf("%d - %s - %f - %d\n", p1.id, p1.name, p1.price, p1.quantity);
                cart[count] = p1;
                count++;
                printf("Do you want to add more product[1/0]\n(1). Yes\n(0). No\n");
                scanf("%d", &option);

                if (option == 1)
                {
                    UpdateQuantity(id, qty);
                    continue;
                }
                else if (option == 0)
                {
                    break;
                }
            }
            break;

        case 2:
            showCart(count);
            printf("(1). Go to the main menu\n(0). Checkout\n");
            scanf("%d", &option);
            if (option == 0)
            {
                Checkout(count);
                printf("Thank you for visiting.\n");
                printf("---------------------------------------------------------\n");
                return 0;
            }

            break;

        case 3:
            Checkout(count);
            printf("Thank you for visiting.\n");
            printf("---------------------------------------------------------\n");
            return 0;

        case 4:
            printf("---------------------------------------------------------\n");
            printf("Thank you for visiting\n");
            printf("---------------------------------------------------------\n");
            return 0;
        
        default:
            break;
        }
    }
}
struct Product getProductDetail(int id )
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i].id == id)
        {
            return inventory[i];
        }
    }

    struct Product p = {0, "", 0.0, 0};
    return p;
}
void showInventory()
{
    printf("\n---------------------------------------------------------\n");
    printf("                         INVENTORY       ");
    printf("\n---------------------------------------------------------\n");

    printf("\nPRODUCT ID       PRODUCT NAME      UNIT PRICE     TOTAL QUANTITY\n");
    for (int i = 0; i <= 3; i++)
    {
        printf("\t%d\t", inventory[i].id);
        printf("\t%s\t\t", inventory[i].name);
        printf("%.2f\t\t", inventory[i].price);
        printf("%d", inventory[i].quantity);

        printf("\n");
    }
    printf("\n---------------------------------------------------------\n");
}
void showMenu()
{
    printf("Please select your option\n");
    printf("---------------------------\n");
    printf("1. Purchase Product\n");
    printf("2. Show cart\n");
    printf("3. Checkout\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
}
void showCart(int count)
{
    printf("\n------------------------ CART -----------------------------\n");
    printf("\nPRODUCT ID       PRODUCT NAME      UNIT PRICE         QUANTITY\n");

    for (int i = 0; i < count; i++)
    {
        printf("\t%d\t", cart[i].id);
        printf("\t%s\t\t", cart[i].name);
        printf("%.2f\t\t", cart[i].price);
        printf("%d", cart[i].quantity);

        printf("\n");
    }
    printf("\n-----------------------------------------------------------\n");
}
void Checkout(int count)
{
    float SubTotalPrice;
    printf("\n------------------------ CART -----------------------------\n");
    printf("\nPRODUCT ID     PRODUCT NAME      UNIT PRICE    QUANTITY    TOTAL AMOUNT\n");

    for (int i = 0; i < count; i++)
    {
        printf("  %d\t", cart[i].id);
        printf("\t%s\t\t", cart[i].name);
        printf("%.2f\t\t", cart[i].price);
        printf("%d\t\t", cart[i].quantity);
        printf("₹%.2f\t\t", cart[i].price * cart[i].quantity);

        SubTotalPrice += cart[i].price * cart[i].quantity;
        printf("\n");
    }
    printf("\n---------------------------------------------------------\n");
    printf("Subtotal amount: ₹%.2f\n", SubTotalPrice);
    printf("\n---------------------------------------------------------\n");
}
int UpdateQuantity(int id, int qty)
{
    for (int i = 0; i <4; i++)
    {
        if (inventory[i].id == id)
        {
            inventory[i].quantity = inventory[i].quantity - qty;
            return inventory[i].quantity;
        }

        // return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("\t%d\t", inventory[i].id);
        printf("\t%s\t\t", inventory[i].name);
        printf("%.2f\t\t", inventory[i].price);
        printf("%d", inventory[i].quantity);

        printf("\n");
    }
}
