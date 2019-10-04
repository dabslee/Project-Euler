import math

def isPrime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    if (n == 4):
        return False
    if (n == 5):
        return True
    for i in range(2, int(n**0.5)+1):
        if (n % i == 0):
            return False
    return True

def shiftleft(sn):
    shifted = sn[1:]
    shifted += sn[0]
    return shifted

def checkcirc(sn):
    if (not isPrime(int(sn))):
        return False
    sn2 = shiftleft(sn)
    while (sn2 != sn):
        if (not isPrime(int(sn2))):
            return False
        sn2 = shiftleft(sn2)
    return True

count = 0
for i in range(2, 1000000):
    if (checkcirc(str(i))):
        count += 1
print(count)
