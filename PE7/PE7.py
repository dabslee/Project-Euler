def isprime(n):
    if (n < 2):
        return False
    for i in range(2, int(n**0.5+1)):
        if (n % i == 0):
            return False
    return True

count = 0
i = 1
while (count < 10001):
    i += 1
    if (isprime(i)):
        count += 1
print (i)
