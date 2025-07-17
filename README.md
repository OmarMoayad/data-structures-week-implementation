🧠 Implemented Data Structures
1. Dynamic Array
A resizable array that automatically grows when full.

Average Time Complexity: O(1) amortized

Worst Case: O(n) during resize

Space Complexity: O(n)

2. Singly Linked List
Each element (node) points to the next; allows dynamic memory allocation.

Time Complexity (Overall): O(n)

Space Complexity: O(n)

3. Stack using Array
A Last-In-First-Out (LIFO) stack using a dynamic array.

Average Time Complexity: O(1)

Worst Case: O(n) during resize

Space Complexity: O(n)

4. Stack using Linked List
LIFO stack implemented with linked list for constant time operations.

Time Complexity (All operations): O(1)

Space Complexity: O(n)

5. Queue using Linked List
A First-In-First-Out (FIFO) queue using a singly linked list.

Enqueue: O(1)

Dequeue: O(1)

Space Complexity: O(n)

6. Queue using Array
FIFO queue using an array with front and rear pointers.

Time Complexity: O(1) (excluding dynamic resizing)

Space Complexity: O(n)

7. Circular Linked List
A linked list where the last node points to the first.

Insert at position: O(n)

Delete/Search: O(n)

Space Complexity: O(n)

8. Doubly Linked List
Each node contains next and prev pointers for bidirectional traversal.

Insert/Delete at front/back: O(1)

Find/Remove by value: O(n)

Space Complexity: O(n)

9. Binary Tree
A general tree with at most two children per node. Supports:

Inorder Traversal: Left → Root → Right

Preorder Traversal: Root → Left → Right

Postorder Traversal: Left → Right → Root

Time Complexity (Traversal): O(n)

Space Complexity: O(n) due to recursion stack

📄 See: binarytree.cpp

10. Binary Search Tree (BST)
A binary tree where left subtree < root < right subtree.

Insert/Search/Delete (Average): O(log n)

Insert/Search/Delete (Worst - skewed tree): O(n)

Traversals (Inorder, Preorder, Postorder): O(n)

Space Complexity: O(n)

11. Hash Table with Chaining
Uses separate chaining (linked list or vector) to handle collisions.

Insert/Delete/Search (Average): O(1)

Insert/Delete/Search (Worst): O(n) — if many collisions

Collision Handling: ✅ via chaining

Hash Function Used: key % bucket_count

Space Complexity: O(n + m), where n is number of elements and m is number of buckets


12. Graph using Adjacency Matrix
A 2D matrix where matrix[i][j] = 1 if there is an edge from vertex i to j.

Edge Lookup: O(1)

Add/Delete Edge: O(1)

Space Complexity: O(V²)

13. Min Heap
A binary tree where the parent is always ≤ its children. The minimum element is always at the root.

Insert / Extract Min: O(log n)

Get Min: O(1)

Build Heap: O(n)

Space Complexity: O(n)
