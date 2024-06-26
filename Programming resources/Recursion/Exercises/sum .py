#Code about exercise 4.1 of Grokking Algorithms

#def sum(arr):
#    first = arr[0]
#    if len(arr) == 1:
#        return arr[0]
#    else:
#        del(arr[0])
#        return first + sum(arr)
    
def sum(arr):
    if arr == []:
        return 0
    else:
        return arr[0] + sum(arr[1:])
    
print(sum([2, 1, 5, 10]))