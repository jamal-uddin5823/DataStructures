public class Main{
    public static void main(String[] args) {
        CircularLinkedList ll = new CircularLinkedList();
        ll.insertAtBeginning(0);
        // System.out.println(ll.getHead());
        
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        ll.insertAtEnd(4);
        // ll.removeWithValue(4);
        ll.print();
    }
}