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

class CircularLinkedList{
private:
    Node* head;
    int size;
public:

    CircularLinkedList(){
        this->head = nullptr;
        this->size = 0;
    }

    int get_size(){
        return this->size;
    }

    Node* get_head(){
        return this->head;
    }

    void insert_front(int value){
        Node* newNode = new Node(value,this->head);
        if(this->head==nullptr){
            this->head = newNode;
        }
        else{
            Node* current = this->head;
            while(current->next!=nullptr){
                current = current->next;

                if(current->next == this->head) break;
            }
            current->next = newNode;
            this->head = newNode;
        }
        this->size++;
    }

    void insert_last(int value){
        
        Node* current = this->head;
        Node* newNode = new Node(value);
    
        if(this->head == nullptr){
            this->head = newNode;
            this->head->next = newNode;
            this->size++;
            return;
        }

        while(current->next!=nullptr){
            current = current->next;
            if(current->next == this->head) break;
        }

        current->next = newNode;
        newNode->next = this->head;
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

        Node* current = this->head;
        while(current->next!=nullptr){
            current = current->next;
            if(current->next == this->head) break;
        }

        Node* temp = this->head;
        this->head = this->head->next;
        current->next = this->head;
        delete temp;
        this->size--;
    }

    void remove_last(){
        Node* current = this->head;

        while(current->next!=nullptr){
            current = current->next;
            if(current->next->next == this->head) break;
        }

        Node* temp = current->next;
        current->next = this->head;

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
            if(current->next == this->head) break;
            pos++;
        }

        if(current==nullptr){
            return -1;
        }
        else if(current->value==value){
            return pos;
        }
        else{
            return -1;
        }
    }

    int remove_with_value(int value){
        int index = this->find(value);

        if(index==-1){
            cout<<"Value not available to remove\n";
            return -1;
        }

        this->remove_middle(index);
        return 0;
    }

    void print(){
        Node* current = this->head;

        while(current!=NULL){
            cout<<current->value<<" -> ";
            current = current->next;
            if(current== this->head) break;
        }cout<<'\n';
    }

    
};

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

    CircularLinkedList arr;

    // int n;  cin>>n;
    arr.insert_front(1);
    arr.insert_front(2);
    // arr.insert_last(1);
    // arr.insert_last(2);
    // arr.print();

    // for (int i = 0; i < n; i++)
    // {
    //     int a;  cin>>a;

    //     arr.insert_last(a);
    // }
    // arr.remove_middle(2);
    // arr.remove_with_value(3);

    // Node* current = arr.get_head();

    // while(current){
    //     cout<<current->value<<"->";
    //     current = current->next;
    // }cout<<'\n';

    arr.print();
    return 0;
}
