# Projet de Ray Tracing - Création d'une sphère

Projet réalisé dans le cadre du cours de sythèse d'image

Ce projet consiste à créer une sphère en utilisant le langage de programmation C++ et le principe de ray tracing. 
Le ray tracing est une technique de rendu d'images qui simule le comportement de la lumière en suivant la trajectoire 
des rayons de lumière à partir d'une source lumineuse jusqu'à leur impact sur une surface.

## Diagramme

```mermaid
classDiagram
    class Ray {
    }
    class Vector3d {
    }
    class BMPHelper {
    }
    class Color {
    }
    
    class Scene {
        + draw()
    }
    class Object3d {
        - radius : int
        + getRadius()
        + setRadius()
        + draw()
    }
    class Sphere {
        - width : int
        - height : int
        + getWidth()
        + setWidth()
        + getHeight()
        + setHeight()
        + draw()
    }
    class Light {
        - side : int
        + getSide()
    }
    class DirectionalLight {
        - side : int
        + getSide()
    }
    Scene <-- Object3d
    Object3d <|-- Sphere
    Scene <-- Light
    Light <|-- DirectionalLight

```

## Résultat
![Result](test.bmp)
