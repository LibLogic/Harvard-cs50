import sys

while True:
    if len(sys.argv) == 2:
        key = int(sys.argv[1])
        break
    else:
        print("Usage: python3 ./caesar key")
        sys.exit(1)

while True:
    pt = input("plaintext: ")
    break
print("ciphertext: ", end="")
for char in pt:
    if char.isalpha():
        if char.isupper():
            asc = ord(char)
            asc = asc - ord('A')
            asc = (asc + key) % 26
            asc = asc + ord('A')
            print(chr(asc), end="")
        elif char.islower():
                asc = ord(char)
                asc = asc - ord('a')
                asc = (asc + key) % 26
                asc = asc + ord('a')
                print(chr(asc), end="")
    else:
        print(char, end="")
print()

