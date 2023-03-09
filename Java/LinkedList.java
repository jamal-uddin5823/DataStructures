class Node{
    int value;
    Node next;

    Node(int value){
        this.value = value;
        this.next=null;
    }

    Node(int value, Node next){
        this.value=value;
        this.next = next;
    }

    
}

class LinkedList{
    private Node head;
    private Node tail;
    private int size;

    LinkedList(){
        this.head = null;
        this.tail = null;
        this.size=0;
    }

    public int getSize(){
        return this.size;
    }

    public int getHead(){
        return this.head.value;
    }

    public int getTail(){
        return this.tail.value;
    }

    
    public void insertAtBeginning(int value){
        this.head = new Node(value,this.head);
        this.size++;
        
        if(this.tail==null) this.tail = this.head;
    }

    
    public void insertAtEnd(int value){
        if(this.head==null){
            this.head = new Node(value);
            this.size++;
            this.tail = this.head;
            return;
        }

        Node newNode = new Node(value);
        this.tail.next = newNode;
        this.tail = this.tail.next;
        this.size++;
    }



    public void insertAtMiddle(int value, int index){
        if(index>=this.size){
            System.err.println("Index out of bound");
            return;
        }

        if(index==0){
            insertAtBeginning(value);
            return;
        }

        if(index == this.size-1){
            insertAtEnd(value);
            return;
        }

        int count = 0;
        Node newNode = new Node(value);
        Node currNode = this.head;

        while(count!=index-1){
            currNode = currNode.next;
            count++;
        }

        newNode.next = currNode.next;
        currNode.next = newNode;
        this.size++;
    }


    public void removeAtBeginning(){
        if(this.head==null){
            System.err.println("List is empty");
            return;
        }
        this.head = this.head.next;
        this.size--;
    }

    public void removeAtEnd(){
        Node currNode = this.head;

        while(currNode.next.next!=null){
            currNode = currNode.next;
        }
        this.tail = currNode;
        currNode.next = null;
        this.size--;
    }



    public void removeAtMiddle(int index){
        if(index==0){
            removeAtBeginning();
            return;
        }
        if(index==this.size-1){
            removeAtEnd();
            return;
        }

        int count=0;
        Node currNode = this.head;

        while(count!=index-1){
            count++;
            currNode = currNode.next;
        }

        currNode.next = currNode.next.next;
        this.size--;
    }


    public int find(int value){
        int index = 0;
        Node currNode = this.head;

        while(currNode!=null && currNode.value!=value){
            currNode=currNode.next;
            index++;
        }

        if(currNode==null) return -1;
        return index;
    }

    public void removeWithValue(int value){
        Node currNode = this.head;

        while(currNode!=null && currNode.next.value!=value){
            currNode=currNode.next;
        }

        if(currNode==null) return;

        currNode.next = currNode.next.next;
        this.size--;
    }


    public void print(){
        Node currNode = this.head;

        while(currNode!=null){
            System.out.print(currNode.value+" -> ");
            currNode = currNode.next;
        }System.out.println();
    }


}