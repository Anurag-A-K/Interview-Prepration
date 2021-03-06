#include<iostream>
#include<vector>

using namespace std;

class Heap{
    vector<int> v;
    bool minType;//min or max heap

    bool compare(int a,int b){
        if(minType){
            return a<b;
        }else{
            return a>b;
        }
    }

    void heapify(int index){
        int left=2*index;
        int right=left+1;

        int last=v.size()-1;
        int min_index=index;

        if(left<=last && compare(v[left],v[index])){
            min_index=left;
        }

        if(right<=last && compare(v[right],v[min_index])){
            min_index=right;
        }

        if(min_index!=index){
            swap(v[index],v[min_index]);
            heapify(min_index);
        }
    }

    public:

    
    Heap(int size=10,int type=true){
        v.reserve(size);
        v.push_back(-1);
        minType=type;
    }

    void push(int data){
        //first insert at last
        v.push_back(data);
        //index at which it was pushed
        int index=v.size()-1;
        int parent=index/2;

        while(index>1 && compare(v[index],v[parent])){
            swap(v[parent],v[index]);
            index=parent;
            parent=parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last_index=v.size()-1;
        swap(v[1],v[last_index]);
        v.pop_back();

        heapify(1);
    }

    bool isEmpty(){
        return v.size()==1;
    }
};

//Building a max heap from a vector (inplace)
void buildHeap(vector<int> &v){
    
    for(int i=2;i<v.size();i++){
        int index=i;
        int parent=i/2;

        while(index>1 && v[index]>v[parent]){
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
}

void printHeap(vector<int> &v){
    for(auto val:v){
        cout<<val<<" ";
    }
}


int main(){

    // Heap h(10,false);
    // int n=10;

    // for(int i=0;i<n;i++){
    //     h.push(i);
    // }

    // while(!h.isEmpty()){
    //     cout<<h.top()<<endl;
    //     h.pop();
    // }

    vector<int> v{-1,10,20,15,16,40,6};
    buildHeap(v);
    printHeap(v);


    return 0;
}