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

/// @file T3RefreshFlags_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'taxon3.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TAXON3_T3REFRESHFLAGS_BASE_HPP
#define OBJECTS_TAXON3_T3REFRESHFLAGS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TAXON3_EXPORT CT3RefreshFlags_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CT3RefreshFlags_Base(void);
    // destructor
    virtual ~CT3RefreshFlags_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef bool TTaxid_changed;
    typedef bool TTaxname_changed;
    typedef bool TDivision_changed;
    typedef bool TLineage_changed;
    typedef bool TGc_changed;
    typedef bool TMgc_changed;
    typedef bool TOrgmod_changed;
    typedef bool TPgc_changed;

    // getters
    // setters

    /// mandatory
    /// typedef bool TTaxid_changed
    ///  Check whether the Taxid_changed data member has been assigned a value.
    bool IsSetTaxid_changed(void) const;
    /// Check whether it is safe or not to call GetTaxid_changed method.
    bool CanGetTaxid_changed(void) const;
    void ResetTaxid_changed(void);
    TTaxid_changed GetTaxid_changed(void) const;
    void SetTaxid_changed(TTaxid_changed value);
    TTaxid_changed& SetTaxid_changed(void);

    /// mandatory
    /// typedef bool TTaxname_changed
    ///  Check whether the Taxname_changed data member has been assigned a value.
    bool IsSetTaxname_changed(void) const;
    /// Check whether it is safe or not to call GetTaxname_changed method.
    bool CanGetTaxname_changed(void) const;
    void ResetTaxname_changed(void);
    TTaxname_changed GetTaxname_changed(void) const;
    void SetTaxname_changed(TTaxname_changed value);
    TTaxname_changed& SetTaxname_changed(void);

    /// mandatory
    /// typedef bool TDivision_changed
    ///  Check whether the Division_changed data member has been assigned a value.
    bool IsSetDivision_changed(void) const;
    /// Check whether it is safe or not to call GetDivision_changed method.
    bool CanGetDivision_changed(void) const;
    void ResetDivision_changed(void);
    TDivision_changed GetDivision_changed(void) const;
    void SetDivision_changed(TDivision_changed value);
    TDivision_changed& SetDivision_changed(void);

    /// mandatory
    /// typedef bool TLineage_changed
    ///  Check whether the Lineage_changed data member has been assigned a value.
    bool IsSetLineage_changed(void) const;
    /// Check whether it is safe or not to call GetLineage_changed method.
    bool CanGetLineage_changed(void) const;
    void ResetLineage_changed(void);
    TLineage_changed GetLineage_changed(void) const;
    void SetLineage_changed(TLineage_changed value);
    TLineage_changed& SetLineage_changed(void);

    /// mandatory
    /// typedef bool TGc_changed
    ///  Check whether the Gc_changed data member has been assigned a value.
    bool IsSetGc_changed(void) const;
    /// Check whether it is safe or not to call GetGc_changed method.
    bool CanGetGc_changed(void) const;
    void ResetGc_changed(void);
    TGc_changed GetGc_changed(void) const;
    void SetGc_changed(TGc_changed value);
    TGc_changed& SetGc_changed(void);

    /// mandatory
    /// typedef bool TMgc_changed
    ///  Check whether the Mgc_changed data member has been assigned a value.
    bool IsSetMgc_changed(void) const;
    /// Check whether it is safe or not to call GetMgc_changed method.
    bool CanGetMgc_changed(void) const;
    void ResetMgc_changed(void);
    TMgc_changed GetMgc_changed(void) const;
    void SetMgc_changed(TMgc_changed value);
    TMgc_changed& SetMgc_changed(void);

    /// mandatory
    /// typedef bool TOrgmod_changed
    ///  Check whether the Orgmod_changed data member has been assigned a value.
    bool IsSetOrgmod_changed(void) const;
    /// Check whether it is safe or not to call GetOrgmod_changed method.
    bool CanGetOrgmod_changed(void) const;
    void ResetOrgmod_changed(void);
    TOrgmod_changed GetOrgmod_changed(void) const;
    void SetOrgmod_changed(TOrgmod_changed value);
    TOrgmod_changed& SetOrgmod_changed(void);

    /// optional
    /// typedef bool TPgc_changed
    ///  Check whether the Pgc_changed data member has been assigned a value.
    bool IsSetPgc_changed(void) const;
    /// Check whether it is safe or not to call GetPgc_changed method.
    bool CanGetPgc_changed(void) const;
    void ResetPgc_changed(void);
    TPgc_changed GetPgc_changed(void) const;
    void SetPgc_changed(TPgc_changed value);
    TPgc_changed& SetPgc_changed(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CT3RefreshFlags_Base(const CT3RefreshFlags_Base&);
    CT3RefreshFlags_Base& operator=(const CT3RefreshFlags_Base&);

    // data
    Uint4 m_set_State[1];
    bool m_Taxid_changed;
    bool m_Taxname_changed;
    bool m_Division_changed;
    bool m_Lineage_changed;
    bool m_Gc_changed;
    bool m_Mgc_changed;
    bool m_Orgmod_changed;
    bool m_Pgc_changed;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CT3RefreshFlags_Base::IsSetTaxid_changed(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetTaxid_changed(void) const
{
    return IsSetTaxid_changed();
}

inline
void CT3RefreshFlags_Base::ResetTaxid_changed(void)
{
    m_Taxid_changed = 0;
    m_set_State[0] &= ~0x3;
}

inline
CT3RefreshFlags_Base::TTaxid_changed CT3RefreshFlags_Base::GetTaxid_changed(void) const
{
    if (!CanGetTaxid_changed()) {
        ThrowUnassigned(0);
    }
    return m_Taxid_changed;
}

inline
void CT3RefreshFlags_Base::SetTaxid_changed(CT3RefreshFlags_Base::TTaxid_changed value)
{
    m_Taxid_changed = value;
    m_set_State[0] |= 0x3;
}

inline
CT3RefreshFlags_Base::TTaxid_changed& CT3RefreshFlags_Base::SetTaxid_changed(void)
{
#ifdef _DEBUG
    if (!IsSetTaxid_changed()) {
        memset(&m_Taxid_changed,UnassignedByte(),sizeof(m_Taxid_changed));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Taxid_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetTaxname_changed(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetTaxname_changed(void) const
{
    return IsSetTaxname_changed();
}

inline
void CT3RefreshFlags_Base::ResetTaxname_changed(void)
{
    m_Taxname_changed = 0;
    m_set_State[0] &= ~0xc;
}

inline
CT3RefreshFlags_Base::TTaxname_changed CT3RefreshFlags_Base::GetTaxname_changed(void) const
{
    if (!CanGetTaxname_changed()) {
        ThrowUnassigned(1);
    }
    return m_Taxname_changed;
}

inline
void CT3RefreshFlags_Base::SetTaxname_changed(CT3RefreshFlags_Base::TTaxname_changed value)
{
    m_Taxname_changed = value;
    m_set_State[0] |= 0xc;
}

inline
CT3RefreshFlags_Base::TTaxname_changed& CT3RefreshFlags_Base::SetTaxname_changed(void)
{
#ifdef _DEBUG
    if (!IsSetTaxname_changed()) {
        memset(&m_Taxname_changed,UnassignedByte(),sizeof(m_Taxname_changed));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Taxname_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetDivision_changed(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetDivision_changed(void) const
{
    return IsSetDivision_changed();
}

inline
void CT3RefreshFlags_Base::ResetDivision_changed(void)
{
    m_Division_changed = 0;
    m_set_State[0] &= ~0x30;
}

inline
CT3RefreshFlags_Base::TDivision_changed CT3RefreshFlags_Base::GetDivision_changed(void) const
{
    if (!CanGetDivision_changed()) {
        ThrowUnassigned(2);
    }
    return m_Division_changed;
}

inline
void CT3RefreshFlags_Base::SetDivision_changed(CT3RefreshFlags_Base::TDivision_changed value)
{
    m_Division_changed = value;
    m_set_State[0] |= 0x30;
}

inline
CT3RefreshFlags_Base::TDivision_changed& CT3RefreshFlags_Base::SetDivision_changed(void)
{
#ifdef _DEBUG
    if (!IsSetDivision_changed()) {
        memset(&m_Division_changed,UnassignedByte(),sizeof(m_Division_changed));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Division_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetLineage_changed(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetLineage_changed(void) const
{
    return IsSetLineage_changed();
}

inline
void CT3RefreshFlags_Base::ResetLineage_changed(void)
{
    m_Lineage_changed = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CT3RefreshFlags_Base::TLineage_changed CT3RefreshFlags_Base::GetLineage_changed(void) const
{
    if (!CanGetLineage_changed()) {
        ThrowUnassigned(3);
    }
    return m_Lineage_changed;
}

inline
void CT3RefreshFlags_Base::SetLineage_changed(CT3RefreshFlags_Base::TLineage_changed value)
{
    m_Lineage_changed = value;
    m_set_State[0] |= 0xc0;
}

inline
CT3RefreshFlags_Base::TLineage_changed& CT3RefreshFlags_Base::SetLineage_changed(void)
{
#ifdef _DEBUG
    if (!IsSetLineage_changed()) {
        memset(&m_Lineage_changed,UnassignedByte(),sizeof(m_Lineage_changed));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Lineage_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetGc_changed(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetGc_changed(void) const
{
    return IsSetGc_changed();
}

inline
void CT3RefreshFlags_Base::ResetGc_changed(void)
{
    m_Gc_changed = 0;
    m_set_State[0] &= ~0x300;
}

inline
CT3RefreshFlags_Base::TGc_changed CT3RefreshFlags_Base::GetGc_changed(void) const
{
    if (!CanGetGc_changed()) {
        ThrowUnassigned(4);
    }
    return m_Gc_changed;
}

inline
void CT3RefreshFlags_Base::SetGc_changed(CT3RefreshFlags_Base::TGc_changed value)
{
    m_Gc_changed = value;
    m_set_State[0] |= 0x300;
}

inline
CT3RefreshFlags_Base::TGc_changed& CT3RefreshFlags_Base::SetGc_changed(void)
{
#ifdef _DEBUG
    if (!IsSetGc_changed()) {
        memset(&m_Gc_changed,UnassignedByte(),sizeof(m_Gc_changed));
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Gc_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetMgc_changed(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetMgc_changed(void) const
{
    return IsSetMgc_changed();
}

inline
void CT3RefreshFlags_Base::ResetMgc_changed(void)
{
    m_Mgc_changed = 0;
    m_set_State[0] &= ~0xc00;
}

inline
CT3RefreshFlags_Base::TMgc_changed CT3RefreshFlags_Base::GetMgc_changed(void) const
{
    if (!CanGetMgc_changed()) {
        ThrowUnassigned(5);
    }
    return m_Mgc_changed;
}

inline
void CT3RefreshFlags_Base::SetMgc_changed(CT3RefreshFlags_Base::TMgc_changed value)
{
    m_Mgc_changed = value;
    m_set_State[0] |= 0xc00;
}

inline
CT3RefreshFlags_Base::TMgc_changed& CT3RefreshFlags_Base::SetMgc_changed(void)
{
#ifdef _DEBUG
    if (!IsSetMgc_changed()) {
        memset(&m_Mgc_changed,UnassignedByte(),sizeof(m_Mgc_changed));
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Mgc_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetOrgmod_changed(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetOrgmod_changed(void) const
{
    return IsSetOrgmod_changed();
}

inline
void CT3RefreshFlags_Base::ResetOrgmod_changed(void)
{
    m_Orgmod_changed = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CT3RefreshFlags_Base::TOrgmod_changed CT3RefreshFlags_Base::GetOrgmod_changed(void) const
{
    if (!CanGetOrgmod_changed()) {
        ThrowUnassigned(6);
    }
    return m_Orgmod_changed;
}

inline
void CT3RefreshFlags_Base::SetOrgmod_changed(CT3RefreshFlags_Base::TOrgmod_changed value)
{
    m_Orgmod_changed = value;
    m_set_State[0] |= 0x3000;
}

inline
CT3RefreshFlags_Base::TOrgmod_changed& CT3RefreshFlags_Base::SetOrgmod_changed(void)
{
#ifdef _DEBUG
    if (!IsSetOrgmod_changed()) {
        memset(&m_Orgmod_changed,UnassignedByte(),sizeof(m_Orgmod_changed));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Orgmod_changed;
}

inline
bool CT3RefreshFlags_Base::IsSetPgc_changed(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CT3RefreshFlags_Base::CanGetPgc_changed(void) const
{
    return IsSetPgc_changed();
}

inline
void CT3RefreshFlags_Base::ResetPgc_changed(void)
{
    m_Pgc_changed = 0;
    m_set_State[0] &= ~0xc000;
}

inline
CT3RefreshFlags_Base::TPgc_changed CT3RefreshFlags_Base::GetPgc_changed(void) const
{
    if (!CanGetPgc_changed()) {
        ThrowUnassigned(7);
    }
    return m_Pgc_changed;
}

inline
void CT3RefreshFlags_Base::SetPgc_changed(CT3RefreshFlags_Base::TPgc_changed value)
{
    m_Pgc_changed = value;
    m_set_State[0] |= 0xc000;
}

inline
CT3RefreshFlags_Base::TPgc_changed& CT3RefreshFlags_Base::SetPgc_changed(void)
{
#ifdef _DEBUG
    if (!IsSetPgc_changed()) {
        memset(&m_Pgc_changed,UnassignedByte(),sizeof(m_Pgc_changed));
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Pgc_changed;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TAXON3_T3REFRESHFLAGS_BASE_HPP
