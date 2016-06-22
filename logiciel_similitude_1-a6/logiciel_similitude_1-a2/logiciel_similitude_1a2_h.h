

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __logiciel_similitude_1a2_h_h__
#define __logiciel_similitude_1a2_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Ilogiciel_similitude_1a2_FWD_DEFINED__
#define __Ilogiciel_similitude_1a2_FWD_DEFINED__
typedef interface Ilogiciel_similitude_1a2 Ilogiciel_similitude_1a2;

#endif 	/* __Ilogiciel_similitude_1a2_FWD_DEFINED__ */


#ifndef __Clogiciel_similitude_1a2Doc_FWD_DEFINED__
#define __Clogiciel_similitude_1a2Doc_FWD_DEFINED__

#ifdef __cplusplus
typedef class Clogiciel_similitude_1a2Doc Clogiciel_similitude_1a2Doc;
#else
typedef struct Clogiciel_similitude_1a2Doc Clogiciel_similitude_1a2Doc;
#endif /* __cplusplus */

#endif 	/* __Clogiciel_similitude_1a2Doc_FWD_DEFINED__ */


#ifndef __ISaisieEssaisView_FWD_DEFINED__
#define __ISaisieEssaisView_FWD_DEFINED__
typedef interface ISaisieEssaisView ISaisieEssaisView;

#endif 	/* __ISaisieEssaisView_FWD_DEFINED__ */


#ifndef __SaisieEssaisView_FWD_DEFINED__
#define __SaisieEssaisView_FWD_DEFINED__

#ifdef __cplusplus
typedef class SaisieEssaisView SaisieEssaisView;
#else
typedef struct SaisieEssaisView SaisieEssaisView;
#endif /* __cplusplus */

#endif 	/* __SaisieEssaisView_FWD_DEFINED__ */


#ifndef __IInterfaceSimilitudeView_FWD_DEFINED__
#define __IInterfaceSimilitudeView_FWD_DEFINED__
typedef interface IInterfaceSimilitudeView IInterfaceSimilitudeView;

#endif 	/* __IInterfaceSimilitudeView_FWD_DEFINED__ */


#ifndef __InterfaceSimilitudeView_FWD_DEFINED__
#define __InterfaceSimilitudeView_FWD_DEFINED__

#ifdef __cplusplus
typedef class InterfaceSimilitudeView InterfaceSimilitudeView;
#else
typedef struct InterfaceSimilitudeView InterfaceSimilitudeView;
#endif /* __cplusplus */

#endif 	/* __InterfaceSimilitudeView_FWD_DEFINED__ */


#ifndef __IAffChartsView_FWD_DEFINED__
#define __IAffChartsView_FWD_DEFINED__
typedef interface IAffChartsView IAffChartsView;

#endif 	/* __IAffChartsView_FWD_DEFINED__ */


#ifndef __AffChartsView_FWD_DEFINED__
#define __AffChartsView_FWD_DEFINED__

#ifdef __cplusplus
typedef class AffChartsView AffChartsView;
#else
typedef struct AffChartsView AffChartsView;
#endif /* __cplusplus */

#endif 	/* __AffChartsView_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __logiciel_similitude_1a2_LIBRARY_DEFINED__
#define __logiciel_similitude_1a2_LIBRARY_DEFINED__

/* library logiciel_similitude_1a2 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_logiciel_similitude_1a2;

#ifndef __Ilogiciel_similitude_1a2_DISPINTERFACE_DEFINED__
#define __Ilogiciel_similitude_1a2_DISPINTERFACE_DEFINED__

/* dispinterface Ilogiciel_similitude_1a2 */
/* [uuid] */ 


