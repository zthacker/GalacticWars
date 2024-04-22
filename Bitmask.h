//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_BITMASK_H
#define GALACTICWARS_BITMASK_H

#include <stdint.h>

class Bitmask {
public:
    Bitmask();

    void SetMask(Bitmask& other);
    uint32_t GetMask() const;

    bool GetBit(int pos) const;
    void SetBit(int pos, bool on);

    void SetBit(int pos);
    void ClearBit(int pos);

    void Clear();

private:
    uint32_t bits;
};


#endif //GALACTICWARS_BITMASK_H
