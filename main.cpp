// Projet_sythese_image.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Scene.h"
#include "Object3d.h"
#include "Color.h"
#include "DirectionalLight.h"
#include "Sphere.h"
#include "Vector3d.h"
#include "Light.h"


int main()
{
    Scene scene;
    
    Object3d* sphere = new Sphere(Vector3d(0.0f, 0.0f, 00.0f), 0.1f);
    sphere->SetColor(Color(255, 0, 0));
    scene.addObject(sphere);

    //Light* light = new DirectionalLight(Vector3d(-1, -1, 0));
    //scene.addLight(light);
    
    scene.render("test.bmp", 1000, 1000, sphere);


    /*
    //std::cout << "Hello World!\n";
    */

    /*
    Vector3d rayOrigin(0, 0, 10);
    Vector3d rayDirection(0, 0, 1);
    scene.rayIntersectsSphere(rayOrigin, rayDirection, sphere);*/

}





// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
