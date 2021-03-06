# DS_Common

Welcome to Data structure common. This repo is my implementation based on ["Fundamentals of Data Structures in C++ /2e"](https://www.tenlong.com.tw/products/9780929306377),from Ellis Horowitz, etc.

##Motivation
Practice is the best way to confirm what you have learnt.

## Environment
+ C++11
+ gtest 
+ visual studio 2015

## Chapters
1. Introduction
2. Array
3. Stack and Queue
4. Linked list
5. Tree
	1. introduction
	2. Binary tree
	3. Traversal of binary trees
	4. More opeartions
	5. Threaded bionary tree
	6. [Heaps](test/src/queue/TestPriorityQueue.cpp)
6. Graph
	1. introduction
	2. basic graph operation
		1. [6.2.1 Depth first search](test/src/graph/TestMatrixWDigraph.cpp)
		2. [6.2.2 Breadth first search](test/src/graph/TestMatrixWDigraph.cpp)
		3. [6.2.3 Components](test/src/graph/TestMatrixWDigraph.cpp)
	3. minimal cost spanning tree
		1. [6.3.1 Kruskal](test/src/graph/TestMatrixWGraph.cpp)
		2. [6.3.2 Prim](test/src/graph/TestMatrixWGraph.cpp)
		3. 6.3.3 Sollin
	4. Shortest path and transitive closure
		1. [6.4.1 Dijkstras: single src, all dest, no negative weight](test/src/graph/TestMatrixWDigraph.cpp)
		2. [6.4.2 BellmanFord: single src, all dest, general weight](test/src/graph/TestMatrixWDigraph.cpp)
		3. [6.4.3 all pairs shortest path](test/src/graph/TestMatrixWDigraph.cpp)
		4. transitive closure
	5. Activity networks
		1. [6.5.1 activity on vertex, AOV, TopologicalOrder](test/src/graph/TestMatrixWDigraph.cpp)
		2. activity on edge, AOE
7. Sort
8. Hashing
9. Priority Queue
10. High priority bionary search tree
11. multi-path search tree
12. Appendix: Others
	1. Set
		1. [Disjoint Set in Array](test/src/set/TestDisjointSetArray.cpp)


## Licenses
MIT License
