import math

def sumfac(n):
    mysum = 0
    for c in str(n):
        mysum += math.factorial(int(c))
    return mysum

def check(n):
    return sumfac(n)==n

mysum = 0
for i in range(3, 100000):
    if (check(i)):
        mysum += i

print(mysum)
