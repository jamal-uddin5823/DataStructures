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

class Stack
{
private:
    int capacity;
    int* st;
    int top;
    int size;
public:
    Stack(int capacity);
    bool push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
    int get_capacitty();
    int get_size();
};

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    this->st = (int*)malloc(capacity*sizeof(int));
    this->top=-1;
    this->size=0;
}

bool Stack::push(int value){
    if(this->isFull()){
        cout<<"Stack overflow\n";
        return false;
    }

    this->st[++this->top]=value;
    this->size++;
    return true;
}

int Stack::pop(){
    if(this->isEmpty()){
        cout<<"Stack Underflow\n";
        return INT_MIN;
    }

    int value = this->st[top];
    this->top--;
    this->size--;
    return value;
}

int Stack::peek(){
    if(this->isEmpty()){
        cout<<"Stack is Empty\n";
        return INT_MIN;
    }
    return this->st[this->top];
}

bool Stack::isEmpty(){
    if(this->top==-1) return true;
    else return false;
}

bool Stack::isFull(){
    if(this->top==this->capacity-1) return true;
    else return false;
}

void Stack::print(){
    for (int i = this->top; i >-1; i--)
    {
        cout<<"| "<<st[i]<<" |\n";
    }cout<<"_____\n";
    
}

int Stack::get_capacitty(){
    return this->capacity;
}

int Stack::get_size(){
    return this->size;
}




int main(){

    fastio
    Stack* st = new Stack(5);
    st->push(5);
    st->push(5);
    st->push(5);
    st->push(5);
    // st->push(5);
    cout<<st->isFull();

    return 0;
}