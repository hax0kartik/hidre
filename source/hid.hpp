#pragma once
#include <3ds.h>
#include "PadRing.hpp"
#include "Pad.hpp"
extern "C"
{
    #include "mythread.h"
}
class Hid
{
    public:
        void CreateAndMapMemoryBlock();
        void CreateRingsOnSharedmemoryBlock();
        void StartThreadsForSampling();
        void InitializePad();
        void EnteringSleepMode() {};
        void ExitingSleepMode() {};
        void IsShellOpened(bool opened) {m_shellisopen = opened; };
        Pad *GetPad() {return &m_pad; };
        Handle *GetSharedMemHandle() { return &m_sharedmemhandle; };
        Handle dummyhandles[4] = {0};
    private:
        Handle m_sharedmemhandle;
        void *m_addr = nullptr;
        PadRing *m_padring = nullptr;
        Pad m_pad;
        bool m_shellisopen = true;
        MyThread m_samplingthread;
        bool m_samplingthreadstarted = false;
};