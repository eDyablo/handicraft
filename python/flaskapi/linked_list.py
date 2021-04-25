class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node


class LinkedList:
    def __init__(self):
        self.head = None
        self.last_node = None

    def print(self):
        text = ''
        node = self.head
        while node:
            text += f'{str(node.data)} -> '
            node = node.next_node
        text += 'None'
        print(text)

    def push_front(self, data):
        new_node = Node(data, self.head)
        self.head = new_node
        if self.last_node is None:
            self.last_node = self.head

    def push_back(self, data):
        if self.head is None:
            self.push_front(data)
        else:
            self.last_node.next_node = Node(data)
            self.last_node = self.last_node.next_node

    def to_list(self):
        lst = []
        node = self.head
        while node:
            lst.append(node.data)
            node = node.next_node
        return lst
