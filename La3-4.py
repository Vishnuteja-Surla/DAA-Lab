A=int(input())
arr=[]
for i in range(A):
    val=int(input())
    if i==0:
        arr.append(val)
    else:
        if val<arr[0]:
            arr.insert(0,val)
        elif val>arr[-1]:
            arr.append(val)
        else:
            arr.insert(1,val)
print(arr[0])
print(arr[-1])