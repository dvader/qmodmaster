#ifndef EUTILS_H
#define EUTILS_H

#include <QString>
#include <QMap>
#include <QTime>
#include "modbus-private.h"

static const QString ModbusFunctionNames[]={"Read Coils (0x01)","Read Discrete Inputs (0x02)","Read Holding Registers (0x03)",
                               "Read Input Registers (0x04)","Write Single Coil (0x05)","Write Single Register (0x06)",
                               "Write Multiple Coils (0x0f)","Write Multiple Registers (0x10)"};

static const int ModbusFunctionCodes[]={0x1,0x2,0x3,0x4,0x5,0x6,0xf,0x10};


class EUtils
{
private:
    EUtils();

public:

    static QString ModbusDataTypeName(int fCode)
    {
            switch(fCode)
            {
                    case _FC_READ_COILS:
                    case _FC_WRITE_SINGLE_COIL:
                    case _FC_WRITE_MULTIPLE_COILS:
                            return "Coil (binary)";
                    case _FC_READ_DISCRETE_INPUTS:
                            return "Discrete Input (binary)";
                    case _FC_READ_HOLDING_REGISTERS:
                    case _FC_WRITE_SINGLE_REGISTER:
                    case _FC_WRITE_MULTIPLE_REGISTERS:
                            return "Holding Register (16 bit)";
                    case _FC_READ_INPUT_REGISTERS:
                            return "Input Register (16 bit)";
                    default:
                            break;
            }
            return "Unknown";
    }

    static bool ModbusIsWriteFunction(int fCode)
    {
            switch(fCode)
            {
                    case _FC_READ_COILS:
                    case _FC_READ_DISCRETE_INPUTS:
                    case _FC_READ_HOLDING_REGISTERS:
                    case _FC_READ_INPUT_REGISTERS:
                        return false;

                    case _FC_WRITE_SINGLE_COIL:
                    case _FC_WRITE_MULTIPLE_COILS:
                    case _FC_WRITE_SINGLE_REGISTER:
                    case _FC_WRITE_MULTIPLE_REGISTERS:
                         return true;

                    default:
                            break;
            }
            return "Unknown";
    }

    static QString ModbusFunctionName(int index)
    {
         return ModbusFunctionNames[index];
    }

    static int ModbusFunctionCode(int index)
    {
            return ModbusFunctionCodes[index];
    }

    static QString TxTimeStamp()
    {
        return ("Tx >" + QTime::currentTime().toString("HH:mm:ss:zzz"));
    }

    static QString RxTimeStamp()
    {
        return ("Rx >" + QTime::currentTime().toString("HH:mm:ss:zzz"));
    }

    static QString SysTimeStamp()
    {
        return ("Sys>" + QTime::currentTime().toString("HH:mm:ss:zzz"));
    }

    static QChar parity(QString p)
    {
        //the first char is what we need
        return p.at(0);
    }

    static enum {RTU = 0, TCP = 1} ModbusMode;

    static enum {Bin = 2, Dec = 10, Hex = 16} Base;

};

#endif // EUTILS_H