#include <string>
#include <SDL2/SDL.h>

class Button {
private:
    SDL_Texture* texture;
    int x, y;
    int width, height;

public:
    Button(SDL_Renderer* renderer, const std::string& imagePath, int posX, int posY, int w, int h)
        : x(posX), y(posY), width(w), height(h) {
        texture = loadTexture(renderer, imagePath.c_str()); // Convertir std::string en const char*
    }

    ~Button() {
        SDL_DestroyTexture(texture);
    }

    void render(SDL_Renderer* renderer) {
        renderTexture(renderer, texture, x, y, width, height);
    }

    bool isClicked(int mouseX, int mouseY) const {
        return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    }


};
