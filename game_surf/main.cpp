#define SDL_MAIN_HANDLED // Définit que SDL gère la fonction main
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "initial_sdl.h"
#include "image.h"
#include "font.h"
#include "boutton.h"
#include "background.h"
#include "smurf.h"
#include "animated_item.h"
#include"animated_background.h"
#include"algorithm"
#include <fstream>
#include"string.h"
#include <iostream>
#include <string>

using namespace std;
template<typename T, typename U>
bool checkCollision1(T& obj1, U& obj2) {
    return (
        obj1.getx() <= obj2.getx1() + 70 &&
        obj1.getx() + obj1.getWidth() >= obj2.getx1() &&
        obj1.gety() <= obj2.gety1() + 70&&
        obj1.gety() + obj1.getHeight() >= obj2.gety1()
    );
}
int main(int argc, char* argv[]) {
    if (!initSDL()) return 1;
    SDL_Window* window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // Create buttons and backgrounds
    Button startButton(renderer, "C:/Users/yakii/Downloads/R (8).png",670, 500, 200, 150);
    Button playButton(renderer, "C:/Users/yakii/Downloads/R (1).png", 670, 400, 300, 100);
    Button helpButton(renderer, "C:/Users/yakii/Downloads/R (30).png", 1200, 700,200,70);
    Button quitButton(renderer, "C:/Users/yakii/Downloads/R (29).png", 700,500,250, 100);
    Button backButton(renderer, "C:/Users/yakii/Downloads/R (9).png", 10, 10, 70, 70);
    Button level1Button(renderer, "C:/Users/yakii/Downloads/R (6).png", 670, 250, 200, 100);
    Button level2Button(renderer, "C:/Users/yakii/Downloads/R (5).png", 670, 400, 200, 100);
    Button level3Button(renderer, "C:/Users/yakii/Downloads/R (7).png",650, 550, 250, 125);
    Button music(renderer, "C:/Users/yakii/Downloads/R (26).png",1500, 10, 40, 40);
    Button view(renderer, "C:/Users/yakii/Downloads/pp.png",1450,690, 70,100);
    Background background(renderer, "C:/Users/yakii/Downloads/level1.png", 1600,800);
    Background background1(renderer, "C:/Users/yakii/Downloads/The-Smurfs-Mission-Vileaf.webp", 1600,800);
    Background backgroundPlay(renderer, "C:/Users/yakii/Downloads/R (4).jpg",1600,800);
    B backgroundOption3(renderer,"C:/Users/yakii/OneDrive/Pictures/Screenshots/Screenshot 2024-05-14 174749.png", 1, 1600,800);
    B backgroundOption1(renderer, "C:/Users/yakii/Downloads/forest3.png",1, 1600,800);
    B backgroundOption2(renderer,"C:/Users/yakii/OneDrive/Pictures/Screenshots/Screenshot 2024-05-14 165928.png",1,1600,800);
    Background blackbackground(renderer, "C:/Users/yakii/Downloads/OIP (9).jpg", 1600,800);
    Background lostbackground(renderer,"C:/Users/yakii/OneDrive/Pictures/Screenshots/Screenshot 2024-05-14 183324.png", 1600,800);
    Background gainbackground(renderer, "C:/Users/yakii/Downloads/ef.jpg", 1600,800);
    Background helpbackground(renderer, "C:/Users/yakii/Downloads/11.png",1600,800);
    // Load font and music
    TTF_Font* boldFont = TTF_OpenFont("C:/Users/yakii/Downloads/alef/Alef-Bold.ttf",50);
    TTF_Font* boldFont1 = TTF_OpenFont("C:/Users/yakii/Downloads/alef/Alef-Bold.ttf",60);
    TTF_Font* boldFont2 = TTF_OpenFont("C:/Users/yakii/Downloads/alef/Alef-Bold.ttf",20);
    Mix_Music* buttonClickMusic = Mix_LoadMUS("C:/Users/yakii/Downloads/creepy-devil-dance-166764.mp3");
    Mix_Music* buttonClickMusic1 = Mix_LoadMUS("C:/Users/yakii/Downloads/cute-level-up-3-189853.mp3");
    Mix_Music* buttonClickMusic3 = Mix_LoadMUS("C:/Users/yakii/Downloads/eee.mp3");
    Mix_Music* buttonClickMusic2 = Mix_LoadMUS("C:/Users/yakii/Downloads/lv2.mp3");
    Mix_Music* buttonClickMusic4 = Mix_LoadMUS("C:/Users/yakii/Downloads/scary.mp3");
    // Create instances of Smurf for each level
    Smurf smurfLevel1(renderer, "C:/Users/yakii/OneDrive/Pictures/sanfour/a-removebg-preview.png", 150,800,110, 100);
    smurfLevel1.setSpeed(1500);
    Smurf smurfLevel2(renderer, "C:/Users/yakii/OneDrive/Pictures/sanfour/a-removebg-preview.png", 150,450,100, 90);
    smurfLevel2.setSpeed(1000);
    Smurf smurfLevel3(renderer, "C:/Users/yakii/OneDrive/Pictures/sanfour/a-removebg-preview.png", 150,450,90, 80);
    smurfLevel3.setSpeed(1500);

    Item rain(renderer,"C:/Users/yakii/Downloads/clear-water-drop-on-transparent-in-grey-color-illustration-isolated-transparency-single-blue-shiny-rain-drop-element-design-for-concept-of-ecology-and-world-water-day-png.png",1500, 700,30,50,5);
    Item2 f1 (renderer, "C:/Users/yakii/Downloads/coin.png", 1500, 700,50,1,3);
    Item2 s1(renderer,"C:/Users/yakii/Downloads/apple-clipart-cartoon-1.png" ,1500, 700,50,1,3);
    Item2 f2 (renderer, "C:/Users/yakii/Downloads/coin.png",1500, 700,50,1,3);
    Item2 s2(renderer,"C:/Users/yakii/Downloads/apple-clipart-cartoon-1.png" ,1500, 700,50,1,3);
    Item2 f3 (renderer, "C:/Users/yakii/Downloads/coin.png",1500, 700,50,1,3);
    Item2 s3(renderer,"C:/Users/yakii/Downloads/apple-clipart-cartoon-1.png" ,1500, 700,50,1,3);
    Item1 o(renderer,"C:/Users/yakii/Downloads/R (23).png", 1500, 300,60,3,1);
    Item1 o1(renderer,"C:/Users/yakii/Downloads/R (22).png", 1500,300 ,60,3,1);
    Item2 c1 (renderer, "C:/Users/yakii/Downloads/R (28).png" ,1500, 700,70,1,3);
    Item2 c2 (renderer, "C:/Users/yakii/Downloads/R (28).png",1500, 700,70,1,3);
    Item2 c3 (renderer, "C:/Users/yakii/Downloads/R (28).png",1500, 700,70,1,3);
    Item2 c4 (renderer, "C:/Users/yakii/Downloads/R (28).png",1500, 700,70,1,3);
    Item2 coin1 (renderer, "C:/Users/yakii/Downloads/coin.png" ,1500, 700,70,1,3);
    Item bat(renderer,"C:/Users/yakii/Downloads/R (21).png", 1500, 300,70,3,1);
    Item2 w1 (renderer, "C:/Users/yakii/Downloads/R (24).png" ,1500, 700, 100,1,3);
    Item2 w2 (renderer, "C:/Users/yakii/Downloads/R (24).png" ,1500, 700, 100,1,3);
    Item2 b1 (renderer, "C:/Users/yakii/Downloads/as.png" ,1500, 700, 100,1,3);
    Item2 b2 (renderer, "C:/Users/yakii/Downloads/as.png" ,1500, 700, 100,1,3);
    Item2 b3 (renderer, "C:/Users/yakii/Downloads/as.png" ,1500, 700, 100,1,3);
    Item2 coin2 (renderer, "C:/Users/yakii/Downloads/coin.png" ,1500, 700,70,1,3);
    Item2 coin3 (renderer, "C:/Users/yakii/Downloads/coin.png" ,1500, 700,70,1,3);
    // Main loop
    bool quit = false;
    bool startScreen = true;
    bool playScreen = false;
    bool subOptionsScreen = false;
    bool level1Selected = false;
    bool level2Selected = false;
    bool level3Selected = false;
    bool lost= false;
    bool gain1 =false;
    bool gain2 =false;
    bool gain3 =false;
    bool help=false;
    bool crypt1=false;
    bool crypt2=false;
    bool crypt3=false;
    string ch1="";
    string ch2="";
    string ch3="";

    int smurfScore1 = 100;
    int smurfScore2 = 100;
    int smurfScore3 = 100;

    // Define Smurf's position and movement speed
    int smurfX1 = 10;
    int smurfY1 = 570;
    int smurfSpeed1 = 10; // Adjust this value as needed

     // Define Smurf's position and movement speed
    int smurfX2 = 10;
    int smurfY2 = 590;
    int smurfSpeed2 = 10; // Adjust this value as needed

     // Define Smurf's position and movement speed
    int smurfX3 = 10;
    int smurfY3 = 600;
    int smurfSpeed3 = 15; // Adjust this value as neede
    Mix_PlayMusic(buttonClickMusic, -1); // Play buttonClickMusic continuously
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Gestion des clics de souris
                 int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (startScreen) {
                    if (startButton.isClicked(mouseX, mouseY)) {
                        startScreen = false;
                        playScreen=true;
                    }
                } else if (subOptionsScreen) {
                        if (level1Button.isClicked(mouseX, mouseY)) {
                        level1Selected=true;
                        subOptionsScreen=false;
                    }else if (level2Button.isClicked(mouseX, mouseY)) {
                        level2Selected = true;
                        subOptionsScreen=false;
                    } else if (level3Button.isClicked(mouseX, mouseY)) {
                        level3Selected = true;
                        subOptionsScreen=false;
                    }else if (helpButton.isClicked(mouseX, mouseY)){help=true;}
                }else if (playScreen && !subOptionsScreen) {
                    if (playButton.isClicked(mouseX, mouseY)) {
                        subOptionsScreen = true;
                        playScreen=false;
                    } else if (quitButton.isClicked(mouseX, mouseY)) {
                        quit = true;
                    }
                }
                if(level1Selected&&view.isClicked(mouseX, mouseY)){crypt1=true;level1Selected=false;}
                if(level2Selected&&view.isClicked(mouseX, mouseY)){crypt2=true;level2Selected=false;}
                if(level3Selected&&view.isClicked(mouseX, mouseY)){crypt3=true;level3Selected=false;}
                if ((level1Selected || level2Selected || level3Selected||help) && backButton.isClicked(mouseX, mouseY)) {
                    subOptionsScreen = true;
                    playScreen=false;
                    level1Selected = false;
                    level2Selected = false;
                    level3Selected = false;
                    help=false;
                }else if(subOptionsScreen&&backButton.isClicked(mouseX, mouseY))
                {
                    subOptionsScreen = false;
                    playScreen=true;
                }
                if((gain1||gain2||gain3||lost)&&backButton.isClicked(mouseX, mouseY))
                {
                    subOptionsScreen = true;
                    playScreen=false;
                    gain1=false;
                    gain2=false;
                    gain3=false;
                    lost=false;
                }
                if(crypt1&&backButton.isClicked(mouseX, mouseY)){crypt1=false;level1Selected=true;}
                if(crypt2&&backButton.isClicked(mouseX, mouseY)){crypt2=false;level2Selected=true;}
                if(crypt3&&backButton.isClicked(mouseX, mouseY)){crypt3=false;level3Selected=true;}
                if ((backButton.isClicked(mouseX, mouseY))||(level1Button.isClicked(mouseX, mouseY))||
                    (level2Button.isClicked(mouseX, mouseY))||(level3Button.isClicked(mouseX, mouseY))
                    ||(playButton.isClicked(mouseX, mouseY))|| (startButton.isClicked(mouseX, mouseY)))
                    {
                        Mix_PlayMusic(buttonClickMusic1, 0);
                    }
                    else if((level1Selected)&&(music.isClicked(mouseX, mouseY)))
                    {
                        Mix_PlayMusic(buttonClickMusic2, -1);
                    }
                    else if((level2Selected)&&(music.isClicked(mouseX, mouseY)))
                    {
                        Mix_PlayMusic(buttonClickMusic3, -1);
                    }
                    else if((level3Selected)&&(music.isClicked(mouseX, mouseY)))
                    {
                        Mix_PlayMusic(buttonClickMusic4, -1);
                    }
            } else if (event.type == SDL_KEYDOWN) {
                // Gestion des touches du clavier pressées
                switch (event.key.keysym.sym) {
                    case SDLK_RETURN: // Touche "Enter" pressée
                        if (startScreen) {
                            startScreen = false;
                            playScreen=true; // Désactive l'écran de démarrage
                        }else if(playScreen){
                                playScreen=false;
                                subOptionsScreen=true;}
                        break;
                    case SDLK_ESCAPE: // Touche "Echap" pressée
                        if (playScreen) {
                            quit = true; // Quitte l'application
                        }
                        break;
                    case SDLK_LEFT:
                        if(level1Selected){
                        ch1+="l";
                        smurfX1 -= smurfSpeed1; // Move Smurf left
                        smurfLevel1.moveLeft(1000);} // Déplacer Smurf vers la gauche
                        else if(level2Selected){
                                ch2+="l";
                        smurfX2 -= smurfSpeed2; // Move Smurf left
                        smurfLevel2.moveLeft(1000);}
                        else if(level3Selected){
                            ch3+="l";
                        smurfX3 -= smurfSpeed3; // Move Smurf left
                        smurfLevel3.moveLeft(1000);}
                        break;
                    case SDLK_RIGHT:
                        if(level1Selected){
                        ch1+="r";
                        smurfX1 += smurfSpeed1; // Move Smurf right
                        smurfLevel1.moveRight(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level2Selected){
                                ch2+="r";
                        smurfX2 += smurfSpeed2; // Move Smurf right
                        smurfLevel2.moveRight(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level3Selected){
                            ch3+="r";
                        smurfX3 += smurfSpeed3; // Move Smurf right
                        smurfLevel3.moveRight(1000); // Déplacer Smurf vers la droite
                        }
                        break;
                        case SDLK_UP:
                        if(level1Selected){
                        ch1+="u";
                        smurfY1 -= smurfSpeed1;
                        smurfLevel1.moveJump(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level2Selected){
                            ch2+="u";
                        smurfY2 -= smurfSpeed2;
                        smurfLevel2.moveJump(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level3Selected){
                            ch3+="u";
                        smurfY3 -= smurfSpeed3;
                        smurfLevel3.moveJump(1000); // Déplacer Smurf vers la droite
                        }
                        break;
                        case SDLK_DOWN:
                        if(level1Selected){
                        ch1+="d";
                        smurfY1 += smurfSpeed1;
                        smurfLevel1.moveDown(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level2Selected){
                            ch2+="d";
                        smurfY2 += smurfSpeed2;
                        smurfLevel2.moveDown(1000); // Déplacer Smurf vers la droite
                        }
                        else if(level3Selected){
                            ch3+="d";
                        smurfY3 += smurfSpeed3;
                        smurfLevel3.moveDown(1000); // Déplacer Smurf vers la droite
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        SDL_RenderClear(renderer);
        // Ensure Smurf stays within the window bounds
        if (smurfX1 < 0) {
            smurfX1 = 0;
        }
        if (smurfY1 < 0) {
            smurfY1 = 0;
        }
        if (smurfY1 > 800 - smurfLevel1.getHeight()) {
            smurfY1 =800 - smurfLevel1.getHeight();
        }
        smurfLevel1.setX(smurfX1); // Update Smurf's X position
        smurfLevel1.setY(smurfY1); // Update Smurf's Y position
        // Ensure Smurf stays within the window bounds
        if (smurfX2 < 0) {
            smurfX2 = 0;
        }
        if (smurfY2 < 0) {
            smurfY2 = 0;
        }
        if (smurfY2 > 800 - smurfLevel2.getHeight()) {
            smurfY2 = 800 - smurfLevel2.getHeight();
        }
        smurfLevel2.setX(smurfX2); // Update Smurf's X position
        smurfLevel2.setY(smurfY2); // Update Smurf's Y position
        // Ensure Smurf stays within the window bounds
        if (smurfX3 < 0) {
            smurfX3 = 0;
        }
        if (smurfY3 < 0) {
            smurfY3 = 0;
        }
        if (smurfY3 > 800 - smurfLevel3.getHeight()) {
            smurfY3 = 800 - smurfLevel3.getHeight();
        }
        smurfLevel3.setX(smurfX3);
        smurfLevel3.setY(smurfY3);
        if (level1Selected)
        {if(checkCollision1(smurfLevel1,f1)||checkCollision1(smurfLevel1,f2)||checkCollision1(smurfLevel1,f3))
                    {smurfScore1=smurfScore1+1;
        }
           else if(checkCollision1(smurfLevel1,s1)||checkCollision1(smurfLevel1,s2)||checkCollision1(smurfLevel1,s3))
            {smurfScore1=smurfScore1-1;}
            if(smurfScore1<=0){lost=true;smurfScore1=100;level1Selected=false;smurfX1=5;smurfY1 = 570;}
            if(smurfX1>=1550){gain1=true;level1Selected=false;}
           }
        if (level2Selected)
        {if(checkCollision1(smurfLevel2,coin1)||checkCollision1(smurfLevel2,coin2))
                    {smurfScore2=smurfScore2+1;
        }
           else if(checkCollision1(smurfLevel2,c1)||checkCollision1(smurfLevel2,c2)||checkCollision1(smurfLevel2,c3)||checkCollision1(smurfLevel2,c4))
                {smurfScore2=smurfScore2-1; }
                  if(smurfScore2<=0){lost=true;level2Selected=false;smurfScore2=100;smurfX2=5;smurfY2 = 590;}
            if(smurfX2>=1550){gain2=true;level2Selected=false;}
                }
        if (level3Selected)
        {if(checkCollision1(smurfLevel3,coin3)||checkCollision1(smurfLevel3,coin2))
                    {smurfScore3=smurfScore3+1;}
           else if(checkCollision1(smurfLevel3,w1)||checkCollision1(smurfLevel3,w2)||checkCollision1(smurfLevel3,b1)||checkCollision1(smurfLevel3,b2)||checkCollision1(smurfLevel3,b3))
                {smurfScore3=smurfScore3-1;}
                  if(smurfScore3<=0){lost=true;level3Selected=false;smurfScore3=100;smurfX3=5;smurfY3 = 590;}
            if( smurfX3 >=1550) {
    gain3 = true;
    level3Selected = false;
}}

        // Render different screens based on the current state
        if (subOptionsScreen) {
            backgroundPlay.render(renderer);
            backButton.render(renderer);
            level1Button.render(renderer);
            level2Button.render(renderer);
            level3Button.render(renderer);
            helpButton.render(renderer);}
            // Check if any of the levels are selected and render accordingly
            if (level1Selected) {
                blackbackground.render(renderer);
                SDL_Color pinkColor = {180, 80, 100};
                backgroundOption1.update();
                backgroundOption1.render();
                renderText(renderer, "Welcome to LEVEL 1", 500, 70, boldFont, pinkColor);
                std::string scoreStr = "Score1: " + std::to_string(smurfScore1);

                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1200, 10, boldFont, pinkColor);
                f1.update(1);
                f1.render(renderer);
                s1.update(1);
                s1.render(renderer);
                f2.update(1);
                f2.render(renderer);
                s2.update(1);
                s2.render(renderer);
                f3.update(1);
                f3.render(renderer);
                s3.update(1);
                s3.render(renderer);
                o1.update(1); // Mettre à jour la pluie
                o1.render(renderer);
                smurfLevel1.render();
                music.render(renderer);
                backButton.render(renderer);
                view.render(renderer);

            } else if (level2Selected) {
                blackbackground.render(renderer);
                backgroundOption2.update();
                backgroundOption2.render();
                SDL_Color blueColor = { 0, 0, 255 };
                c1.update(1);
                c1.render(renderer);
                c3.update(1);
                c3.render(renderer);
                c2.update(1);
                c2.render(renderer);
                c4.update(1);
                c4.render(renderer);
                coin1.update(1);
                coin1.render(renderer);
                coin2.update(1);
                coin2.render(renderer);
                o.update(1); // Mettre à jour la pluie
                o.render(renderer);
                smurfLevel2.render();
                music.render(renderer);
                renderText(renderer, "Welcome to LEVEL 2", 500, 70, boldFont, blueColor);
                std::string scoreStr = "Score2: " + std::to_string(smurfScore2);
                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1200, 10, boldFont, blueColor);
                backButton.render(renderer);
                view.render(renderer);
        }
            else if (level3Selected) {
                blackbackground.render(renderer);
                backgroundOption3.update();
                backgroundOption3.render();
                SDL_Color redColor = { 255, 0, 0 };
                rain.update(1); // Mettre à jour la pluie
                rain.render(renderer);
                bat.update(1); // Mettre à jour la pluie
                bat.render(renderer);
                w1.update(1);
                w1.render(renderer);
                w2.update(1);
                w2.render(renderer);
                coin2.update(1);
                coin2.render(renderer);
                coin3.update(1);
                coin3.render(renderer);
                b1.update(1);
                b1.render(renderer);
                b2.update(1);
                b2.render(renderer);
                b3.update(1);
                b3.render(renderer);
                smurfLevel3.render();
                 music.render(renderer);
                 view.render(renderer);
                renderText(renderer, "Welcome to LEVEL 3", 500, 70, boldFont, redColor);
                std::string scoreStr = "Score3: " + std::to_string(smurfScore3);
                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1200, 10, boldFont, redColor);
                backButton.render(renderer);

        }
        if (crypt1){blackbackground.render(renderer);
                            backButton.render(renderer);
                            SDL_Color redColor = { 255, 0, 0 };
                renderText(renderer, "Message Crypté:",100 ,50, boldFont2, redColor);
                            SDL_Color whiteColor = {255, 255, 255};
                            renderText(renderer, ch1.c_str(), 100, 150,boldFont2, whiteColor);
                        }
     // Modifier les coordonnées selon vos besoins
if (crypt2){blackbackground.render(renderer);SDL_Color redColor = { 255, 0, 0 };
                renderText(renderer, "Message Crypté:",100,50, boldFont2, redColor);
                SDL_Color whiteColor = {255, 255, 255};
                            renderText(renderer, ch2.c_str(), 100, 150,boldFont2, whiteColor);
            backButton.render(renderer);}
 if (crypt3){blackbackground.render(renderer);SDL_Color redColor = { 255, 0, 0 };
                renderText(renderer, "Message Crypté:",100 ,50, boldFont2, redColor);
                SDL_Color whiteColor = {255, 255, 255};
                            renderText(renderer, ch3.c_str(), 100, 150,boldFont2, whiteColor);
                            backButton.render(renderer);}
         if(help){helpbackground.render(renderer);
            backButton.render(renderer);}

        if(lost)
            {
                lostbackground.render(renderer);
                backButton.render(renderer);
                SDL_Color redColor = { 255, 0, 0 };
                renderText(renderer, "Oops!",800 ,270, boldFont1, redColor);
                renderText(renderer, "You Lost!",790 ,340, boldFont1, redColor);
                renderText(renderer, "It is Okay",780,410, boldFont1, redColor);
                renderText(renderer, "Try Again",780,480, boldFont1, redColor);

        }
        if(gain1)
            {
                gainbackground.render(renderer);
                backButton.render(renderer);
                SDL_Color blueColor = { 0, 250, 20 };
                renderText(renderer, "Well Done!", 1000,320, boldFont1, blueColor);
                renderText(renderer, "You Win!", 1000,390, boldFont1, blueColor);
                std::string scoreStr = "Your score :" + std::to_string(smurfScore1);
                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1000, 460, boldFont1, blueColor);
                renderText(renderer, "Try An Other Level", 970,530, boldFont1, blueColor);
        }
        if(gain2)
            {
                 gainbackground.render(renderer);
                backButton.render(renderer);
                SDL_Color blueColor = { 0, 250, 20 };
                renderText(renderer, "Well Done!", 1000,320, boldFont1, blueColor);
                renderText(renderer, "You Win!", 1000,390, boldFont1, blueColor);
                std::string scoreStr = "Your score :" + std::to_string(smurfScore2);
                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1000, 460, boldFont1, blueColor);
                renderText(renderer, "Try An Other Level", 970,530, boldFont1, blueColor);
        }
        if(gain3)
            {
                gainbackground.render(renderer);
                backButton.render(renderer);
                SDL_Color blueColor = { 0, 250, 20 };
                renderText(renderer, "Well Done!", 1000,320, boldFont1, blueColor);
                renderText(renderer, "You Win!", 1000,390, boldFont1, blueColor);
                std::string scoreStr = "Your score :" + std::to_string(smurfScore3);
                // Afficher la chaîne de caractères contenant le score
                renderText(renderer, scoreStr.c_str(),1000, 460, boldFont1, blueColor);
                renderText(renderer, "Lets Start Again",970,530, boldFont1, blueColor);
        }
        // Render the start
        if (startScreen) {
            background.render(renderer);
            startButton.render(renderer);
            SDL_Color whiteColor = { 255, 255, 255 };
            renderText(renderer, "   Welcome to our game", 510,290, boldFont, whiteColor);
            renderText(renderer, "**Magic Forest**", 530, 350, boldFont, whiteColor);
            renderText(renderer, "     By Group one ", 570, 420, boldFont, whiteColor);
        } else if (playScreen) {
            background1.render(renderer);
            playButton.render(renderer);
            quitButton.render(renderer);
        }

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    ch1.clear();
     ch2.clear();
     ch3.clear();
    TTF_CloseFont(boldFont);
    Mix_FreeMusic(buttonClickMusic);
    Mix_FreeMusic(buttonClickMusic1);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
