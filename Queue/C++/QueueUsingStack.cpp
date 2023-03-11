#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

//*****************************************
//NOT FINISHED
//*****************************************
class Queue{
private:
    int *st1,*st2;
    int top1, top2;
    int capacity;

public:
    Queue(int capacity){
        this->capacity = capacity;
        top1=-1;top2=-1;
        st1 = new int[capacity];
        st2 = new int[capacity];
    }

    void enqueue(int value){
        if(top1==capacity-1) return;

        st1[++top1]=value;
    }

    void dequeue(){
        int j;
        for (int i = top1,j=0; i >= 0; i--,j++)
        {
            st2[j]=st1[i];
        }
        top2 = j-1;

        for (int i = top2,j=0; i >= 0; i--,j++)
        {
            st1[j] = st2[i];
        }
        top1 = j;
        
    }

    int peek(){
        int j;
        for (int i = top1,j=0; i >= 0; i--,j++)
        {
            st2[j]=st1[i];
        }
        int value = st2[j];
        top2 = j;


        return value;
    }

    void print(){
        int j;
        for (int i = top1,j=0; i >= 0; i--,j++)
        {
            st2[j]=st1[i];
        }
        top2 = j;

        for (int i = top2; i >= 0; i--)
        {
            cout<<st2[i]<<" -> ";
        }cout<<'\n';
        
    }
};

int main(){

    fastio

    Queue* q = new Queue(5);
    q->enqueue(1);
    q->print();
    q->enqueue(2);
    q->print();

    return 0;
}