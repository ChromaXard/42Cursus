# Troisième Cercle - 42 Projects

Dans ce **Troisième Cercle** du cursus 42, les projets se concentrent sur la maîtrise des bases de la programmation et l'introduction à des concepts essentiels de gestion des ressources, de structuration de code, et de résolution algorithmique. Ces projets marquent une transition entre les exercices de base et les défis plus avancés en fournissant une compréhension solide des fondations de la programmation et en introduisant progressivement des notions de performance et de logique. 

### Liste de Projets

* [so_long](#so_long)
* [pipex](#pipex)
* [push_swap](#push_swap)

## so_long

**Cub3D** est un projet de type *raycasting*, inspiré du jeu **Wolfenstein 3D**. L'objectif principal est de créer un moteur 3D simplifié en partant de zéro, utilisant des techniques de projection géométrique. Le programme affiche des murs en 3D, une minimap, et permet à l'utilisateur de naviguer dans cet environnement à l'aide de contrôles en temps réel.

Ce projet nous a permis de découvrir et mettre en œuvre plusieurs concepts essentiels, tels que :

- **Gestion des textures** : affichage de textures sur des parcelles de l'écran par rapport à une map donné
- **Contrôles utilisateur** : gestion des événements clavier pour déplacer l'utilisateur dans l'environnement donné.

### Détails techniques

> **Note :** Ce projet ne compile actuellement que sous macOS. Des ajustements sont nécessaires pour une compatibilité complète avec Linux.

## Pipex

Le projet **Pipex** consiste à recréer une chaîne de traitement de commandes en ligne, en utilisant des pipes (`|`), comme dans un shell Unix. Ce projet introduit les concepts de **gestion des processus**, **redirection des flux d’entrée et de sortie**, et **communication inter-processus** via des pipes. L'objectif principal est de développer une compréhension des mécanismes de bas niveau qui permettent de connecter plusieurs commandes et rediriger leurs résultats en toute transparence.

Ce projet permet de :

- Apprendre à **créer et gérer des processus "enfant"** pour exécuter des commandes de façon indépendante.
- Maîtriser les **redirections des entrées et sorties** en utilisant les descripteurs de fichiers pour transmettre les données entre les processus via des pipes.

### Détails Techniques

#### Utilisation

1. **Téléchargement** : Récupérez le dossier `pipex` de ce répertoire.

2. **Compilation** : Dans le dossier `pipex`, compilez le programme avec la commande :
    ```bash
    make
    ```
   Après compilation, un exécutable nommé `pipex` sera généré dans le dossier.

3. **Exécution** :
    - Lancez le programme avec les arguments suivants :
        ```bash
        ./pipex <fichier_entrée> <première_commande> <seconde_commande> <fichier_sortie>
        ```

    **Exemple d'utilisation** : 
    ```bash
    ./pipex entrée.txt "cat -e" "grep 'bonjour'" sortie.txt
    ```
    
    Cette commande est équivalente à l'exécution en ligne suivante :
    ```bash
    < entrée.txt cat -e | grep 'bonjour' > sortie.txt
    ```

    Dans cet exemple, le programme `pipex` :
    - Lit le contenu du fichier entrée.txt à l'aide de cat -e.
    - Envoie le résultat de cat -e directement à la commande grep 'bonjour' via un pipe.
    - Filtre les lignes contenant le mot "bonjour" et les redirige dans sortie.txt.

## Push_swap

Le projet **Push_swap** vise à développer un programme capable de trier une pile de nombres entiers en utilisant un nombre limité de mouvements et d'instructions, dans l’esprit des algorithmes de tri. Ce projet introduit les bases des **algorithmes de tri** ainsi que la **gestion de la complexité algorithmique** et nous pousse à concevoir une solution performante, en particulier sur des listes d’éléments de taille variable.

L’objectif est de trier une pile initiale, `stack A`, en une pile triée en ordre croissant avec un minimum de mouvements. Pour cela, nous disposons d’une seconde pile, `stack B`, ainsi que d'un ensemble limité d'instructions pour déplacer les éléments entre les deux piles.

Le projet Push_swap permet de développer des compétences dans les domaines suivants :

- **Compréhension et conception d'algorithmes de tri efficaces** : Choisir un algorithme de tri adapté pour une pile d’entiers avec un nombre minimum de mouvements, en prenant en compte la complexité algorithmique.
- **Optimisation des opérations** : Minimiser le nombre d'instructions nécessaires pour accomplir le tri, notamment pour de grandes piles.
- **Manipulation de structures de données** : Manipuler les piles et gérer les opérations de transfert et de rotation.

Pour accomplir le tri, un ensemble spécifique d’instructions est disponible :

- **sa** (swap A) : échange les deux premiers éléments au sommet de `stack A`.
- **sb** (swap B) : échange les deux premiers éléments au sommet de `stack B`.
- **ss** : effectue `sa` et `sb` simultanément.
- **pa** (push A) : prend le premier élément de `stack B` et le place au sommet de `stack A`.
- **pb** (push B) : prend le premier élément de `stack A` et le place au sommet de `stack B`.
- **ra** (rotate A) : décale tous les éléments de `stack A` d’une position vers le haut (le premier élément devient le dernier).
- **rb** (rotate B) : décale tous les éléments de `stack B` d’une position vers le haut.
- **rr** : effectue `ra` et `rb` simultanément.
- **rra** (reverse rotate A) : décale tous les éléments de `stack A` d’une position vers le bas (le dernier élément devient le premier).
- **rrb** (reverse rotate B) : décale tous les éléments de `stack B` d’une position vers le bas.
- **rrr** : effectue `rra` et `rrb` simultanément.

### Détails Techniques

### Utilisation

1. **Téléchargement** : Récupérez le dossier `push_swap` depuis le dépôt.

2. **Compilation** : Dans le dossier `push_swap`, compilez le programme avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un exécutable `push_swap` sera généré dans le dossier.

3. **Exécution** :
   - Exécutez le programme en fournissant une série de nombres non triés en argument, par exemple :
      ```bash
      ./push_swap 3 2 5 1 4
      ```
   Le programme affichera une série d’instructions pour trier les nombres donnés en utilisant les commandes listées précédemment.

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
