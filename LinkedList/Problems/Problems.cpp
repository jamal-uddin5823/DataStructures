
#include<bits/stdc++.h>
#include<E:\Prog stuffs\DataStructures\LinkedList\C++\LinkedList.hpp>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

class LL: public LinkedList{
private:
    void rec(Node* currNode, Node* newNode, int index){
        if(currNode==nullptr|| index==0){
            if(index==0)
                // newNode->next = this->head;
                newNode->next = this->get_head();
            // this->head = newNode;
            this->set_head(newNode);
            this->increase_size();
            // this->size++;
            return;
        }
        if(index==1){
            newNode->next = currNode->next;
            currNode->next = newNode;
            // this->size++;
            this->increase_size();
            return;
        }

        rec(currNode->next,newNode,index-1);
    }

    Node* recwithNode(int value, int index, Node* node){
        if(index==0){
            Node* newNode = new Node(value,node);
            // this->size++;
            this->increase_size();
            return newNode;
        }

        node->next = recwithNode(value,index-1,node->next);
        return node;
    }
public:
    void insertRec(int value, int index){
        if(index<0 || index> this->get_size()) return;
        
        Node* newNode = new Node(value);

        rec(this->get_head(),newNode,index);
    }

    void insertRecNode(int value, int index){
        // this->head = recwithNode(value, index,this->head);
        this->set_head(recwithNode(value, index,this->get_head()));
    }
};

int main(){

    fastio

    LL* ll = new LL();
    ll->insertRec(3,0);
    ll->insertRec(4,0);
    ll->insertRec(5,0);
    ll->insertRec(6,0);
    ll->insertRec(7,0);
    ll->print();
    ll->insertRecNode(56,2);
    ll->print();
    

    return 0;
}
