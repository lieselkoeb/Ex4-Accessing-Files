#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countwords.h"

/* FOWARD DECLARATIONS */


/* LOCAL FUNCTIONS */

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
        printf("%s, ", w->word);
        w = w->next;
    }

    printf("\n");
}

/* FUNCTIONS */

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

    if (!wiq) {
        return 0; // Word is already in the queue, invalid pointer or error
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

struct wordFrequency * wordInQueue(char * string, struct queue * queue) {
    int i, equal;
    char * word;
    struct wordFrequency * w;

    if ((!string) || (!queue)) {
        return NULL;
    }
    
    w = queue->beg;
    if (w != NULL) {
        word = w->word;
    }
    
    for (i = 0; i < queue->size; i++) {
        equal = strcmp(word, string);
        if (equal == 0) {
            return w;
        }
        w = w->next;
        if (w != NULL) {
            word = w->word;
        }
    }

    return NULL;
}
