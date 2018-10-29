#include <iomanip>
#include <iostream>

int main(int argc, char const *argv[]) {
    long double price;
    std::cout << "Please, enter the price: ";
    std::cin >> std::get_money(price);
    if (std::cin.fail())
        std::cout << "Error reading price\n";
    else
        std::cout << "The price entered is: " << std::put_money(price) << '\n';
    return 0;
}