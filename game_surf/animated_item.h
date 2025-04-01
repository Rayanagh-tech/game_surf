#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//selon y
class Item {
public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de la goutte de pluie,
    // la largeur et la hauteur de l'�cran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme param�tres
    Item(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le g�n�rateur de nombres al�atoires
        srand(time(nullptr));

        // Cr�e des gouttes de pluie initiales avec des positions al�atoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x al�atoire
            int y = -(rand() % screenHeight); // Position y al�atoire, d�marrant au-dessus de l'�cran
            raindrops.push_back({ x, y }); // Ajoute la goutte � la liste des gouttes
        }
    }

    // Destructeur
    ~Item() {
        SDL_DestroyTexture(raindropTexture); // Lib�re la m�moire allou�e pour la texture de goutte de pluie
    }

    // M�thode pour mettre � jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
        // Calcule la distance de d�placement des gouttes de pluie en fonction de la vitesse et du temps �coul�
        float speedPerPixel = speed * deltaTime;
        // Parcourt toutes les gouttes de pluie et les d�place vers le bas
        for (auto& drop : raindrops) {
            drop.y += speedPerPixel; // D�placement vertical
            // Si une goutte de pluie tombe en dessous de l'�cran, elle est r�initialis�e au-dessus de l'�cran
            if (drop.y > screenHeight) {
                // R�initialise la position de la goutte de pluie avec des coordonn�es al�atoires
                drop.x = rand() % screenWidth;
                drop.y = -(rand() % screenHeight);
            }
        }
    }

    // M�thode pour afficher les gouttes de pluie � l'�cran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend � l'�cran
        for (auto& drop : raindrops) {
            // Cr�e un rectangle de destination pour la goutte de pluie
            SDL_Rect rect = { drop.x, drop.y, raindropSize, raindropSize };
            // Rend la texture de la goutte de pluie sur le rendu SDL
            SDL_RenderCopy(renderer, raindropTexture, nullptr, &rect);
        }
    }
private:
    SDL_Renderer* renderer; // Rendu SDL
    int screenWidth; // Largeur de l'�cran
    int screenHeight; // Hauteur de l'�cran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de pluie

    // Structure pour repr�senter une goutte de pluie avec des coordonn�es x et y
    struct Raindrop {
        int x; // Coordonn�e x de la goutte de pluie
        int y; // Coordonn�e y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie
};

//selonx
class Item1 {
public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de la goutte de pluie,
    // la largeur et la hauteur de l'�cran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme param�tres
    Item1(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le g�n�rateur de nombres al�atoires
        srand(time(nullptr));

        // Cr�e des gouttes de pluie initiales avec des positions al�atoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x al�atoire
            int y = -(rand() % screenHeight); // Position y al�atoire, d�marrant au-dessus de l'�cran
            raindrops.push_back({ x, y }); // Ajoute la goutte � la liste des gouttes
        }
    }

    // Destructeur
    ~Item1() {
        SDL_DestroyTexture(raindropTexture); // Lib�re la m�moire allou�e pour la texture de goutte de pluie
    }

    // M�thode pour mettre � jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
    // Calcule la distance de d�placement des gouttes de pluie en fonction de la vitesse et du temps �coul�
    float speedPerPixel = speed * deltaTime;
    // Parcourt toutes les gouttes de pluie et les d�place horizontalement
    for (auto& drop : raindrops) {
        drop.x += speedPerPixel; // D�placement horizontal
        // Si une goutte de pluie d�passe l'�cran � droite, elle est r�initialis�e � gauche avec une nouvelle position en y al�atoire
        if (drop.x > screenWidth) {
            drop.x = -(raindropSize + rand() % screenWidth); // R�initialisation � une position al�atoire � gauche de l'�cran
            drop.y = (rand() % screenHeight); // R�initialisation de la position en y
        }
    }
}

    // M�thode pour afficher les gouttes de pluie � l'�cran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend � l'�cran
        for (auto& drop : raindrops) {
            // Cr�e un rectangle de destination pour la goutte de pluie
            SDL_Rect rect = { drop.x, drop.y, raindropSize, raindropSize };
            // Rend la texture de la goutte de pluie sur le rendu SDL
            SDL_RenderCopy(renderer, raindropTexture, nullptr, &rect);
        }
    }
    int getx1() {
        for (auto& drop : raindrops) {
            return drop.x;}
    }
     int gety1() {
        for (auto& drop : raindrops) {
            return drop.y;}
    }
    int getw(){return raindropSize;}
private:
    SDL_Renderer* renderer; // Rendu SDL
    int screenWidth; // Largeur de l'�cran
    int screenHeight; // Hauteur de l'�cran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de pluie

    // Structure pour repr�senter une goutte de pluie avec des coordonn�es x et y
    struct Raindrop {
        int x; // Coordonn�e x de la goutte de pluie
        int y; // Coordonn�e y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie
};
//selonx
class Item2 {
public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de la goutte de pluie,
    // la largeur et la hauteur de l'�cran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme param�tres
    Item2(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le g�n�rateur de nombres al�atoires
        srand(time(nullptr));

        // Cr�e des gouttes de pluie initiales avec des positions al�atoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x al�atoire
            int y =  -rand() % (screenHeight);// Position y al�atoire, d�marrant au-dessus de l'�cran
            raindrops.push_back({ x, y }); // Ajoute la goutte � la liste des gouttes
        }
    }

    // Destructeur
    ~Item2() {
        SDL_DestroyTexture(raindropTexture); // Lib�re la m�moire allou�e pour la texture de goutte de pluie
    }

    // M�thode pour mettre � jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
    float speedPerPixel = speed * deltaTime;
    for (auto& drop : raindrops) {
        drop.x -= speedPerPixel; // Changement de signe ici pour inverser le sens
        if (drop.x < -raindropSize) { // Modification de la condition pour r�initialiser les gouttes qui sortent de l'�cran � gauche
            drop.x = screenWidth + rand() % screenWidth; // R�initialisation � une position al�atoire � droite de l'�cran
            drop.y = (rand() % screenHeight); // R�initialisation de la position en y
        }
    }
}

    // M�thode pour afficher les gouttes de pluie � l'�cran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend � l'�cran
        for (auto& drop : raindrops) {
            // Cr�e un rectangle de destination pour la goutte de pluie
            SDL_Rect rect = { drop.x, drop.y, raindropSize, raindropSize };
            // Rend la texture de la goutte de pluie sur le rendu SDL
            SDL_RenderCopy(renderer, raindropTexture, nullptr, &rect);
        }
    }
     int getx1() {
        for (auto& drop : raindrops) {
            return drop.x;}
    }
     int gety1() {
        for (auto& drop : raindrops) {
            return drop.y;}
    }
    int getw(){return raindropSize;}


private:
    SDL_Renderer* renderer; // Rendu SDL
    int screenWidth; // Largeur de l'�cran
    int screenHeight; // Hauteur de l'�cran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de

    // Structure pour repr�senter une goutte de pluie avec des coordonn�es x et y
    struct Raindrop {
        int x; // Coordonn�e x de la goutte de pluie
        int y; // Coordonn�e y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie

};
