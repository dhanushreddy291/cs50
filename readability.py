from cs50 import get_string

# Gets text Input.
text = get_string("Text : ")

lettercount = 0
wordcount = 1
sentencescount = 0
index = 0

# A For Loop for counting the number of letters, words and sentences.
for ch in text:
    
    #The isalpha() method returns True if character is an alphabet
    if ch.isalpha() == 1:
        lettercount += 1
    elif ch == " ":
        wordcount += 1
    elif ch == "." or ch == "?" or ch == "!":
        sentencescount += 1

# Calculation of Index using Coleman-Liau Formula
index = round(5.88 * (lettercount / (wordcount * 1.00)) - 29.6 * (sentencescount / (wordcount * 1.00)) - 15.8)

# Prints the Grade Level of given text.
if index < 1:
    print("Before Grade 1")
    exit(0)
elif index >= 16:
    print("Grade 16+")
    exit(0)

print("Grade " + str(index))
exit(0)