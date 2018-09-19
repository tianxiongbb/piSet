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

/// @file Remap_query_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'remap.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_REMAP_REMAP_QUERY_BASE_HPP
#define OBJECTS_REMAP_REMAP_QUERY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

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
class NCBI_REMAP_EXPORT CRemap_query_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CRemap_query_Base(void);
    // destructor
    virtual ~CRemap_query_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TFrom_build;
    typedef string TTo_build;
    typedef list< CRef< CSeq_loc > > TLocs;

    // getters
    // setters

    /// build to map from
    /// mandatory
    /// typedef string TFrom_build
    ///  Check whether the From_build data member has been assigned a value.
    bool IsSetFrom_build(void) const;
    /// Check whether it is safe or not to call GetFrom_build method.
    bool CanGetFrom_build(void) const;
    void ResetFrom_build(void);
    const TFrom_build& GetFrom_build(void) const;
    void SetFrom_build(const TFrom_build& value);
    TFrom_build& SetFrom_build(void);

    /// build to map to
    /// mandatory
    /// typedef string TTo_build
    ///  Check whether the To_build data member has been assigned a value.
    bool IsSetTo_build(void) const;
    /// Check whether it is safe or not to call GetTo_build method.
    bool CanGetTo_build(void) const;
    void ResetTo_build(void);
    const TTo_build& GetTo_build(void) const;
    void SetTo_build(const TTo_build& value);
    TTo_build& SetTo_build(void);

    /// the locations to remap
    /// mandatory
    /// typedef list< CRef< CSeq_loc > > TLocs
    ///  Check whether the Locs data member has been assigned a value.
    bool IsSetLocs(void) const;
    /// Check whether it is safe or not to call GetLocs method.
    bool CanGetLocs(void) const;
    void ResetLocs(void);
    const TLocs& GetLocs(void) const;
    TLocs& SetLocs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CRemap_query_Base(const CRemap_query_Base&);
    CRemap_query_Base& operator=(const CRemap_query_Base&);

    // data
    Uint4 m_set_State[1];
    string m_From_build;
    string m_To_build;
    list< CRef< CSeq_loc > > m_Locs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CRemap_query_Base::IsSetFrom_build(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CRemap_query_Base::CanGetFrom_build(void) const
{
    return IsSetFrom_build();
}

inline
const CRemap_query_Base::TFrom_build& CRemap_query_Base::GetFrom_build(void) const
{
    if (!CanGetFrom_build()) {
        ThrowUnassigned(0);
    }
    return m_From_build;
}

inline
void CRemap_query_Base::SetFrom_build(const CRemap_query_Base::TFrom_build& value)
{
    m_From_build = value;
    m_set_State[0] |= 0x3;
}

inline
CRemap_query_Base::TFrom_build& CRemap_query_Base::SetFrom_build(void)
{
#ifdef _DEBUG
    if (!IsSetFrom_build()) {
        m_From_build = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_From_build;
}

inline
bool CRemap_query_Base::IsSetTo_build(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CRemap_query_Base::CanGetTo_build(void) const
{
    return IsSetTo_build();
}

inline
const CRemap_query_Base::TTo_build& CRemap_query_Base::GetTo_build(void) const
{
    if (!CanGetTo_build()) {
        ThrowUnassigned(1);
    }
    return m_To_build;
}

inline
void CRemap_query_Base::SetTo_build(const CRemap_query_Base::TTo_build& value)
{
    m_To_build = value;
    m_set_State[0] |= 0xc;
}

inline
CRemap_query_Base::TTo_build& CRemap_query_Base::SetTo_build(void)
{
#ifdef _DEBUG
    if (!IsSetTo_build()) {
        m_To_build = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_To_build;
}

inline
bool CRemap_query_Base::IsSetLocs(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CRemap_query_Base::CanGetLocs(void) const
{
    return true;
}

inline
const CRemap_query_Base::TLocs& CRemap_query_Base::GetLocs(void) const
{
    return m_Locs;
}

inline
CRemap_query_Base::TLocs& CRemap_query_Base::SetLocs(void)
{
    m_set_State[0] |= 0x10;
    return m_Locs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_REMAP_REMAP_QUERY_BASE_HPP
