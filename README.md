# My_first_Perceptron-
un modele de classification lineaire 
 :

---

# Perceptron pour la Porte Logique AND

Ce projet implémente un **perceptron simple en C** qui apprend à reproduire le comportement de la porte logique **AND**. Le programme initialise aléatoirement les poids et le biais, puis utilise une fonction d'activation (fonction seuil) et une boucle d'apprentissage pour ajuster les paramètres du modèle en fonction de l'erreur entre la sortie attendue et la sortie calculée.

---

## Fonctionnalités

- **Initialisation Aléatoire** : Les poids et le biais du perceptron sont initialisés aléatoirement.
- **Fonction d'Activation** : Application d'une fonction seuil pour déterminer la sortie (1 si la somme pondérée + biais est ≥ 0, sinon 0).
- **Apprentissage Supervisé** : Utilisation d'une boucle d'entraînement sur plusieurs itérations (epochs) pour ajuster les poids et le biais en fonction de l'erreur.
- **Affichage des Résultats** : À la fin de l'apprentissage, le programme affiche les sorties calculées pour chaque exemple d'entrée ainsi que les sorties attendues.

---

## Prérequis

- **Environnement de Développement C** : Un compilateur C (tel que GCC, Clang, etc.).
- **Système d'Exploitation** : Compatible avec Linux, Windows, macOS, etc.

---

## Compilation et Exécution

Pour compiler le programme, utilisez une commande similaire à celle-ci (exemple avec GCC) :

```bash
gcc -o perceptron perceptron.c
```

Puis, exécutez le programme :

```bash
./perceptron
```

> **Remarque** : Le programme utilise des données d'entraînement prédéfinies pour la porte AND. Vous pouvez modifier ces données directement dans le code si nécessaire.

---

## Structure du Code

- **`perceptron`** : La structure contient :
  - `poids[2]` : Tableau de deux poids pour les deux entrées.
  - `TauxDapprentissage` : Le taux d'apprentissage utilisé pour ajuster les poids.
  - `biais` : La valeur de décalage appliquée à la somme pondérée.

- **`perceptron_init`** : Initialise le perceptron en attribuant des valeurs aléatoires aux poids et au biais, et définit le taux d'apprentissage.

- **`fonction_d_activation`** : Calcule, pour chaque exemple, la somme pondérée (entrées × poids + biais) et applique la fonction seuil pour déterminer la sortie du perceptron.

- **`apprentissage`** : Compare la sortie calculée avec la sortie attendue pour chaque exemple et ajuste les poids et le biais en fonction de l'erreur.

- **Boucle d'Entraînement dans `main`** : Le programme effectue 100 itérations (epochs) d'apprentissage, recalculant les sorties et mettant à jour les paramètres à chaque epoch.

---

## Expérimentation

Vous pouvez :
- Modifier le nombre d'epochs dans la boucle d'entraînement pour observer l'évolution de l'apprentissage.
- Ajuster le taux d'apprentissage dans `perceptron_init` pour voir son impact sur la convergence.
- Tester d'autres portes logiques (par exemple, OR) en changeant les données d'entraînement et les sorties attendues.

---

## Auteur

*Joseph BAMENOU  
*Jhbmn440gmail.com

---

Ce fichier README fournit une description claire du projet, des instructions pour la compilation et l'exécution, ainsi qu'une vue d'ensemble de la structure et des fonctionnalités du code. N'hésitez pas à l'adapter en fonction de vos besoins spécifiques.
