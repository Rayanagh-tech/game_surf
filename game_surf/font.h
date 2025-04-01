#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Fonction pour afficher du texte à l'écran
void renderText(SDL_Renderer* renderer, const char* text, int x, int y, TTF_Font* font, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
     int texW = 100;
    int texH = 100;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH); // Obtention des dimensions de la texture
    SDL_Rect dstRect = { x, y, texW, texH };

    SDL_RenderCopy(renderer, texture, NULL, &dstRect);// Affichage final du texte
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

}
