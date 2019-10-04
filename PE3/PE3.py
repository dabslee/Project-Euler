def isPrime(n):
    if (n < 2):
        return False
    if (n < 4):
        return True
    for f in range(2, int(n**0.5)+1):
        if (n % f == 0):
            return False
    return True

n = 600851475143
maxi = 0
i = 2
while (i <= n):
    if (n % i == 0 and isPrime(i)):
        maxi = i
        n /= i
    i += 1
print(maxi)
