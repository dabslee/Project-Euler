import sys

primitives = [[3,4,5], [5, 12, 13], [8, 15, 17], [7, 24, 25], [20, 21, 29], [12, 35, 37], [9, 40, 41], [28, 45, 53], [11, 60, 61], [33, 56, 65], [16, 63, 65], [48, 55, 73], [36, 77, 85], [13, 84, 85], [39, 80, 89], [65, 72, 97]]

perimeters = []
for i in range(1000+1):
    perimeters.append(0)

for triple in primitives:
    tcopy = triple.copy()
    while (sum(tcopy)<=1000):
        perimeters[sum(tcopy)] += 1
        tcopy[0] += triple[0]
        tcopy[1] += triple[1]
        tcopy[2] += triple[2]

mymax = max(perimeters)
for i in range(len(perimeters)):
    if (perimeters[i] == mymax):
        print(i)
        sys.exit()
