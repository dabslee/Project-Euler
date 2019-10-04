import math

fracs_n = []
fracs_d = []

#(ab)/(cd)
for a in range(1, 10):
    for b in range(0, 10):
        for c in range(1, 10):
            for d in range(0, 10):
                if (10*a+b > 10*c+d or 10*a+b == 10*c+d):
                    continue
                if (b == 0 and d == 0):
                    continue
                if (math.gcd(10*a+b, 10*c+d) == 1):
                    continue
                if (a == c):
                    if (d == 0 or b/d != (10*a+b)/(10*c+d)):
                        continue
                elif (a == d):
                    if (b/c != (10*a+b)/(10*c+d)):
                        continue
                elif (b == c):
                    if (d == 0 or a/d != (10*a+b)/(10*c+d)):
                        continue
                elif (b == d):
                    if (a/c != (10*a+b)/(10*c+d)):
                        continue
                else:
                    continue
                fracs_n.append(10*a+b)
                fracs_d.append(10*c+d)

numer = 1
for n in fracs_n:
    numer *= n
denom = 1
for d in fracs_d:
    denom *= d

print(denom//math.gcd(numer, denom))
