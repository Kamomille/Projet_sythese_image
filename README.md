# Projet de Ray Tracing - Création d'une sphère

Projet réalisé dans le cadre du cours de sythèse d'image

Ce projet consiste à créer une sphère en utilisant le langage de programmation C++ et le principe de ray tracing. 
Le ray tracing est une technique de rendu d'images qui simule le comportement de la lumière en suivant la trajectoire 
des rayons de lumière à partir d'une source lumineuse jusqu'à leur impact sur une surface.

## Diagramme

```mermaid
classDiagram
    class Ray {
        - origin : Point3d
        - direction : Vector3d
    }
    class Vector3d {
        - x : double
        - y : double
        - z : double
    }
    class BMPHelper {
    }
    class Color {
        - r : double
        - g : double
        - b : double
    }
    
    class Scene {
    }
    class Object3d {
    }
    class Sphere {
        - center : Vector3d
        - radius : double
    }
    class Light {
    }
    class DirectionalLight {
        - direction : Vector3d
    }
    Scene <-- Object3d
    Object3d <|-- Sphere
    Scene <-- Light
    Light <|-- DirectionalLight

```

## Résultat final
![Result](move_spheres.gif)


