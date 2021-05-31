#pragma once

#include <mutex>

#include "cell.h"

#define width  50 /* Width of field */
#define height 50 /* Height of field */

typedef Cell field_t[width][height];

extern field_t field;
extern std::mutex field_mutex;

/* Fill field with random cells */
void field_fill();
