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

/// @file Taxon1_data_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'taxon1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TAXON1_TAXON1_DATA_BASE_HPP
#define OBJECTS_TAXON1_TAXON1_DATA_BASE_HPP

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


// forward declarations
class COrg_ref;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TAXON1_EXPORT CTaxon1_data_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTaxon1_data_Base(void);
    // destructor
    virtual ~CTaxon1_data_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef COrg_ref TOrg;
    typedef string TDiv;
    typedef string TEmbl_code;
    typedef bool TIs_species_level;

    // getters
    // setters

    /// Org-ref with Org-name and db filled in
    /// optional
    /// typedef COrg_ref TOrg
    ///  Check whether the Org data member has been assigned a value.
    bool IsSetOrg(void) const;
    /// Check whether it is safe or not to call GetOrg method.
    bool CanGetOrg(void) const;
    void ResetOrg(void);
    const TOrg& GetOrg(void) const;
    void SetOrg(TOrg& value);
    TOrg& SetOrg(void);

    /// GenBank division
    /// mandatory
    /// typedef string TDiv
    ///  Check whether the Div data member has been assigned a value.
    bool IsSetDiv(void) const;
    /// Check whether it is safe or not to call GetDiv method.
    bool CanGetDiv(void) const;
    void ResetDiv(void);
    const TDiv& GetDiv(void) const;
    void SetDiv(const TDiv& value);
    TDiv& SetDiv(void);

    /// 2 letter EMBL code
    /// optional
    /// typedef string TEmbl_code
    ///  Check whether the Embl_code data member has been assigned a value.
    bool IsSetEmbl_code(void) const;
    /// Check whether it is safe or not to call GetEmbl_code method.
    bool CanGetEmbl_code(void) const;
    void ResetEmbl_code(void);
    const TEmbl_code& GetEmbl_code(void) const;
    void SetEmbl_code(const TEmbl_code& value);
    TEmbl_code& SetEmbl_code(void);

    /// species level or below
    /// mandatory
    /// typedef bool TIs_species_level
    ///  Check whether the Is_species_level data member has been assigned a value.
    bool IsSetIs_species_level(void) const;
    /// Check whether it is safe or not to call GetIs_species_level method.
    bool CanGetIs_species_level(void) const;
    void ResetIs_species_level(void);
    TIs_species_level GetIs_species_level(void) const;
    void SetIs_species_level(TIs_species_level value);
    TIs_species_level& SetIs_species_level(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTaxon1_data_Base(const CTaxon1_data_Base&);
    CTaxon1_data_Base& operator=(const CTaxon1_data_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TOrg > m_Org;
    string m_Div;
    string m_Embl_code;
    bool m_Is_species_level;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTaxon1_data_Base::IsSetOrg(void) const
{
    return m_Org.NotEmpty();
}

inline
bool CTaxon1_data_Base::CanGetOrg(void) const
{
    return IsSetOrg();
}

inline
const CTaxon1_data_Base::TOrg& CTaxon1_data_Base::GetOrg(void) const
{
    if (!CanGetOrg()) {
        ThrowUnassigned(0);
    }
    return (*m_Org);
}

inline
bool CTaxon1_data_Base::IsSetDiv(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTaxon1_data_Base::CanGetDiv(void) const
{
    return IsSetDiv();
}

inline
const CTaxon1_data_Base::TDiv& CTaxon1_data_Base::GetDiv(void) const
{
    if (!CanGetDiv()) {
        ThrowUnassigned(1);
    }
    return m_Div;
}

inline
void CTaxon1_data_Base::SetDiv(const CTaxon1_data_Base::TDiv& value)
{
    m_Div = value;
    m_set_State[0] |= 0xc;
}

inline
CTaxon1_data_Base::TDiv& CTaxon1_data_Base::SetDiv(void)
{
#ifdef _DEBUG
    if (!IsSetDiv()) {
        m_Div = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Div;
}

inline
bool CTaxon1_data_Base::IsSetEmbl_code(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CTaxon1_data_Base::CanGetEmbl_code(void) const
{
    return IsSetEmbl_code();
}

inline
const CTaxon1_data_Base::TEmbl_code& CTaxon1_data_Base::GetEmbl_code(void) const
{
    if (!CanGetEmbl_code()) {
        ThrowUnassigned(2);
    }
    return m_Embl_code;
}

inline
void CTaxon1_data_Base::SetEmbl_code(const CTaxon1_data_Base::TEmbl_code& value)
{
    m_Embl_code = value;
    m_set_State[0] |= 0x30;
}

inline
CTaxon1_data_Base::TEmbl_code& CTaxon1_data_Base::SetEmbl_code(void)
{
#ifdef _DEBUG
    if (!IsSetEmbl_code()) {
        m_Embl_code = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Embl_code;
}

inline
bool CTaxon1_data_Base::IsSetIs_species_level(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CTaxon1_data_Base::CanGetIs_species_level(void) const
{
    return IsSetIs_species_level();
}

inline
void CTaxon1_data_Base::ResetIs_species_level(void)
{
    m_Is_species_level = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CTaxon1_data_Base::TIs_species_level CTaxon1_data_Base::GetIs_species_level(void) const
{
    if (!CanGetIs_species_level()) {
        ThrowUnassigned(3);
    }
    return m_Is_species_level;
}

inline
void CTaxon1_data_Base::SetIs_species_level(CTaxon1_data_Base::TIs_species_level value)
{
    m_Is_species_level = value;
    m_set_State[0] |= 0xc0;
}

inline
CTaxon1_data_Base::TIs_species_level& CTaxon1_data_Base::SetIs_species_level(void)
{
#ifdef _DEBUG
    if (!IsSetIs_species_level()) {
        memset(&m_Is_species_level,UnassignedByte(),sizeof(m_Is_species_level));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Is_species_level;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TAXON1_TAXON1_DATA_BASE_HPP
