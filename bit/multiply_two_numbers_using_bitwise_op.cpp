#include<iostream>

using namespace std;

int multiply(int m, int n)
{
	int result = 0, i = 0;
	while(n) {
		if(n & 1) {
			result += m * (1 << i);
		}
		i++;
		n >>= 1;
	}
	return result;
}


int main()
{
	int m = 0, n = 0;
	cout << "Enter two number: ";
	cin >> m;
	cin >> n;
	cout << "Multiplication is: " << multiply(m, n) << endl;
}
