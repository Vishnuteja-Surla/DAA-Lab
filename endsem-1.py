# Merge Sort
def mergeSort(array):
    if len(array) > 1:
        r = len(array)//2
        arr1 = array[:r]
        arr2 = array[r:]
        
        mergeSort(arr1)
        mergeSort(arr2)

        i = j = k = 0

        while i < len(arr1) and j < len(arr2):
            if arr1[i] < arr2[j]:
                array[k] = arr1[i]
                i += 1
            else:
                array[k] = arr2[j]
                j += 1
            k += 1
        
        while i < len(arr1):
            array[k] = arr1[i]
            i += 1
            k += 1

        while j < len(arr2):
            array[k] = arr2[j]
            j += 1
            k += 1

# Main Function
if __name__ == "__main__":
    array = []
    n = int(input("Enter the number of numbers in the array : "))
    for i in range(n):
        num = int(input(f"Enter the number-{i+1} of the array : "))
        array.append(num)
    print(f'Your Array : {array}')
    mergeSort(array)
    print(f'Sorted Array : {array}')