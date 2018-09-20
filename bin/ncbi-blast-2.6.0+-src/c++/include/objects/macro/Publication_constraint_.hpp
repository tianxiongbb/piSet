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

/// @file Publication_constraint_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_PUBLICATION_CONSTRAINT_BASE_HPP
#define OBJECTS_MACRO_PUBLICATION_CONSTRAINT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/Pub_type.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CPub_field_constraint;
class CPub_field_special_constraint;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CPublication_constraint_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPublication_constraint_Base(void);
    // destructor
    virtual ~CPublication_constraint_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef EPub_type TType;
    typedef CPub_field_constraint TField;
    typedef CPub_field_special_constraint TSpecial_field;

    // getters
    // setters

    /// mandatory
    /// typedef EPub_type TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    TType GetType(void) const;
    void SetType(TType value);
    TType& SetType(void);

    /// optional
    /// typedef CPub_field_constraint TField
    ///  Check whether the Field data member has been assigned a value.
    bool IsSetField(void) const;
    /// Check whether it is safe or not to call GetField method.
    bool CanGetField(void) const;
    void ResetField(void);
    const TField& GetField(void) const;
    void SetField(TField& value);
    TField& SetField(void);

    /// optional
    /// typedef CPub_field_special_constraint TSpecial_field
    ///  Check whether the Special_field data member has been assigned a value.
    bool IsSetSpecial_field(void) const;
    /// Check whether it is safe or not to call GetSpecial_field method.
    bool CanGetSpecial_field(void) const;
    void ResetSpecial_field(void);
    const TSpecial_field& GetSpecial_field(void) const;
    void SetSpecial_field(TSpecial_field& value);
    TSpecial_field& SetSpecial_field(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPublication_constraint_Base(const CPublication_constraint_Base&);
    CPublication_constraint_Base& operator=(const CPublication_constraint_Base&);

    // data
    Uint4 m_set_State[1];
    EPub_type m_Type;
    CRef< TField > m_Field;
    CRef< TSpecial_field > m_Special_field;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPublication_constraint_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPublication_constraint_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
void CPublication_constraint_Base::ResetType(void)
{
    m_Type = (ncbi::objects::EPub_type)(0);
    m_set_State[0] &= ~0x3;
}

inline
CPublication_constraint_Base::TType CPublication_constraint_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(0);
    }
    return m_Type;
}

inline
void CPublication_constraint_Base::SetType(CPublication_constraint_Base::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0x3;
}

inline
CPublication_constraint_Base::TType& CPublication_constraint_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Type;
}

inline
bool CPublication_constraint_Base::IsSetField(void) const
{
    return m_Field.NotEmpty();
}

inline
bool CPublication_constraint_Base::CanGetField(void) const
{
    return IsSetField();
}

inline
const CPublication_constraint_Base::TField& CPublication_constraint_Base::GetField(void) const
{
    if (!CanGetField()) {
        ThrowUnassigned(1);
    }
    return (*m_Field);
}

inline
bool CPublication_constraint_Base::IsSetSpecial_field(void) const
{
    return m_Special_field.NotEmpty();
}

inline
bool CPublication_constraint_Base::CanGetSpecial_field(void) const
{
    return IsSetSpecial_field();
}

inline
const CPublication_constraint_Base::TSpecial_field& CPublication_constraint_Base::GetSpecial_field(void) const
{
    if (!CanGetSpecial_field()) {
        ThrowUnassigned(2);
    }
    return (*m_Special_field);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_PUBLICATION_CONSTRAINT_BASE_HPP