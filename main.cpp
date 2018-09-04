#include <iostream>
#include <map>
#include <set>
#include <regex>
#include <queue>
#include <random>

using namespace std;

class ExeMap{
public:
    void solve(){
        map<int, string> map1;
        //插入
        map1[5] = "zhu";
        map1.insert(pair<int, string>(6, "lu"));
        //查找
        bool have = (map1.find(6) != map1.end());
        //删除
        map1.erase(5);
        auto iter = map1.find(6);
        map1.erase(iter);
        map1.erase(map1.begin(), map1.end()); //删除全部

        cout << map1.size() << endl;
    }
};

class ExeSet{
public:
    void solve(){
        set<int> set1 = {0, 1};
        set1.insert(2); //增
        set1.erase(0);//删
        //查
        bool have = (set1.find(2) != set1.end());
        cout << have << endl;
    }
};

class RegularMatch{
public:
    void solve(){
        //no space in regular match!!
        //是否有大写字母
        regex regex1("[A-Z]+");//是否有大写, +表示一次或多次, *零次或多次,?零次或一次
        regex regex2("([A-Z])\\1");//连续两个同样的大写, AA, BB 结构, \\结构对应()中内容
        regex regex3("[A-Z]{2,}");//连续两个大写, 无需一样
        regex regex4(".*([A-Z]).*([A-Z]).*");//是否有两个大写

        regex regex5(".*apple.*|.*banana.*");//匹配apple与banana字符串 //字符串匹配结构也可以形如^string$
        regex regex6("[0-9\\+\\&]+");//匹配自定义结构,0-9,+,&
        regex regex7("[0-9a-z]+");//匹配自定义结构0-9a-z

        regex regex8(".*(.)(.*\\1).*");//重复的字符
        regex regex9(".*([a-z])\\1([0-9])\\2.*");//匹配自定义结构,aa99
        regex regex10(".*(.).*(.)(.*\\1)(.*\\2).*");//重复的子序列结构,如AABB, XYXY

        //手机号：^((13[0-9])|(14[0-9])|(15[0-9])|(17[0-9])|(18[0-9]))\d{8}$

        vector<int> vector1;

        cout << regex_search("strABnvvVg",regex1);

//        cout << regex_search("aaA99", regex9);
    }
};

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

class Heap{ //默认大根堆
public:
    class Student{
    public:
        int id;
        string name;
        Student(const int& ID, const string& NAME){
            id = ID;
            name = NAME;
        }
    };

    struct cmp{ //小根堆用>, 大根堆用<
        bool operator () (const Student& student1, const Student& student2){
            return student1.id < student2.id;
        }
    };

    void bigHeap(){
        priority_queue<int, vector<int>, less<int>> bigHeap;
        for(int i = 0; i < 10; i++){
            bigHeap.push(rand() % 20);
        }

        for(int i = 0; i < 10; i++){
            cout << bigHeap.top() << "  ";
            bigHeap.pop();
        }
    }

    void smallHeap(){
        priority_queue<int, vector<int>, greater<int>> bigHeap;
        for(int i = 0; i < 10; i++){
            bigHeap.push(rand() % 20);
        }

        for(int i = 0; i < 10; i++){
            cout << bigHeap.top() << "  ";
            bigHeap.pop();
        }
    }

    void myBigHeap(){

        priority_queue<Student, vector<Student>, cmp> student_list;
        student_list.push(Student(1, "Zhu"));
        student_list.push(Student(6, "lu"));
        student_list.push(Student(4, "fen"));
        student_list.push(Student(9, "yang"));

        for (int i = 0; i < 4; i++){
            cout << student_list.top().name << endl;
            student_list.pop();
        }
    }

};

int main(){
    ExeMap exeMap;
    ExeSet exeSet;
    RegularMatch regularMatch;
    Print print;
    Heap heap;

    heap.myBigHeap();
}