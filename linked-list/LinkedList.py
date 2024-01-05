class LinkedList:
    def __init__(self) -> None:
        self.head = None

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
    print(llist)