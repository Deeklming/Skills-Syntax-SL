class Node:
    def __init__(self, next=None, data=None):
        self.next = next
        self.data = data
class SimpleLinkedList:
    def __init__(self):
        self.header = Node()
        self.pos = self.header
    def InsertNode(self, d):
        newnode = Node(self.pos.next, d)
        self.pos.next = newnode
        self.pos = newnode
        print("insert", d)
    def PrintList(self):
        p = self.header.next
        print("header", end='')
        while p != None:
            print(f"->{p.data}", end='')
            p = p.next
        print()
    def DeleteNode(self, d):
        pre = self.header
        p = self.header.next
        while p != None:
            if p.data == d:
                pre.next = p.next
                if self.pos.data == d:
                    self.pos = pre
                del p
                print("delete", d)
                return
            pre = p
            p = p.next
    def CheckData(self, d):
        p = self.header.next
        while p != None:
            if p.data == d:
                return True
            p = p.next
        return False

if __name__ == "__main__":
    sll = SimpleLinkedList()
    sll.InsertNode("A")
    sll.InsertNode("B")
    sll.PrintList()
    sll.DeleteNode("A")
    sll.InsertNode("C")
    sll.InsertNode("D")
    sll.PrintList()
    print("B in list?", sll.CheckData("B"))
    if sll.CheckData("E") == False:
        sll.InsertNode("E")
    sll.PrintList()