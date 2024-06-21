def findCity(total):
    if total == 1:
        return 1
    else:
        return total * findCity(total - 1)

print(findCity(6))

# Every time the number is increased, the necessary quantity of operations increases a lot 
# The Big O here is O(n!)