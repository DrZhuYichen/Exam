//
// Created by agent on 2018/8/26.
//

#include <iostream>
#include <vector>

using namespace std;

static void heapInsert(vector<int>& arr, int index);
static void showArr(const vector<int>& arr);
static void heapify(vector<int>& arr, int index, const int size);

int main() {

    vector<int> arr = {2,4,1,9,5,3,10,3,6};

    for(int i = 0; i < arr.size(); i++){
        heapInsert(arr, i);
    }

    cout << "heapSort result: " << endl;
    showArr(arr);


    arr[0] = 7;
    heapify(arr, 0, arr.size()-1);

    cout << endl << "heapify result: " << endl;
    showArr(arr);

    return 0;
}


static void heapInsert(vector<int>& arr, int index){
    while (arr[(index-1) / 2] < arr[index]){
        swap(arr[(index-1) / 2], arr[index]);
        index = (index-1) / 2;
    }
}

static void showArr(const vector<int>& arr){
    for(auto i=arr.begin(); i != arr.end(); i++){
        cout << *i << "  ";
    }
}

static void heapify(vector<int>& arr, int index, const int size){
    int large_index = 0;
    while((2*index+1) < size){
        large_index = arr[(2*index+1)] > arr[(2*index+2)] ? 2*index+1 : 2*index+2;
        if(arr[index] < arr[large_index]){
            swap(arr[large_index], arr[index]);
            index = large_index;
        } else {
            break;
        }
    }
}