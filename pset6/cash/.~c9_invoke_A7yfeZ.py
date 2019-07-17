while True:
  myInput = input("Change owed: ")
  myInput = float(myInput)
  if myInput > 0:
    break
cents = int(myInput * 100)

coinCount = getChange(cents)

def getChange(cents):
  coinCount = 0
  while cents > 0:
    if cents >= 25:
      coinCount = coim
      
  