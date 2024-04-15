import random

nombres = list(range(100))

# Mélanger aléatoirement la liste
random.shuffle(nombres)

# Extraire les nombres un par un de la liste mélangée
for nombre in nombres:
    print(nombre, end=' ')