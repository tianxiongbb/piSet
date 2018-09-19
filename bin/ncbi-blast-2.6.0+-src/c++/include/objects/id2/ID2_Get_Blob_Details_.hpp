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

/// @file ID2_Get_Blob_Details_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'id2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ID2_ID2_GET_BLOB_DETAILS_BASE_HPP
#define OBJECTS_ID2_ID2_GET_BLOB_DETAILS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSeq_loc;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// The following structure describes what parts of blob are required
/// immediately after ID2-Request-Get-Blob-Info in case blob is split.
/// Seq-entry level will have probably the same values as Entry-complexities.
class NCBI_ID2_EXPORT CID2_Get_Blob_Details_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2_Get_Blob_Details_Base(void);
    // destructor
    virtual ~CID2_Get_Blob_Details_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /// level of sequence data to load
    enum ESequence_level {
        eSequence_level_none     = 0,  ///< not required
        eSequence_level_seq_map  = 1,  ///< at least seq-map
        eSequence_level_seq_data = 2  ///< include seq-data
    };
    
    /// Access to ESequence_level's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(ESequence_level)(void);
    
    // types
    typedef CSeq_loc TLocation;
    typedef int TSeq_class_level;
    typedef int TDescr_level;
    typedef int TDescr_type_mask;
    typedef int TAnnot_type_mask;
    typedef int TFeat_type_mask;
    typedef ESequence_level TSequence_level;

    // getters
    // setters

    /// reference location for details - can be only part of sequence
    /// optional
    /// typedef CSeq_loc TLocation
    ///  Check whether the Location data member has been assigned a value.
    bool IsSetLocation(void) const;
    /// Check whether it is safe or not to call GetLocation method.
    bool CanGetLocation(void) const;
    void ResetLocation(void);
    const TLocation& GetLocation(void) const;
    void SetLocation(TLocation& value);
    TLocation& SetLocation(void);

    /// Seq-entry level for all data except descriptors (sequnence, annots)
    /// optional with default 1
    /// typedef int TSeq_class_level
    ///  Check whether the Seq_class_level data member has been assigned a value.
    bool IsSetSeq_class_level(void) const;
    /// Check whether it is safe or not to call GetSeq_class_level method.
    bool CanGetSeq_class_level(void) const;
    void ResetSeq_class_level(void);
    void SetDefaultSeq_class_level(void);
    TSeq_class_level GetSeq_class_level(void) const;
    void SetSeq_class_level(TSeq_class_level value);
    TSeq_class_level& SetSeq_class_level(void);

    /// Seq-entry level for descriptors
    /// optional with default 1
    /// typedef int TDescr_level
    ///  Check whether the Descr_level data member has been assigned a value.
    bool IsSetDescr_level(void) const;
    /// Check whether it is safe or not to call GetDescr_level method.
    bool CanGetDescr_level(void) const;
    void ResetDescr_level(void);
    void SetDefaultDescr_level(void);
    TDescr_level GetDescr_level(void) const;
    void SetDescr_level(TDescr_level value);
    TDescr_level& SetDescr_level(void);

    /// mask of descriptor types - see Seqdesc for variants' values
    /// optional with default 0
    /// typedef int TDescr_type_mask
    ///  Check whether the Descr_type_mask data member has been assigned a value.
    bool IsSetDescr_type_mask(void) const;
    /// Check whether it is safe or not to call GetDescr_type_mask method.
    bool CanGetDescr_type_mask(void) const;
    void ResetDescr_type_mask(void);
    void SetDefaultDescr_type_mask(void);
    TDescr_type_mask GetDescr_type_mask(void) const;
    void SetDescr_type_mask(TDescr_type_mask value);
    TDescr_type_mask& SetDescr_type_mask(void);

    /// mask of annotation types - see Seq-annot.data for values
    /// optional with default 0
    /// typedef int TAnnot_type_mask
    ///  Check whether the Annot_type_mask data member has been assigned a value.
    bool IsSetAnnot_type_mask(void) const;
    /// Check whether it is safe or not to call GetAnnot_type_mask method.
    bool CanGetAnnot_type_mask(void) const;
    void ResetAnnot_type_mask(void);
    void SetDefaultAnnot_type_mask(void);
    TAnnot_type_mask GetAnnot_type_mask(void) const;
    void SetAnnot_type_mask(TAnnot_type_mask value);
    TAnnot_type_mask& SetAnnot_type_mask(void);

    /// mask of feature types - see SeqFeatData for values
    /// optional with default 0
    /// typedef int TFeat_type_mask
    ///  Check whether the Feat_type_mask data member has been assigned a value.
    bool IsSetFeat_type_mask(void) const;
    /// Check whether it is safe or not to call GetFeat_type_mask method.
    bool CanGetFeat_type_mask(void) const;
    void ResetFeat_type_mask(void);
    void SetDefaultFeat_type_mask(void);
    TFeat_type_mask GetFeat_type_mask(void) const;
    void SetFeat_type_mask(TFeat_type_mask value);
    TFeat_type_mask& SetFeat_type_mask(void);

    /// optional with default eSequence_level_none
    /// typedef ESequence_level TSequence_level
    ///  Check whether the Sequence_level data member has been assigned a value.
    bool IsSetSequence_level(void) const;
    /// Check whether it is safe or not to call GetSequence_level method.
    bool CanGetSequence_level(void) const;
    void ResetSequence_level(void);
    void SetDefaultSequence_level(void);
    TSequence_level GetSequence_level(void) const;
    void SetSequence_level(TSequence_level value);
    TSequence_level& SetSequence_level(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2_Get_Blob_Details_Base(const CID2_Get_Blob_Details_Base&);
    CID2_Get_Blob_Details_Base& operator=(const CID2_Get_Blob_Details_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TLocation > m_Location;
    int m_Seq_class_level;
    int m_Descr_level;
    int m_Descr_type_mask;
    int m_Annot_type_mask;
    int m_Feat_type_mask;
    ESequence_level m_Sequence_level;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID2_Get_Blob_Details_Base::IsSetLocation(void) const
{
    return m_Location.NotEmpty();
}

inline
bool CID2_Get_Blob_Details_Base::CanGetLocation(void) const
{
    return IsSetLocation();
}

inline
const CID2_Get_Blob_Details_Base::TLocation& CID2_Get_Blob_Details_Base::GetLocation(void) const
{
    if (!CanGetLocation()) {
        ThrowUnassigned(0);
    }
    return (*m_Location);
}

inline
bool CID2_Get_Blob_Details_Base::IsSetSeq_class_level(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetSeq_class_level(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetSeq_class_level(void)
{
    m_Seq_class_level = 1;
    m_set_State[0] &= ~0xc;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultSeq_class_level(void)
{
    ResetSeq_class_level();
}

inline
CID2_Get_Blob_Details_Base::TSeq_class_level CID2_Get_Blob_Details_Base::GetSeq_class_level(void) const
{
    return m_Seq_class_level;
}

inline
void CID2_Get_Blob_Details_Base::SetSeq_class_level(CID2_Get_Blob_Details_Base::TSeq_class_level value)
{
    m_Seq_class_level = value;
    m_set_State[0] |= 0xc;
}

inline
CID2_Get_Blob_Details_Base::TSeq_class_level& CID2_Get_Blob_Details_Base::SetSeq_class_level(void)
{
#ifdef _DEBUG
    if (!IsSetSeq_class_level()) {
        memset(&m_Seq_class_level,UnassignedByte(),sizeof(m_Seq_class_level));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Seq_class_level;
}

inline
bool CID2_Get_Blob_Details_Base::IsSetDescr_level(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetDescr_level(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetDescr_level(void)
{
    m_Descr_level = 1;
    m_set_State[0] &= ~0x30;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultDescr_level(void)
{
    ResetDescr_level();
}

inline
CID2_Get_Blob_Details_Base::TDescr_level CID2_Get_Blob_Details_Base::GetDescr_level(void) const
{
    return m_Descr_level;
}

inline
void CID2_Get_Blob_Details_Base::SetDescr_level(CID2_Get_Blob_Details_Base::TDescr_level value)
{
    m_Descr_level = value;
    m_set_State[0] |= 0x30;
}

inline
CID2_Get_Blob_Details_Base::TDescr_level& CID2_Get_Blob_Details_Base::SetDescr_level(void)
{
#ifdef _DEBUG
    if (!IsSetDescr_level()) {
        memset(&m_Descr_level,UnassignedByte(),sizeof(m_Descr_level));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Descr_level;
}

inline
bool CID2_Get_Blob_Details_Base::IsSetDescr_type_mask(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetDescr_type_mask(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetDescr_type_mask(void)
{
    m_Descr_type_mask = 0;
    m_set_State[0] &= ~0xc0;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultDescr_type_mask(void)
{
    ResetDescr_type_mask();
}

inline
CID2_Get_Blob_Details_Base::TDescr_type_mask CID2_Get_Blob_Details_Base::GetDescr_type_mask(void) const
{
    return m_Descr_type_mask;
}

inline
void CID2_Get_Blob_Details_Base::SetDescr_type_mask(CID2_Get_Blob_Details_Base::TDescr_type_mask value)
{
    m_Descr_type_mask = value;
    m_set_State[0] |= 0xc0;
}

inline
CID2_Get_Blob_Details_Base::TDescr_type_mask& CID2_Get_Blob_Details_Base::SetDescr_type_mask(void)
{
#ifdef _DEBUG
    if (!IsSetDescr_type_mask()) {
        memset(&m_Descr_type_mask,UnassignedByte(),sizeof(m_Descr_type_mask));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Descr_type_mask;
}

inline
bool CID2_Get_Blob_Details_Base::IsSetAnnot_type_mask(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetAnnot_type_mask(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetAnnot_type_mask(void)
{
    m_Annot_type_mask = 0;
    m_set_State[0] &= ~0x300;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultAnnot_type_mask(void)
{
    ResetAnnot_type_mask();
}

inline
CID2_Get_Blob_Details_Base::TAnnot_type_mask CID2_Get_Blob_Details_Base::GetAnnot_type_mask(void) const
{
    return m_Annot_type_mask;
}

inline
void CID2_Get_Blob_Details_Base::SetAnnot_type_mask(CID2_Get_Blob_Details_Base::TAnnot_type_mask value)
{
    m_Annot_type_mask = value;
    m_set_State[0] |= 0x300;
}

inline
CID2_Get_Blob_Details_Base::TAnnot_type_mask& CID2_Get_Blob_Details_Base::SetAnnot_type_mask(void)
{
#ifdef _DEBUG
    if (!IsSetAnnot_type_mask()) {
        memset(&m_Annot_type_mask,UnassignedByte(),sizeof(m_Annot_type_mask));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Annot_type_mask;
}

inline
bool CID2_Get_Blob_Details_Base::IsSetFeat_type_mask(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetFeat_type_mask(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetFeat_type_mask(void)
{
    m_Feat_type_mask = 0;
    m_set_State[0] &= ~0xc00;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultFeat_type_mask(void)
{
    ResetFeat_type_mask();
}

inline
CID2_Get_Blob_Details_Base::TFeat_type_mask CID2_Get_Blob_Details_Base::GetFeat_type_mask(void) const
{
    return m_Feat_type_mask;
}

inline
void CID2_Get_Blob_Details_Base::SetFeat_type_mask(CID2_Get_Blob_Details_Base::TFeat_type_mask value)
{
    m_Feat_type_mask = value;
    m_set_State[0] |= 0xc00;
}

inline
CID2_Get_Blob_Details_Base::TFeat_type_mask& CID2_Get_Blob_Details_Base::SetFeat_type_mask(void)
{
#ifdef _DEBUG
    if (!IsSetFeat_type_mask()) {
        memset(&m_Feat_type_mask,UnassignedByte(),sizeof(m_Feat_type_mask));
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Feat_type_mask;
}

inline
bool CID2_Get_Blob_Details_Base::IsSetSequence_level(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CID2_Get_Blob_Details_Base::CanGetSequence_level(void) const
{
    return true;
}

inline
void CID2_Get_Blob_Details_Base::ResetSequence_level(void)
{
    m_Sequence_level = eSequence_level_none;
    m_set_State[0] &= ~0x3000;
}

inline
void CID2_Get_Blob_Details_Base::SetDefaultSequence_level(void)
{
    ResetSequence_level();
}

inline
CID2_Get_Blob_Details_Base::TSequence_level CID2_Get_Blob_Details_Base::GetSequence_level(void) const
{
    return m_Sequence_level;
}

inline
void CID2_Get_Blob_Details_Base::SetSequence_level(CID2_Get_Blob_Details_Base::TSequence_level value)
{
    m_Sequence_level = value;
    m_set_State[0] |= 0x3000;
}

inline
CID2_Get_Blob_Details_Base::TSequence_level& CID2_Get_Blob_Details_Base::SetSequence_level(void)
{
#ifdef _DEBUG
    if (!IsSetSequence_level()) {
        memset(&m_Sequence_level,UnassignedByte(),sizeof(m_Sequence_level));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Sequence_level;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID2_ID2_GET_BLOB_DETAILS_BASE_HPP
