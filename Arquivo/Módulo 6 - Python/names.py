import sys

numbers = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ronald"]

if "Ron" in numbers: # busca linear com nomes
    print("Found")
    sys.exit(0)
else:
    print("Not found")
    sys.exit(1)
