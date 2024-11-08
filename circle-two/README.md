# Second Cercle - 42 Projects

Nous voici au second cercle des projets, où la difficulté commence à s'intensifier avec des sujets plus techniques. Ce cercle introduit de nouveaux concepts et des pratiques avancées en programmation et en systèmes, que je décris ci-dessous.

### Liste de Projets :

* [get_next_line](#get_next-line)
* [ft_printf](#ft_printf)
* [Born2beroot](#born2beroot)

## get_next_line

Le projet **get_next_line** consiste à créer une fonction qui lit ligne par ligne depuis un fichier donné, en utilisant un descripteur de fichier (`fd`). Dans la partie bonus, la fonction doit gérer plusieurs descripteurs simultanément. C'est un projet fondamental pour maîtriser la gestion de la mémoire et l'utilisation des `fd` en C.

### Détails techniques

#### Utilisation

1. **Téléchargement** : Récupérez le dossier `get_next_line` de ce répertoire.
2. **Compilation** : Dans le dossier `get_next_line`, compilez la bibliothèque avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un fichier `gnl.a` sera créé dans le dossier.
3. **Ajout au projet** :
   - Copiez les fichiers `gnl.a` et `get_next_line_bonus.h` dans le dossier de votre projet.
   - Ajoutez l'inclusion `get_next_line_bonus.h` dans votre code source pour utiliser la fonction :
      ```c
      #include "./chemin-vers-le-fichier/get_next_line_bonus.h"
      ```
      *(Remplacez `"chemin-vers-le-fichier"` par le chemin vers `get_next_line_bonus.h`)*
4. **Compilation de votre programme avec get_next_line** :
   - Utilisez la commande suivante pour compiler un fichier `exemple.c` avec `gnl.a` :
      ```bash
      cc exemple.c ./gnl.a -o monExec
      ```

#### Liste des fonctions utilisables publiquement

- `get_next_line`  
   **Prototype** : `char *get_next_line(int fd);`


## ft_printf

Le projet **ft_printf** vise à reproduire une partie de la fonction `printf` de la bibliothèque standard C. À l’aide de la documentation de `printf`, nous devions implémenter la gestion des chaînes de caractères, des nombres entiers, et des formats hexadécimaux, tout en respectant le même formatage.

### Détails techniques

#### Utilisation

1. **Téléchargement** : Récupérez le dossier `ft_printf` de ce répertoire.
2. **Compilation** : Dans le dossier `ft_printf`, compilez la bibliothèque avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un fichier `ft_printf.a` sera créé dans le dossier.
3. **Ajout au projet** :
   - Copiez les fichiers `ft_printf.a` et `ft_printf.h` dans le dossier de votre projet.
   - Ajoutez l'inclusion `ft_printf.h` dans votre code source pour utiliser la fonction :
      ```c
      #include "./chemin-vers-le-fichier/ft_printf.h"
      ```
      *(Remplacez `"chemin-vers-le-fichier"` par le chemin vers `ft_printf.h`)*
4. **Compilation de votre programme avec ft_printf** :
   - Utilisez la commande suivante pour compiler un fichier `exemple.c` avec `ft_printf.a` :
      ```bash
      cc exemple.c ./ft_printf.a -o monExec
      ```

#### Liste des fonctions utilisables publiquement

- `ft_printf`  
   **Prototype** : `int ft_printf(const char *strbase, ...);`

## Born2beroot

**Born2beroot** est un projet de configuration système qui consiste à configurer une machine virtuelle sous Debian avec une interface en ligne de commande. L’objectif est d’apprendre les bases de l’administration système en créant un environnement sécurisé et fonctionnel.

### Détails du projet

1. **Configuration de la VM** : Installer et configurer une machine virtuelle sous Debian, avec une interface en ligne de commande uniquement. 
2. **Paramètres de sécurité** : Mettre en place un système de connexion SSH pour permettre l’accès distant, configurer un pare-feu (firewall) pour restreindre les connexions, et établir une politique de mot de passe stricte.
3. **Script de monitoring** : Écrire un script de surveillance permettant d’obtenir des métriques sur l’état de la machine à intervalles réguliers.
4. **Autres configurations** : D’autres paramètres spécifiques sont à appliquer pour s’assurer que la VM répond aux exigences du projet, notamment en matière de sécurité et de performance.

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
