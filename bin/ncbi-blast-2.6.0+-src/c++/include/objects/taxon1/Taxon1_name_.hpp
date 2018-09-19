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

/// @file Taxon1_name_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'taxon1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TAXON1_TAXON1_NAME_BASE_HPP
#define OBJECTS_TAXON1_TAXON1_NAME_BASE_HPP

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
class NCBI_TAXON1_EXPORT CTaxon1_name_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTaxon1_name_Base(void);
    // destructor
    virtual ~CTaxon1_name_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef NCBI_NS_NCBI::TEntrezId TTaxid;
    typedef NCBI_NS_NCBI::TEntrezId TCde;
    typedef string TOname;
    typedef string TUname;

    // getters
    // setters

    /// mandatory
    /// typedef NCBI_NS_NCBI::TEntrezId TTaxid
    ///  Check whether the Taxid data member has been assigned a value.
    bool IsSetTaxid(void) const;
    /// Check whether it is safe or not to call GetTaxid method.
    bool CanGetTaxid(void) const;
    void ResetTaxid(void);
    TTaxid GetTaxid(void) const;
    void SetTaxid(TTaxid value);
    TTaxid& SetTaxid(void);

    /// mandatory
    /// typedef NCBI_NS_NCBI::TEntrezId TCde
    ///  Check whether the Cde data member has been assigned a value.
    bool IsSetCde(void) const;
    /// Check whether it is safe or not to call GetCde method.
    bool CanGetCde(void) const;
    void ResetCde(void);
    TCde GetCde(void) const;
    void SetCde(TCde value);
    TCde& SetCde(void);

    /// optional
    /// typedef string TOname
    ///  Check whether the Oname data member has been assigned a value.
    bool IsSetOname(void) const;
    /// Check whether it is safe or not to call GetOname method.
    bool CanGetOname(void) const;
    void ResetOname(void);
    const TOname& GetOname(void) const;
    void SetOname(const TOname& value);
    TOname& SetOname(void);

    /// optional
    /// typedef string TUname
    ///  Check whether the Uname data member has been assigned a value.
    bool IsSetUname(void) const;
    /// Check whether it is safe or not to call GetUname method.
    bool CanGetUname(void) const;
    void ResetUname(void);
    const TUname& GetUname(void) const;
    void SetUname(const TUname& value);
    TUname& SetUname(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTaxon1_name_Base(const CTaxon1_name_Base&);
    CTaxon1_name_Base& operator=(const CTaxon1_name_Base&);

    // data
    Uint4 m_set_State[1];
    ncbi::TIntId m_Taxid;
    ncbi::TIntId m_Cde;
    string m_Oname;
    string m_Uname;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTaxon1_name_Base::IsSetTaxid(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CTaxon1_name_Base::CanGetTaxid(void) const
{
    return IsSetTaxid();
}

inline
void CTaxon1_name_Base::ResetTaxid(void)
{
    m_Taxid = 0;
    m_set_State[0] &= ~0x3;
}

inline
CTaxon1_name_Base::TTaxid CTaxon1_name_Base::GetTaxid(void) const
{
    if (!CanGetTaxid()) {
        ThrowUnassigned(0);
    }
    return reinterpret_cast<const TTaxid&>(m_Taxid);
}

inline
void CTaxon1_name_Base::SetTaxid(CTaxon1_name_Base::TTaxid value)
{
    reinterpret_cast<TTaxid&>(m_Taxid) = value;
    m_set_State[0] |= 0x3;
}

inline
CTaxon1_name_Base::TTaxid& CTaxon1_name_Base::SetTaxid(void)
{
#ifdef _DEBUG
    if (!IsSetTaxid()) {
        memset(&m_Taxid,UnassignedByte(),sizeof(m_Taxid));
    }
#endif
    m_set_State[0] |= 0x1;
    return reinterpret_cast<TTaxid&>(m_Taxid);
}

inline
bool CTaxon1_name_Base::IsSetCde(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTaxon1_name_Base::CanGetCde(void) const
{
    return IsSetCde();
}

inline
void CTaxon1_name_Base::ResetCde(void)
{
    m_Cde = 0;
    m_set_State[0] &= ~0xc;
}

inline
CTaxon1_name_Base::TCde CTaxon1_name_Base::GetCde(void) const
{
    if (!CanGetCde()) {
        ThrowUnassigned(1);
    }
    return reinterpret_cast<const TCde&>(m_Cde);
}

inline
void CTaxon1_name_Base::SetCde(CTaxon1_name_Base::TCde value)
{
    reinterpret_cast<TCde&>(m_Cde) = value;
    m_set_State[0] |= 0xc;
}

inline
CTaxon1_name_Base::TCde& CTaxon1_name_Base::SetCde(void)
{
#ifdef _DEBUG
    if (!IsSetCde()) {
        memset(&m_Cde,UnassignedByte(),sizeof(m_Cde));
    }
#endif
    m_set_State[0] |= 0x4;
    return reinterpret_cast<TCde&>(m_Cde);
}

inline
bool CTaxon1_name_Base::IsSetOname(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CTaxon1_name_Base::CanGetOname(void) const
{
    return IsSetOname();
}

inline
const CTaxon1_name_Base::TOname& CTaxon1_name_Base::GetOname(void) const
{
    if (!CanGetOname()) {
        ThrowUnassigned(2);
    }
    return m_Oname;
}

inline
void CTaxon1_name_Base::SetOname(const CTaxon1_name_Base::TOname& value)
{
    m_Oname = value;
    m_set_State[0] |= 0x30;
}

inline
CTaxon1_name_Base::TOname& CTaxon1_name_Base::SetOname(void)
{
#ifdef _DEBUG
    if (!IsSetOname()) {
        m_Oname = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Oname;
}

inline
bool CTaxon1_name_Base::IsSetUname(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CTaxon1_name_Base::CanGetUname(void) const
{
    return IsSetUname();
}

inline
const CTaxon1_name_Base::TUname& CTaxon1_name_Base::GetUname(void) const
{
    if (!CanGetUname()) {
        ThrowUnassigned(3);
    }
    return m_Uname;
}

inline
void CTaxon1_name_Base::SetUname(const CTaxon1_name_Base::TUname& value)
{
    m_Uname = value;
    m_set_State[0] |= 0xc0;
}

inline
CTaxon1_name_Base::TUname& CTaxon1_name_Base::SetUname(void)
{
#ifdef _DEBUG
    if (!IsSetUname()) {
        m_Uname = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Uname;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TAXON1_TAXON1_NAME_BASE_HPP
