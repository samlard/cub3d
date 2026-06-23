# cub3d

Projet **cub3d** réalisé à l'école 42.

## Collaboration

Ce projet a été réalisé en collaboration avec **[maximevanvelthoven](https://github.com/maximevanvelthoven)**.

## Description

`cub3d` est un moteur 3D de type raycasting inspiré de Wolfenstein 3D.
Le programme lit une map `.cub`, charge des textures XPM, puis affiche un rendu en pseudo-3D avec MinilibX.

## Prérequis

- `make`
- compilateur C (`cc`)
- bibliothèques X11 (Linux)

## Compilation

```bash
make
```

## Lancement

```bash
./cub3D map/map.cub
```

## Nettoyage

```bash
make clean
make fclean
```