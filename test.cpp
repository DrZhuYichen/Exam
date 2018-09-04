#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

class Solution {
public:
    static void solve(){
        int n;
        cin >> n;
        int loop = n;
        string string1;
        vector<string> vector1 = {"A", "B", "C"};

        int count = 0;
        recursion(n, count, string1, vector1);

        cout << count << endl;

    }

    static void recursion(int n, int& count, string string1, const vector<string>& vector1){
        if (n == 0){
            cout << string1 << "  ";
            regex regex1(".*ABC.*|.*ACB.*|.*BAC.*|.*BCA.*|.*CAB.*|.*CBA.*");
            if (!regex_search(string1, regex1)){
                count++;
            }
            return;
        }

        n--;
        recursion(n, count, string1 + vector1[0], vector1);
        recursion(n, count, string1 + vector1[1], vector1);
        recursion(n, count, string1 + vector1[2], vector1);

    }

};

int main(){
    Solution solution;
    solution.solve();
}

