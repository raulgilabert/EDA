#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> words;
    string func;

    while (cin >> func) {
	if (func == "minimum?") {
	    if (words.size() == 0)
		cout << "indefinite minimum" << endl;
	    else
		cout << "minimum: " << words.begin()->first << ", " <<
		    words.begin()->second << " time(s)" << endl;
	}
	else if (func == "maximum?") {
	    if (words.size() == 0)
		cout << "indefinite maximum" << endl;
	    else
		cout << "maximum: " << (--words.end())->first << ", " <<
		    (--words.end())->second << " time(s)" << endl;
	}
	else if (func == "store") {
	    string word;
	    cin >> word;
	    ++words[word];
	}
	else if (func == "delete") {
	    string word;
	    cin >> word;

	    auto w = words.find(word);

	    if (w != words.end()) {
		--words[word];
		if (words[word] == 0)
		    words.erase(w);
	    }
	}
    }
}
