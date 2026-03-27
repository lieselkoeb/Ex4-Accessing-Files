#ifndef __COUNTWORDS__
#define __COUNTWORDS__
#define MAX_WORD_LENGTH 100

// Doubly linked list node that stores a word and its frequency.
struct wordFrequency {
    int frequency;                 // Number of occurrences of the word
    char *word;                    // The word itself (string)
    struct wordFrequency *next;    // Pointer to next node
    struct wordFrequency *prev;    // Pointer to previous node
};

// Queue structure (implemented as a doubly linked list).
struct queue {
    int size;                      // Number of elements in the queue
    struct wordFrequency *beg;     // Pointer to the first element
    struct wordFrequency *end;     // Pointer to the last element
};

// Creates and initializes a new queue.
struct queue * createQueue();

// Creates and initializes a new wordFrequency node.
struct wordFrequency * createWordFrequency();

// Frees the queue memory and its nodes.
void destroyQueue(struct queue *q);

// Frees a wordFrequency node.
void destroyWordFrequency(struct wordFrequency * w);

// Adds a word to the queue and set its frequency to 1.
// Returns 1 on success.
// Returns 0 if the word is already in the queue (no changes made).
// Returns -1 if there is an invalid pointer or another error.
int addWord(char * string, struct queue * queue);

// Removes a word from the queue and destroys it.
// Returns 1 on success.
// Returns 0 if the word is not in the queue.
// Returns -1 if there is an invalid pointer or another error.
int removeWord(char * string, struct queue * queue);

// Increases the frequency of a word by 1.
// Returns the updated frequency.
// Returns 0 if the word is not in the queue (no changes made).
// Returns -1 if there is an invalid pointer or another error.
int increaseWordFrequency(char * string, struct queue * queue);

// Decreases the frequency of a word by 1.
// If the frequency reaches 0, the word is removed from the queue.
// Returns the updated frequency.
// Returns 0 if the word was removed.
// Returns -1 if there is an invalid pointer or another error.
int decreaseWordFrequency(char * string, struct queue * queue);

// Returns the frequency of a word in the queue.
// Returns 0 if the word is not in the queue.
// Returns -1 if there is an invalid pointer or another error.
int wordInQueue(char * string, struct queue * queue);

// Prints the queue
void printQueue (struct queue *q);
#endif