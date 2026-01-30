# CODTECH-C-Internship-2
COMPANY : CODTECH IT SOLUTIONS
NAME    : OM NARENDRA DOKHE
INTERN ID : CTIS1983
DOMAIN  : C LANGUAGE
DURATION : 4 WEEKS
MENTOR  : NEELA SANTOSH
OUTPUT  :


DESCRIPTION :
This task focuses on implementing a complete singly linked list data structure in the C programming language. Linked lists are one of the most fundamental and important concepts in Data Structures, widely used in real-world software development for dynamic memory management. Unlike arrays, which require fixed-size memory allocation, linked lists allow flexible and efficient memory usage by allocating nodes dynamically during runtime.

In this task, a singly linked list is created where each node contains two parts: the data value and a pointer to the next node. The program supports essential operations such as insertion, deletion, and traversal. A menu-driven interface is provided so the user can interact with the linked list easily and perform different operations based on their choice.

Insertion is implemented in multiple forms, such as inserting a node at the beginning, at the end, or at a specific position in the list. This demonstrates how pointers are used to adjust links between nodes without shifting elements, which is a major advantage of linked lists over arrays. Deletion operations are also implemented carefully, allowing removal of nodes from the beginning, end, or any specific value in the list. Proper pointer updates and memory deallocation using free() are handled to prevent memory leaks.

Traversal is another important feature included in this program. Traversal means visiting each node one by one and displaying the stored data. This helps in understanding how nodes are connected sequentially through pointers. The program ensures that edge cases such as empty list conditions, invalid positions, or deleting a non-existing node are handled properly, making the implementation more robust and professional.

This task was developed in C using dynamic memory allocation functions like malloc() and free(). These functions allow the program to allocate memory for each new node during runtime, which is the core concept behind linked list implementation. The project was written and tested on Windows 11 using Visual Studio Code as the primary editor. GCC compiler from MinGW-w64 was used to compile and execute the program through the integrated terminal.

Linked lists have wide applicability in real-world systems. They are used in operating systems for process scheduling, in memory management techniques, in implementing stacks and queues, in music playlist navigation, browser history tracking, and even in complex structures such as graphs and hash tables. Many applications rely on linked lists when frequent insertion and deletion operations are required, as these operations are more efficient compared to arrays.

This task provides strong practical knowledge of pointers, dynamic memory allocation, and structured programming in C. It builds a solid foundation for advanced data structures and helps students understand how real systems manage data dynamically. Overall, implementing a singly linked list is a key milestone for anyone learning programming and core computer science concepts.

Tools and Platform Used

Language: C
Compiler: GCC (MinGW-w64)
Editor: Visual Studio Code
Operating System: Windows 11

Commands to Compile and Run

Open the VS Code terminal in the folder containing the file and execute:

gcc task2.c -o task2
.\task2.exe
