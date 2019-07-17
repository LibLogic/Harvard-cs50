while True:
    myInput = input("Change Owed: ")
    try:
        if "." in myInput:
            myInput = float(myInput)
            if myInput > 0:
                break
        myInput = int(myInput)
        if myInput > 0:
            break
    except:
        continue
cents = int(myInput * 100)


def getChange(cents):
    coinCount = 0
    while cents > 0:
        if cents >= 25:
            coinCount = coinCount + 1
            cents = cents - 25
        elif cents >= 10:
            coinCount = coinCount + 1
            cents = cents - 10
        elif cents >= 5:
            coinCount = coinCount + 1
            cents = cents - 5
        elif cents >= 1:
            coinCount = coinCount + 1
            cents = cents - 1
    return coinCount


coinCount = getChange(cents)
print(coinCount)