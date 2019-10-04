def checkpan(n):
    nstr = str(n)
    ndigits = len(nstr)
    for i in range(1, ndigits+1):
        if str(i) not in nstr:
            return False
    return True

def checkprime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    for i in range(2, int(n**0.5)+1):
        if (n % i == 0):
            return False
    return True

mymax = 0
for i in range(1, 10000000):
    if (checkpan(i) and checkprime(i)):
        mymax = i
print(mymax)
