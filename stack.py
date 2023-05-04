class Stack:
    def __init__(self):
        self.stack = []

    def __del__(self):
        del self.stack

    def push(self, item):
        self.stack.append(item)

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            return None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

    def remove(self, item):
        if item in self.stack:
            self.stack.remove(item)
            return item
        else:
            return None
