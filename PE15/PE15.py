# A simple combinatorics problem.
# Basically equivalent to number of ways you can arrange 20 R's and 20 D's.
# Which is then equivalent to the number of ways you can select 10 positions out of 20 to put the R's.
# Which is ncr(20, 10).

def factorial(n):
    prod = 1
    for i in range(1, n+1):
        prod *= i
    return prod

def ncr(n, r):
    return factorial(n)//(factorial(r) * factorial(n-r))

size = 20
print(ncr(size*2,size))
