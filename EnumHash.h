//
// Created by zthacker on 4/20/2024.
//

#ifndef GALACTICWARS_ENUMHASH_H
#define GALACTICWARS_ENUMHASH_H

#include <iostream>

struct EnumHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

#endif //GALACTICWARS_ENUMHASH_H
