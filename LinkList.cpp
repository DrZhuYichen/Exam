#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node* next = nullptr;
};

class LinkList{
private:
    Node* Head;
public:
    LinkList(){
        Head = new Node;
    }

    void create_list(int number){
        Node* p;
        Node* temp;
        p = Head;

        while (number--){
            temp = new Node;
            cin >> temp->value;
            p->next = temp;
            p = temp;
        }
    }

    void insert(int position, int i){
        Node* temp;
        temp = Head;
        while (position--){
            temp = temp->next;
            if (temp == nullptr){
                cout << "error" << endl;
                return;
            }
        }
        Node* insert = new Node;
        insert->value = i;
        insert->next = temp->next;
        temp->next = insert;
    }

    void display(){
        Node* temp;
        temp = Head->next;
        while (temp){
            cout << temp->value << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleted(int i){
        Node* temp;
        temp = Head;
        while (--i){
            temp = temp->next;
            if (temp->next == nullptr){
                cout << "error" << endl;
                return;
            }
        }

        Node* help;
        help = temp->next;
        temp->next = help->next;

    }

    void reverse_display(){
        Node* temp;
        temp = Head->next;
        vector<int> vec;
        while (temp != nullptr){
            vec.push_back(temp->value);
            temp = temp->next;
        }

        int loop = vec.size();
        while (loop--){
            cout << vec[loop] << "  " <<endl;
        }

    }

    void reverse(){

        Node* temp;
        Node* point;
        point = Head->next;
        temp = point;
        point = point->next;
        temp->next = nullptr;
        Node* help;
        while (point != nullptr){
            help = temp;
            temp = point;
            point = point->next;
            temp->next = help;
        }
        Head->next = temp;
    }

    void find_mid(){
        Node* slow;
        Node* fast;
        slow = Head->next;
        fast = Head->next;

        while (fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        cout << "mid list is: " << slow->value << endl;


    }

    void find_last_k_value(int k){
        Node* fast = Head->next;
        Node* slow = Head->next;
        if(k < 1){
            cout << "Input ERROR!" << endl;
        }
        while (--k){
            if(fast->next == nullptr){
                cout << "Input over flow! " << endl;
            }
            fast = fast->next;
        }

        while (fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        cout << "last K value is: " << slow->value;

    }
};

int main(){
    LinkList a;
    a.create_list(5);
    a.display();
    a.find_last_k_value(3);

    return 0;
}
