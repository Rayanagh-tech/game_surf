#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Classe encapsulant une image charg�e
class Image {
public:
    Image(SDL_Renderer* renderer) : texture(nullptr), renderer(renderer) {}
    ~Image() {
        if (texture) SDL_DestroyTexture(texture);
    }

    // Charge une image � partir d'un fichier
    bool load(const char* filePath) {
        SDL_Surface* surface = IMG_Load(filePath);
        if (!surface) {
            std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
            return false;
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        return texture != nullptr;
    }

    // Rend l'image � l'�cran
    void render(int x, int y, int w, int h) {
        if (texture) {
            SDL_Rect destRect = { x, y, w, h };
            SDL_RenderCopy(renderer, texture, NULL, &destRect);
        }
    }

private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};
// Fonction pour charger une texture � partir d'un fichier image
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);// Lib�ration de la surface maintenant que la texture est cr��e
    return texture;
}

// Fonction pour afficher une texture � l'�cran
void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h) {
    SDL_Rect destRect = { x, y, w, h };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
