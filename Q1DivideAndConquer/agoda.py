import copy
x= [int(e) for e in input().split()]
y=copy.deepcopy(x)
y.sort()
m = {}
count = 1
ans = []
for i in y:
    if i in m:
        continue
    else :
        m[i] = count
        count+=1
for i in x:
    ans.append(str(m[i]))
print(" ".join(ans))