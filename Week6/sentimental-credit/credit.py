# TODO
from cs50 import get_string
from sys import exit

cardnumber = get_string("Number: ")
cardlength = len(cardnumber)

if cardlength != 13 and cardlength != 15 and cardlength != 16:
    print("INVALID")
    exit()

sum1, sum2 = 0, 0
x = cardnumber
y = cardlength

if y % 2 == 0:
    for i in range(y):
        num = int(x[i])
        if i % 2 == 0:
            multiple = num * 2
            if multiple >= 10:
                sum1 += multiple // 10
                sum1 += multiple % 10
            else:
                sum1 += multiple
        else:
            sum2 += num
else:
    for i in range(y):
        num = int(x[i])
        if i % 2 != 0:
            multiple = num * 2
            if multiple >= 10:
                sum1 += multiple // 10
                sum1 += multiple % 10
            else:
                sum1 += multiple
        else:
            sum2 += num

checksum = (sum1 + sum2) % 10

if checksum == 0:
    first = int(cardnumber[0])
    second = int(cardnumber[1])
    if first == 3 and (second == 4 or second == 7):
        print("AMEX")
    elif first == 4:
        print("VISA")
    elif first == 5 and second > 0 and second < 6:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")