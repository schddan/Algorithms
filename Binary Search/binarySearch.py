def binarySearch(list, item):
    low = 0
    high = len(list) - 1
    steps = 0
    while low <= high:
        steps += 1
        middle = (low + high) // 2
        guess = list[middle]
        if guess == item:
            print(f"Steps: {steps}")
            return middle
        if guess > item:
            high = middle - 1
        else:
            low = middle + 1
    print(f"Steps: {steps}")
    return None

list1 = [1, 3, 5, 7, 9]

print(binarySearch(list1, 9))