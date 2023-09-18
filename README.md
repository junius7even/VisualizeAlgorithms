# VisualizeAlgorithms Summary
This project was inspired by the many videos on youtube demonstrating the visualization of sorting algorithms, so I decided to take a crack at it having finished an algorithms & data structures course from my previous semester using C++ and SFML.
![0917](https://github.com/junius7even/VisualizeAlgorithms/assets/33168288/91eeddb4-963e-4cfc-ac3d-cb222db557cc)

## Available algorithms
Currently, only one sorting algorithm is implemented, but in the future I plan to add more implementations of sorting algorithms that I've learned or will come across in the future.

## How it works
The "animation" is done by abusing the framerate limit that SFML windows provide, and with each step of the iterative sort(mostly) the screen will re-display all the elements of the array, who are attributed an "isSorted" property as a color code.

## Acknowledgements
Some common window events aren't handled by the main program such as resizing, and clicking the program in the midst of the sorting process will result in a windows prompt telling you the program isn't responding.

## Commands
Press R to randomize an array containing n = 80 elements. 

Press S to start the sort visualization process.
