import sys


#sys.stdin = open("input.txt")

sys.setrecursionlimit(10000)

MOD = 10 ** 9


class Program:
    def __init__(self):
        self.n = 0
        self.e = 0

    def mul(self, m):
        self.n *= m
        self.e *= m

    def add(self, p):
        self.n = (self.n + p.n) % MOD
        self.e = (self.e + p.e) % MOD

    def move(self, c):
        if(c == 'W'):
            self.e -= 1
        elif(c == 'E'):
            self.e += 1
        elif(c == 'N'):
            self.n -= 1
        elif(c == 'S'):
            self.n += 1


def parse(p, comms, i):
    if(i == len(comms)):
        return -1
    if(comms[i] == '('):
        return parse(p, comms, i + 1)
    elif(comms[i] == ')'):
        return i + 1
    elif(comms[i] in "NSWE"):
        p.move(comms[i])
        return parse(p, comms, i + 1)
    else:
        num = int(comms[i])
        new_p = Program()
        new_i = parse(new_p, comms, i + 1)
        new_p.mul(num)
        p.add(new_p)
        return parse(p, comms, new_i)


testCases = int(input())

for testCase in range(1, testCases + 1):
    comms = input().strip()

    p = Program()

    parse(p, comms, 0)

    MOD = (10 ** 9)

    new_w = 1 + p.e % MOD
    new_h = 1 + p.n % MOD

    print("CASE #{}: {} {}".format(testCase, new_w, new_h))
