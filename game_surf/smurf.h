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
    // une largeur, et une hauteur en param�tres
    Smurf(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
        : renderer(renderer), x(x), y(y), initialY(y), width(width), height(height),  m_jumpSpeed(10) {
        surface = IMG_Load(imagePath); // Charge l'image du Smurf
        texture = SDL_CreateTextureFromSurface(renderer, surface); // Cr�e une texture SDL � partir de l'image charg�e
        // Charge les textures pour chaque direction
        loadAnimationTextures(renderer);
    }

    // Destructeur
    ~Smurf() {
        SDL_FreeSurface(surface); // Lib�re la m�moire allou�e pour la surface SDL
        SDL_DestroyTexture(texture); // D�truit la texture SDL
        // Lib�re la m�moire allou�e pour chaque texture d'animation
        for (int i = 0; i < NumDirections; ++i) {
            for (int j = 0; j < NumFrames[i]; ++j) {
                SDL_DestroyTexture(animationTextures[i][j]);
            }
        }
    }

    // M�thode pour afficher le Smurf � l'�cran
    void render() {
        SDL_Rect rect = { x, y, width, height }; // Rectangle de destination pour le rendu
        SDL_Texture* currentTexture = animationTextures[currentDirection][currentFrame]; // Texture actuelle � afficher
        SDL_RenderCopy(renderer, currentTexture, nullptr, &rect); // Copie la texture sur le rendu
    }

    // M�thodes pour d�placer le Smurf dans diff�rentes directions avec une gestion du temps
    void moveRight(float deltaTime) {
        currentDirection = Right; // D�finit la direction comme droite
        x += speed * deltaTime; // D�placement horizontal vers la droite
        incrementFrameIndex(); // Incr�mente l'indice de l'image pour l'animation
    }

    void moveLeft(float deltaTime) {
        currentDirection = Left; // D�finit la direction comme gauche
        x -= speed * deltaTime; // D�placement horizontal vers la gauche
        incrementFrameIndex(); // Incr�mente l'indice de l'image pour l'animation
    }

    void moveDown(float deltaTime) {
        currentDirection = Down; // D�finit la direction comme bas
        y += speed * deltaTime * 2; // D�placement vertical vers le bas
        incrementFrameIndex(); // Incr�mente l'indice de l'image pour l'animation
    }

    void moveJump(float deltaTime) {
        currentDirection = Jump; // D�finit la direction comme saut
        y -= m_jumpSpeed * deltaTime *1000; // Ajuste la position verticale au lieu de l'horizontale pour simuler un saut
        incrementFrameIndex(); // Incr�mente l'indice de l'image pour l'animation
    }

    // Getters pour la largeur et la hauteur
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Getters pour les coordonn�es x et y
    int getx() { return x; }
    int gety() { return y; }

    // Setters pour les coordonn�es x, y et le nombre de vies
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    // Setter pour la vitesse
    void setSpeed(float newSpeed) { speed = newSpeed; }
private:
    SDL_Renderer* renderer; // Rendu SDL
    SDL_Surface* surface; // Surface SDL pour l'image du Smurf
    SDL_Texture* texture; // Texture SDL pour l'image du Smurf
    SDL_Texture* animationTextures[4][5]; // Tableau de textures pour les animations (ajust� pour le saut)
    int x, y; // Position du Smurf
    int initialY; // Position Y initiale avant le saut
    int width, height; // Largeur et hauteur du Smurf
    float speed = 200.0f; // Vitesse par d�faut
    int currentFrame = 0; // Image actuelle de l'animation
    int m_jumpSpeed;
    Direction currentDirection = Right; // Direction par d�faut
    static const int MaxFrames = 5; // Nombre maximal de frames pour l'animation
    int NumFrames[NumDirections] = { 5, 5, 1,1}; // Nombre de frames pour chaque direction d'animation
    // Chemins d'acc�s aux images pour les animations dans chaque direction
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
    // M�thode pour charger les textures d'animation
    void loadAnimationTextures(SDL_Renderer* renderer) {
        for (int i = 0; i < NumDirections; ++i) {
            for (int j = 0; j < NumFrames[i]; ++j) {
                // Charge la texture SDL � partir de l'image correspondante
                animationTextures[i][j] = SDL_CreateTextureFromSurface(renderer, IMG_Load(animationPaths[i][j]));
            }
        }
    }

    // M�thode pour incr�menter l'indice de l'image pour l'animation
    void incrementFrameIndex() {
        currentFrame = (currentFrame + 1) % NumFrames[currentDirection]; // Incr�mente l'indice de l'image avec wrap-around
    }
};
