# kchiu6-bjwong3-ayxu2
This is the final project for Kyle Chiu, Brandon Wong, and Anthony Xu. <br/>This program uses the openflights data to be used for getting needed airports for airlines, shortest distance from one airport to another, and a breadth first search of the entire airport graph. 

## Build Instructions
Make sure you are in the same folder as the `Makefile`. Run `make clean` to ensure that no junk files are left over. After, run `make` to compile the program. Once it finishes, it should produce an executable named `final_project`. Run this program by running `./final_project` in the terminal. <br/>
Alternatively, if you want to build and run our tests, run `make clean` to get rid of any junk files (this will also delete any executables, including the "final_project" executable). Then run `make test` to create the test executable, which you can run with `./test` in the terminal.

## How To Use
### Loading Data
When the program is first run, it will ask for the path of the airport data, the airline data, and the route data (in that order). You will need to type the path to that folder (e.g. the data is in the data folder, so you would put `data/FILENAME`). If all files are found, the program will create the graph and you will be able to run any of the listed commands: `airlineNeeded`, `allNeeded`, `shortestDist`, `bfs`, or `exit`.

### Using The Functions
#### airlineNeeded and allNeeded
These two functions get the needed airports for an airline or multiple airlines. <br/>
What does "needed airport" mean? Every airline is available at different airports. For example, Delta Airlines might be available at one airport but not another. So a needed airport is an airport that an airline is currently available there, but there is no way for that same airline customer to get there using the same airline. This translates to a strongly connected component that has no in-bound edges. Since it has no in-bound edges, no airplane from that airline can get to that airport. So getting needed airports allows an airline to find which routes they need to add for maximum availability to their customers.<br/>
These two commands basically do the exact same thing, except `airlineNeeded` gets all the needed airports for a user-chosen airline, and `allNeeded` gets all the needed airports for every single airline given in the data file. The results of the data will be exported to a text file (file name will be printed in terminal). 

#### shortestDist
This function finds the shortest path and distance between two airports using dijkstras algorithm. First, the user inputs a starting airport based on its IACO/IATA code, which will build the dijkstras graph. Then the user will input the destination airport which will output the shortest path of airports and shortest distance in kilometers into "dijkstra.txt". The user can choose to continue inputting destination airports or input "back" to go back to the function menu.

#### bfs
This function prints out a list of airports that makes up the full path traversal following the BFS algorithm on to the terminal starting from the first airport defined in the data set, distinguishing which airports are connected and which ones aren't. It will then export the path into "BFS.txt" and return to the function menu.

#### exit
Simply exits the program. 

### Doxygen
Doxygen documentation for our project is included in the `doxygen` folder.

####
Presentation Link: https://youtu.be/N2JOwp6n_j8
