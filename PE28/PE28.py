#1, 9, 25, 49 ... 1001^2
#sqs
#+8, +16, +24

#1, 3, 13, 31
#+2, +10, +18

#1, 5, 17, 37
#+4, +12, +20

#1, 7, 21, 43
#+6, +14, +22


mysum = 0

# up right diagonal
addend = 1
delta = 8
while (addend <= 1001**2):
    mysum += addend
    addend += delta
    delta += 8

# down right diagonal
addend = 1
delta = 2
while (addend <= 1001**2):
    mysum += addend
    addend += delta
    delta += 8

# down left diagonal
addend = 1
delta = 4
while (addend <= 1001**2):
    mysum += addend
    addend += delta
    delta += 8

# up left diagonal
addend = 1
delta = 6
while (addend <= 1001**2):
    mysum += addend
    addend += delta
    delta += 8

mysum -= 3

print(mysum)
