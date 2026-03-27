#include <stdio.h>
#include <stdlib.h>
#include "countwords.h"

#define LINESIZE 1024
 
int main () {
    FILE *file;
    struct queue *queue;
    char string[21];
    char w[MAX_WORD_LENGTH + 1];

    printf("Type the file name, including its extesion: ");
    scanf("%20s", string);
    printf("\n");

    file = fopen(string, "r");

    if (!file) {
        printf("Error: Not able to open file\n");
        return (1);
    }

    queue = createQueue();
    if (!queue) {
        return (1);
    }

    while (!feof(file)) {
        fscanf(file, "%s", w);
        
        if (addWord(w, queue) == 0) {
            increaseWordFrequency(w, queue);
        }
    }

    printMostFrequentWord(queue);
    return (0);
}