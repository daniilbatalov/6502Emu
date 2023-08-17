#include "memory_ram.h"

Memory::Memory()
{
    this->data.resize(MEM_LIM);

    std::fill(this->data.begin(), this->data.end(), 0);
}

Byte Memory::fetch_byte(Word adr)
{
    return data[adr];
}

Word Memory::fetch_word(Word adr)
{
    Word tmp = (data[adr + 1] << 8);
    tmp |= data[adr];
    return tmp;
}

void Memory::write_byte(Byte val, Word adr)
{
    data[adr] = val;
#ifdef DEBUG
    std::cout << "Value at address " << std::hex << adr << " is set to " << (int)data[adr] << std::endl;
#endif
}

void Memory::write_word(Word val, Word adr)
{
    Byte lsb = val & 0xff;
    Byte msb = val >> 8;
    data[adr] = lsb;
    data[adr + 1] = msb;

#ifdef DEBUG
    std::cout << "Value at address " << std::hex << adr << " is set to " << (int)data[adr] << std::endl;
    std::cout << "Value at address " << std::hex << adr + 1 << " is set to " << (int)data[adr + 1] << std::endl;
#endif
}

