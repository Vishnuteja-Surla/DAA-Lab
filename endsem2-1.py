def matrixchain(order):
    n = len(order)
    scalar_mul = [[0 for x in range(n)] for x in range(n)]
    
    for L in range(1,n-1):
        for i in range(1,n-L):
            j = i+L

            for k in range(i,j):

                val = scalar_mul[i][k] + scalar_mul[k+1][j] + order[i-1]*order[k]*order[j]

                if k == i:
                    scalar_mul[i][j] = val

                if val < scalar_mul[i][j]:
                    scalar_mul[i][j] = val
    
    print("Number of Minimum Scalar Multiples is ",scalar_mul[1][n-1])


if __name__=="__main__":
    order = []
    n = int(input("Enter the number of matrices to be multiplied : "))
    for i in range(n):
        m = int(input(f"Enter the number of rows of matrix-{i+1} : "))
        n = int(input(f"Enter the number of columns of matrix-{i+1} : "))
        if i>0 and m != order[i]:
            print("<-- INVALID MATRIX -->")
            break
        if i == 0:
            order.append(m)
            order.append(n)
        else:
            order.append(n)
    print("Order List : ",order)
    matrixchain(order)