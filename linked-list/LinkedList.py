class LinkedList:
    def __init__(self, nodes=None) -> None:
        self.head = None
        if nodes is not None:
            node = Node(data=nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = Node(data=elem)
                node = node.next

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def __repr__(self) -> str:
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)
    
    
class Node:
    def __init__(self,data) -> None:
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return self.data
    
if __name__=='__main__':
    llist = LinkedList()

    first_node = Node("F")
    llist.head = first_node
    print(llist)

    second_node = Node("e")
    third_node = Node("l")
    first_node.next = second_node
    second_node.next = third_node
    
    for node in llist: print(node)