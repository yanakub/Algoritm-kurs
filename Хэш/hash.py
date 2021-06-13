import string, random

def spisok():
  s = list(string.ascii_letters + string.digits)
  return random.sample(s, 10)


print("1)")

g = spisok()
print(g)

    
print("2)")

text = 'Задание номер 2 и это произвольный текст'.split()
keys = g

for i in zip(keys, text):
    print(i)
