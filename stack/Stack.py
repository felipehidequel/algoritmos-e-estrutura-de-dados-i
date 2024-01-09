# stack implementation using a linked list
# node class

class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class Stack:

    # Initializing a stack.
    # Use a dummy node, which is
    # eaisier for handling edge cases.
    def __init__(self) -> None:
        self.head = Node("head")
        self.size = 0
    
    # String representation of the stack
    def __str__(self) -> str:
        cur = self.head.next
        out = ""
        while cur:
            out += str(cur.data) + "->"
            cur = cur.next
        return out[:-2]
    
    # Get the current size of the stack
    def getSize(self):
        return self.size
    
    # Check if the stack is empty
    def isEmpty(self):
        return self.size == 0
    
    # Get the top item of the stack
    def peek(self):

        # Sanitary check to see if we
        # are peeking an empty stack.
        if self.isEmpty():
            raise Exception("Peeking from an empty stack")
        return self.head.next.data
    
    # Push a data into the stack.
    def push(self, data):
        node = Node(data)
        node.next = self.head.next
        self.head.next = node
        self.size += 1

    # Remove a value from the stack and return
    def pop(self):
        if self.isEmpty():
            raise Exception("Popping from an empty stack")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return remove.data

if __name__=="__main__":
    stack = Stack()
    for i in range(1,11):
        stack.push(i)
    print(f'Stack: {stack}')

    for _ in range(1,6):
        remove = stack.pop()
        print(f'Pop: {remove}')
    print(f'Stack: {stack}')