#include "fun.h"
#include <iostream>

int coord_of_points(char *s, int *points) { //получаем индексы точек, которые разделяют предложения
    int ind = 0, sz = std::strlen(s);
    for (int i = 0; i < sz; ++i) {
        if (s[i] == '.') {
            points[ind] = i;
            ++ind;
        }
    }
    return ind;
}

int* lens_of_sentens(int *points, int sz) { //считаем размер всех предложений, зная индексы точек, окружающие его
    int *lens = new int [sz];
    if (sz > 0) {
        lens[0] = points[0];
        for (int i = 1; i < sz; ++i) {
            lens[i] = (points[i] - points[i - 1] - 2);
        }
    }
    return lens;
}

int* coord_of_spaces(char *max_sent, int spaces_cnt, int sz) { //получаем индексы пробелов в максимально длинном предложении
    int *spaces = new int [spaces_cnt];
    int temp_cnt = 0;
    for (int i = 0; i < sz; ++i) {
        if (max_sent[i] == ' ') {
            spaces[temp_cnt] = i;
            ++temp_cnt;
        }
    }
    return spaces;
}