def regressive(i):
    print(i)
    if i <= 1: #base case
        return
    else: #recursive case
        regressive(i - 1)

regressive(10)