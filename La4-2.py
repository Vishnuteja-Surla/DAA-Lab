n = int(input())
if n == 1:
    print('*')
    exit()
arr = []
d = dict()
for i in range(n):
    num = int(input())
    arr.append(num)
    try:
        d[num] += 1
    except KeyError:
        d[num] = 1

for i,j in d.items():
    if(j >= (n//2+1)):
        print(i)
        break;
else:
    print("*")