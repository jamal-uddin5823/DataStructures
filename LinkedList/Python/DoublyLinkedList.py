class Node:

    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class DoublyLinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = Node(data)
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        new_node.prev = temp
        temp.next = new_node

    def append_lst(self, lst):
        for i in lst:
            self.append(i)

    def print_forward(self):

        temp = self.head
        while temp:
            if temp.next:
                print(temp.data, end='-->')
            else:
                print(temp.data)
            temp = temp.next

    def print_backword(self):
        temp = self.head
        while temp.next:
            temp = temp.next

        while temp:
            if temp.prev:
                print(temp.data, end='-->')
            else:
                print(temp.data)
            temp = temp.prev


ll = DoublyLinkedList()
ll.append_lst(["banana", "mango", "grapes", "orange"])
ll.print_forward()
ll.print_backword()
