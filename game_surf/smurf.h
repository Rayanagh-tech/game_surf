#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Smurf {

public:
    enum Direction {
        Left,
        Right,
        Down,
        Jump,
        NumDirections
    };

    // Constructeur prenant un rendu SDL, un chemin d'image, une position (x, y),
    // une largeur, et une hauteur en paramètres
    Smurf(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
        : renderer(renderer), x(x), y(y), initialY(y), width(width), height(height),  m_jumpSpeed(10) {
        surface = IMG_Load(imagePath); // Charge l'image du Smurf
        texture = SDL_CreateTextureFromSurface(renderer, surface); // Crée une texture SDL à partir de l'image chargée
        // Charge les textures pour chaque direction
        loadAnimationTextures(renderer);
    }

    // Destructeur
    ~Smurf() {
        SDL_FreeSurface(surface); // Libère la mémoire allouée pour la surface SDL
        SDL_DestroyTexture(texture); // Détruit la texture SDL
        // Libère la mémoire allouée pour chaque texture d'animation
        for (int i = 0; i < NumDirections; ++i) {
            for (int j = 0; j < NumFrames[i]; ++j) {
                SDL_DestroyTexture(animationTextures[i][j]);
            }
        }
    }

    // Méthode pour afficher le Smurf à l'écran
    void render() {
        SDL_Rect rect = { x, y, width, height }; // Rectangle de destination pour le rendu
        SDL_Texture* currentTexture = animationTextures[currentDirection][currentFrame]; // Texture actuelle à afficher
        SDL_RenderCopy(renderer, currentTexture, nullptr, &rect); // Copie la texture sur le rendu
    }

    // Méthodes pour déplacer le Smurf dans différentes directions avec une gestion du temps
    void moveRight(float deltaTime) {
        currentDirection = Right; // Définit la direction comme droite
        x += speed * deltaTime; // Déplacement horizontal vers la droite
        incrementFrameIndex(); // Incrémente l'indice de l'image pour l'animation
    }

    void moveLeft(float deltaTime) {
        currentDirection = Left; // Définit la direction comme gauche
        x -= speed * deltaTime; // Déplacement horizontal vers la gauche
        incrementFrameIndex(); // Incrémente l'indice de l'image pour l'animation
    }

    void moveDown(float deltaTime) {
        currentDirection = Down; // Définit la direction comme bas
        y += speed * deltaTime * 2; // Déplacement vertical vers le bas
        incrementFrameIndex(); // Incrémente l'indice de l'image pour l'animation
    }

    void moveJump(float deltaTime) {
        currentDirection = Jump; // Définit la direction comme saut
        y -= m_jumpSpeed * deltaTime *1000; // Ajuste la position verticale au lieu de l'horizontale pour simuler un saut
        incrementFrameIndex(); // Incrémente l'indice de l'image pour l'animation
    }

    // Getters pour la largeur et la hauteur
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Getters pour les coordonnées x et y
    int getx() { return x; }
    int gety() { return y; }

    // Setters pour les coordonnées x, y et le nombre de vies
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    // Setter pour la vitesse
    void setSpeed(float newSpeed) { speed = newSpeed; }
private:
    SDL_Renderer* renderer; // Rendu SDL
    SDL_Surface* surface; // Surface SDL pour l'image du Smurf
    SDL_Texture* texture; // Texture SDL pour l'image du Smurf
    SDL_Texture* animationTextures[4][5]; // Tableau de textures pour les animations (ajusté pour le saut)
    int x, y; // Position du Smurf
    int initialY; // Position Y initiale avant le saut
    int width, height; // Largeur et hauteur du Smurf
    float speed = 200.0f; // Vitesse par défaut
    int currentFrame = 0; // Image actuelle de l'animation
    int m_jumpSpeed;
    Direction currentDirection = Right; // Direction par défaut
    static const int MaxFrames = 5; // Nombre maximal de frames pour l'animation
    int NumFrames[NumDirections] = { 5, 5, 1,1}; // Nombre de frames pour chaque direction d'animation
    // Chemins d'accès aux images pour les animations dans chaque direction
    const char* animationPaths[NumDirections][MaxFrames] = {
        { "C:/Users/yakii/OneDrive/Pictures/sanfour/a1-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aa1-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aaa1-removebg-preview.png",
            "C:/Users/yakii/OneDrive/Pictures/sanfour/aaaa1-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aaaaa1-removebg-preview.png" },
        { "C:/Users/yakii/OneDrive/Pictures/sanfour/a-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aa-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aaa-removebg-preview.png",
            "C:/Users/yakii/OneDrive/Pictures/sanfour/aaaa-removebg-preview.png", "C:/Users/yakii/OneDrive/Pictures/sanfour/aaaaa-removebg-preview.png" },
        {
            "C:/Users/yakii/Downloads/fdf.png"
        },
        {
            "C:/Users/yakii/Downloads/fly.png"
        }
    };
    // Méthode pour charger les textures d'animation
    void loadAnimationTextures(SDL_Renderer* renderer) {
        for (int i = 0; i < NumDirections; ++i) {
            for (int j = 0; j < NumFrames[i]; ++j) {
                // Charge la texture SDL à partir de l'image correspondante
                animationTextures[i][j] = SDL_CreateTextureFromSurface(renderer, IMG_Load(animationPaths[i][j]));
            }
        }
    }

    // Méthode pour incrémenter l'indice de l'image pour l'animation
    void incrementFrameIndex() {
        currentFrame = (currentFrame + 1) % NumFrames[currentDirection]; // Incrémente l'indice de l'image avec wrap-around
    }
};
