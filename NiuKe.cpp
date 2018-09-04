#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Print{
public:
    void printVector(const vector<int>& vector1){
        for(int i = 0; i < vector1.size(); i++){
            cout << vector1[i] << " " ;
        }
        cout << endl;
    }

    void printVector(const vector<string>& vector1){
        for(int i = 0; i < vector1.size(); i++){
            cout << vector1[i] << " " ;
        }
        cout << endl;
    }

    void printVector(const vector<vector<int>>& vector1){
        for(int i = 0; i < vector1.size(); i++){
            for (int j = 0; j < vector1[0].size(); j++){
                cout << vector1[i][j] << "  ";
            }
            cout << endl;
        }
    }

};

class Islands{
public:
    void slove(){
        vector<vector<int>> vector1 = {{0,0,1,0,1,0}, {1,1,1,0,1,0}, {1,0,0,1,0,0}, {0,0,0,0,0,1}};

        int H_max = vector1.size() - 1;
        int L_max = vector1[0].size() - 1;

        int time = 0;

        for (int i = 0; i <= H_max; i++){
            for (int j = 0; j <= L_max; j++){
                if (vector1[i][j] == 1){
                    affect(vector1, H_max, L_max, i, j);
                    time++;
                }
            }
        }

        cout << time;

    }

    void affect(vector<vector<int>>& vector1, int H_max, int L_max, int H, int L){
        if (H > H_max || L > L_max || H < 0 || L < 0 || vector1[H][L] != 1){
            return;
        }

        vector1[H][L] = 2;

        Print* print = new Print;
        print->printVector(vector1);
        delete print;
        cout << endl << endl;

        affect(vector1, H_max, L_max, H + 1, L );
        affect(vector1, H_max, L_max, H, L + 1);
        affect(vector1, H_max, L_max, H - 1, L );
        affect(vector1, H_max, L_max, H, L - 1);

    }

};

class StrSort{
public:
    void solve(){
        vector<string> vector1 = {"zhu", "lu", "fen", "a"};
        sort(vector1.begin(), vector1.end(), compare);
        Print* print = new Print;
        print->printVector(vector1);
        delete print;
    }

    static bool compare(const string& string1, const string& string2){
        return (string2 + string1 < string1 + string2);
    }

};

class CutGoldBar{
public:
    static void solve(){
        vector<int> vector1 = {40, 30, 20, 35};
        int temp = 0;
        int total = 0;
        while (vector1.size() > 1){
            sort(vector1.begin(), vector1.end(), reCompare);
            temp = *(vector1.end() - 1) + *(vector1.end() - 2);
            vector1.pop_back();
            vector1.pop_back();
            vector1.push_back(temp);
            total += temp;
        }
        cout << total << endl;
    }

    static bool reCompare(const int& a, const int& b){
        return a > b;
    }
};

class MakeMoney{
public:
    struct Project{
        int cost;
        int profit;
    };

    struct SmallCosts{
        bool operator()(const Project& project1, const Project& project2){
            return project1.cost > project2.cost;
        }
    };

    struct BigProfits{
        bool operator()(const Project& project1, const Project& project2){
            return project1.profit < project2.profit;
        }
    };

    void solve(){
        vector<int> costs = {900, 200, 100, 700, 300};
        vector<int> profits = {200, 50, 20, 100, 150};
        int m = 500;
        int k = 3;
        vector<Project> projects(costs.size());

        for (int i = 0; i < costs.size(); i++){
            projects[i].cost = costs[i];
            projects[i].profit = profits[i];
        }

        priority_queue<Project, vector<Project>, SmallCosts> smallCosts;
        priority_queue<Project, vector<Project>, BigProfits> bigProfits;

        for (Project project:projects){
            smallCosts.push(project);
        }

        while (k > 0){
            while (m >= smallCosts.top().cost && !smallCosts.empty()){
                bigProfits.push(smallCosts.top());
                smallCosts.pop();
            }
            if (!bigProfits.empty()){
                m = m + bigProfits.top().profit;
                bigProfits.pop();
                cout << m << "  ";
                k--;
            } else{
                break;
            }
        }
    }
};

int main(){
//    Islands solution;
    StrSort strSort;
    CutGoldBar cutGoldBar;
    MakeMoney makeMoney;
    makeMoney.solve();
}