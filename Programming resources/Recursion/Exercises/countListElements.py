#Code about exercise 4.2 of Grokking Algorithms

def count(arr):
    if arr == []:
        return 0
    else:
        return 1 + count(arr[1:])
    
print(count([2, 5, 2, 9]))