#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<double>& v, double x, int l, int r) {
    if (l > r)
	return -1;
    int mid = (l + r)/2;
    
    if (x < v[mid])
	return binary_search(v, x, l, mid - 1);
    if (x > v[mid])
	return binary_search(v, x, mid + 1, r);
    
    if (mid - 1 >= 0) {
	int mid1 = binary_search(v, x, l, mid - 1);
	if (mid1 != -1) return mid1;
    }
    return mid;
}


int first_occurrence(double x, const vector<double>& v) {
    if (v.empty() or x < v[0] or v[v.size() - 1] < x)
	return -1;

    return binary_search(v, x, 0, v.size());
}

int main() {
    double x;
    vector<double> v(10);
    for (int i = 0; i < 10; ++i)
      v[i] = i + i/2.0;
    for (int i = 0; i < 10; ++i)
      cout << v[i] << ' ';
    cout << endl << "Search for: " << endl;
    cin >> x;
    int loc = first_occurrence(x, v);
    cout << "Found: " << loc << endl;
}
