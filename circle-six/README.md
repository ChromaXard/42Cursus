# Sixième Cercle - 42 Projects

Le sixième cercle de l'école 42 représente une étape avancée dans le cursus, où les étudiants consolident leurs compétences en programmation système, en réseaux, en conteneurisation, et en C++. Ce cercle met l'accent sur des projets qui requièrent une compréhension approfondie des technologies réseaux, des concepts avancés de la programmation orientée objet, ainsi que de la gestion et l’orchestration de services conteneurisés.

### Liste des projets

* [ft_irc](#ft_irc)
* [Inception](#inception)
* [CPP Modules 05-09](#cpp-modules)

## ft_irc

> Le projet **ft_irc** a été réalisé en collaboration avec deux personnes : [Quentin Denizart](https://github.com/LaDeniseDe42) et [Alexandre Herrmann](https://github.com/alexandre6795).

### Détails techniques

#### Installation

1. **Téléchargement** : Récupérez le dossier `ft_irc` sur votre machine locale.

2. **Compilation** : Dans le dossier du projet, compilez avec la commande suivante :
    ```bash
    make
    ```
    Un exécutable `ircserv` sera généré après compilation.

3. **Exécution** :
    - Lancez le serveur IRC avec un port et un mot de passe :
        ```bash
        ./ircserv <port> <mot de passe>
        ```

4. **Connexion au serveur** :
    - Utilisez un client IRC pour vous connecter :
    ```bash
    irssi
    /connect <ip_du_serveur> <port_du_serveur> <mot_de_passe_du_serveur>
    ```

> Une documentation plus détaillée pour l'utilsation du client est disponible sur [le GitHub de Quentin](https://github.com/LaDeniseDe42/FT_IRC).

## Inception

**Inception** est un projet Docker où vous construisez une architecture multi-conteneurs. L'objectif est de configurer une infrastructure composée de plusieurs services isolés, comme un serveur web, une base de données, etc., et de les interconnecter à l'aide de Docker Compose.

### Détails techniques

> **Note** : Ce projet nécessite encore quelques ajustements pour être pleinement fonctionnel sur n'importe quel machine.

## CPP Modules

Les **CPP Modules** couvrent des concepts avancés en C++, du module 05 au module 09. Voici une brève description de chaque module :

### Module 05

Ce module est une introduction à la gestion des **exceptions** en C++, pour apprendre à gérer les erreurs de manière plus robuste et élégante.

### Module 06

Apprenez à utiliser les **casts** en C++ : dynamique (`dynamic_cast`), statique (`static_cast`), et les autres types de conversions.

### Module 07

Approfondissez vos connaissances sur les **templates génériques** et comment les utiliser pour rendre votre code plus flexible et réutilisable.

### Module 08

Manipulation des **conteneurs standards (STL)** : `vector`, `map`, `list`, etc., et gestion de données dans des structures optimisées.

### Module 09

Introduction à la **programmation fonctionnelle** en C++, avec des algorithmes et l'utilisation des fonctions dans la STL.

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
