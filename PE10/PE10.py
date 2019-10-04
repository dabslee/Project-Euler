# Slower than C++ and Java, takes like 30 s to run. Could optimize with sieve of erastothenes, but this is easier to program.

def isprime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    for f in range(2, int(n**0.5)+1):
        if (n % f == 0):
            return False
    return True

mysum = 2
upto = 2000000
for i in range(3, upto, 2):
    if (isprime(i)):
        mysum += i
print(mysum)
