public class Main{
    public static void main(String[] args) {
        DoublyLinkedList ll = new DoublyLinkedList();

        ll.insertAtBeginning(0);
        ll.insertAtBeginning(1);
        ll.insertAtEnd(2);
        ll.insertAtMiddle(34, 2);
        ll.printForward();
        ll.removeAtMiddle(2);
        ll.printForward();
        System.out.println(ll.find(2));
    }
}