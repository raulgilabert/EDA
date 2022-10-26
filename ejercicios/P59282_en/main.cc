#include <iostream>
#include <set>

using namespace std;


void calc(multiset<int>& nums, int sum) {
    multiset<int>::iterator it = nums.begin();
    cout << "minimum: " << *it;

    float avg = float(sum)/nums.size();

    cout << ", maximum: " << *(--nums.end()) << ", average: " << avg << endl;
}


int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    string op;

    multiset<int> nums;

    int sum = 0;

    while (cin >> op) {
        if (op == "number") {
            int num;
            cin >> num;

            nums.insert(num);
            sum += num;
            calc(nums, sum);

        }
        else if (op == "delete") {
            if (not nums.empty()) {
                int num = *(nums.begin());
                sum -= num;
                nums.erase(num);
            }

            if (not nums.empty())
                calc(nums, sum);
            else
                cout << "no elements" << endl;
        }
        cout << sum << endl;
    }
}

