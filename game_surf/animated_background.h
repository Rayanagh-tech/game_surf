#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

class B {
private:
    SDL_Renderer* renderer; // Rendu SDL pour afficher les textures
    std::vector<SDL_Texture*> textures; // Vecteur de textures pour stocker les diff�rentes couches du fond d'�cran
    std::vector<int> positions; // Positions horizontales des diff�rentes couches du fond d'�cran
    int speed; // Vitesse de d�filement du fond d'�cran
    int width; // Largeur du fond d'�cran
    int height; // Hauteur du fond d'�cran
    int position; // Position horizontale actuelle du fond d'�cran

public:
    // Constructeur prenant le rendu SDL, le chemin de l'image de fond, la vitesse de d�filement, la largeur et la hauteur du fond d'�cran
    B(SDL_Renderer* renderer, const std::string& imagePath, int speed, int width, int height) :
        renderer(renderer), speed(speed), width(width),
        height(height), position(0) {
        // Charger les textures du fond d'�cran
        loadBackground(imagePath);

        // Initialiser les positions des diff�rentes couches
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

    // M�thode pour mettre � jour la position du fond d'�cran en fonction de la vitesse
    void update() {
        position += speed; // Met � jour la position en fonction de la vitesse
        if (position >= width) { // Si le fond d'�cran a d�pass� sa largeur
            position = 0; // R�initialise la position � 0 pour cr�er un effet de boucle
        }
    }

    // M�thode pour rendre le fond d'�cran
    void render() {
        // Rendre chaque couche du fond d'�cran en r�p�tant l'image horizontalement
        int numLayers = textures.size();
        for (int i = 0; i < numLayers; ++i) {
            int xPos = positions[i] - position; // Position horizontale ajust�e en fonction de la position actuelle du fond d'�cran
            while (xPos <= -width) { // Si la position est inf�rieure � la largeur du fond d'�cran, ajuste-la
                xPos += width;
            }
            while (xPos < width) { // Tant que la position est dans la largeur du rendu, rend l'image
                SDL_Rect destRect = {xPos, 0, width, height}; // Rectangle de destination pour le rendu de l'image
                SDL_RenderCopy(renderer, textures[i], nullptr, &destRect); // Copie la texture sur le rendu SDL
                xPos += width; // Passe � la position suivante pour le prochain rendu
            }
        }
    }

    // M�thode pour charger l'image de fond et cr�er sa texture SDL
    void loadBackground(const std::string& imagePath) {
        // Charger l'image de fond
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // Cr�er une texture SDL � partir de la surface charg�e
        SDL_FreeSurface(surface); // Lib�rer la surface charg�e, la texture a maintenant sa propre copie de l'image
        textures.push_back(texture); // Ajouter la texture au vecteur de textures
    }

    // M�thode pour d�finir la vitesse de d�filement du fond d'�cran
    void setSpeed(int newSpeed) {
        speed = newSpeed; // Met � jour la vitesse
    }
};
