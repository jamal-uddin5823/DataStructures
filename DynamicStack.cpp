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

class Node{
public:
    int value;
    Node* next;
    Node(int value, Node* next = NULL){
        this->value=value;
        this->next = next;
    }
};

class Stack{
private:
    Node* top; //head
    int size;

public:
    Stack(){
        this->top = NULL;
        this->size = 0;
    }

    void push(int value){ //insert_at_beginning
        Node* newNode = new Node(value,this->top);
        if(this->top==NULL){
            top = newNode;
            this->size++;
            return;
        }
        this->top = newNode;
        this->size++;
    }

    int pop(){ //remove_from_beginning
        if(this->isEmpty()){
            cout<<"Stack Underflow\n";
            return INT_MIN;
        }
        Node* temp = this->top;
        int value = temp->value;
        this->top = this->top->next;
        this->size--;
        delete temp;
        return value;
    }

    int peek(){
        if(this->isEmpty()){
            cout<<"Stack Underflow\n";
            return INT_MIN;
        }

        return this->top->value;
    }

    bool isEmpty(){
        if(this->top==NULL) return true;
        return false;
    }

    int get_size(){
        return this->size;
    }

    void print(){
        Node* current = this->top;
        while(current){
            cout<<"| "<<current->value<<" |\n";
            current =current->next;
        }cout<<"_____\n";
    }

    

};

int main(){

    fastio

    Stack* st = new Stack();
    st->push(5);
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);
    cout<<st->peek()<<'\n';
    st->pop();
    st->print();
    cout<<st->get_size()<<'\n';
    

    return 0;
}