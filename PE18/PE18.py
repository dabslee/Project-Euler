# get input

sc = open("PE18.txt", 'r')

inputlist = []
depth = 1
inputint = 0

for line in sc:
    oneline = []
    for s in line.split():
        oneline.append(int(s))
    inputlist.append(oneline)
    depth += 1
depth -= 1

# create matrix of zeros
sums = []
for i in range(0, depth):
    row = []
    for j in range(0, depth + 1):
        row.append(0)
    sums.append(row)

sums[0][1] = inputlist[0][0]
for i in range(1, depth):
    for j in range(1, i+2):
        sums[i][j] = max(sums[i - 1][j - 1] + inputlist[i][j-1], sums[i - 1][j] + inputlist[i][j - 1])

maxsum = 0
for i in range(0, depth+1):
    maxsum = max(maxsum, sums[depth - 1][i])
print(maxsum)