EXTERN_C const IID DIID_Ilogiciel_similitude_1a2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3B3739B3-C6BE-4B05-94F5-382B0C141D1B")
    Ilogiciel_similitude_1a2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct Ilogiciel_similitude_1a2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Ilogiciel_similitude_1a2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Ilogiciel_similitude_1a2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Ilogiciel_similitude_1a2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Ilogiciel_similitude_1a2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Ilogiciel_similitude_1a2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Ilogiciel_similitude_1a2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Ilogiciel_similitude_1a2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } Ilogiciel_similitude_1a2Vtbl;

    interface Ilogiciel_similitude_1a2
    {
        CONST_VTBL struct Ilogiciel_similitude_1a2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Ilogiciel_similitude_1a2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Ilogiciel_similitude_1a2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Ilogiciel_similitude_1a2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Ilogiciel_similitude_1a2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Ilogiciel_similitude_1a2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Ilogiciel_similitude_1a2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Ilogiciel_similitude_1a2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Ilogiciel_similitude_1a2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Clogiciel_similitude_1a2Doc;

#ifdef __cplusplus

class DECLSPEC_UUID("F6CFA656-0768-42B0-A9B6-10FC5D4083A2")
Clogiciel_similitude_1a2Doc;
#endif

#ifndef __ISaisieEssaisView_DISPINTERFACE_DEFINED__
#define __ISaisieEssaisView_DISPINTERFACE_DEFINED__

/* dispinterface ISaisieEssaisView */
/* [uuid] */ 


EXTERN_C const IID DIID_ISaisieEssaisView;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8FB47E05-3681-4802-A270-AB91240EF169")
    ISaisieEssaisView : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISaisieEssaisViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISaisieEssaisView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISaisieEssaisView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISaisieEssaisView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISaisieEssaisView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISaisieEssaisView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISaisieEssaisView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISaisieEssaisView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISaisieEssaisViewVtbl;

    interface ISaisieEssaisView
    {
        CONST_VTBL struct ISaisieEssaisViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISaisieEssaisView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISaisieEssaisView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISaisieEssaisView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISaisieEssaisView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISaisieEssaisView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISaisieEssaisView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISaisieEssaisView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISaisieEssaisView_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SaisieEssaisView;

#ifdef __cplusplus

class DECLSPEC_UUID("93A9B5B3-949C-48F1-A88A-3FBBA6A286D6")
SaisieEssaisView;
#endif

#ifndef __IInterfaceSimilitudeView_DISPINTERFACE_DEFINED__
#define __IInterfaceSimilitudeView_DISPINTERFACE_DEFINED__

/* dispinterface IInterfaceSimilitudeView */
/* [uuid] */ 


EXTERN_C const IID DIID_IInterfaceSimilitudeView;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D23D4262-3148-4E58-8EE5-2D85040B0877")
    IInterfaceSimilitudeView : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSimilitudeViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSimilitudeView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSimilitudeView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSimilitudeView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSimilitudeView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSimilitudeView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSimilitudeView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSimilitudeView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IInterfaceSimilitudeViewVtbl;

    interface IInterfaceSimilitudeView
    {
        CONST_VTBL struct IInterfaceSimilitudeViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSimilitudeView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSimilitudeView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSimilitudeView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSimilitudeView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSimilitudeView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSimilitudeView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSimilitudeView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IInterfaceSimilitudeView_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_InterfaceSimilitudeView;

#ifdef __cplusplus

class DECLSPEC_UUID("700C1834-64EB-4668-BF0D-AF93E57255B1")
InterfaceSimilitudeView;
#endif

#ifndef __IAffChartsView_DISPINTERFACE_DEFINED__
#define __IAffChartsView_DISPINTERFACE_DEFINED__

/* dispinterface IAffChartsView */
/* [uuid] */ 


EXTERN_C const IID DIID_IAffChartsView;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F2E4D3F7-0ED5-4E2C-A516-02E3A87C5D27")
    IAffChartsView : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAffChartsViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAffChartsView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAffChartsView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAffChartsView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAffChartsView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAffChartsView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAffChartsView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAffChartsView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAffChartsViewVtbl;

    interface IAffChartsView
    {
        CONST_VTBL struct IAffChartsViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAffChartsView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAffChartsView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAffChartsView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAffChartsView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAffChartsView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAffChartsView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAffChartsView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAffChartsView_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AffChartsView;

#ifdef __cplusplus

class DECLSPEC_UUID("D809A7D1-876A-4296-A6ED-551EE3DA9025")
AffChartsView;
#endif
#endif /* __logiciel_similitude_1a2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


