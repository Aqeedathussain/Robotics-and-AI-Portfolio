#include <iostream>
using namespace std;

int main() {
    // Declare variables
    float costPrice, salePrice;
    const float GST_RATE = 15; // GST rate is 15%

    // Input cost price
    cout << "Enter the cost price of the good: ";
    cin >> costPrice;

    // Calculate sale price (cost price + GST)
    salePrice = costPrice + (costPrice * GST_RATE / 100);

    // Display sale price
    cout << "Sale price of the good: " << salePrice << endl;

    return 0;
}
