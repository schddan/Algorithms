def quicksort(arr):
    if len(arr) < 2:
        return arr
    else:
        pivot = arr[0]
        smaller = [i for i in arr[1:] if i <= pivot] # Creates subarray of elements smaller than pivot
        bigger = [i for i in arr[1:] if i > pivot] # Creates subarray of elements bigger than pivot
        return quicksort(smaller) + [pivot] + quicksort(bigger)
    
print(quicksort([2, 9, 1, 10, 15, 13, 17]))