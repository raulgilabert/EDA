#include <iostream>
#include <set>

using namespace std;


int main() {
    set<string> words;
    string w;

    set<string>::iterator it = words.begin(), mid_it;

    while (cin >> w and w != "END") {
        if (words.size() == 0) {
            it = words.insert(it, w);
            cout << w << endl;
            mid_it = words.begin();
        }
        else {
            words.insert(it, w);
            if (words.size() % 2 == 0 and w < *mid_it) --mid_it;
            else if (words.size() % 2 != 0 and w > *mid_it) ++mid_it;
            cout << *mid_it << endl;
        }
    }
}
