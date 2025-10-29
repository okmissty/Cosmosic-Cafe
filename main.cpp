// Tyeon Ford 
// 10/29/25

#include <iostream>
using namespace std;

int GALLEON = 493;
int SICKLE = 29;
int KNUT = 1;

string ALL_TOPPINGS[] = {
    "Whipped Cream", 
    "Marshmallows", 
    "Chocolate Shavings", 
    "Cinnamon Stick", 
    "Caramel Drizzle", 
    "Nutmeg Sprinkle",
    "Crushed Candy Cane"
};

// structure to keep track of the order
struct Order{
    string name;
    string drink;
    char drink_size;
    int toppingList[3];
    int *coin;
};

// shows the order for the wizard
void showOrder(Order *order){
    cout << "Wizard: " << (*order).name << endl;
    cout << "Drink: " << (*order).drink << " (" << (*order).drink_size << ")" << endl;
    cout << "Toppings: ";

    cout << "| ";
    for (int i = 0; i < 3; i++) {
        int topping_index = (*order).toppingList[i];
        // Only prints valid topping indices (0-6)
        if (topping_index >= 0 && topping_index < 7) {
            cout << ALL_TOPPINGS[topping_index] << " | ";
        }
    }
    cout << "Price: " << (*(*order).coin) << "c" << endl;
    cout << endl;
}

int main(){
    // sets prices based on the size of the drink 
    int *small_price = new int(KNUT*20);
    int *med_price = new int(SICKLE*2);
    int *large_price = new int(GALLEON/5);

    // create orders
    WizardOrder harry = WizardOrder{"Harry", "Felix Felicis Espresso Shot", 'S', {2, -1, -1}, small_price};     // toppings: Chocolate Shavings
    WizardOrder ron = WizardOrder{"Ron", "Butterbeer Latte", 'L', {0, 4, 6}, large_price};                      // toppings: Whipped Cream, Caramel Drizzle, Crushed Candy Cane
    WizardOrder hermione = WizardOrder{"Hermione", "Pumpkin Juice Smoothie", 'M', {1, 5, -1}, med_price};       // toppings: Marshmallows, Nutmeg Sprinkle
    WizardOrder draco = WizardOrder{"Draco", "Gillywater Spritzer", 'M', {-1, -1, -1}, med_price};              // toppings: (Nothing)

    // adds each wizard 
    WizardOrder *all_orders = new WizardOrder[4];
    all_orders[0] = harry;
    all_orders[1] = ron;
    all_orders[2] = hermione;
    all_orders[3] = draco;

    //shows the orders
    for(int i=0; i<4; i++){
        showOrder(&all_orders[i]);
    }

    // Cleans up dynamically allocated memory
    delete small_price;
    delete med_price;
    delete large_price;
    delete[] all_orders;

    return 0;
}