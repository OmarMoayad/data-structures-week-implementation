🧠 Implemented Data Structures
1. Dynamic Array
A resizable array that automatically grows when full.

Average Time Complexity: O(1) amortized

Worst Case: O(n) during resize

Space Complexity: O(n)

[ 5 | 7 | 9 | _ | _ ]  <-- capacity 5, size 3
When full, resize to bigger array and copy elements

2. Singly Linked List
Each element (node) points to the next; allows dynamic memory allocation.

Time Complexity (Overall): O(n)

Space Complexity: O(n)

[5] -> [7] -> [9] -> nullptr
Each node points to next node

3. Stack using Array
A Last-In-First-Out (LIFO) stack using a dynamic array.

Average Time Complexity: O(1)

Worst Case: O(n) during resize

Space Complexity: O(n)

Top -> [9]
        [7]
        [5]
Stack grows upwards in array
Push and pop from top

4. Stack using Linked List
LIFO stack implemented with linked list for constant time operations.

Time Complexity (All operations): O(1)

Space Complexity: O(n)

Top -> [9] -> [7] -> [5] -> nullptr
Push and pop at head node

5. Queue using Linked List
A First-In-First-Out (FIFO) queue using a singly linked list.

Enqueue: O(1)

Dequeue: O(1)

Space Complexity: O(n)

Front -> [5] -> [7] -> [9] -> nullptr <- Rear
Enqueue at rear, Dequeue at front

6. Queue using Array
FIFO queue using an array with front and rear pointers.

Time Complexity: O(1) (excluding dynamic resizing)

Space Complexity: O(n)

Array: [7, 9, _, 5, 6]
Front -> index 3
Rear -> index 1
Wraps around when rear reaches end

7. Circular Linked List
A linked list where the last node points to the first.

Insert at position: O(n)

Delete/Search: O(n)

Space Complexity: O(n)

[5] -> [7] -> [9] --+
   ^                |
   +----------------+
Last node points back to first

8. Doubly Linked List
Each node contains next and prev pointers for bidirectional traversal.

Insert/Delete at front/back: O(1)

Find/Remove by value: O(n)

Space Complexity: O(n)

nullptr <- [5] <-> [7] <-> [9] -> nullptr
Each node has prev and next pointers

9. Binary Tree
A general tree with at most two children per node. Supports:

Inorder Traversal: Left → Root → Right

Preorder Traversal: Root → Left → Right

Postorder Traversal: Left → Right → Root

Time Complexity (Traversal): O(n)

Space Complexity: O(n) due to recursion stack

        5
       / \
      3   7
     / \   \
    2   4   9

Traversal orders:
- Inorder: 2 3 4 5 7 9
- Preorder: 5 3 2 4 7 9
- Postorder: 2 4 3 9 7 5


10. Binary Search Tree (BST)
A binary tree where left subtree < root < right subtree.

Insert/Search/Delete (Average): O(log n)

Insert/Search/Delete (Worst - skewed tree): O(n)

Traversals (Inorder, Preorder, Postorder): O(n)

Space Complexity: O(n)

        10
       /  \
      5    15
     / \     \
    2   7     20

Left subtree < root < right subtree

11. Hash Table with Chaining
Uses separate chaining (linked list or vector) to handle collisions.

Insert/Delete/Search (Average): O(1)

Insert/Delete/Search (Worst): O(n) — if many collisions

Collision Handling: ✅ via chaining

Hash Function Used: key % bucket_count

Space Complexity: O(n + m), where n is number of elements and m is number of buckets

Buckets:
0 -> [15] -> [25]
1 -> nullptr
2 -> [2]
3 -> [13] -> [23]
4 -> nullptr

Keys hashed by key % bucket_count (5)


12. Graph using Adjacency Matrix
A 2D matrix where matrix[i][j] = 1 if there is an edge from vertex i to j.

Edge Lookup: O(1)

Add/Delete Edge: O(1)

Space Complexity: O(V²)

Vertices: 0,1,2

Adjacency Matrix:
   0 1 2
0 [0 1 0]
1 [1 0 1]
2 [0 1 0]

Edge exists if matrix[i][j] = 1

13. Min Heap
A binary tree where the parent is always ≤ its children. The minimum element is always at the root.

Insert / Extract Min: O(log n)

Get Min: O(1)

Build Heap: O(n)

Space Complexity: O(n)

        2
       / \
      5   7
     / \
    9   10

Parent ≤ children property maintained

14. Trie (Prefix Tree)
    
Tree structure storing strings by prefix.

Insert/Search/Delete: O(m), m = key length

BFS & DFS traversals implemented to explore nodes and print words

Space: O(n * alphabet_size)

root
 |
 h
 | \
 e  i
 |   \
 l    l
 | \    \
 l  p    u
 |       |
 o       m

Words stored: "hell", "help", "helium", "hello"

15. Union-Find (Disjoint Set)

Structure for grouping elements into disjoint sets.

Find/Union: Amortized O(α(n)) (Inverse Ackermann function)

Space: O(n)

Sets represented as trees:

1) 1--2--3  (root 1)
2) 4--5     (root 4)
3) 6        (root 6)

Union merges trees, Find returns root
