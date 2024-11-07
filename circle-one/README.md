# Premier Cercle - 42 Projects

Bienvenue dans le premier projet du cursus de 42, Libft. Ce projet consiste à recréer une librairie standard en C, un excellent point de départ pour bien comprendre le langage et les bases de la programmation en C. Ce README vous guidera pour compiler, utiliser et comprendre le contenu de la libft.


### Liste de Projets :

* Libft

## Libft

Le projet Libft consiste à recoder une partie des fonctions standards de la bibliothèque C. Bien que cela semble simple, ce projet est exigeant pour des débutants en C et permet d'acquérir des bases solides pour la suite du cursus.

### Détails techniques

#### Utilisation

Pour utiliser cette librairie, suivez les étapes suivantes :

1. **Téléchargez le dossier** : Récupérez le dossier `libft` de ce répertoire.
2. **Compilation** : Allez dans le dossier `libft` et compilez la librairie avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un fichier `libft.a` sera créé dans le dossier.
3. **Ajoutez la bibliothèque à votre projet** :
   - Copiez les fichiers `libft.a` et `libft.h` dans le dossier de votre projet.
   - Incluez `libft.h` dans vos fichiers `.c` pour pouvoir utiliser les fonctions de la bibliothèque :
      ```c
      #include "./chemin-vers-le-fichier/libft.h"
      ```
      (Remplacez `"chemin-vers-le-fichier"` par le chemin vers `libft.h`)

4. **Compilation de votre programme avec libft** :
   - Utilisez la commande suivante pour compiler un fichier `exemple.c` avec `libft.a` :
      ```bash
      cc exemple.c -L./libft.a -o monExec
      ```

#### Liste de Fonctions

**Fonctions de conversion** :
- `ft_atoi`
- `ft_itoa`

**Fonctions de gestion mémoire** :
- `ft_bzero`
- `ft_calloc`
- `ft_memchr`
- `ft_memcmp`
- `ft_memcpy`
- `ft_memmove`
- `ft_memset`

**Fonctions de chaînes de caractères** :
- `ft_split`
- `ft_strchr`
- `ft_strdup`
- `ft_strjoin`
- `ft_strlen`
- `ft_strtrim`
- `ft_substr`

**Fonctions de manipulation de caractères** :
- `ft_isalnum`
- `ft_isalpha`
- `ft_isascii`
- `ft_isdigit`
- `ft_isprint`
- `ft_tolower`
- `ft_toupper`

**Fonctions de listes chaînées** :
- `ft_lstadd_back`
- `ft_lstadd_front`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstlast`
- `ft_lstmap`
- `ft_lstnew`
- `ft_lstsize`

**Fonctions de fichier** :
- `ft_putchar_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`
- `ft_putstr_fd`

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
