import numpy as np
from collections import defaultdict

def reconstruct_path(camefrom, current):
    total_path = [current]
    while(current in camefrom):
        current = camefrom[current]
        total_path += [current]
    return total_path

def A_Star(start, goal, h, graph,cost):
    openset = [start]
    camefrom = {}

    gScore = defaultdict(lambda: float('inf'))
    gScore[start] = 0

    fScore = defaultdict(lambda: float('inf'))
    fScore[start] = h[start]

    i = openset[0]
    closedSet = []
    while(i in openset):
        current = min(openset)
        if(current == goal):
            return reconstruct_path(camefrom,current)
        closedSet += [current]
        openset.remove(current)
        for i in Graph[current]:
            if i in closedSet:
                continue
            tentative_gScore = gScore[current] + cost[current][i]
            if(tentative_gScore < gScore[i]):
                camefrom[i] = current
                gScore[i] = tentative_gScore
                fScore[i] = gScore[i] + h[i]
                if i not in openset:
                    openset += [i]
    return 0

#Graph 1
nodes = np.arange(5)
visited = np.zeros(5)

h = np.array([7,6,2,1,0], dtype=int)# heuristics

cost = np.full([5,5],-1)

cost[0][1] = 1
cost[0][2] = 4
cost[1][2] = 2
cost[1][3] = 5
cost[1][4] = 12
cost[2][3] = 2
cost[3][4] = 3 

start = 0
goal = 4

Graph = dict()
Graph.update({0:[1,2]})
Graph.update({1:[2,3,4]})
Graph.update({2:[3]})
Graph.update({3:[4]})
Graph.update({4:[]})

#Graph 2
h2 = np.array([10,5,6,4,15,5,8,0], dtype=int)# heuristics

cost2 = np.full([8,8],-1)

cost2[0][1] = 1
cost2[0][2] = 2
cost2[1][4] = 4
cost2[1][3] = 7
cost2[2][5] = 7
cost2[2][6] = 1
cost2[3][7] = 3
cost2[4][7] = 2
cost2[5][7] = 3
cost2[6][7] = 12

start2 = 0
goal2 = 7

Graph2 = dict()
Graph2.update({0:[1,2]})
Graph2.update({1:[3,4]})
Graph2.update({2:[5,6]})
Graph2.update({3:[7]})
Graph2.update({4:[7]})
Graph2.update({5:[7]})
Graph2.update({6:[7]})
Graph2.update({7:[]})

a = A_Star(start,goal,h,Graph,cost)
a.reverse()
print('Path of Graph1 is ',a)

a2 = A_Star(start2,goal2,h2,Graph2,cost2)
a2.reverse()
print('Path is of Graph2 is',a2)
'''
# Creative print of path
print('Path is ',end=' ')
for i in a:
    if(i == a[-1]):
        print(i)
        break
    print(i,'->', end=' ')
'''
