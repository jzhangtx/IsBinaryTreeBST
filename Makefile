IsBinaryTreeBST: IsBinaryTreeBST.o
	g++ -g -o IsBinaryTreeBST.exe IsBinaryTreeBST.o -pthread    

IsBinaryTreeBST.o: IsBinaryTreeBST/IsBinaryTreeBST.cpp
	g++ -g  -c -pthread IsBinaryTreeBST/IsBinaryTreeBST.cpp
