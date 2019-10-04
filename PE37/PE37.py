def isPrime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    for i in range(2, int(n**0.5)+1):
        if (n % i == 0):
            return False
    return True

def truncateleft(n):
    if (n > 9):
        return int(str(n)[1:])
    return 0

def truncateright(n):
    return n//10

def checkleft(n):
    while (n != 0):
        if (not isPrime(n)):
            return False
        n = truncateleft(n)
    return True

def checkright(n):
    while (n != 0):
        if (not isPrime(n)):
            return False
        n = truncateright(n)
    return True

count = 0
mysum = 0
i = 9
while (count < 11):
    i += 1
    if (checkleft(i) and checkright(i)):
        count += 1
        mysum += i

print(mysum)
