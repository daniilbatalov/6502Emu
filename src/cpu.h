#ifndef CPU_H
#define CPU_H

#include "aliases.h"
#include "memory_ram.h"
#include "opcodes.h"

class CPU
{
public:
    CPU(Memory& mem) : m{mem} {}
    void Init();
    void Execute (uint64_t cycles);

    Byte getAC() const;
    void setAC(Byte newAC);
    Byte getXR() const;
    void setXR(Byte newXR);
    Byte getYR() const;
    void setYR(Byte newYR);
    Byte getSP() const;
    void setSP(Byte newSP);
    Word getPC() const;
    void setPC(Word newPC);

private:
    Byte AC;
    Byte XR;
    Byte YR;

    Byte SP;

    Word PC;
    FlagWord P;

    void setCFlag();
    void clearCFlag();
    Byte getCFlag();

    void setZFlag();
    void clearZFlag();
    Byte getZFlag();

    void setIFlag();
    void clearIFlag();
    Byte getIFlag();

    void setDFlag();
    void clearDFlag();
    Byte getDFlag();

    void setBFlag();
    void clearBFlag();
    Byte getBFlag();

    void setVFlag();
    void clearVFlag();
    Byte getVFlag();

    void setNFlag();
    void clearNFlag();
    Byte getNFlag();



    Memory m;


};

#endif // CPU_H
