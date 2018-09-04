#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

class ReturnValueForB{
public:
    bool isBalance;
    int level;

    ReturnValueForB(bool isB, int lev){
        isBalance = isB;
        level = lev;
    }
};

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(const int temp){value = temp; left = nullptr; right = nullptr;}

    Node(){left = nullptr; right = nullptr;}

    void preOrderRecur(Node* head){
        if (head == nullptr){
            return;
        }

        cout << head->value << "  ";
        preOrderRecur(head->left);
        preOrderRecur(head->right);

    }

    void inOrderRecur(Node* head){
        if (head == nullptr){
            return;
        }

        inOrderRecur(head->left);
        cout << head->value << "  ";
        inOrderRecur(head->right);

    }

    void backOrderRecur(Node* head){
        if (head == nullptr){
            return;
        }

        backOrderRecur(head->left);
        backOrderRecur(head->right);
        cout << head->value << "  ";

    }

    ReturnValueForB isBalanceTree(Node* head){
        if (head == nullptr){
            return ReturnValueForB(true, 0);
        }

        ReturnValueForB rightTree = isBalanceTree(head->right);
        if (!rightTree.isBalance){
            return ReturnValueForB(false, 0);
        }

        ReturnValueForB leftTree = isBalanceTree(head->left);
        if (!leftTree.isBalance){
            return ReturnValueForB(false, 0);
        }

        if (abs(rightTree.level - leftTree.level) > 1){
            return ReturnValueForB(false, 0);
        }

        return ReturnValueForB(true, max(rightTree.level, leftTree.level) + 1);

    }

    bool isCompleteTree(Node* head){

        deque<Node*> deque1;
        deque1.push_back(head);
        bool check_leaf = 0;

        while (!deque1.empty()){
            head = deque1.front();
            deque1.pop_front();
            Node* l = head->left;
            Node* r = head->right;
            if( (check_leaf == 1 && (l != nullptr || r != nullptr)) || (r != nullptr && l == nullptr) ){
                return false;
            }

            if (l != nullptr){
                deque1.push_back(l);
            }

            if (r != nullptr){
                deque1.push_back(r);
            } else{
                check_leaf = 1;
            }
        }
        return true;
    }

    int depth(Node* head){
        int level = 0;
        while (head != nullptr){
            level++;
            head = head->left;
        }
        return level;
    }

    int completeTreeNodeNumber(Node* head, int level, int h){
        if (level == h){
            return 1;
        }

        if (depth(head->right) + level == h){
            return (1 << (h - level)) + completeTreeNodeNumber(head->right, level + 1, h);
        } else{
            return (1 << (h - level - 1)) + completeTreeNodeNumber(head->left, level + 1, h);
        }

    }
};

int main(){
    Node* head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(8);
    head->left->left = new Node(2);
    head->left->right = new Node(4);
    head->right->left = new Node(6);
    head->right->right = new Node(10);

    head->left->left->left = new Node(19);
    head->left->left->right = new Node(11);


//    head->preOrderRecur(head);
//    head->inOrderRecur(head);
//    head->backOrderRecur(head);

//    cout << head->isCompleteTree(head);
    cout << head->completeTreeNodeNumber(head, 1, head->depth(head));

    delete(head);

}