#include "ipc.hpp"

void IPC::HandleCommands(Hid *hid)
{
    uint32_t *cmdbuf = getThreadCommandBuffer();
    uint16_t cmdid = cmdbuf[0] >> 16;
    switch(cmdid)
    {
        case 1: // TouchScreenCalibrateParam
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 2: // TouchScreenFlushParam
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 3:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 4:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 5:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 6:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 7:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 8:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 9:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0xA:
        {
            cmdbuf[0] = 0xA0047;
            cmdbuf[1] = 0;
            cmdbuf[2] = 0x14000000;
            cmdbuf[3] = *hid->GetSharedMemHandle();
            cmdbuf[4] = *hid->GetPad()->GetEvent();
            cmdbuf[5] = hid->dummyhandles[0];
            cmdbuf[6] = hid->dummyhandles[1];
            cmdbuf[7] = hid->dummyhandles[2];
            cmdbuf[8] = hid->dummyhandles[3];
            break;
        }

        case 0xB:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0xC:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0xD:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0xE:
        {
            cmdbuf[0] = 0xE0200;
            cmdbuf[1] = 0;
            break;
        }

        case 0xF:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0x10:
        {
            cmdbuf[0] = 0x100100;
            cmdbuf[1] = 0;
            break;
        }

        case 0x11:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0x12:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0x13:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0x14:
        {
            cmdbuf[0] = IPC_MakeHeader(cmdid, 1, 0);
            cmdbuf[1] = 0;
            break;
        }

        case 0x15:
        {
            cmdbuf[0] = 0x150080;
            cmdbuf[1] = 0;
            cmdbuf[2] = 0x41660000;
            break;
        }

        case 0x16:
        {
            cmdbuf[0] = 0x160180;
            cmdbuf[1] = 0;
            break;
        }

        case 0x17:
        {
            cmdbuf[0] = 0x170080;
            cmdbuf[1] = 0;
            cmdbuf[2] = 0;
            break;
        }
    }
}