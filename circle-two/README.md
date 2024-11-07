# Second Cercle - 42 Projects

Nous sommes rendu au second cercles des projets desormais, le top depart est lance, la difficulte commence a augmenter avec les differents projets, plus consequants, qui vont etre detailles ci dessous !

### Liste de Projets :

* [get_next_line](#get_next_line)
* [ft_printf](#ft_printf)
* [Born2beroot](#born2beroot)

## get_next_line

Dans ce projet nous devions creer une fonction appelle get_next_line, oui, comme le nom du projet. Cette derniere avait pour objectif, dans la partie obligatoire d'etre en capacite de lire un fichier depuis ce que l'on appelle un "fd" (file descriptor). Un file descriptor (descripteur de fichier), nous permet d'effectuer des actions (lire ou ecrire) sur le fichier pointe grace a lui. Dans la partie considere comme "bonus", le principe etait le meme mais avec la possibilite d'utiliser differents fd a la chaine avec la fonction.

### Détails techniques

#### Utilisation

1. **Téléchargez le dossier** : Récupérez le dossier `get_next_line` de ce répertoire.
2. **Compilation** : Allez dans le dossier `get_next_line` et compilez la librairie avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un fichier `gnl.a` sera créé dans le dossier.
3. **Ajoutez la bibliothèque à votre projet** :
   - Copiez les fichiers `gnl.a` et `get_next_line_bonus.h` dans le dossier de votre projet.
   - Incluez `get_next_line_bonus.h` dans vos fichiers `.c` pour pouvoir utiliser la fonction dans votre projet :
      ```c
      #include "./chemin-vers-le-fichier/get_next_line_bonus.h"
      ```
      (Remplacez `"chemin-vers-le-fichier"` par le chemin vers `get_next_line_bonus.h`)

4. **Compilation de votre programme avec get_next_line** :
   - Utilisez la commande suivante pour compiler un fichier `exemple.c` avec `gnl.a` :
      ```bash
      cc exemple.c ./gnl.a -o monExec
      ```

#### Liste de fonctions utilisable publiquement

get_next_line (prototype : char *get_next_line(int fd))

## ft_printf

Description a venir

### Détails techniques

#### Utilisation

aide d'utilisation a venir

#### Liste de fonctions utilisable publiquement

liste de fonction a venir

## Born2beroot

Description a venir

### Détails techniques

#### Utilisation

aide d'utilisation a venir

#### Liste de fonctions utilisable publiquement

liste de fonction a venir

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
