<H1> COP3530 - Project 3 Group 183 </h1>
Group Members: Gabriel Lemus, Jack Ozerovitch, Santiago Tovar

<h2> Steps to Execute Code </h2>

- [Step 1. Download GraphViz](https://graphviz.org/download/)
	- Make sure that during the install, you select Add to PATH for current user
- Step 2. Clone Repo
- Step 3. Paste the following into the terminal from the src folder of the repo
	- 'g++ main.cpp WalkMap.cpp BFS.cpp DFS.cpp -o main'
- Step 4. Execute the exe by typing './main'
	- Map size is how many points to generate (high amounts will take a long time to generate, 10 is the suggested value)
	- Number of connections is the max number of connections that a point can have
	- Enter source node as an integer from 0 to map size - 1
	- Enter the destination node as an integer greater than the source node, but still less than map size
- Step 5. bfs_graph.png and dfs_graph.png should have appeared in the src folder and contain a visual representation of their respective searches
