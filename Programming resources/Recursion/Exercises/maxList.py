#Code about exercise 4.3 of Grokking Algorithms

def maxList(arr):
    if len(arr) == 2: # If there are only two elements - base case
        return arr[0] if arr[0] > arr[1] else arr[1] # Compares the wo remaining elements of the array
    sub_max = maxList(arr[1:]) # Calls the function again with a smaller array
    return arr[0] if arr[0] > sub_max else sub_max

print(maxList([1, 10, 7, 2]))

# maxList([1, 10, 7, 3]) becomes
# maxList([10, 7, 3]) becomes
# maxList([7, 3]) returns 7 to sub_max
# maxList([10, 7, 3]) returns 10 to sub_max because arr[0] > previous sub_max
# maxList([1, 10, 7, 3]) returns 10 because previous sub_max > arr[0]


