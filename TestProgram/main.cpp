#include <iostream>
#include "header.h"
using namespace std;

int main() {
	int answer = 0, a = 4, b = 6;

	answer = sum(a, b);
	cout << a << " + " << b << " = " << answer << endl;

	return 0;
}