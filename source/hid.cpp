#include <malloc.h>
#include <new>
#include "hid.hpp"
#include "PadRing.hpp"

static uint8_t ALIGN(8) hidthreadstack[0x1000];
void Hid::CreateAndMapMemoryBlock()
{
    // 0x1000 is rounded off size for 0x2B0
    signed int ret = svcCreateMemoryBlock(&m_sharedmemhandle, 0, 0x1000, (MemPerm)(MEMPERM_READ | MEMPERM_WRITE), MEMPERM_READ);
    if(R_SUCCEEDED(ret))
    {
        m_addr = (void*)0x10000000;
        if(m_addr)
        {
            ret = svcMapMemoryBlock(m_sharedmemhandle, (u32)m_addr, (MemPerm)(MEMPERM_READ | MEMPERM_WRITE), MEMPERM_DONTCARE);
            if(ret != 0) 
                *(u32*)ret = (u32)m_addr;
        }
        else svcBreak(USERBREAK_ASSERT);
        
    }
    else svcBreak(USERBREAK_ASSERT);
    for(int i = 0; i < 4; i++)
    {
        svcCreateEvent(&dummyhandles[i], RESET_ONESHOT);
    }
}

void Hid::CreateRingsOnSharedmemoryBlock()
{
    m_padring = new(m_addr) PadRing;
}

void Hid::InitializePad()
{
    m_pad.Initialize();
    m_pad.SetPadRing(m_padring);
}

static void SamplingFunction(void *argv)
{
    Hid *hid = (Hid*)argv;
    Result ret = 0;
    Handle *padtimer = hid->GetPad()->GetTimer();
    while(1)
    {
        ret = svcWaitSynchronization(*padtimer, U64_MAX);
        if(ret > 0) svcBreak(USERBREAK_ASSERT);
        hid->GetPad()->Sampling();
    }
}

void Hid::StartThreadsForSampling()
{
    if(!m_samplingthreadstarted)
    {
        m_padring->Reset();
        m_pad.SetTimer();
        MyThread_Create(&m_samplingthread, SamplingFunction, this, hidthreadstack, 0x1000, 0x15, -2);
        m_samplingthreadstarted = true;
    }
}