#include <iostream>
#include <queue>

void output(int a, int b) {	std::cout << a << ':' << b << std::endl;}
void clear(int &a, int &b) { a = b = 0;}

int main(int argc, const char * argv[]) {
	std::queue<char> list;
	char c;
	int a = 0, b = 0;
	while ((c = std::cin.get()) != 'E') {
		if (c == 'W')
			a++;
		else if (c == 'L')
			b++;
		if ((a == 11 && b < 10) || (a < 10 && b == 11) || (a >= 10 && b >= 10 && ((a - b) == 2 || (b - a == 2)))) {
			output(a, b);
			clear(a, b);
		}
	}
	if (a || b)
		output(a, b);
	return 0;
}
