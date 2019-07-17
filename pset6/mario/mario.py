while True:
    n = input("Height: ")
    if n.isdigit():
        n = int(n)
        l = n
        if n >= 1 and n <= 8:
            break
while n > 0:
    for j in range(1, n + 1):
        if j < n:
            print(" ", end="")
        else:
            k = l - j
            while k >= 0:
                print("#", end="")
                k = k - 1
        j = j - 1
    print()
    n = n - 1

