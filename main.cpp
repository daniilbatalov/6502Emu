#include <iostream>

#include "cpu.h"


int main()
{
    Memory m;

    //start - inline test code
    m.write_word(0x0001, 0xfffc);
    m.write_byte(op_lda_imm, 0x0001);
    m.write_byte(0x52, 0x0002);
    //end - inline test code
    CPU c(m);
    c.Init();
    c.Execute(2);
    std::cout << "AC is " << std::hex << (int) c.getAC() << std::endl;
    return 0;
}
