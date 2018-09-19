/* $Id$
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 */

/// @file ValidErrItem_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'valerr.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_VALERR_VALIDERRITEM_BASE_HPP
#define OBJECTS_VALERR_VALIDERRITEM_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_VALERR_EXPORT CValidErrItem_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CValidErrItem_Base(void);
    // destructor
    virtual ~CValidErrItem_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum ESev {
        eSev_info     = 0,
        eSev_warning  = 1,
        eSev_error    = 2,
        eSev_critical = 3,
        eSev_fatal    = 4,
        eSev_trace    = 5
    };
    
    /// Access to ESev's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(ESev)(void);
    
    enum EObjectType {
        eObjectType_seqentry    =  1,
        eObjectType_bioseq      =  2,
        eObjectType_bioseqset   =  3,
        eObjectType_seqdesc     =  4,
        eObjectType_seqannot    =  5,
        eObjectType_annotdesc   =  6,
        eObjectType_seqfeat     =  7,
        eObjectType_seqalign    =  8,
        eObjectType_seqgraph    =  9,
        eObjectType_seqsub      = 10,
        eObjectType_submitblock = 11
    };
    
    /// Access to EObjectType's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EObjectType)(void);
    
    // types
    typedef int TSev;
    typedef unsigned int TErrIndex;
    typedef string TMsg;
    typedef string TObjDesc;
    typedef string TAccession;
    typedef string TFeatureId;
    typedef int TSeqOffset;
    typedef int TObjectType;
    typedef string TErrorName;
    typedef string TErrorGroup;
    typedef string TAccnver;
    typedef int TVersion;

    // getters
    // setters

    /// mandatory
    /// typedef int TSev
    ///  Check whether the Sev data member has been assigned a value.
    bool IsSetSev(void) const;
    /// Check whether it is safe or not to call GetSev method.
    bool CanGetSev(void) const;
    void ResetSev(void);
    TSev GetSev(void) const;
    void SetSev(TSev value);
    TSev& SetSev(void);

    /// mandatory
    /// typedef unsigned int TErrIndex
    ///  Check whether the ErrIndex data member has been assigned a value.
    bool IsSetErrIndex(void) const;
    /// Check whether it is safe or not to call GetErrIndex method.
    bool CanGetErrIndex(void) const;
    void ResetErrIndex(void);
    TErrIndex GetErrIndex(void) const;
    void SetErrIndex(TErrIndex value);
    TErrIndex& SetErrIndex(void);

    /// mandatory
    /// typedef string TMsg
    ///  Check whether the Msg data member has been assigned a value.
    bool IsSetMsg(void) const;
    /// Check whether it is safe or not to call GetMsg method.
    bool CanGetMsg(void) const;
    void ResetMsg(void);
    const TMsg& GetMsg(void) const;
    void SetMsg(const TMsg& value);
    TMsg& SetMsg(void);

    /// mandatory
    /// typedef string TObjDesc
    ///  Check whether the ObjDesc data member has been assigned a value.
    bool IsSetObjDesc(void) const;
    /// Check whether it is safe or not to call GetObjDesc method.
    bool CanGetObjDesc(void) const;
    void ResetObjDesc(void);
    const TObjDesc& GetObjDesc(void) const;
    void SetObjDesc(const TObjDesc& value);
    TObjDesc& SetObjDesc(void);

    /// mandatory
    /// typedef string TAccession
    ///  Check whether the Accession data member has been assigned a value.
    bool IsSetAccession(void) const;
    /// Check whether it is safe or not to call GetAccession method.
    bool CanGetAccession(void) const;
    void ResetAccession(void);
    const TAccession& GetAccession(void) const;
    void SetAccession(const TAccession& value);
    TAccession& SetAccession(void);

    /// optional
    /// typedef string TFeatureId
    ///  Check whether the FeatureId data member has been assigned a value.
    bool IsSetFeatureId(void) const;
    /// Check whether it is safe or not to call GetFeatureId method.
    bool CanGetFeatureId(void) const;
    void ResetFeatureId(void);
    const TFeatureId& GetFeatureId(void) const;
    void SetFeatureId(const TFeatureId& value);
    TFeatureId& SetFeatureId(void);

    /// optional
    /// typedef int TSeqOffset
    ///  Check whether the SeqOffset data member has been assigned a value.
    bool IsSetSeqOffset(void) const;
    /// Check whether it is safe or not to call GetSeqOffset method.
    bool CanGetSeqOffset(void) const;
    void ResetSeqOffset(void);
    TSeqOffset GetSeqOffset(void) const;
    void SetSeqOffset(TSeqOffset value);
    TSeqOffset& SetSeqOffset(void);

    /// optional
    /// typedef int TObjectType
    ///  Check whether the ObjectType data member has been assigned a value.
    bool IsSetObjectType(void) const;
    /// Check whether it is safe or not to call GetObjectType method.
    bool CanGetObjectType(void) const;
    void ResetObjectType(void);
    TObjectType GetObjectType(void) const;
    void SetObjectType(TObjectType value);
    TObjectType& SetObjectType(void);

    /// optional
    /// typedef string TErrorName
    ///  Check whether the ErrorName data member has been assigned a value.
    bool IsSetErrorName(void) const;
    /// Check whether it is safe or not to call GetErrorName method.
    bool CanGetErrorName(void) const;
    void ResetErrorName(void);
    const TErrorName& GetErrorName(void) const;
    void SetErrorName(const TErrorName& value);
    TErrorName& SetErrorName(void);

    /// optional
    /// typedef string TErrorGroup
    ///  Check whether the ErrorGroup data member has been assigned a value.
    bool IsSetErrorGroup(void) const;
    /// Check whether it is safe or not to call GetErrorGroup method.
    bool CanGetErrorGroup(void) const;
    void ResetErrorGroup(void);
    const TErrorGroup& GetErrorGroup(void) const;
    void SetErrorGroup(const TErrorGroup& value);
    TErrorGroup& SetErrorGroup(void);

    /// optional
    /// typedef string TAccnver
    ///  Check whether the Accnver data member has been assigned a value.
    bool IsSetAccnver(void) const;
    /// Check whether it is safe or not to call GetAccnver method.
    bool CanGetAccnver(void) const;
    void ResetAccnver(void);
    const TAccnver& GetAccnver(void) const;
    void SetAccnver(const TAccnver& value);
    TAccnver& SetAccnver(void);

    /// optional
    /// typedef int TVersion
    ///  Check whether the Version data member has been assigned a value.
    bool IsSetVersion(void) const;
    /// Check whether it is safe or not to call GetVersion method.
    bool CanGetVersion(void) const;
    void ResetVersion(void);
    TVersion GetVersion(void) const;
    void SetVersion(TVersion value);
    TVersion& SetVersion(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CValidErrItem_Base(const CValidErrItem_Base&);
    CValidErrItem_Base& operator=(const CValidErrItem_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Sev;
    unsigned int m_ErrIndex;
    string m_Msg;
    string m_ObjDesc;
    string m_Accession;
    string m_FeatureId;
    int m_SeqOffset;
    int m_ObjectType;
    string m_ErrorName;
    string m_ErrorGroup;
    string m_Accnver;
    int m_Version;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CValidErrItem_Base::IsSetSev(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CValidErrItem_Base::CanGetSev(void) const
{
    return IsSetSev();
}

inline
void CValidErrItem_Base::ResetSev(void)
{
    m_Sev = (ESev)(0);
    m_set_State[0] &= ~0x3;
}

inline
CValidErrItem_Base::TSev CValidErrItem_Base::GetSev(void) const
{
    if (!CanGetSev()) {
        ThrowUnassigned(0);
    }
    return m_Sev;
}

inline
void CValidErrItem_Base::SetSev(CValidErrItem_Base::TSev value)
{
    m_Sev = value;
    m_set_State[0] |= 0x3;
}

inline
CValidErrItem_Base::TSev& CValidErrItem_Base::SetSev(void)
{
#ifdef _DEBUG
    if (!IsSetSev()) {
        memset(&m_Sev,UnassignedByte(),sizeof(m_Sev));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Sev;
}

inline
bool CValidErrItem_Base::IsSetErrIndex(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CValidErrItem_Base::CanGetErrIndex(void) const
{
    return IsSetErrIndex();
}

inline
void CValidErrItem_Base::ResetErrIndex(void)
{
    m_ErrIndex = 0;
    m_set_State[0] &= ~0xc;
}

inline
CValidErrItem_Base::TErrIndex CValidErrItem_Base::GetErrIndex(void) const
{
    if (!CanGetErrIndex()) {
        ThrowUnassigned(1);
    }
    return m_ErrIndex;
}

inline
void CValidErrItem_Base::SetErrIndex(CValidErrItem_Base::TErrIndex value)
{
    m_ErrIndex = value;
    m_set_State[0] |= 0xc;
}

inline
CValidErrItem_Base::TErrIndex& CValidErrItem_Base::SetErrIndex(void)
{
#ifdef _DEBUG
    if (!IsSetErrIndex()) {
        memset(&m_ErrIndex,UnassignedByte(),sizeof(m_ErrIndex));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_ErrIndex;
}

inline
bool CValidErrItem_Base::IsSetMsg(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CValidErrItem_Base::CanGetMsg(void) const
{
    return IsSetMsg();
}

inline
const CValidErrItem_Base::TMsg& CValidErrItem_Base::GetMsg(void) const
{
    if (!CanGetMsg()) {
        ThrowUnassigned(2);
    }
    return m_Msg;
}

inline
void CValidErrItem_Base::SetMsg(const CValidErrItem_Base::TMsg& value)
{
    m_Msg = value;
    m_set_State[0] |= 0x30;
}

inline
CValidErrItem_Base::TMsg& CValidErrItem_Base::SetMsg(void)
{
#ifdef _DEBUG
    if (!IsSetMsg()) {
        m_Msg = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Msg;
}

inline
bool CValidErrItem_Base::IsSetObjDesc(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CValidErrItem_Base::CanGetObjDesc(void) const
{
    return IsSetObjDesc();
}

inline
const CValidErrItem_Base::TObjDesc& CValidErrItem_Base::GetObjDesc(void) const
{
    if (!CanGetObjDesc()) {
        ThrowUnassigned(3);
    }
    return m_ObjDesc;
}

inline
void CValidErrItem_Base::SetObjDesc(const CValidErrItem_Base::TObjDesc& value)
{
    m_ObjDesc = value;
    m_set_State[0] |= 0xc0;
}

inline
CValidErrItem_Base::TObjDesc& CValidErrItem_Base::SetObjDesc(void)
{
#ifdef _DEBUG
    if (!IsSetObjDesc()) {
        m_ObjDesc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_ObjDesc;
}

inline
bool CValidErrItem_Base::IsSetAccession(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CValidErrItem_Base::CanGetAccession(void) const
{
    return IsSetAccession();
}

inline
const CValidErrItem_Base::TAccession& CValidErrItem_Base::GetAccession(void) const
{
    if (!CanGetAccession()) {
        ThrowUnassigned(4);
    }
    return m_Accession;
}

inline
void CValidErrItem_Base::SetAccession(const CValidErrItem_Base::TAccession& value)
{
    m_Accession = value;
    m_set_State[0] |= 0x300;
}

inline
CValidErrItem_Base::TAccession& CValidErrItem_Base::SetAccession(void)
{
#ifdef _DEBUG
    if (!IsSetAccession()) {
        m_Accession = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Accession;
}

inline
bool CValidErrItem_Base::IsSetFeatureId(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CValidErrItem_Base::CanGetFeatureId(void) const
{
    return IsSetFeatureId();
}

inline
const CValidErrItem_Base::TFeatureId& CValidErrItem_Base::GetFeatureId(void) const
{
    if (!CanGetFeatureId()) {
        ThrowUnassigned(5);
    }
    return m_FeatureId;
}

inline
void CValidErrItem_Base::SetFeatureId(const CValidErrItem_Base::TFeatureId& value)
{
    m_FeatureId = value;
    m_set_State[0] |= 0xc00;
}

inline
CValidErrItem_Base::TFeatureId& CValidErrItem_Base::SetFeatureId(void)
{
#ifdef _DEBUG
    if (!IsSetFeatureId()) {
        m_FeatureId = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x400;
    return m_FeatureId;
}

inline
bool CValidErrItem_Base::IsSetSeqOffset(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CValidErrItem_Base::CanGetSeqOffset(void) const
{
    return IsSetSeqOffset();
}

inline
void CValidErrItem_Base::ResetSeqOffset(void)
{
    m_SeqOffset = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CValidErrItem_Base::TSeqOffset CValidErrItem_Base::GetSeqOffset(void) const
{
    if (!CanGetSeqOffset()) {
        ThrowUnassigned(6);
    }
    return m_SeqOffset;
}

inline
void CValidErrItem_Base::SetSeqOffset(CValidErrItem_Base::TSeqOffset value)
{
    m_SeqOffset = value;
    m_set_State[0] |= 0x3000;
}

inline
CValidErrItem_Base::TSeqOffset& CValidErrItem_Base::SetSeqOffset(void)
{
#ifdef _DEBUG
    if (!IsSetSeqOffset()) {
        memset(&m_SeqOffset,UnassignedByte(),sizeof(m_SeqOffset));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_SeqOffset;
}

inline
bool CValidErrItem_Base::IsSetObjectType(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CValidErrItem_Base::CanGetObjectType(void) const
{
    return IsSetObjectType();
}

inline
void CValidErrItem_Base::ResetObjectType(void)
{
    m_ObjectType = (EObjectType)(0);
    m_set_State[0] &= ~0xc000;
}

inline
CValidErrItem_Base::TObjectType CValidErrItem_Base::GetObjectType(void) const
{
    if (!CanGetObjectType()) {
        ThrowUnassigned(7);
    }
    return m_ObjectType;
}

inline
void CValidErrItem_Base::SetObjectType(CValidErrItem_Base::TObjectType value)
{
    m_ObjectType = value;
    m_set_State[0] |= 0xc000;
}

inline
CValidErrItem_Base::TObjectType& CValidErrItem_Base::SetObjectType(void)
{
#ifdef _DEBUG
    if (!IsSetObjectType()) {
        memset(&m_ObjectType,UnassignedByte(),sizeof(m_ObjectType));
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_ObjectType;
}

inline
bool CValidErrItem_Base::IsSetErrorName(void) const
{
    return ((m_set_State[0] & 0x30000) != 0);
}

inline
bool CValidErrItem_Base::CanGetErrorName(void) const
{
    return IsSetErrorName();
}

inline
const CValidErrItem_Base::TErrorName& CValidErrItem_Base::GetErrorName(void) const
{
    if (!CanGetErrorName()) {
        ThrowUnassigned(8);
    }
    return m_ErrorName;
}

inline
void CValidErrItem_Base::SetErrorName(const CValidErrItem_Base::TErrorName& value)
{
    m_ErrorName = value;
    m_set_State[0] |= 0x30000;
}

inline
CValidErrItem_Base::TErrorName& CValidErrItem_Base::SetErrorName(void)
{
#ifdef _DEBUG
    if (!IsSetErrorName()) {
        m_ErrorName = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10000;
    return m_ErrorName;
}

inline
bool CValidErrItem_Base::IsSetErrorGroup(void) const
{
    return ((m_set_State[0] & 0xc0000) != 0);
}

inline
bool CValidErrItem_Base::CanGetErrorGroup(void) const
{
    return IsSetErrorGroup();
}

inline
const CValidErrItem_Base::TErrorGroup& CValidErrItem_Base::GetErrorGroup(void) const
{
    if (!CanGetErrorGroup()) {
        ThrowUnassigned(9);
    }
    return m_ErrorGroup;
}

inline
void CValidErrItem_Base::SetErrorGroup(const CValidErrItem_Base::TErrorGroup& value)
{
    m_ErrorGroup = value;
    m_set_State[0] |= 0xc0000;
}

inline
CValidErrItem_Base::TErrorGroup& CValidErrItem_Base::SetErrorGroup(void)
{
#ifdef _DEBUG
    if (!IsSetErrorGroup()) {
        m_ErrorGroup = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40000;
    return m_ErrorGroup;
}

inline
bool CValidErrItem_Base::IsSetAccnver(void) const
{
    return ((m_set_State[0] & 0x300000) != 0);
}

inline
bool CValidErrItem_Base::CanGetAccnver(void) const
{
    return IsSetAccnver();
}

inline
const CValidErrItem_Base::TAccnver& CValidErrItem_Base::GetAccnver(void) const
{
    if (!CanGetAccnver()) {
        ThrowUnassigned(10);
    }
    return m_Accnver;
}

inline
void CValidErrItem_Base::SetAccnver(const CValidErrItem_Base::TAccnver& value)
{
    m_Accnver = value;
    m_set_State[0] |= 0x300000;
}

inline
CValidErrItem_Base::TAccnver& CValidErrItem_Base::SetAccnver(void)
{
#ifdef _DEBUG
    if (!IsSetAccnver()) {
        m_Accnver = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100000;
    return m_Accnver;
}

inline
bool CValidErrItem_Base::IsSetVersion(void) const
{
    return ((m_set_State[0] & 0xc00000) != 0);
}

inline
bool CValidErrItem_Base::CanGetVersion(void) const
{
    return IsSetVersion();
}

inline
void CValidErrItem_Base::ResetVersion(void)
{
    m_Version = 0;
    m_set_State[0] &= ~0xc00000;
}

inline
CValidErrItem_Base::TVersion CValidErrItem_Base::GetVersion(void) const
{
    if (!CanGetVersion()) {
        ThrowUnassigned(11);
    }
    return m_Version;
}

inline
void CValidErrItem_Base::SetVersion(CValidErrItem_Base::TVersion value)
{
    m_Version = value;
    m_set_State[0] |= 0xc00000;
}

inline
CValidErrItem_Base::TVersion& CValidErrItem_Base::SetVersion(void)
{
#ifdef _DEBUG
    if (!IsSetVersion()) {
        memset(&m_Version,UnassignedByte(),sizeof(m_Version));
    }
#endif
    m_set_State[0] |= 0x400000;
    return m_Version;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_VALERR_VALIDERRITEM_BASE_HPP
