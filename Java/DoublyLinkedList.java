class DoublyNode{
    int value;
    DoublyNode next;
    DoublyNode prev;

    DoublyNode(int value){
        this.value = value;
        this.next=null;
        this.prev = null;
    }

    DoublyNode(int value, DoublyNode next){
        this.value=value;
        this.next = next;
        this.prev = null;
    }

    DoublyNode(int value, DoublyNode prev, DoublyNode next){
        this.value=value;
        this.prev=prev;
        this.next=next;
    }

    
}

public class DoublyLinkedList {
    private DoublyNode head;
    private DoublyNode tail;

    private int size;

    public int getSize(){
        return this.size;
    }

    public int getHead(){
        return this.head.value;
    }

    public int getTail(){
        return this.tail.value;
    }

    public DoublyLinkedList(){
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void insertAtBeginning(int value){
        DoublyNode newNode = new DoublyNode(value,this.head);
        if(this.head==null){
            this.tail = newNode;
        }
        else{
            this.head.prev = newNode;
        }
        this.head =newNode;
        this.size++;
    }

    public void insertAtEnd(int value){
        DoublyNode newNode = new DoublyNode(value,this.tail,null);
        if(this.tail==null){
            this.head = newNode;
        }
        else{
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.size++;
    }

    public void insertAtMiddle(int value, int index){
        if(index>this.size) return;

        if(index==0){
            insertAtBeginning(value);
            return;
        }

        if(index==this.size){
            insertAtEnd(value);
            return;
        }

        if(2*index<this.size){
            DoublyNode currNode = this.head;
            DoublyNode newNode = new DoublyNode(value);
            int count = 0;

            while(count!=index-1){
                count++;
                currNode = currNode.next;
            }
            newNode.prev = currNode;
            newNode.next = currNode.next;
            currNode.next.prev = newNode;
            currNode.next = newNode;
        }

        else{
            DoublyNode curNode = this.tail;
            DoublyNode newNode = new DoublyNode(value);
            int count = this.size-1;

            while(count!=index){
                count++;
                curNode = curNode.prev;
            }

            curNode.prev.next = newNode;
            newNode.prev = curNode.prev;
            curNode.prev = newNode;
            newNode.next = curNode;
        }

        this.size++;
    }

    public void removeAtBeginning(){
        if(this.head==null) return;
        this.head = this.head.next;
        this.head.prev = null;
        this.size--;
    }

    public void removeAtEnd(){
        if(this.tail==null) return;
        this.tail = this.tail.prev;
        this.tail.next = null;
        this.size--;
    }

    public void removeAtMiddle(int index){
        if(index>this.size) return;
        if(index==0){
            removeAtBeginning();
            return;
        }
        if(index==this.size-1){
            removeAtEnd();
            return;
        }

        if(2*index<this.size){
            DoublyNode currNode = this.head;
            int count =0;
            
            while(count!=index-1){
                count++;
                currNode = currNode.next;
            }

            currNode.next = currNode.next.next;
            currNode.next.prev = currNode;
        }

        else{
            DoublyNode currNode = this.tail;
            int count = this.size-1;

            while(count!=index+1){
                count--;
                currNode = currNode.prev;
            }

            currNode.prev = currNode.prev.prev;
            currNode.prev.next = currNode;
        }
        this.size--;
    }

    public int find(int value){
        DoublyNode currNode = this.head;
        int index=0;
        while(currNode!=null && currNode.value!=value){
            index++;
            currNode = currNode.next;
        }

        if(currNode==null)
            return -1;

        return index;
    }

    public int removeWithValue(int value){
        DoublyNode currNode = this.head;
        int index = 0;

        while(currNode!=null && currNode.value!=value){
            index++;
            currNode = currNode.next;
        }

        if(currNode==null) return -1;
        return index;
    }

    public void printForward(){
        DoublyNode currNode = this.head;
        while(currNode!=null){
            System.out.print(currNode.value+" <-> ");
            currNode = currNode.next;
        }System.out.println();
    }

    public void printBackward(){
        DoublyNode currNode = this.tail;

        while(currNode!=null){
            System.out.println(currNode.value+" <-> ");
            currNode = currNode.prev;
        }System.out.println();
    }
}
