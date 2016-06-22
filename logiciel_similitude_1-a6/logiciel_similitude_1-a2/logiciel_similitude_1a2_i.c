

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Jun 22 20:06:56 2016
 */
/* Compiler settings for logiciel_similitude_1a2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_logiciel_similitude_1a2,0xB71CA0F0,0xF146,0x4220,0xA4,0x63,0x03,0x5A,0xCB,0x0A,0x68,0xAB);


MIDL_DEFINE_GUID(IID, DIID_Ilogiciel_similitude_1a2,0x3B3739B3,0xC6BE,0x4B05,0x94,0xF5,0x38,0x2B,0x0C,0x14,0x1D,0x1B);


MIDL_DEFINE_GUID(CLSID, CLSID_Clogiciel_similitude_1a2Doc,0xF6CFA656,0x0768,0x42B0,0xA9,0xB6,0x10,0xFC,0x5D,0x40,0x83,0xA2);


MIDL_DEFINE_GUID(IID, DIID_ISaisieEssaisView,0x8FB47E05,0x3681,0x4802,0xA2,0x70,0xAB,0x91,0x24,0x0E,0xF1,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_SaisieEssaisView,0x93A9B5B3,0x949C,0x48F1,0xA8,0x8A,0x3F,0xBB,0xA6,0xA2,0x86,0xD6);


MIDL_DEFINE_GUID(IID, DIID_IInterfaceSimilitudeView,0xD23D4262,0x3148,0x4E58,0x8E,0xE5,0x2D,0x85,0x04,0x0B,0x08,0x77);


MIDL_DEFINE_GUID(CLSID, CLSID_InterfaceSimilitudeView,0x700C1834,0x64EB,0x4668,0xBF,0x0D,0xAF,0x93,0xE5,0x72,0x55,0xB1);


MIDL_DEFINE_GUID(IID, DIID_IAffChartsView,0xF2E4D3F7,0x0ED5,0x4E2C,0xA5,0x16,0x02,0xE3,0xA8,0x7C,0x5D,0x27);


MIDL_DEFINE_GUID(CLSID, CLSID_AffChartsView,0xD809A7D1,0x876A,0x4296,0xA6,0xED,0x55,0x1E,0xE3,0xDA,0x90,0x25);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



