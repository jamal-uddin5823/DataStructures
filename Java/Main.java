public class Main{
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        // ll.removeAtBeginning();
        ll.insertAtBeginning(3);
        ll.insertAtEnd(0);
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtMiddle(45, 2);

        ll.print();
        ll.removeWithValue(45);
        // ll.removeAtMiddle(3);   
        ll.print();

        System.out.println(ll.find(45));
    }
}