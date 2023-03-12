#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int value, Node* next= nullptr){
        this->value=value;
        this->next = next;
    }

};

class LinkedList{
private:
    Node* head;
    int size;
public:

    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }


    int get_size(){return this->size;}

    void set_size(int size){this->size = size;}

    void increase_size(){this->size++;}
    void decrease_size(){this->size--;}

    Node* get_head(){return this->head;}

    void set_head(Node* head){this->head = head;}

    void insert_front(int value){
        Node* newNode = new Node(value,this->head);

        this->head = newNode;
        this->size++;
    }

    void insert_last(int value){
        
        Node* current = this->head;
        Node* newNode = new Node(value);
    
        if(this->head == nullptr){
            this->head = newNode;
            this->size++;
            return;
        }

        while(current->next!=nullptr){
            current = current->next;
        }

        current->next = newNode;
        this->size++;
    }

    int insert_middle(int value, int index){
        if(index>this->size){
            cout<<"index out of bound\n";
            return -1;
        }
        if(index==0){
            insert_front(value);
            return 0;
        }

        if(index==this->size){
            insert_last(value);
            return 0;
        }

        int pos = 0;
        Node* current = this->head;
        Node* newNode = new Node(value);

        while(pos<index-1){
            current = current->next;
            pos++;
        }
        newNode->next = current->next;
        current->next = newNode;
        this->size++;
        return 0;
        
    }


    void remove_front(){
        if(this->head==nullptr) return;
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }

    void remove_last(){
        Node* current = this->head;

        while(current->next->next!=nullptr){
            current = current->next;
        }

        Node* temp = current->next;

        current->next = nullptr;

        delete temp;
        this->size--;
    }

    int remove_middle(int index){
        if(index>=this->size){
            cout<<"Index out of bound\n";
            return -1;
        }

        if(index == 0){
            this->remove_front();
            return 0;
        }

        if(index==this->size-1){
            this->remove_last();
            return 0;
        }

        Node* current = this->head;
        int pos = 0;

        while(pos<index-1){
            current = current->next;
            pos++;
        }

        Node* temp = current->next;

        current->next = current->next->next;

        delete temp;
        this->size--;
        return 0;
    }

    int find(int value){
        Node* current = this->head;
        int pos = 0;
        while(current!=nullptr && current->value!=value){
            current = current->next;
            pos++;
        }

        if(current!=nullptr){
            return pos;
        }
        else{
            return -1;
        }
    }

    int remove_with_value(int value){
        int index = this->find(value);
        Node* current = this->head;

        while(current!=nullptr && current->next->value!=value){
            current = current->next;
        }
        
        if(current==nullptr) return -1;

        current->next = current->next->next;
        this->size--;
        return 0;
    }

    void print(){
        Node* current = this->head;

        while(current!=NULL){
            cout<<current->value<<" -> ";
            current = current->next;
        }cout<<'\n';
    }

    
};


LinkedList merge(LinkedList a, LinkedList b){
    LinkedList ans;
    Node* node_a = a.get_head();
    Node* node_b = b.get_head();

    while(node_a!=nullptr && node_b!=nullptr){
        if(node_a->value<=node_b->value){
            ans.insert_last(node_a->value);
            node_a = node_a->next;
        }
        else{
            ans.insert_last(node_b->value);
            node_b = node_b->next;
        }
    }

    while(node_a!=nullptr){
        ans.insert_last(node_a->value);
        node_a = node_a->next;
    }

    while(node_b!=nullptr){
        ans.insert_last(node_b->value);
        node_b = node_b->next;
    }

    return ans;
}




// //******************A******************************//
// int main(int argc, char const *argv[])
// {
//     // associates standard input with input.txt 
//     freopen("Ain.txt", "r", stdin);
//     // associates standard output with output.txt
//     // (this will create a new file called output.txt if none exists)
// 	freopen("Aout.txt", "w", stdout);

//     LinkedList arr1, arr2;

//     int n;  cin>>n;
    

//     for (int i = 0; i < n; i++)
//     {
//         int a;  cin>>a;

//         arr1.insert_last(a);
//     }
    
//     cin>>n;

//     for (int i = 0; i < n; i++)
//     {
//         int a;  cin>>a;

//         arr2.insert_last(a);
//     }
    

//     LinkedList ans = merge(arr1,arr2);

//     ans.print();
//     return 0;
// }


// ////******************B*************************
// int main(int argc, char const *argv[])
// {
//     // associates standard input with input.txt 
//     freopen("Bin.txt", "r", stdin);
//     // associates standard output with output.txt
//     // (this will create a new file called output.txt if none exists)
// 	freopen("Bout.txt", "w", stdout);

//     int tot;    cin>>tot;
//     // cout<<tot<<'\n';
//     LinkedList ans;

//     for (int i = 0; i < tot; i++)
//     {
//         int n;  cin>>n;
//         LinkedList arr1;

//         for (int j = 0; j < n; j++)
//         {
//             int a; cin>>a;
//             arr1.insert_last(a);
//         }

//         ans = merge(ans, arr1);
        
//     }
    
//     ans.print();
//     return 0;
// }





