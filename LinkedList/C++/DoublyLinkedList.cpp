#include<bits/stdc++.h>
using namespace std;

class DoublyNode{
public:
    int value;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(int value,DoublyNode* prev = nullptr, DoublyNode* next= nullptr){
        this->value=value;
        this->next = next;
        this->prev=prev;
    }

};

class DoublyLinkedList{
private:
    DoublyNode* head;
    DoublyNode* tail;
    int size;
public:

    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    int get_size(){
        return this->size;
    }

    DoublyNode* get_head(){
        return this->head;
    }
    DoublyNode* get_tail(){
        return this->tail;
    }

    void insert_front(int value){
        DoublyNode* newNode = new DoublyNode(value,this->head);

        this->head = newNode;
        this->size++;
        if(this->tail == nullptr){
            this->tail = this->head;
        }
    }

    void insert_last(int value){
        
        DoublyNode* newNode = new DoublyNode(value);
        if(this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
            this->size++;
            return;
        }

        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
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
        DoublyNode* current = this->head;
        DoublyNode* latter = current->next;
        DoublyNode* newNode = new DoublyNode(value);

        while(pos<index-1){
            current = current->next;
            latter = current->next;
            pos++;
        }
        newNode->next = latter;
        latter->prev=newNode;

        current->next = newNode;
        newNode->prev = current;

        this->size++;
        return 0;
        
    }


    void remove_front(){
        if(this->head==nullptr && this->tail==nullptr) return;
        
        DoublyNode* temp = this->head;
        if(this->head == this->tail){
            this->tail == nullptr;
        }
        this->head = this->head->next;
        this->head->prev = nullptr;
        delete temp;
        this->size--;
    }

    void remove_last(){
        if(this->head==nullptr && this->tail==nullptr) return;
        DoublyNode* current = this->tail;

        if(this->head == this->tail){
            this->head == nullptr;
        }
        this->tail  = this->tail->prev;
        delete current;
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

        DoublyNode* current = this->head;
        int pos = 0;

        while(pos<index-1){
            current = current->next;
            pos++;
        }

        DoublyNode* temp = current->next;

        current->next = temp->next;
        temp->next->prev = current;

        delete temp;
        this->size--;
        return 0;
    }

    int find(int value){
        DoublyNode* current = this->head;
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

        if(index==-1){
            cout<<"Value not available to remove\n";
            return -1;
        }

        this->remove_middle(index);
        return 0;
    }

    void printForward(){
        DoublyNode* current = this->head;

        while(current!=NULL){
            cout<<current->value<<" <-> ";
            current = current->next;
        }cout<<'\n';
    }

    void printBackward(){
        DoublyNode* current = this->tail;

        while(current!=NULL){
            cout<<current->value<<" <-> ";
            current = current->prev;
        }cout<<'\n';
    }


    
};

DoublyLinkedList make_unique(DoublyLinkedList arr){
    DoublyLinkedList ans;
    DoublyNode* current = arr.get_head();
    DoublyNode* curr_ans = ans.get_head();

    while(current){
        if(current->prev== nullptr && current->value!=current->next->value ){
            ans.insert_last(current->value);
        }
        else if(current->next == nullptr && current->value!=current->prev->value){
            ans.insert_last(current->value);
        }
        else if(current->prev != nullptr && current->next != nullptr && current->value!=current->prev->value && current->value!=current->next->value){
            ans.insert_last(current->value);
        }
        current = current->next;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
        // associates standard input with input.txt 
    freopen("Cin.txt", "r", stdin);
    // associates standard output with output.txt
    // (this will create a new file called output.txt if none exists)
	freopen("Cout.txt", "w", stdout);

    int n;  cin>>n;
    DoublyLinkedList arr;

    for (int i = 0; i < n; i++)
    {
        int a;  cin>>a;
        arr.insert_last(a);
    }

    DoublyLinkedList unique = make_unique(arr);

    unique.printForward();
    
    return 0;
}