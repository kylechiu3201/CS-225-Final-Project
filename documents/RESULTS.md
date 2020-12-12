# Results
## The Data
The breadth first search data is available in `REPLACE WITH FILE NAME OF BFS DATA`. The shortest path data is available in `dijkstras.txt`. The strongly connected components data is available in `allAirlinesNeeded.txt`. 
## Outcome Of Project
Results were fine besides the Tarjan's hiccup.
## Discoveries Made
### BFS Discoveries
Going through the traversal revealed routes with empty airports in our implementation of the graph, causing a default vertex to be placed in when using real world data. Smaller data sets with more thought out routes work fine however and the traversal still goes through all airports regardless.
### Strongly Connected Components Discoveries
While there weren't any shocking discoveries, I was a bit surprised at how many airports did not have any vertices with an in-degree of zero, which is good since this means that they have wide availability for their customers. 
## Individual Results
### BFS Results
The function is able to fully traverse the graph using the BFS algorithm. It is able to show which airports are connected while it is traversed and makes sure to account for all vertices even if some aren't connected by edges.
### Shortest Path Results
The shortestDist function turned out pretty well. It does what we intended it to do by outputing the shortest path between two airports into a text file. By including a visited unordered_map, we were also able to minimize running time of the function. 
### Strongly Connected Components Results
Although we weren't able to get the strongly connected components, we were able to get all vertices with an in-degree of zero, meaning that we have all airports of a chosen airline of which there is no way to get to that airport via that same chosen airline.<br/>
So with this, we were able to get a list of all airlines along with a list of all airports that each respective airline needs to add a route to in order to maximize the airline's availability to their customers.
