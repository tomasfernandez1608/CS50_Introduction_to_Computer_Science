# TODO

def get_height():
    while True:
        n = input("Height: ")
        if n > '0' and n < '9':
            return int(n)


Height = get_height()

for i in range(Height):
    j = Height - 1
    cont = 0
    while j >= 0:
        if j > i:
            print(" ", end="")
        else:
            print("#", end="")
            cont += 1
        j -= 1
    print(" ", "#" * cont)
    
