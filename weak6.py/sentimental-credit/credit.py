# TODO
import sys

cont=0
def main():
    numero = input("Number: ")
    tarjeta(numero)

def tarjeta(num):
    if valid(num) == False:
        print("INVALID")
        sys.exit()
    start = int(num[0]) * 10 + int(num[1])
    if cont == 14 and (start == 34 or start == 37):
        print("AMEX")
    elif cont == 15 and start > 50 and start < 56:
        print("MASTERCARD")
    elif cont >= 12 and cont < 16 and num[0] == '4':
        print("VISA")
    else:
        print("INVALID")


def valid(num):
    sumx2 = 0
    global cont
    r = list(reversed(num))
    sum = int(r[0])
    for i in r[1:]:
        if cont % 2 == 0:
            if int(i) * 2 > 9:
                n = int(i) * 2 - 10
                sumx2 += n + 1
            else:
                sumx2 += int(i) * 2
        else:
            sum += int(i)
        cont += 1
    sumx2 += sum
    if sumx2 % 10 == 0:
        return True
    else:
        return False

main()