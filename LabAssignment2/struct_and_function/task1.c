#include <stdio.h>

struct OrderItem {
    int quantity;
    float unit_price;
};

int main() {
    struct OrderItem paratha;
    struct OrderItem vegetable;
    struct OrderItem water;
    int num_people;
    float total_bill, bill_per_person;


    printf("Quantity of Paratha: ");
    scanf("%d", &paratha.quantity);

    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity of Vegetable: ");
    scanf("%d", &vegetable.quantity);

    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);

    printf("Quantity of Water: ");
    scanf("%d", &water.quantity);

    printf("Unit Price: ");
    scanf("%f", &water.unit_price);

    total_bill = (paratha.quantity * paratha.unit_price) +
                  (vegetable.quantity * vegetable.unit_price) +
                  (water.quantity * water.unit_price);


    printf("Number of people: ");
    scanf("%d", &num_people);


    
    bill_per_person = total_bill / num_people;

    printf("Individual people will pay: %.2f tk\n", bill_per_person);
 

    return 0;
}