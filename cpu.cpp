#include "cpu.h"


void CPU::Init()
{
    this->SP = 0xff; //should be 0x01ff, but 01 is hardcoded
    this->setIFlag();
    this->PC = this->m.fetch_word(0xfffc);
}

void CPU::Execute(uint64_t cycles)
{
    while (cycles)
    {
        Byte code = this->m.fetch_byte(PC++);
        --cycles;
        switch (code)
        {
        case op_lda_imm:
        {
            Byte val = this->m.fetch_byte(PC++);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= 1;
            break;
        }
        case op_lda_zp:
        {
            Byte adr = this->m.fetch_byte(PC++);
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= 2;
            break;
        }
        case op_lda_zpx:
        {
            Byte adr = (this->m.fetch_byte(PC++) + this->XR) & 0xff;
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= 3;
            break;
        }
        case op_lda_ab:
        {
            Word adr = this->m.fetch_word(PC++);
            ++PC;
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= 3;
            break;
        }
        case op_lda_abx:
        {
            Byte low_addr = this->m.fetch_byte(PC);
            Word adr = (this->m.fetch_word(PC++) + this->XR) & 0xffff;
            ++PC;
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= ((low_addr + this->XR) & 0x100 ? 4 : 3);
            break;
        }
        case op_lda_aby:
        {
            Byte low_addr = this->m.fetch_byte(PC);
            Word adr = (this->m.fetch_word(PC++) + this->YR) & 0xffff;
            ++PC;
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= ((low_addr + this->YR) & 0x100 ? 4 : 3);
            break;
        }
        case op_lda_inx: //indexed-indirect x
        {
            Byte v = (this->m.fetch_byte(PC++) + this->XR) & 0xff;
            Word adr = this->m.fetch_word(v);
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= 5;
            break;
        }
        case op_lda_iny: //indirect-indexed y
        {

            Byte v = this->m.fetch_word(PC++);
            Byte low_addr = this->m.fetch_byte(v);
            Word adr = (this->m.fetch_word(v) + this->YR) & 0xffff;
            Byte val = this->m.fetch_byte(adr);
            this->AC = val;
            (val == 0) ? this->setZFlag() : this->clearZFlag();
            (val & 0x80) ? this->setNFlag() : this->clearNFlag();
            cycles -= ((low_addr + this->YR) & 0x100 ? 5 : 4);
            break;
        }
        default:
        {
        #ifdef DEBUG
            --cycles;
            std::cout << "Opcode is not detected: " << code << std::endl;
        #endif
            break;
        }
        }
    }
}

Byte CPU::getAC() const
{
    return AC;
}

void CPU::setAC(Byte newAC)
{
    AC = newAC;
}

Byte CPU::getXR() const
{
    return XR;
}

void CPU::setXR(Byte newXR)
{
    XR = newXR;
}

Byte CPU::getYR() const
{
    return YR;
}

void CPU::setYR(Byte newYR)
{
    YR = newYR;
}

Byte CPU::getSP() const
{
    return SP;
}

void CPU::setSP(Byte newSP)
{
    SP = newSP;
}

Word CPU::getPC() const
{
    return PC;
}

void CPU::setPC(Word newPC)
{
    PC = newPC;
}

void CPU::setCFlag()
{
    this->P[0] = 1;
}

void CPU::clearCFlag()
{
    this->P[0] = 0;
}

Byte CPU::getCFlag()
{
    return this->P[0];
}

void CPU::setZFlag()
{
    this->P[1] = 1;
}

void CPU::clearZFlag()
{
    this->P[1] = 0;
}

Byte CPU::getZFlag()
{
    return this->P[1];
}

void CPU::setIFlag()
{
    this->P[2] = 1;
}

void CPU::clearIFlag()
{
    this->P[2] = 0;
}

Byte CPU::getIFlag()
{
    return this->P[2];
}

void CPU::setDFlag()
{
    this->P[3] = 1;
}

void CPU::clearDFlag()
{
    this->P[3] = 0;
}

Byte CPU::getDFlag()
{
    return this->P[3];
}

void CPU::setBFlag()
{
    this->P[4] = 1;
}

void CPU::clearBFlag()
{
    this->P[4] = 0;
}

Byte CPU::getBFlag()
{
    return this->P[4];
}

void CPU::setVFlag()
{
    this->P[6] = 1;
}

void CPU::clearVFlag()
{
    this->P[6] = 0;
}

Byte CPU::getVFlag()
{
    return this->P[6];
}

void CPU::setNFlag()
{
    this->P[7] = 1;
}

void CPU::clearNFlag()
{
    this->P[7] = 0;
}

Byte CPU::getNFlag()
{
    return this->P[7];
}
