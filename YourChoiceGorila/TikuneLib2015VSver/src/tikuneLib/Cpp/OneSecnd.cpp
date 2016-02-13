#include "../ƒwƒbƒ_[/OneSecond.h"

void OneSecondCount::OneSecond()
{
    if (!isElapsed)
    {
        time += 1;
    }
    if (time >= ONE_SECOND)
    {
        time = 0;
        isElapsed = true;
    }
}