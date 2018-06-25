// 1029.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, year, month;
	std::cin >> year >> month;
	std::cout << months[month - 1] + ((((!(year % 4) && year % 100) || !(year % 400)) && (month == 2)) ? 1 : 0) << std::endl;
	return 0;
}
