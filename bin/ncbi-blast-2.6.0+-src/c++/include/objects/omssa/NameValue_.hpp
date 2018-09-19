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

/// @file NameValue_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'omssa.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OMSSA_NAMEVALUE_BASE_HPP
#define OBJECTS_OMSSA_NAMEVALUE_BASE_HPP

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
/// Generic holder for experimental info
class NCBI_OMSSA_EXPORT CNameValue_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CNameValue_Base(void);
    // destructor
    virtual ~CNameValue_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TName;
    typedef string TValue;

    // getters
    // setters

    /// mandatory
    /// typedef string TName
    ///  Check whether the Name data member has been assigned a value.
    bool IsSetName(void) const;
    /// Check whether it is safe or not to call GetName method.
    bool CanGetName(void) const;
    void ResetName(void);
    const TName& GetName(void) const;
    void SetName(const TName& value);
    TName& SetName(void);

    /// mandatory
    /// typedef string TValue
    ///  Check whether the Value data member has been assigned a value.
    bool IsSetValue(void) const;
    /// Check whether it is safe or not to call GetValue method.
    bool CanGetValue(void) const;
    void ResetValue(void);
    const TValue& GetValue(void) const;
    void SetValue(const TValue& value);
    TValue& SetValue(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CNameValue_Base(const CNameValue_Base&);
    CNameValue_Base& operator=(const CNameValue_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Name;
    string m_Value;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CNameValue_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CNameValue_Base::CanGetName(void) const
{
    return IsSetName();
}

inline
const CNameValue_Base::TName& CNameValue_Base::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(0);
    }
    return m_Name;
}

inline
void CNameValue_Base::SetName(const CNameValue_Base::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0x3;
}

inline
CNameValue_Base::TName& CNameValue_Base::SetName(void)
{
#ifdef _DEBUG
    if (!IsSetName()) {
        m_Name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Name;
}

inline
bool CNameValue_Base::IsSetValue(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CNameValue_Base::CanGetValue(void) const
{
    return IsSetValue();
}

inline
const CNameValue_Base::TValue& CNameValue_Base::GetValue(void) const
{
    if (!CanGetValue()) {
        ThrowUnassigned(1);
    }
    return m_Value;
}

inline
void CNameValue_Base::SetValue(const CNameValue_Base::TValue& value)
{
    m_Value = value;
    m_set_State[0] |= 0xc;
}

inline
CNameValue_Base::TValue& CNameValue_Base::SetValue(void)
{
#ifdef _DEBUG
    if (!IsSetValue()) {
        m_Value = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Value;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OMSSA_NAMEVALUE_BASE_HPP
