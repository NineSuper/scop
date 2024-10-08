# SCOP


Bienvenue dans SCOP 👾 Un mini-projet passionnant de l'école 42 dédié à l'infographie et au rendu 3D !

Ici, on plonge dans le monde captivant de la programmation graphique. On apprend à donner vie à des objets 3D à partir de fichiers .obj, tout en explorant différentes techniques de rendu et de manipulation.

Prêt à repousser les limites de votre imagination ? Let's dive in! 🚀

## 📚 Description

SCOP est une application graphique conçue pour afficher des objets 3D à partir de fichiers .obj.

Ce projet permet de se familiariser avec les concepts de rendu 3D en utilisant des bibliothèques graphiques telles que OpenGL, Vulkan, Metal ou la MLX.

## 🛠️ Fonctionnalités

- [x] Parsing des fichiers .obj pour obtenir le rendu demandé
- [x] Affichage d'objets 3D à partir de fichiers .obj
- [x] Rendu en perspective avec rotation autour de l'object
- [x] Gestion des déplacements sur les trois axes
- [x] Application de textures sur l'objet avec légère transition

## 🔧 Prérequis

Assurez-vous d'avoir les bibliothèques graphiques nécessaires installées sur votre système.

🐧 Linux:
```bash
sudo apt-get install libsdl2-dev libx11-dev libxext-dev libbsd-dev libgl1-mesa-dev mesa-common-dev freeglut3-dev libglfw3-dev
```
💻 MacOs:
```bash
brew install sdl2 libx11 libxext libbsd mesa freeglut
```

## 🗳️ Installation

Clonez le dépôt SCOP :
```bash
git clone https://github.com/NineSuper/scop.git
```

Compilez le projet :
```
make
```

Compilez le projet :
```
./Scop <file>.obj
```

## ⌨️ Contrôles
- W/A/S/D : Déplacements sur les axes X, Y, Z
- X/Z : Zoom/Dézoom
- G : Appliquer/retirer la texture
- Esc : Quitter l'application

## 👀 Aperçus actuels

![42](./gif/42.gif)
![cube](./gif/Cube.gif)
![teapot](./gif/teapot.gif)

## 📝 Auteur

- 🎫 [@NineSuper](https://www.github.com/NineSuper)
