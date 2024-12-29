# Ecosystem-Simulation

### University project for Object Oriented Programming classes

### Idea
We tried to simulate small ecosystem in which we have herbivore and carnivore animals. Herbivore animals eat grass, which is randomly generated on the map.
Carnivore animals eat meat which is created when any animal dies. Also carnivore animals are able to attack herbivore animals.
Simulation is based on a grid map with turn based movement.

### Details
- Written in C++, with additional plot creation in Python
- Includes complex OOP code structure
- Has Unit tests (we used GTest)
- Visualization with SFML
- Memory safe implementation

### Statistics
After specified number of turns the simulation ends and statistics are written to the statistics.csv file
##### Plot we have generated with acquired data
![statistics_plot](https://github.com/user-attachments/assets/e7335ee5-30f4-4f23-a5c7-cea5942cb57c)


### Execution
- Requires CMake with version at least 3.22
- Requires SFML, however CMake should download it and build it automatically
- To change parameters of the simulation one can edit settings.csv file. It is advised to only change existing values, because otherwise unexpected errors may happen

### Creators
- Jakub Adamski 160291
- Piotr Franc ehm 160306
- Piotr Foltyniewicz 160295

