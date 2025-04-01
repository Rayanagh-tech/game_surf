#include <string>
#include <SDL2/SDL.h>

class Background {
private:
    SDL_Texture* texture;
    int width;
    int height;
    int posX;
    int posY;

public:
    Background(SDL_Renderer* renderer, const std::string& imagePath,
               int imgWidth, int imgHeight) {
        texture = loadTexture(renderer, imagePath.c_str());
        width = imgWidth;
        height = imgHeight;

        // Calcul des coordonnées x et y pour positionner l'image au milieu de l'écran
        int screenWidth, screenHeight;
        SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);
        posX = (screenWidth - width) / 2;
        posY = (screenHeight - height) / 2;
    }

    ~Background() {
        SDL_DestroyTexture(texture);
    }

    void render(SDL_Renderer* renderer) {
        renderTexture(renderer, texture, posX, posY, width, height);
    }
};
