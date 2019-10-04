# determines if a number n can be written as the sum of fifth powers of its digits
def writable(n):
    mysum = 0
    for c in str(n):
        mysum += (int(c))**5
    return (n == mysum)

mysum = 0
for i in range(2, 1000000): # a good guess at an upper bound to the answers
    if (writable(i)):
        mysum += i

print(mysum)
