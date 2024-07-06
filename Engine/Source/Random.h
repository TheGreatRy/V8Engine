#pragma once
#include <random>

int random() { return rand(); }
int random(unsigned int max) { return rand() % max; }
int random(int min, int max) { return min + random(max - min); }

float randomf() { return rand() / (float)RAND_MAX; }//0-1
float randomf(float max) { return max + randomf(); }//scaler
float randomf(float min, float max) { return min + randomf(max + min); }
