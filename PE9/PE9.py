import sys

for a in range(1, 1000):
    for b in range(1, a+1):
        csq = a*a + b*b
        if (csq**0.5==int(csq**0.5) and a+b+csq**0.5==1000):
            print(int(a*b*csq**0.5))
            sys.exit()
