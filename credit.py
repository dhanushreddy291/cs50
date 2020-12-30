# Gets the Card Number from the user.
cardnumber = input("Number : ")

# To find the length of the Card Number and the First Two Digits.
size = len(cardnumber)
hundredsplace = 10 * int(cardnumber[0]) + int(cardnumber[1])
sum = 0

# Finding the sum using Luhn's credit card algorithm validator
for i in range(size):
    if i%2 == 0:
        sum += int(cardnumber[size - i - 1])
    else:
        temp = 2 * int(cardnumber[size - i - 1])
        sum += int(temp/10) + int(temp%10)

if size == 13 or size == 15 or size == 16:

    if sum % 10 == 0:
        
        # Checks if Card is a valid American Express Card.
        if size == 15 and (hundredsplace == 34 or hundredsplace == 37):
            print("AMEX")
            exit(0)
        
        # Checks if  Card is a valid Mastercard.
        elif size == 16 and hundredsplace > 50 and hundredsplace < 56:
            print("MASTERCARD")
            exit(0)
        
        # Checks if  Card is a valid VISA Card.
        elif (size == 13 or size == 16) and hundredsplace / 10 == 4:
            print("VISA")
            exit(0)

# Prints Invalid if card doesnot satisfy any of the above Conditions.
print("INVALID")
exit(0)