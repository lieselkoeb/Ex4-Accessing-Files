#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countwords.h"

struct queue * createQueue() {
    struct queue *q;

    if (!(q = calloc(1,sizeof(struct queue)))) {
        return NULL;
    }

    return q;
}

struct wordFrequency * createWordFrequency() {
    struct wordFrequency *w;

    if (!(w = calloc(1, sizeof (struct wordFrequency)))) {
        return NULL;
    }

    return w;
}

int addWord(char * string, struct queue * queue) {
    int wiq;
    struct wordFrequency *w;

    if ((!string) || (!queue)) {
        return -1;
    }
    
    wiq = wordInQueue(string, queue);

    if (wiq > 0) {
        return 0; // Word is already in the queue
    }
    if (wiq < 0) {
        return -1; // Invalid pointer or error
    }

    w = createWordFrequency();
    if (!w) {
        return -1;
    }

    w->frequency = 1;
    w->word = strdup(string);
    if (!w->word) {
        free(w);
        return -1; 
    }

    // EMPTY QUEUE
    if (queue->size == 0) {
        queue->beg = w;
    }
    else {
        queue->end->next = w;
        w->prev = queue->end;
    }
    
    queue->end = w;
    queue->size++;

    return 1;
}

int wordInQueue(char * string, struct queue * queue) {
    int i, equal;
    char * word;
    struct wordFrequency * w;

    if ((!string) || (!queue)) {
        return -1;
    }
    
    w = queue->beg;
    if (!w) { // EMPTY QUEUE
        return 0;
    }
    
    word = w->word;
    for (i = 0; i < queue->size; i++) {
        equal = strcmp(word, string);
        if (equal == 0) {
            return w->frequency;
        }
        w = w->next;
        if (w != NULL) {
            word = w->word;
        }
    }

    return 0;
}

int increaseWordFrequency(char * string, struct queue * queue) {
    int wiq, equal;
    struct wordFrequency *w;
    char *word;

    if ((!string) || (!queue)) {
        return -1;
    }
    
    wiq = wordInQueue(string, queue);

    if (wiq == 0) {
        return 0; // Word is not in the queue
    }
    if (wiq < 0) {
        return -1; // Invalid pointer or error
    }

    w = queue->beg;
    if (!w) { // EMPTY QUEUE
        return 0;
    }

    while (w) {
        word = w->word;
        equal = strcmp(word, string);
        if (equal == 0) {
            w->frequency++;
            return w->frequency;
        }
        w = w->next;
    }

    return 0;
}


void printQueue (struct queue *q) {
    int i;
    struct wordFrequency *w;

    if (!q) {
        return;
    }
    if (!q->beg) {
        return;
    }

    w = q->beg;
    for (i = 0; i < q->size; i++) {
        printf("%s: %d, ", w->word, w->frequency);
        w = w->next;
    }

    printf("\n");
}