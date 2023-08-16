#ifndef MEMORY_H
#define MEMORY_H

#include "aliases.h"
#include <iostream>
#include <vector>

class Memory
{

private:
    static constexpr uint32_t MEM_LIM = 1024 * 64;
    std::vector<Byte> data;


public:
    Memory();
    Byte fetch_byte(Word adr);
    Word fetch_word(Word adr);
    void write_byte(Byte val, Word adr);
    void write_word(Word val, Word adr);



};

#endif // MEMORY_H
