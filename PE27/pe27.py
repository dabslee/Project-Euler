
def isPrime(n):
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True

def f(a, b, n):
    return n*n+a*n+b

def numprimes(a, b):
    n = 0
    while (isPrime(f(a,b,n))):
        n += 1
    return n

maxnum = 0
maxprod = 0
for a in range(-999,999+1):
    for b in range(-1000,1000+1):
        nump = numprimes(a,b)
        if (nump > maxnum):
            maxnum = nump
            maxprod = a*b

print(maxprod)
