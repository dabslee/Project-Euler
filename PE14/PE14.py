# brute force probably will take ages
# dynamic programming solution is best

chainlengths = [-1, 1] # edge/base cases

def findlength(n):
    if (n >= len(chainlengths)):
        if (n % 2 == 0):
            return findlength(n//2) + 1
        else:
            return findlength(3*n+1) + 1
    if (chainlengths[n] != -1):
        return chainlengths[n]
    if (n % 2 == 0):
        chainlengths[n] = findlength(n//2) + 1
        return chainlengths[n]
    else:
        chainlengths[n] = findlength(3*n+1) + 1
        return chainlengths[n]

# initialize chainlengths
for i in range(1000000):
    chainlengths.append(-1)


maxlen = 0
index = 0
for i in range(1, 1000000):
    thislen = findlength(i)
    if (thislen > maxlen):
        maxlen = thislen
        index = i

print(index)
