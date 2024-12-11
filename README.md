Is Binary Tree BST (Please refer to the docx version of README for a better understanding)


Every node in a binary search tree holds the following properties:

The left subtree has nodes with values less than its own.
The right subtree has nodes with values greater than its own.
The left and right subtrees must also be Binary Search Trees.
Given the root node of a binary tree, determine whether it's a binary search tree.

is-binary-tree-bst
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with 1 or 0 based on whether the binary tree is a binary search tree or not respectively.

Sample Input
5
7
6 4 8 1 5 -1 12
3
6 -1 4
2
6 8
6
17 11 28 -1 -1 18
1
6
Expected Output
1
0
0
1
1