def minimum(array):
    if len(array) > 0:
        min = array[0]
        for i in range(len(array)):
            if array[i] < min:
                min = array[i]
        return min
    else:
        return 0

def coinchange(den,x):
    num_coins = [-1 for i in range(x)]
    
    for i in den:
        if i <= x:
            num_coins[i-1] = 1

    print(num_coins)
    
    for i in range(x):
        min_array = []
        for j in den:
            if i-j+1 > 0:
                min_array.append(num_coins[i-j])
            if i-j+1==0:
                min_array.append(0)
        val = minimum(min_array)
        num_coins[i] = val + 1
    
    print(num_coins[x-1])

    print(num_coins)

if __name__=="__main__":
    denominations = []
    n = int(input("Enter the number of different denominations you would like change in ? : "))
    for i in range(n):
        x = int(input(f"Enter denaomination-{i+1} : "))
        denominations.append(x)
    denominations.sort()
    x = int(input("Enter the number for which you want the change : "))
    coinchange(denominations,x)