import random

# Générer une liste de nombres de 0 à 100
nombres = list(range(101))

# Mélanger aléatoirement la liste
random.shuffle(nombres)

# Extraire les nombres un par un de la liste mélangée
for nombre in nombres:
    print(nombre, end=' ')