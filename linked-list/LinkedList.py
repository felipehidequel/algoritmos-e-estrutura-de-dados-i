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
    
    def add_first(self, node):
        node.next = self.head
        self.head = node

    def add_last(self,node):
        if self.head is None:
            self.head = node
            return
        for current_node in self:
            pass
        current_node.next = node

    def add_after(self, target_node_data, new_node):
        if self.head is None:
            raise Exception("List is empty")

        for node in self:
            if node.data == target_node_data:
                new_node.next = node.next
                node.next = new_node
                return
        
        raise Exception("Node with data '%s' not found" % target_node_data)
    
    def add_before(self, target_node_data, new_node):
        if self.head is None:
            raise Exception("List is empty")
        
        if self.head.data == target_node_data:
            return self.add_first(new_node)
        
        prev_node = self.head
        for node in self:
            if node.data == target_node_data:
                prev_node.next = new_node
                new_node.next = node
                return
            prev_node = node

        raise Exception("Node with data '%s' not found" % target_node_data)

    def remove_node(self, target_node_data):
        if self.head is None:
            raise Exception("List is empty")

        if self.head.data == target_node_data:
            self.head = self.head.next
            return
        
        previous_node = self.head
        for node in self:
            if node.data == target_node_data:
                previous_node.next = node.next
                return
            previous_node = node
        
        raise Exception("Node with data '%s' not found" % target_node_data)

    def get(self, index):
        if self.head is None:
            raise Exception("List is empty")
        
        for i,node in enumerate(self):
            if i == index:
                return node
        raise Exception("Node with index '%s' not found" % index)
    

class Node:
    def __init__(self,data) -> None:
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return self.data
    
if __name__=='__main__':
    llist = LinkedList()

    llist.add_first(Node('F'))
    llist.add_after("F", Node("E"))
    llist.add_last(Node("L"))
    llist.add_before("E", Node("E"))
    llist.remove_node("E")
    print(llist.get(1))
    reverse_ll = llist.reverse()
    print(llist)
    print(reverse_ll)