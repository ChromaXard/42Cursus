# Troisième Cercle - 42 Projects

Dans ce second cercle, les projets se concentrent sur des compétences de programmation avancées, notamment la gestion de processus, la synchronisation, et l'implémentation de fonctionnalités de shell. Ces projets visent à nous familiariser avec des concepts de bas niveau en programmation système et à renforcer notre compréhension des interactions utilisateur-machine.

### Liste de Projets

* [Minishell](#minishell)
* [Philosophers](#philosophers)

## Minishell

> Le projet **Minishell** a été réalisé en collaboration avec [Quentin Denizart](https://github.com/LaDeniseDe42).

Ce projet avancé du cursus nous a demandé de recréer plusieurs fonctionnalités clés d'un terminal. L'objectif était de simuler un shell minimaliste capable de traiter des commandes utilisateur, en gérant plusieurs aspects techniques essentiels, comme décrit ci-dessous :

- **Entrée utilisateur** : Gestion des commandes saisies par l'utilisateur.
- **Parsing** : Analyse et interprétation de caractères spéciaux ou de chaînes, en fonction des paramètres fournis.
- **Redirections** : Gestion des redirections de fichiers (entrée/sortie) dans la ligne de commande.
- **Pipes** : Envoi de la sortie d'une commande vers l'entrée d'une autre commande.
- **Builtins** : Reproduction de plusieurs commandes internes au shell (ci-dessous) :

    - **echo** : Affiche du texte avec un saut de ligne.
    - **cd** : Navigation dans les répertoires.
    - **pwd** : Affiche le répertoire courant.
    - **export** : Définit une variable d'environnement ou affiche les variables exportées.
    - **unset** : Supprime une variable exportée.
    - **env** : Affiche les variables exportées avec leurs valeurs.
    - **exit** : Ferme le shell.

### Détails techniques

> **Note :** Ce projet ne compile actuellement que sous macOS. Des ajustements sont nécessaires pour une compatibilité complète avec Linux.


## Philosophers

Le projet **Philosophers** explore les concepts de gestion des threads et de synchronisation. Il s'agit de simuler le problème classique des philosophes mangeurs, où plusieurs philosophes assis autour d'une table doivent tour à tour manger, penser, et dormir en partageant des ressources limitées (fourchettes). Ce projet introduit des notions de concurrence et de gestion de ressources dans un environnement multi-threadé.

### Détails techniques

#### Utilisation

1. **Téléchargement** : Récupérez le dossier `Philosophers` de ce répertoire.

2. **Compilation** : Dans le dossier `Philosophers`, compilez le programme avec la commande suivante :
    ```bash
    make
    ```
   Après compilation, un exécutable `philo` sera généré dans le dossier.

3. **Exécution** :
   - Lancez le programme en utilisant les arguments suivants :
      ```bash
      ./philo <nombre de philosophes> <temps avant de mourir> <temps pour manger> <temps pour dormir>
      ```
      *(les temps sont en ms)*

   **Exemple** : Pour lancer une simulation avec 5 philosophes, un délai de 200 ms avant la mort, 100 ms pour manger et 100 ms pour dormir, entrez :
   ```bash
   ./philo 5 200 100 100
   ```

## Auteurs

Créé par [Kastler Axel](https://github.com/ChromaXard)
