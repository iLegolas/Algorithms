# https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174

def func(a):
    note = 0
    brk = 0
    for i in range(1,len(a)):
        if a[i] > a[i-1]:
            note -= 1
        elif a[i] < a[i-1]:
            note += 1
        if note < -3 or note > 3:
            note = 0
            brk += 1
    return brk

t = int(input())
for i in range(1,t+1):
    k = int(input())
    a = list(map(int,input().strip().split()))[:k]
    print("Case #"+str(i)+": "+str(func(a)))
