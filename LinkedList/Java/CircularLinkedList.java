class Node{
    int value;
    Node next;

    Node(int value){
        this.value = value;
        this.next = null;
    }

    Node(int value, Node next){
        this.value = value;
        this.next = next;
    }
}

public class CircularLinkedList {
    private Node head;
    private int size;

    public CircularLinkedList(){
        this.head = null;
        this.size = 0;
    }

    public int getSize(){
        return this.size;
    }

    public int getHead(){
        return this.head.value;
    }

    public void insertAtBeginning(int value){
        Node newNode = new Node(value, this.head);
        if(this.head == null){
            this.head = newNode;
            newNode.next = this.head;
        }
        else{
            Node currNode = this.head;
            while(true){
                currNode = currNode.next;

                if(currNode.next==this.head) break;
            }

            currNode.next = newNode;
            this.head = newNode;
        }

        this.size++;
    }

    public void insertAtEnd(int value){
        Node newNode = new Node(value, this.head);
        if(this.head == null){
            this.head = newNode;
            // newNode.next = this.head;
        }
        else{
            Node currNode = this.head;
            while(true){
                currNode = currNode.next;

                if(currNode.next==this.head) break;
            }

            currNode.next = newNode;
        }

        this.size++;
    }

    public void insertAtMiddle(int value, int index){
        Node newNode = new Node(value);
        if(index>this.size) return;
        if(index==0){
            insertAtBeginning(value);
            return;
        }
        if(index==this.size){
            insertAtEnd(value);
            return;
        }

        Node currNode = this.head;
        int count=0;

        while(count!=index-1){
            count++;
            currNode = currNode.next;
        }

        newNode.next = currNode.next;
        currNode.next = newNode;
        this.size++;
        
    }

    public void removeAtBeginning(){
        if(this.head==null) return;

        Node currNode = this.head;

        while(true){
            currNode = currNode.next;
            if(currNode.next == this.head) break;
        }

        currNode.next = this.head.next;
        this.head = currNode.next;

        this.size--;
    }

    public void removeAtEnd(){
        if(this.head==null) return;

        Node currNode = this.head;

        while(true){
            currNode = currNode.next;
            if(currNode.next.next == this.head) break;
        }

        currNode.next = this.head;

        this.size--;
    }

    public void removeAtMiddle(int index){
        if(index>=this.size) return;
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
            currNode = currNode.next;
            count++;
        }

        currNode.next = currNode.next.next;
        this.size--;
    }

    public int find(int value){
        int index=0;
        Node currNode = this.head;

        while(true){
            if(currNode.value==value) break;

            currNode = currNode.next;
            index++;

            if(currNode==this.head) return -1;
        }

        return index;
    }

    public void removeWithValue(int value){
        if(this.head.value==value){
            removeAtBeginning();
            return;
        }
        
        Node currNode = this.head;


        while(true){
            if(currNode.next.value==value) break;
            currNode = currNode.next;

            if(currNode.next==this.head)return;
        }   

        currNode.next = currNode.next.next;
    }


    public void print(){
        Node currNode = this.head;

        while(true){
            System.out.print(currNode.value+"->");
            currNode = currNode.next;
            
            if(currNode==this.head) break;
        }System.out.println();
    }

}
