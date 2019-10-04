import sys

primes = []
twicesquares = []

def isprime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    for i in range(2, int(n**0.5)+1):
        if (n % i == 0):
            return False
    return True

for i in range(2, 10000):
    if (isprime(i)):
        primes.append(i)

for i in range(1, 100):
    twicesquares.append(2*i*i)

array = []
for i in range(30000):
    array.append(False)

for p in primes:
    for t in twicesquares:
        array[p+t] = True

for i in range(1, 100000000):
    if (not(isprime(2*i+1))):
        if (not(array[2*i+1])):
            print(2*i+1)
            sys.exit()

