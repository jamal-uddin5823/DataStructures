class Node:
    def __init__(self, value, next:'Node'=None) -> None:
        self.value = value
        self.next = next

    

class CircularLinkedList:
    def __init__(self):
        self.head = None
        self.size=0

    def insertAtBeginning(self,value):
        newNode = Node(value,self.head)

        if(self.head==None):
            self.head=newNode
            newNode.next = self.head

        else:
            currNode = self.head

            while(1):
                currNode = currNode.next
                if currNode.next == self.head:
                    break

            currNode.next = newNode
            self.head = newNode
        
        self.size+=1

    def insertAtEnd(self, value):
        newNode = Node(value,self.head)

        if self.head is None:
            self.head = newNode
            self.head.next = self.head
        
        else:
            currNode = self.head
            
            while 1:
                currNode = currNode.next

                if currNode.next == self.head: break

            currNode.next = newNode
        
        self.size+=1

    
    def insertAtMiddle(self,value,index):
        newNode = Node(value)

        if index> self.size: return
        if index==0:
            self.insertAtBeginning(value)
            return

        if index==self.size:
            self.insertAtEnd(value)
            return

        currNode = self.head

        count =0

        while count!= index-1:
            count+=1
            currNode = currNode.next

        newNode.next = currNode.next
        currNode.next = newNode
        self.size+=1

    def removeAtBeginning(self):
        if self.head is None: return

        currNode = self.head

        while 1:
            currNode = currNode.next
            if currNode.next == self.head: break

        currNode.next = self.head.next
        self.head = currNode.next

        self.size-=1

    def removeAtEnd(self):
        if self.head is None: return

        currNode = self.head

        while 1:
            currNode = currNode.next
            if currNode.next.next == self.head: break

        currNode.next = self.head

        self.size-=1

    def removeAtMiddle(self, index):
        if index >= self.size: return
        if index==0:
            self.removeAtBeginning()
            return

        if index == self.size-1:
            self.removeAtEnd()
            return
        
        count=0
        currNode = self.head

        while count != index-1:
            currNode = currNode.next
            count+=1
        
        currNode.next = currNode.next.next
        self.size-=1

    def find(self, value):
        index=0
        currNode = self.head

        while 1:
            if currNode.value == value: break

            currNode = currNode.next
            index+=1

            if currNode==self.head: return -1

        return index
    

    def removeWithValue(self, value):
        if self.head.value == value:
            self.removeAtBeginning()
            return
        
        currNode = self.head

        while 1:
            if currNode.next.value == value: break
            currNode = currNode.next

            if currNode.next == self.head: return

        currNode.next = currNode.next.next


    def print(self):
        currNode = self.head

        while 1:
            print(f'{currNode.value} -> ',end="")
            currNode = currNode.next

            if currNode==self.head: break

        print()



if __name__=="__main__":
    ll = CircularLinkedList()
    ll.insertAtEnd(1)
    ll.insertAtEnd(2)
    ll.insertAtEnd(3)
    ll.insertAtEnd(3)
    ll.insertAtBeginning(23)
    ll.insertAtMiddle(234,1)
    ll.removeAtBeginning()
    ll.removeAtEnd()
    ll.removeAtMiddle(2)
    print(ll.find(1))
    ll.removeWithValue(1)
    ll.print()