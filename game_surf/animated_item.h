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
    // la largeur et la hauteur de l'écran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme paramètres
    Item(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le générateur de nombres aléatoires
        srand(time(nullptr));

        // Crée des gouttes de pluie initiales avec des positions aléatoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x aléatoire
            int y = -(rand() % screenHeight); // Position y aléatoire, démarrant au-dessus de l'écran
            raindrops.push_back({ x, y }); // Ajoute la goutte à la liste des gouttes
        }
    }

    // Destructeur
    ~Item() {
        SDL_DestroyTexture(raindropTexture); // Libère la mémoire allouée pour la texture de goutte de pluie
    }

    // Méthode pour mettre à jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
        // Calcule la distance de déplacement des gouttes de pluie en fonction de la vitesse et du temps écoulé
        float speedPerPixel = speed * deltaTime;
        // Parcourt toutes les gouttes de pluie et les déplace vers le bas
        for (auto& drop : raindrops) {
            drop.y += speedPerPixel; // Déplacement vertical
            // Si une goutte de pluie tombe en dessous de l'écran, elle est réinitialisée au-dessus de l'écran
            if (drop.y > screenHeight) {
                // Réinitialise la position de la goutte de pluie avec des coordonnées aléatoires
                drop.x = rand() % screenWidth;
                drop.y = -(rand() % screenHeight);
            }
        }
    }

    // Méthode pour afficher les gouttes de pluie à l'écran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend à l'écran
        for (auto& drop : raindrops) {
            // Crée un rectangle de destination pour la goutte de pluie
            SDL_Rect rect = { drop.x, drop.y, raindropSize, raindropSize };
            // Rend la texture de la goutte de pluie sur le rendu SDL
            SDL_RenderCopy(renderer, raindropTexture, nullptr, &rect);
        }
    }
private:
    SDL_Renderer* renderer; // Rendu SDL
    int screenWidth; // Largeur de l'écran
    int screenHeight; // Hauteur de l'écran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de pluie

    // Structure pour représenter une goutte de pluie avec des coordonnées x et y
    struct Raindrop {
        int x; // Coordonnée x de la goutte de pluie
        int y; // Coordonnée y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie
};

//selonx
class Item1 {
public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de la goutte de pluie,
    // la largeur et la hauteur de l'écran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme paramètres
    Item1(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le générateur de nombres aléatoires
        srand(time(nullptr));

        // Crée des gouttes de pluie initiales avec des positions aléatoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x aléatoire
            int y = -(rand() % screenHeight); // Position y aléatoire, démarrant au-dessus de l'écran
            raindrops.push_back({ x, y }); // Ajoute la goutte à la liste des gouttes
        }
    }

    // Destructeur
    ~Item1() {
        SDL_DestroyTexture(raindropTexture); // Libère la mémoire allouée pour la texture de goutte de pluie
    }

    // Méthode pour mettre à jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
    // Calcule la distance de déplacement des gouttes de pluie en fonction de la vitesse et du temps écoulé
    float speedPerPixel = speed * deltaTime;
    // Parcourt toutes les gouttes de pluie et les déplace horizontalement
    for (auto& drop : raindrops) {
        drop.x += speedPerPixel; // Déplacement horizontal
        // Si une goutte de pluie dépasse l'écran à droite, elle est réinitialisée à gauche avec une nouvelle position en y aléatoire
        if (drop.x > screenWidth) {
            drop.x = -(raindropSize + rand() % screenWidth); // Réinitialisation à une position aléatoire à gauche de l'écran
            drop.y = (rand() % screenHeight); // Réinitialisation de la position en y
        }
    }
}

    // Méthode pour afficher les gouttes de pluie à l'écran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend à l'écran
        for (auto& drop : raindrops) {
            // Crée un rectangle de destination pour la goutte de pluie
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
    int screenWidth; // Largeur de l'écran
    int screenHeight; // Hauteur de l'écran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de pluie

    // Structure pour représenter une goutte de pluie avec des coordonnées x et y
    struct Raindrop {
        int x; // Coordonnée x de la goutte de pluie
        int y; // Coordonnée y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie
};
//selonx
class Item2 {
public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de la goutte de pluie,
    // la largeur et la hauteur de l'écran, la taille des gouttes de pluie, le nombre
    // de gouttes de pluie et la vitesse de chute comme paramètres
    Item2(SDL_Renderer* renderer, const char* imagePath, int screenWidth,
         int screenHeight, int r, int n, float s)
        : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight),
        raindropSize(r), numRaindrops(n), speed(s) {
        // Charge l'image de la goutte de pluie en tant que texture SDL
        raindropTexture = IMG_LoadTexture(renderer, imagePath);
        // Initialise le générateur de nombres aléatoires
        srand(time(nullptr));

        // Crée des gouttes de pluie initiales avec des positions aléatoires
        for (int i = 0; i < numRaindrops; ++i) {
            int x = rand() % screenWidth; // Position x aléatoire
            int y =  -rand() % (screenHeight);// Position y aléatoire, démarrant au-dessus de l'écran
            raindrops.push_back({ x, y }); // Ajoute la goutte à la liste des gouttes
        }
    }

    // Destructeur
    ~Item2() {
        SDL_DestroyTexture(raindropTexture); // Libère la mémoire allouée pour la texture de goutte de pluie
    }

    // Méthode pour mettre à jour la position des gouttes de pluie en fonction du temps
    void update(float deltaTime) {
    float speedPerPixel = speed * deltaTime;
    for (auto& drop : raindrops) {
        drop.x -= speedPerPixel; // Changement de signe ici pour inverser le sens
        if (drop.x < -raindropSize) { // Modification de la condition pour réinitialiser les gouttes qui sortent de l'écran à gauche
            drop.x = screenWidth + rand() % screenWidth; // Réinitialisation à une position aléatoire à droite de l'écran
            drop.y = (rand() % screenHeight); // Réinitialisation de la position en y
        }
    }
}

    // Méthode pour afficher les gouttes de pluie à l'écran
    void render(SDL_Renderer* renderer) {
        // Parcourt toutes les gouttes de pluie et les rend à l'écran
        for (auto& drop : raindrops) {
            // Crée un rectangle de destination pour la goutte de pluie
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
    int screenWidth; // Largeur de l'écran
    int screenHeight; // Hauteur de l'écran
    int raindropSize; // Taille des gouttes de pluie
    int numRaindrops; // Nombre de gouttes de pluie
    float speed; // Vitesse de chute des gouttes de pluie
    SDL_Texture* raindropTexture; // Texture de la goutte de

    // Structure pour représenter une goutte de pluie avec des coordonnées x et y
    struct Raindrop {
        int x; // Coordonnée x de la goutte de pluie
        int y; // Coordonnée y de la goutte de pluie
    };

    std::vector<Raindrop> raindrops; // Vecteur de gouttes de pluie

};
