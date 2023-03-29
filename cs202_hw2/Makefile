hw1: main.o BST.o BSTNode.o analysis.o
	g++ main.o BST.o BSTNode.o analysis.o -o hw2

main.o: main.cpp
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

analysis.o: analysis.cpp analysis.h
	g++ -c analysis.cpp

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c BSTNode.cpp

clean: 
	rm *.o hw2