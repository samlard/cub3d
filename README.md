# cub3D — 42

Projet de l’école 42 : réaliser un moteur 3D en vue à la première personne avec **raycasting** et **MiniLibX**, inspiré de Wolfenstein 3D.

## Objectif

Afficher un labyrinthe 2D sous forme de rendu 3D temps réel, avec :
- textures de murs différentes selon l’orientation (**N/S/E/W**),
- couleur de sol et de plafond,
- déplacements et rotation du joueur.

## Compilation

```bash
make
```

Règles Makefile disponibles :
- `all`
- `clean`
- `fclean`
- `re`

> Prérequis Linux : dépendances X11 (ex. `X11/X.h`) nécessaires à MiniLibX.

## Exécution

```bash
./cub3D <map.cub>
```

Exemple :
```bash
./cub3D map/map_valid.cub
```

## Contrôles

- `W` : avancer
- `S` : reculer
- `A` : déplacement gauche (strafe)
- `D` : déplacement droite (strafe)
- `←` / `→` : rotation caméra
- `ESC` : quitter proprement
- Clic sur la croix de la fenêtre : quitter proprement

## Format de fichier `.cub`

Le programme prend en argument un fichier scène `.cub` contenant :

### 1) Les textures de murs
- `NO ./path_to_north_texture.xpm`
- `SO ./path_to_south_texture.xpm`
- `WE ./path_to_west_texture.xpm`
- `EA ./path_to_east_texture.xpm`

### 2) Les couleurs
- `F R,G,B` (sol)
- `C R,G,B` (plafond)

Chaque composante RGB doit être dans l’intervalle `[0,255]`.

### 3) La carte (en dernier dans le fichier)

Caractères autorisés :
- `1` : mur
- `0` : espace vide
- `N`, `S`, `E`, `W` : position/orientation initiale du joueur
- espaces : autorisés dans la map (à gérer au parsing)

Contraintes :
- la map doit être **fermée** (entourée de murs),
- la map est la **dernière section** du fichier,
- les éléments (textures/couleurs) peuvent être dans n’importe quel ordre,
- lignes vides autorisées entre éléments (hors map).

## Gestion d’erreurs

En cas de configuration invalide (`.cub` incorrect, texture manquante, map ouverte, couleur invalide, etc.), le programme doit quitter proprement avec :

```text
Error
<message explicite>
```

## Fonctions autorisées (sujet)

- `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`
- Fonctions de la librairie math (`-lm`)
- Fonctions de la MiniLibX
- `libft` autorisée