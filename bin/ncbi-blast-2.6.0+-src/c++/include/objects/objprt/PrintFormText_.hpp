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

/// @file PrintFormText_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'objprt.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OBJPRT_PRINTFORMTEXT_BASE_HPP
#define OBJECTS_OBJPRT_PRINTFORMTEXT_BASE_HPP

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
class NCBI_OBJPRT_EXPORT CPrintFormText_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPrintFormText_Base(void);
    // destructor
    virtual ~CPrintFormText_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TTextfunc;

    // getters
    // setters

    /// optional
    /// typedef string TTextfunc
    ///  Check whether the Textfunc data member has been assigned a value.
    bool IsSetTextfunc(void) const;
    /// Check whether it is safe or not to call GetTextfunc method.
    bool CanGetTextfunc(void) const;
    void ResetTextfunc(void);
    const TTextfunc& GetTextfunc(void) const;
    void SetTextfunc(const TTextfunc& value);
    TTextfunc& SetTextfunc(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPrintFormText_Base(const CPrintFormText_Base&);
    CPrintFormText_Base& operator=(const CPrintFormText_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Textfunc;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPrintFormText_Base::IsSetTextfunc(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPrintFormText_Base::CanGetTextfunc(void) const
{
    return IsSetTextfunc();
}

inline
const CPrintFormText_Base::TTextfunc& CPrintFormText_Base::GetTextfunc(void) const
{
    if (!CanGetTextfunc()) {
        ThrowUnassigned(0);
    }
    return m_Textfunc;
}

inline
void CPrintFormText_Base::SetTextfunc(const CPrintFormText_Base::TTextfunc& value)
{
    m_Textfunc = value;
    m_set_State[0] |= 0x3;
}

inline
CPrintFormText_Base::TTextfunc& CPrintFormText_Base::SetTextfunc(void)
{
#ifdef _DEBUG
    if (!IsSetTextfunc()) {
        m_Textfunc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Textfunc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OBJPRT_PRINTFORMTEXT_BASE_HPP