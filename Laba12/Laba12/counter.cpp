#include "counter.h"

Counter::Counter()
{
}

int Counter::getCount()
{
    return ++Count;
}

int Counter::Count = 0;
