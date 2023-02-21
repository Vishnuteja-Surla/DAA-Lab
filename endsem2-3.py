def knapsack_0_1(n,W,weights,profits):
    max_profit = [[0 for x in range(W+1)] for x in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,W+1):
            if weights[i] <= j:
                max_profit[i][j] = max(profits[i] + max_profit[i-1][j-weights[i]] , max_profit[i-1][j])
            else:
                max_profit[i][j] = max_profit[i-1][j]
    print(f"Max Profit : {max_profit[n][W]}")

if __name__=="__main__":
    W = int(input("Enter the weight limit of the knapsack : "))
    weights = [0]
    profits = [0]
    n = int(input("Enter the total number of objects we have : "))
    for i in range(n):
        w = int(input(f"Enter the weight of object-{i+1} : "))
        p = int(input(f"Enter the profit of object-{i+1} : "))
        weights.append(w)
        profits.append(p)
    knapsack_0_1(n,W,weights,profits)