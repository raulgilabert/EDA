#include <iostream>
#include <queue>

using namespace std;

int main() {
    char function;
    int n; 

    priority_queue<int> elements;

    while (cin >> function) {
	if (function == 'A') { // Print grater
	    if (elements.empty())
		cout << "error!";
	    else
		cout << elements.top();	

	    cout << endl;
	} else if (function == 'S') { // Add
	    cin >> n;

	    elements.push(n);
	} else if (function == 'R') { // Remove greater
	    if (not elements.empty())
		elements.pop();
	    else
		cout << "error!" << endl;
	} else if (function == 'I') { // Increase the gratest
	    cin >> n;

	    if (not elements.empty()) {
		n = elements.top() + n;
		elements.pop();
		elements.push(n);
	    } else
		cout << "error!" << endl;
	} else if (function == 'D') { // Decrease the greatest
	    cin >> n;

	    if (not elements.empty()) {
	       n = elements.top() - n;
	        elements.pop();
		elements.push(n);
	    } else
		cout << "error!" << endl;
	}
    }
}
