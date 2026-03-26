#include <stdio.h>
#include <stdlib.h>
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
