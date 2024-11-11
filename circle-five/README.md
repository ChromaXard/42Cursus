# Cinquième Cercle - 42 Projects

Dans ce **Cinquième Cercle**, les projets se concentrent sur des compétences de programmation avancées, telles que la gestion des processus, la synchronisation, et l'implémentation de fonctionnalités de shell. Ces projets visent à nous familiariser avec des concepts bas niveau en programmation système, tout en renforçant notre compréhension des interactions utilisateur-machine.

### Liste de Projets

* [cub3d](#cub3d)
* [NetPractice](#netpractice)
* [CPP Modules 00-04](#cpp-modules)

## Cub3D

> Le projet **cub3d** a été réalisé à deux reprises durant mon cursus. La version présentée ici est la seconde.
>
> La première version a été réalisée en collaboration avec [Quentin Denizart](https://github.com/LaDeniseDe42).
>
> La seconde version, qui suit, a été réalisée avec [Alexandre Herrmann](https://github.com/alexandre6795).

**Cub3D** est un projet de type *raycasting*, inspiré du jeu **Wolfenstein 3D**. L'objectif principal est de créer un moteur 3D simplifié en partant de zéro, utilisant des techniques de projection géométrique. Le programme affiche des murs en 3D, une minimap, et permet à l'utilisateur de naviguer dans cet environnement à l'aide de contrôles en temps réel.

Ce projet nous a permis de découvrir et mettre en œuvre plusieurs concepts essentiels, tels que :

- **Raycasting** : calcul de la distance entre la caméra et les objets pour simuler l'effet de la 3D.
- **Gestion des textures** : affichage de textures sur les murs.
- **Contrôles utilisateur** : gestion des événements clavier pour déplacer et orienter la caméra dans l'environnement.
- **Minimap** : représentation de la carte en vue du dessus pour faciliter la navigation.

### Détails techniques

#### Utilisation

> **Note :**
> 
> Ce projet nécessite quelques dépendances supplémentaires. Installez-les en utilisant la commande suivante :
```
sudo apt update
sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```

> **Utilisateur WSL :**
>
> Si vous utilisez WSL sous Windows, suivez ce tutoriel [ici](https://github.com/codam-coding-college/MLX42?tab=readme-ov-file#for-windows-with-windows-subsystem-for-linux-2-wsl2) jusqu'à l'étape 4 pour que la librairie soit fonctionnelle sous Windows.

1. **Téléchargement** : Récupérez le dossier `cub3d` de ce dépôt.

2. **Compilation** : Dans le dossier `cub3d`, compilez le projet avec la commande suivante :
    make
   Un exécutable `cub3D` sera généré une fois la compilation terminée.

3. **Exécution** :
   - Lancez le programme avec une carte spécifique :
      ```
      ./cub3D <nom_de_la_carte.cub>
      ```
      Le fichier `.cub` est un fichier de configuration définissant les murs, textures, et la position de la caméra dans l'environnement. Vous trouverez des exemples de cartes dans le dossier `maps`.

4. **Commandes du jeu** :
   - Utilisez les touches `WASD` pour vous déplacer et les flèches directionneles droite et gauche pour déplacer la caméra.
   - Appuyez sur `Echap` pour quitter.
   - Mouvements bonus :
      - mouvement de la caméra avec la souris (désactivable avec la touche 'm' de votre clavier). (fonctionalité non stable avec WSL)
      - l'ouverture et la fermeture de portes avec la touche e de votre clavier

## NetPractice

Le projet **NetPractice** a pour objectif d’enseigner les bases des réseaux informatiques. Il consiste à configurer des réseaux via l’attribution d’adresses IP, la gestion des sous-réseaux et des routes. Vous devrez corriger des erreurs dans les configurations pour permettre une bonne communication entre les différents appareils du réseau.

## CPP Modules

Les **CPP Modules** sont une série de projets qui introduisent progressivement les concepts fondamentaux de la programmation orientée objet (OOP) en C++, du module 00 au module 04. Chaque module se concentre sur des fonctionnalités spécifiques du C++, allant de la syntaxe de base jusqu’aux notions plus avancées comme l’héritage et le polymorphisme.

Les modules suivants sont abordés :

### Module 00
- **Syntaxe de base et principes fondamentaux de C++** : Introduction aux types de données, aux fonctions, aux classes et aux objets, ainsi qu’à la gestion de la mémoire avec `new` et `delete`.
- **Gestion de la mémoire** : Compréhension des pointeurs et de la gestion de la mémoire manuelle.

### Module 01
- **Gestion dynamique de la mémoire** : Approfondissement de la gestion dynamique avec les constructeurs et destructeurs.
- **Constructeurs et destructeurs** : Comment utiliser et implémenter les constructeurs et destructeurs pour une gestion appropriée des ressources.

### Module 02
- **Surcharge des opérateurs** : Introduction à la surcharge d'opérateurs pour rendre les classes plus manipulables et flexibles.
- **Encapsulation et accès aux données** : Mise en pratique des getters et setters pour protéger les données membres.

### Module 03
- **Héritage** : Concepts d'héritage pour réduire la duplication du code et créer des hiérarchies de classes.
- **Polymorphisme** : Utilisation des fonctions virtuelles pour permettre le polymorphisme et la personnalisation du comportement des classes.

### Module 04
- **Classes abstraites et interfaces** : Mise en place de classes abstraites et d’interfaces pour une conception flexible et évolutive.
- **Polymorphisme avancé** : Exploration du polymorphisme avancé avec les fonctions virtuelles pures.

Ces modules sont conçus pour fournir une solide base théorique et pratique en C++, tout en renforçant les bonnes pratiques de conception orientée objet.

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
