#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED
#include "vertex.h"

// Później priority queue będzie wskazywać na Row
// na podstawie distance

// I zwykła indeksowana tablicy będzie wskazywać na Row,
// gdzie indeks 0 będzie oznaczać vertex 0.
// Ta tablica służy do zmiany distance w priority que
// gdy zajdzie taka potrzeba

struct Row
{
    bool visited = false;
    int distance = INT_MAX; // "infinity"
    int previous;
};

#endif // ROW_H_INCLUDED
