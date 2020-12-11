# kchiu6-bjwong3-ayxu2
Final Project
nice

## Build Instructions
Make sure you are in the same folder as the `Makefile`. Run `make`. Once it finishes, it should produce an executable named `final_project`. Run this program by running `./final_project` in the terminal. 
## How To Use
### Loading Data
When the program is first run, it will ask for the path of the airport data, the airline data, and the route data (in that order). You will need to type the path to that folder (e.g. the data is in the data folder, so you would put `data/FILENAME`). If all files are found, the program will create the graph and you will be able to run any of the listed commands: `airlineNeeded`, `allNeeded`, `shortestDist`, `bfs`, or `exit`.
### Using The Functions
##### airlineNeeded and allNeeded
These two functions get the needed airports for an airline or multiple airlines. <br/><br/>
What does "needed airport" mean? Every airline is available at different airports. For example, Delta Airlines might be available at one airport but not another. So a needed airport is an airport that an airline is currently available there, but there is no way for that same airline customer to get there using the same airline. This translates to a strongly connected component that has no in-bound edges. Since it has no in-bound edges, no airplane from that airline can get to that airport. So getting needed airports allows an airline to find which routes they need to add for maximum availability to their customers.<br/><br/>
These two commands basically do the exact same thing, except `airlineNeeded` gets all the needed airports for a user-chosen airline, and `allNeeded` gets all the needed airports for every single airline given in the data file. The results of the data will be exported to a text file (file name will be printed in terminal). 
##### shortestDist

##### bfs

##### exit
Simply exits the program. 
