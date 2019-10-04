SIZE = 20
LEN = 4

def printmatrix(matrix):
    for i in range(SIZE):
        for j in range(SIZE):
            print(str(matrix[i][j])+" ", end="")
        print("")
    print("")

def getinput(matrix):
    myfile = open("PE11.txt", "r")
    for j in range(SIZE):
        linearr = myfile.readline().strip().split(" ")
        for i in range(0, SIZE):
            matrix[j][i] = int(linearr[i])
    myfile.close()
    
def product(matrix, lenn, i0, j0, di, dj):
    s = 1
    num = 0
    while (num < lenn):
        newi = i0 + di * num
        newj = j0 + dj * num
        if (newi > 0 and newi < SIZE and newj > 0 and newj < SIZE):
            s *= matrix[i0 + di * num][j0 + dj * num]
        num += 1
    return s

maxim = 0
matrix = []
for i in range(SIZE):
    row = []
    for j in range(SIZE):
        row.append(0)
    matrix.append(row)

getinput(matrix)

for i in range(0, SIZE):
    for j in range(0, SIZE):
        for di in range(-1, 2):
            for dj  in range(-1, 2):
                if not (di == 0 and dj == 0):
                    maxim = max(maxim, product(matrix, LEN, i, j, di, dj))
print(maxim)


