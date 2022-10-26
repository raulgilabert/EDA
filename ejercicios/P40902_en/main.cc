#include <iostream>
#include <map>

using namespace std;

int main() {
    string name, func;
    
    map<string, int> people;

    while (cin >> name >> func) {
	if (func == "enters") {
	    if (people.find(name) != people.end())
		cout << name << " is already in the casino" << endl;
	    else
		people[name] = 0;
	}
	else if (func == "wins") {
	    int num;
	    cin >> num;

	    if (people.find(name) == people.end())
		cout << name << " is not in the casino" << endl;
	    else
		people[name] += num;
	}
	else if (func == "leaves") {
	    if (people.find(name) == people.end())
		cout << name << " is not in the casino" << endl;
	    else {
		cout << name << " has won " << people[name] << endl;
		people.erase(name);
	    }
	}
    }

    cout << "----------" << endl;

    for (auto it : people) {
	cout << it.first << " is winning " << it.second << endl;
    }
}
