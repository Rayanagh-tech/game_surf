#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class B {
private:
    SDL_Renderer* renderer; // Rendu SDL pour afficher les textures
    std::vector<SDL_Texture*> textures; // Vecteur de textures pour stocker les différentes couches du fond d'écran
    std::vector<int> positions; // Positions horizontales des différentes couches du fond d'écran
    int speed; // Vitesse de défilement du fond d'écran
    int width; // Largeur du fond d'écran
    int height; // Hauteur du fond d'écran
    int position; // Position horizontale actuelle du fond d'écran

public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de fond, la vitesse de défilement, la largeur et la hauteur du fond d'écran
    B(SDL_Renderer* renderer, const std::string& imagePath, int speed, int width, int height) :
        renderer(renderer), speed(speed), width(width),
        height(height), position(0) {
        // Charger les textures du fond d'écran
        loadBackground(imagePath);

        // Initialiser les positions des différentes couches
        int numLayers = textures.size();
        for (int i = 0; i < numLayers; ++i) {
            positions.push_back(i * width);
        }
    }

    // Destructeur
    ~B() {
        // Nettoyage des textures
        for (SDL_Texture* texture : textures) {
            SDL_DestroyTexture(texture);
        }
    }

    // Méthode pour mettre à jour la position du fond d'écran en fonction de la vitesse
    void update() {
        position += speed; // Met à jour la position en fonction de la vitesse
        if (position >= width) { // Si le fond d'écran a dépassé sa largeur
            position = 0; // Réinitialise la position à 0 pour créer un effet de boucle
        }
    }

    // Méthode pour rendre le fond d'écran
    void render() {
        // Rendre chaque couche du fond d'écran en répétant l'image horizontalement
        int numLayers = textures.size();
        for (int i = 0; i < numLayers; ++i) {
            int xPos = positions[i] - position; // Position horizontale ajustée en fonction de la position actuelle du fond d'écran
            while (xPos <= -width) { // Si la position est inférieure à la largeur du fond d'écran, ajuste-la
                xPos += width;
            }
            while (xPos < width) { // Tant que la position est dans la largeur du rendu, rend l'image
                SDL_Rect destRect = {xPos, 0, width, height}; // Rectangle de destination pour le rendu de l'image
                SDL_RenderCopy(renderer, textures[i], nullptr, &destRect); // Copie la texture sur le rendu SDL
                xPos += width; // Passe à la position suivante pour le prochain rendu
            }
        }
    }

    // Méthode pour charger l'image de fond et créer sa texture SDL
    void loadBackground(const std::string& imagePath) {
        // Charger l'image de fond
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // Créer une texture SDL à partir de la surface chargée
        SDL_FreeSurface(surface); // Libérer la surface chargée, la texture a maintenant sa propre copie de l'image
        textures.push_back(texture); // Ajouter la texture au vecteur de textures
    }

    // Méthode pour définir la vitesse de défilement du fond d'écran
    void setSpeed(int newSpeed) {
        speed = newSpeed; // Met à jour la vitesse
    }
};
