import sys


def main():

    while True:
        if len(sys.argv) == 2:
            with open(sys.argv[1]) as f:
                dictionary = f.readlines()
            dictionary = [x.strip() for x in dictionary]
            break
        else:
            print("Usage: python bleep.py dictionary")
            sys.exit(1)

    userText = input("What message would you like to censor? ")

    for word in userText.split():
        for bleep in dictionary:
            if (word.lower() == bleep):
                for c in word:
                    print("*", end="")
                print(" ", end="")
                break
        if (word != bleep and word != bleep.upper()):
            print(word, end=" ")
    print()


if __name__ == "__main__":
    main()
