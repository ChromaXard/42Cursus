# Quatrième Cercle - 42 Projects

Dans ce quatrième cercle, les projets se concentrent sur des compétences de programmation avancées, notamment la gestion de processus, la synchronisation, et l'implémentation de fonctionnalités de shell. Ces projets visent à nous familiariser avec des concepts de bas niveau en programmation système et à renforcer notre compréhension des interactions utilisateur-machine.

### Liste de Projets

* [cub3d](#cub3d)
* [NetPractice](#netpractice)
* [CPP Modules](#cpp-modules)

## Cub3D

> Le projet **cub3d** a été réalisé deux fois au cours de mon cursus. La version présentée ici est la seconde.
>
> La première version a été réalisée en collaboration avec [Quentin Denizart](https://github.com/LaDeniseDe42).
>
> La seconde version, présentée ici, a été faite en partenariat avec [Alexandre Herrmann](https://github.com/alexandre6795).

**Cub3D** est un projet de type "raycasting", inspiré du jeu **Wolfenstein 3D**. Le but est de créer une première expérience de moteur 3D à partir de zéro, permettant de représenter un environnement tridimensionnel simplifié en utilisant des techniques de projection et de calculs géométriques. L'application affiche des murs, une minimap, et permet à l'utilisateur de naviguer dans cet environnement avec des contrôles en temps réel.

Ce projet nous a permis de nous familiariser avec plusieurs concepts essentiels, tels que :

- **Raycasting** : technique permettant de calculer la distance entre la position de la caméra et les objets à l’écran, simulant ainsi un effet de 3D.
- **Gestion des textures** : affichage de textures sur les murs et gestion de l’éclairage.
- **Contrôles utilisateur** : gestion des événements de clavier pour permettre au joueur de se déplacer et de tourner dans l’environnement.
- **Minimap** : représentation de la carte en vue de dessus pour faciliter la navigation.
  
### Détails techniques

#### Utilisation

Pour exécuter le projet, suivez les étapes ci-dessous :

1. **Téléchargement** : Récupérez le dossier `cub3d` de ce dépôt.

2. **Compilation** : Rendez-vous dans le dossier `cub3d` et compilez le projet en utilisant la commande :
    ```bash
    make
    ```
   Une fois la compilation terminée, un exécutable `cub3D` sera créé dans le dossier.

3. **Lancer le programme** :
   - Utilisez la commande suivante pour exécuter le projet avec une carte spécifique :
      ```bash
      ./cub3D <nom_de_la_carte.cub>
      ```
      Le fichier `.cub` est un fichier de configuration décrivant les murs, textures, et la position de départ de la caméra dans l’environnement, vous avez des exemples de maps dans le dossier `maps`.

4. **Commandes du jeu** :
   - Utilisez les touches directionnelles ou `WASD` pour vous déplacer.
   - `Echap` pour quitter le programme.

#### Exemple de lancement

Un exemple de lancement avec un fichier de carte nommé `map.cub` serait :

```bash
./cub3D map.cub
```