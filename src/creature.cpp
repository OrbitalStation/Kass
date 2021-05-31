
#include <SFML/System/Sleep.hpp>

#include "../inc/creature.h"
#include "../inc/field.h"
#include "../inc/random.h"

std::vector <Creature> creatures;

void creature_handler(Creature &ward) {
    sf::sleep(sf::seconds(1));
    ward.kill();
}

Creature::Creature(u8 x, u8 y): x(x), y(y), health(255) { // NOLINT(cppcoreguidelines-pro-type-member-init)
    //for (u64 i = 0; i < capacity / sizeof(u32); ++i) ((u32 *) code)[i] = mersenne();
    handler = std::thread(creature_handler, std::ref(*this));
    sf::sleep(sf::milliseconds(100));
}

void Creature::move(Direction direction) {
    switch (direction) {
        case Up:
            if (y != 0 and field[x][y - 1] == Void) {
        field[x][y--] = Void;
        field[x][y] = Alive;
    }
            break;
        case Right:
            if (x != (width - 1) and field[x + 1][y] == Void) {
        field[x++][y] = Void;
        field[x][y] = Alive;
    }
            break;
        case Down:
            if (y != (height - 1) and field[x][y + 1] == Void) {
        field[x][y++] = Void;
        field[x][y] = Alive;
    }
            break;
        case Left:
            if (x != 0 and field[x - 1][y] == Void) {
        field[x--][y] = Void;
        field[x][y] = Alive;
    }
            break;
    }
}

void Creature::kill() {
    field_mutex.lock();
    health = 0;
    field[x][y] = Void;
    field_mutex.unlock();
}

bool Creature::alive() const {
    return health != 0;
}
