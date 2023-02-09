class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_beginning(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return
        new_node.next = self.head
        self.head = new_node

    def insert(self, index, data):
        new_node = Node(data)
        temp = self.head
        if index < 0 or index >= self.length():
            raise Exception('invalid index')
        else:
            for i in range(index-1):
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node

    def append(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node

    def append_list(self, lst):
        for i in lst:
            self.append(i)

    def remove_by_index(self, index):
        temp = self.head
        if index < 0 or index >= self.length():
            raise Exception('invalid index')
        elif index == 0:
            self.head = self.head.next
        else:
            for i in range(index-1):
                temp = temp.next
            temp.next = temp.next.next

    def print_ll(self):
        print('linked list: ', end='')
        temp = self.head
        while temp:
            if temp.next is None:
                print(temp.data)
            else:
                print(temp.data, end='-->')
            temp = temp.next

    def length(self):
        length = 0
        temp = self.head
        while temp:
            length += 1
            temp = temp.next

        return length

    def insert_after_value(self, data_after, data_to_insert):
        if self.head is None:
            return

        new_node = Node(data_to_insert)
        temp = self.head
        while temp:
            if temp.data == data_after:
                # new_node.next = temp.next
                # temp.next = new_node
                temp.next = Node(data_to_insert, temp.next)
                break

            temp = temp.next
        else:
            print(
                f'Value not available. So {data_to_insert} cannot be inserted')

    def remove_by_value(self, data):
        if self.head is None:
            return

        if self.head.data == data:
            self.head = self.head.next
            return

        temp = self.head
        while temp.next:
            if temp.next.data == data:
                temp.next = temp.next.next
                break

            temp = temp.next
        else:
            print(f'Value not available. So, {data} cannot be removed.')

    def reverse(self):
        prev = None
        temp = self.head
        while temp:
            next = temp.next
            temp.next = prev
            prev = temp
            temp = next
        self.head = prev


ll = LinkedList()
ll.append_list(["banana", "mango", "grapes", "orange"])
ll.print_ll()
ll.reverse()
ll.print_ll()
# ll.insert_after_value("mango", "apple")  # insert apple after mango
# ll.print_ll()

# ll.remove_by_value("orange")  # remove orange from linked list
# ll.print_ll()
# ll.remove_by_value("banana")
# ll.print_ll()
# new = LinkedList()
# new.append_list([1, 2, 4, 5])
# new.insert(2, 3)
# new.print_ll()
# new.remove(2)
# new.print_ll()
# ll = LinkedList()
# ll.append(3)
# ll.append(4)
# ll.append(5)
# ll.remove(1)
# ll.print_ll()
