#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED
#include "vertex.h"
#include <limits>

// Później priority queue będzie wskazywać na Row
// na podstawie distance

// I zwykła indeksowana tablicy będzie wskazywać na Row,
// gdzie indeks 0 będzie oznaczać vertex 0.
// Ta tablica służy do zmiany distance w priority que
// gdy zajdzie taka potrzeba

struct Row
{
    bool visited = false;
    float distance = std::numeric_limits<float>::infinity(); // "infinity"
    int previous;
};

#endif // ROW_H_INCLUDED
