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
    def rm(self,item):
      if len(self.stack) >= item:
          del self.stack[item]

    def rmtop(self):
        if len(self.stack):
          del self.stack[-1]
        else:
            return None

s = Stack() #create stack obj  
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5) #insert val
s.rmtop() #pop top


while(s.size()):
    print(s.peek())
    s.rmtop()
