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

/// @file MSBioseq_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'omssa.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OMSSA_MSBIOSEQ_BASE_HPP
#define OBJECTS_OMSSA_MSBIOSEQ_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CBioseq;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// bioseq container
class NCBI_OMSSA_EXPORT CMSBioseq_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMSBioseq_Base(void);
    // destructor
    virtual ~CMSBioseq_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TOid;
    typedef CBioseq TSeq;

    // getters
    // setters

    /// blast library oid
    /// mandatory
    /// typedef int TOid
    ///  Check whether the Oid data member has been assigned a value.
    bool IsSetOid(void) const;
    /// Check whether it is safe or not to call GetOid method.
    bool CanGetOid(void) const;
    void ResetOid(void);
    TOid GetOid(void) const;
    void SetOid(TOid value);
    TOid& SetOid(void);

    /// mandatory
    /// typedef CBioseq TSeq
    ///  Check whether the Seq data member has been assigned a value.
    bool IsSetSeq(void) const;
    /// Check whether it is safe or not to call GetSeq method.
    bool CanGetSeq(void) const;
    void ResetSeq(void);
    const TSeq& GetSeq(void) const;
    void SetSeq(TSeq& value);
    TSeq& SetSeq(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMSBioseq_Base(const CMSBioseq_Base&);
    CMSBioseq_Base& operator=(const CMSBioseq_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Oid;
    CRef< TSeq > m_Seq;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMSBioseq_Base::IsSetOid(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMSBioseq_Base::CanGetOid(void) const
{
    return IsSetOid();
}

inline
void CMSBioseq_Base::ResetOid(void)
{
    m_Oid = 0;
    m_set_State[0] &= ~0x3;
}

inline
CMSBioseq_Base::TOid CMSBioseq_Base::GetOid(void) const
{
    if (!CanGetOid()) {
        ThrowUnassigned(0);
    }
    return m_Oid;
}

inline
void CMSBioseq_Base::SetOid(CMSBioseq_Base::TOid value)
{
    m_Oid = value;
    m_set_State[0] |= 0x3;
}

inline
CMSBioseq_Base::TOid& CMSBioseq_Base::SetOid(void)
{
#ifdef _DEBUG
    if (!IsSetOid()) {
        memset(&m_Oid,UnassignedByte(),sizeof(m_Oid));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Oid;
}

inline
bool CMSBioseq_Base::IsSetSeq(void) const
{
    return m_Seq.NotEmpty();
}

inline
bool CMSBioseq_Base::CanGetSeq(void) const
{
    return true;
}

inline
const CMSBioseq_Base::TSeq& CMSBioseq_Base::GetSeq(void) const
{
    if ( !m_Seq ) {
        const_cast<CMSBioseq_Base*>(this)->ResetSeq();
    }
    return (*m_Seq);
}

inline
CMSBioseq_Base::TSeq& CMSBioseq_Base::SetSeq(void)
{
    if ( !m_Seq ) {
        ResetSeq();
    }
    return (*m_Seq);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OMSSA_MSBIOSEQ_BASE_HPP
