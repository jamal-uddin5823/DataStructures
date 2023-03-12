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

int* merge(int a1[], int s1, int a2[], int s2){
    int* ans = new int[s1+s2];

    int i=0,j=0,k=0, p=0;

    while(i<s1 && j<s2){
        if(a1[i]<=a2[j] ){
            ans[p++]=a1[i++];
        }

        else{
            ans[p++]=a2[j++];
        }
    }

    while(i<s1) ans[p++]=a1[i++];
    while(j<s2) ans[p++]=a2[j++];

    return ans;

}

int* merge3arr(int a1[], int s1, int a2[], int s2, int a3[], int s3){
    int* arr1 = merge(a1,s1,a2,s2);
    int* arr2 = merge(a3,s3,arr1,s1+s2);

    return arr2;
}

class Node{
public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        this->next = nullptr;
    }
};

Node* mergeLL(Node* a, Node* b){
    Node* ans = new Node(0);

    Node* c = ans;

    while(a!=nullptr && b!=nullptr){
        if(a->value<=b->value){
            c->next = a;
            a = a->next; 
        }
        else{
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }

    while(a!=nullptr){
        c->next = a;
        a = a->next;
        c = c->next;

    }

    while(b!=nullptr){
        c->next = b;
        b = b->next;
        c = c->next;

    }

    return ans->next;
}

void print(Node* a){
    while(a!=nullptr){
        cout<<a->value<<" -> ";
        a = a->next;
    }cout<<'\n';
}

int main(){

    fastio

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->next = c;
    b->next = d;

    Node* ans = mergeLL(a,b);
    
    
    print(ans);
    
    

    return 0;
}