# 2, 3, 5, 7, 11, 13, 17, 19
# Need to be div by all primes under 20
# Need to be div by prod of all primes under 20

def checksol (n):
    for i in range(1, 21):
        if (n % i != 0):
            return False
    return True

p = 2*3*5*7*11*13*17*19
i = 0
while (True):
    i += p
    if (checksol(i)):
        print(i)
        break
