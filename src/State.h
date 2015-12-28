#ifndef STATE_H
#define STATE_H

#include <iostream>

struct PointerPack;
struct State {
    virtual ~State() { }
    virtual void run(PointerPack &pack) = 0;
};

#endif