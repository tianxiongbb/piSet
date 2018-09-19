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

/// @file ID2_Reply_Get_Blob_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'id2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ID2_ID2_REPLY_GET_BLOB_BASE_HPP
#define OBJECTS_ID2_ID2_REPLY_GET_BLOB_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CID2_Blob_Id;
class CID2_Reply_Data;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Reply to ID2-Request-Get-Blob-Info.
class NCBI_ID2_EXPORT CID2_Reply_Get_Blob_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2_Reply_Get_Blob_Base(void);
    // destructor
    virtual ~CID2_Reply_Get_Blob_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CID2_Blob_Id TBlob_id;
    typedef int TSplit_version;
    typedef CID2_Reply_Data TData;
    typedef int TBlob_state;

    // getters
    // setters

    /// mandatory
    /// typedef CID2_Blob_Id TBlob_id
    ///  Check whether the Blob_id data member has been assigned a value.
    bool IsSetBlob_id(void) const;
    /// Check whether it is safe or not to call GetBlob_id method.
    bool CanGetBlob_id(void) const;
    void ResetBlob_id(void);
    const TBlob_id& GetBlob_id(void) const;
    void SetBlob_id(TBlob_id& value);
    TBlob_id& SetBlob_id(void);

    /// version of split data
    /// (0 for non split)
    /// optional with default 0
    /// typedef int TSplit_version
    ///  Check whether the Split_version data member has been assigned a value.
    bool IsSetSplit_version(void) const;
    /// Check whether it is safe or not to call GetSplit_version method.
    bool CanGetSplit_version(void) const;
    void ResetSplit_version(void);
    void SetDefaultSplit_version(void);
    TSplit_version GetSplit_version(void) const;
    void SetSplit_version(TSplit_version value);
    TSplit_version& SetSplit_version(void);

    /// whole blob or blob skeleton
    /// not set if error occurred
    /// optional
    /// typedef CID2_Reply_Data TData
    ///  Check whether the Data data member has been assigned a value.
    bool IsSetData(void) const;
    /// Check whether it is safe or not to call GetData method.
    bool CanGetData(void) const;
    void ResetData(void);
    const TData& GetData(void) const;
    void SetData(TData& value);
    TData& SetData(void);

    /// state bits of the blob, 0 or missing means regular live data
    /// optional
    /// typedef int TBlob_state
    ///  Check whether the Blob_state data member has been assigned a value.
    bool IsSetBlob_state(void) const;
    /// Check whether it is safe or not to call GetBlob_state method.
    bool CanGetBlob_state(void) const;
    void ResetBlob_state(void);
    TBlob_state GetBlob_state(void) const;
    void SetBlob_state(TBlob_state value);
    TBlob_state& SetBlob_state(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2_Reply_Get_Blob_Base(const CID2_Reply_Get_Blob_Base&);
    CID2_Reply_Get_Blob_Base& operator=(const CID2_Reply_Get_Blob_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TBlob_id > m_Blob_id;
    int m_Split_version;
    CRef< TData > m_Data;
    int m_Blob_state;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID2_Reply_Get_Blob_Base::IsSetBlob_id(void) const
{
    return m_Blob_id.NotEmpty();
}

inline
bool CID2_Reply_Get_Blob_Base::CanGetBlob_id(void) const
{
    return true;
}

inline
const CID2_Reply_Get_Blob_Base::TBlob_id& CID2_Reply_Get_Blob_Base::GetBlob_id(void) const
{
    if ( !m_Blob_id ) {
        const_cast<CID2_Reply_Get_Blob_Base*>(this)->ResetBlob_id();
    }
    return (*m_Blob_id);
}

inline
CID2_Reply_Get_Blob_Base::TBlob_id& CID2_Reply_Get_Blob_Base::SetBlob_id(void)
{
    if ( !m_Blob_id ) {
        ResetBlob_id();
    }
    return (*m_Blob_id);
}

inline
bool CID2_Reply_Get_Blob_Base::IsSetSplit_version(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CID2_Reply_Get_Blob_Base::CanGetSplit_version(void) const
{
    return true;
}

inline
void CID2_Reply_Get_Blob_Base::ResetSplit_version(void)
{
    m_Split_version = 0;
    m_set_State[0] &= ~0xc;
}

inline
void CID2_Reply_Get_Blob_Base::SetDefaultSplit_version(void)
{
    ResetSplit_version();
}

inline
CID2_Reply_Get_Blob_Base::TSplit_version CID2_Reply_Get_Blob_Base::GetSplit_version(void) const
{
    return m_Split_version;
}

inline
void CID2_Reply_Get_Blob_Base::SetSplit_version(CID2_Reply_Get_Blob_Base::TSplit_version value)
{
    m_Split_version = value;
    m_set_State[0] |= 0xc;
}

inline
CID2_Reply_Get_Blob_Base::TSplit_version& CID2_Reply_Get_Blob_Base::SetSplit_version(void)
{
#ifdef _DEBUG
    if (!IsSetSplit_version()) {
        memset(&m_Split_version,UnassignedByte(),sizeof(m_Split_version));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Split_version;
}

inline
bool CID2_Reply_Get_Blob_Base::IsSetData(void) const
{
    return m_Data.NotEmpty();
}

inline
bool CID2_Reply_Get_Blob_Base::CanGetData(void) const
{
    return IsSetData();
}

inline
const CID2_Reply_Get_Blob_Base::TData& CID2_Reply_Get_Blob_Base::GetData(void) const
{
    if (!CanGetData()) {
        ThrowUnassigned(2);
    }
    return (*m_Data);
}

inline
bool CID2_Reply_Get_Blob_Base::IsSetBlob_state(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CID2_Reply_Get_Blob_Base::CanGetBlob_state(void) const
{
    return IsSetBlob_state();
}

inline
void CID2_Reply_Get_Blob_Base::ResetBlob_state(void)
{
    m_Blob_state = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CID2_Reply_Get_Blob_Base::TBlob_state CID2_Reply_Get_Blob_Base::GetBlob_state(void) const
{
    if (!CanGetBlob_state()) {
        ThrowUnassigned(3);
    }
    return m_Blob_state;
}

inline
void CID2_Reply_Get_Blob_Base::SetBlob_state(CID2_Reply_Get_Blob_Base::TBlob_state value)
{
    m_Blob_state = value;
    m_set_State[0] |= 0xc0;
}

inline
CID2_Reply_Get_Blob_Base::TBlob_state& CID2_Reply_Get_Blob_Base::SetBlob_state(void)
{
#ifdef _DEBUG
    if (!IsSetBlob_state()) {
        memset(&m_Blob_state,UnassignedByte(),sizeof(m_Blob_state));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Blob_state;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID2_ID2_REPLY_GET_BLOB_BASE_HPP
