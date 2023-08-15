
text = input("Text: ")

L = 0
P = 1
O = 0
for c in text:
    if c.isalpha():
        L += 1
    elif c.isspace():
        P += 1
    elif c == '.' or c == '!' or c == '?':
        O += 1

print(f"letter:{L}")
print(f"words:{P}")
print(f"sentences:{O}")
prom_L = (L / P) * 100.00
prom_O = (O / P) * 100.00
index = round(0.0588 * prom_L - 0.296 * prom_O - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
