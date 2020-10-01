# https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

'''
Problem
Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. A day is record breaking if it satisfies both of the following conditions:
The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day!

Please help Isyana find out the number of record breaking days.
'''

def func(v):
    maxm = -1
    count = 0
    for i in range(0,len(v)-1):
        if v[i] > maxm:
            maxm = v[i]
        else:
            continue
        if v[i] > v[i+1]:
            count += 1
    if v[-1] > maxm:
        count += 1
    return count
    
t = int(input())
for i in range(1,t+1):
    n = int(input())
    v = list(map(int,input().strip().split()))[:n]
    print("Case #"+str(i)+": "+str(func(v)))
