#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Factorial {
public:
    void solve() {
        int n = 10;
        cout << recursion(n) << endl;
    }

    int recursion(int n) {
        if (n == 1) {
            return 1;
        }
        return n * recursion(n - 1);
    }

};   //阶乘

class HanNuoTa {
public:

    void solve() {
        recursion(3, "left", "mid", "right");
    }

    void recursion(int n, const string &from, const string &help, const string &to) {
        if (n == 1) {
            cout << from << " to " << to << endl;
            return;
        }

        n--;

        recursion(n, from, help, to);
        recursion(n, help, from, to);
    }
};    //汉诺塔

class AllSubString {
public:
    void solve() {
        vector<string> vector1 = {"a", "b", "c"};
        int i = 3;
        recursion(vector1, i, "");
    }

    void recursion(const vector<string> &vector1, const int &i, const string &string1) {
        if (i == 0) {
            cout << string1 << endl;
            return;
        }

        recursion(vector1, i - 1, string1);
        recursion(vector1, i - 1, string1 + vector1[i - 1]);

    }
};  //字符串全部子序列

class AllArrangeString {
public:
    void solve() {
        vector<string> vector1 = {"a", "b", "c", "d"};
        recursion(vector1, 0);
    }

    void recursion(vector<string>& vector1, int point) {
        if(point == vector1.size() - 1){
            for (string str : vector1){
                cout << str;
            }
            cout << endl;
            return;
        }

        for (int i = point; i < vector1.size(); i++){
            swap(vector1[point], vector1[i]);
            recursion(vector1, point + 1);
            swap(vector1[i], vector1[point]);
        }

    }

}; //字符串全排列

class BornCows {
public:
    void solve() {
        int n = 6;
        cout << recursion(n) << endl;
    }

    int recursion(const int &n) {
        if (n == 1 || n == 2 || n == 3) {
            return n;
        }

        return recursion(n - 1) + recursion(n - 3);

    }
};

class MinPath {
public:
    void solve() {
        vector<vector<int>> vector1 = {{1, 1, 3, 1},
                                       {7, 1, 0, 9},
                                       {6, 1, 1, 2}};
        cout << recursion(vector1, 0, 0) << endl;
    }

    int recursion(const vector<vector<int>> &vector1, int H, int L) {
        if (H == vector1.size() - 1 && L == vector1[0].size() - 1){
            return vector1[H][L];
        }

        if (H == vector1.size() - 1){
            return vector1[H][L] + recursion(vector1, H, L + 1);
        }


        if (L == vector1[0].size() - 1){
            return vector1[H][L] + recursion(vector1, H + 1, L);
        }

        return vector1[H][L] + min(recursion(vector1, H, L + 1), recursion(vector1, H + 1, L));

    }

}; //最小路径

int main() {
    Factorial factorial;
    HanNuoTa hanNuoTa;
    AllSubString allSubString;
    AllArrangeString allArrangeString;
    BornCows bornCows;
    MinPath minPath;

    allArrangeString.solve();

}
