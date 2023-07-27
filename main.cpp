#include <iostream>
#include <SFML/Graphics.hpp>
#include<unistd.h>
#include <random>

int randomNumber (int min, int max) {
    static std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution (min, max);
    return distribution (generator);
}

sf::RenderWindow static window(sf::VideoMode(800, 600), "VisualizeAlgorithms");
int n = 80;
bool sorted = false;
float recHs[80];
unsigned int microsecond = 1000000;

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
            dispSort(j);
        }
        recHs[j + 1] = key;


    }
    usleep(microsecond*5);
    sorted = true;
    dispSort(i);
}

int main(){

    window.setFramerateLimit(FPS);

    for(int i=0; i<n; i++){
        recHs[i]=(rand()%500);
    }
    while(window.isOpen()){
        sf::Event event;


        while (window.pollEvent(event)){
            switch(event.type){

                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }
        if(!sorted){
            dispSort(0);
            insertionSort();
        }

    }

}
/*
int main() {
    for (int i = 0; i < n; i++) {
        recHs[i] = (randomNumber(0, 500));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
            }
        }
        if (!sorted) {
            dispSort(0);
            insertionSort();
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
 */