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
        del self.stack[item]

    def remove(self, item):
        if item in self.stack:
            self.stack.remove(item)
            return item
        else:
            return None
s = Stack() #deklarasi stac

s.push(1) #memasukan nilai
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.push(6)
s.remove(s.peek())#hapus nilai paling atas
s.rm(1) #hapus stack ke 1

while(s.size()):
    print(s.peek())
    s.remove(s.peek())
