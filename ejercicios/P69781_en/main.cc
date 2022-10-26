#include <iostream>
#include <vector>

using namespace std;

int collatz(int x, int y, int n) {
    vector<int> v;
    v.push_back(n);

    while (n <= 100000000) {
	if (n % 2 == 0)
	    n = n/2 + x;
	else
	    n = 3*n + y;

	for (int i = 0; i < v.size(); ++i) {
	    if (v[i] == n)
		return v.size() - i;
	}

	v.push_back(n);
    }
    return n;
}

int main() {
    int x, y, n;

    while (cin >> x >> y >> n) {
	cout << collatz(x, y, n) << endl;
    }
}
