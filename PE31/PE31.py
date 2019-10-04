poss = [1, 2, 5, 10, 20, 50, 100, 200]
dynamic = []
for i in range(201):
    dynamic.append(0)
dynamic[0] = 1;

for i in range(len(poss)):
    for j in range(poss[i], 200+1):
        dynamic[j] += dynamic[j - poss[i]]

print (dynamic[200])
