from cs50 import get_int

#Loop doesnot exit until the user inputs a number between 1 to 8 inclusive
while True:
    height = get_int("Height : ")
    if 0 < height < 9:
        break

# A loop to print require Pyramid
for i in range(height):
    
    # Prints white spaces
    for j in range(height - i - 1):
        print(" ", end="")
    
    # Prints '#'
    for k in range(i + 1):
        print("#", end="")
    print()    