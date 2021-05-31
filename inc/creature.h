#pragma once

#include <vector>
#include <thread>
#include "../inc/direction.h"

#define capacity 256 /* Capacity of buffer that contains creature's code  */

struct Creature {
    u8 x;                /* x position  [0; width  - 1] */
    u8 y;                /* y position  [0; height - 1] */
    u8 health;           /* health [0; 255] */
    u8 code[capacity];   /* brains */
    std::thread handler; /* thread that watches after creature */

    Creature(u8 x, u8 y);
    void move(Direction direction);
    void kill();
    bool alive() const;
};

/* List of all creatures */
extern std::vector <Creature> creatures;
