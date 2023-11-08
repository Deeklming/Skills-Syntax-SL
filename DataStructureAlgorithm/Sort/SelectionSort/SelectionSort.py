class SelectionSort:
    def __init__(self):
        self.li = [9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6]
        self.listlen = self.li.__len__()

    def swap(self, a, b):
        self.li[a], self.li[b] = self.li[b], self.li[a]

    def selectionSort(self, opt):#true이면 오름차순 false이면 내림차순
        if opt:
            for i in range(self.listlen-1):
                n = i
                for j in range(i+1, self.listlen):
                    if self.li[j] < self.li[n]:
                        n = j
                self.swap(i, n)
        else:
            for i in range(self.listlen-1, -1, -1):
                n = i
                for j in range(i-1, -1, -1):
                    if self.li[j] < self.li[n]:
                        n = j
                self.swap(i, n)
    
    def pr(self):
        print(self.li)

if __name__ == "__main__":
    ss = SelectionSort()
    ss.selectionSort(False)
    ss.pr()
    ss.selectionSort(True)
    ss.pr()
