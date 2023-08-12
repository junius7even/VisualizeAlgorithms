#include <iostream>
#include <SFML/Graphics.hpp>
#include<unistd.h>
#include <random>

int FPS = 120;

int randomNumber (int min, int max) {
    static std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution (min, max);
    return distribution (generator);
}

const int windowWidth = 12 * 80;
const int windowHeight = 600;

sf::Clock deltaClock;

sf::RenderWindow static window(sf::VideoMode(windowWidth, windowHeight), "VisualizeAlgorithms");
int n = 80;
bool sorted = false;
float recHs[80];
unsigned int microsecond = 1000000;
bool isSorting = false;

static void dispSort(int index){
    window.clear();
    for(int i=0; i<n; i++){
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i*12, 600-recHs[i]);
        block.setFillColor(sorted || i==index? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
    window.display();
}

void DrawArray(bool isSorting = false, int index = -1) {
    if (isSorting)
        window.clear();
    for (int i = 0; i < sizeof(recHs); i++){
        sf::RectangleShape rectToDraw(sf::Vector2f(10, recHs[i]));
        rectToDraw.setPosition(i * 12, windowHeight - recHs[i]);
        rectToDraw.setFillColor(sorted || i == index? sf::Color::Green : sf::Color::White);
        window.draw(rectToDraw);
    }
    if (isSorting)
        window.display();
}

void RandomizeArray() {
    for (int i = 0; i < 80; i++) {
        recHs[i] = randomNumber(0, 500);
    }
}

// Generic sorting algorithm
// Draw the array after sorting each step. Speed of displaying the sort is regulated by the allowed FPS of the sfml window.
void insertionSort()
{
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = recHs[i];
        j = i - 1;

        while (j >= 0 && recHs[j] > key)
        {
            recHs[j + 1] = recHs[j];
            j = j - 1;
            DrawArray(true, j);
        }
        recHs[j + 1] = key;
    }
}

//void DrawSortedArray() {
//    int hasDrawnGreen[n];
//    for (int j = 0; j < sizeof(recHs); j++) {
//        window.clear();
//        hasDrawnGreen[j] = true;
//        for (int i = 0; i < sizeof(recHs); i++){
//            sf::RectangleShape rectToDraw(sf::Vector2f(10, recHs[i]));
//            rectToDraw.setPosition(i * 12, windowHeight - recHs[i]);
//            rectToDraw.setFillColor(hasDrawnGreen[i] ? sf::Color::Green : sf::Color::White);
//            window.draw(rectToDraw);
//        }
//        window.display();
//    }
//}

// Procedure:
// Step 1: Sort ONE step at a time.
// Step 2: Draw the array at that instant. Display for an amount of time (dictated by deltatime) before sorting the next entry
// Step 3: Repeat the above in that order.
void StartSortAnimation() {
    insertionSort();
    sorted = true;
    isSorting = false;
    // DrawSortedArray();
}

int main(){
    // Caps the display speed of the sorting algo
    window.setFramerateLimit(FPS);

    for(int i=0; i<n; i++){
        recHs[i]=(rand()%500);
    }
    while(window.isOpen()){
        sf::Time deltaTime = deltaClock.restart();
        std::cout<<"Deltatime: "<<deltaTime.asSeconds()<<std::endl;
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){

                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            RandomizeArray();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sorted = false;
            isSorting = true;
            StartSortAnimation();
        }
        //window.draw();
        DrawArray();
        if (!isSorting)
            window.display();
        // Draw first then display everything last
    }
}

