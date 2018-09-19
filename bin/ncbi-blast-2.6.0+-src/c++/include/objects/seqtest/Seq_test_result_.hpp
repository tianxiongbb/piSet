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

/// @file Seq_test_result_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqtest.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQTEST_SEQ_TEST_RESULT_BASE_HPP
#define OBJECTS_SEQTEST_SEQ_TEST_RESULT_BASE_HPP

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
class CDate;
class CUser_object;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQTEST_EXPORT CSeq_test_result_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSeq_test_result_Base(void);
    // destructor
    virtual ~CSeq_test_result_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TTest;
    typedef CDate TDate;
    typedef CUser_object TOutput_data;

    // getters
    // setters

    /// mandatory
    /// typedef string TTest
    ///  Check whether the Test data member has been assigned a value.
    bool IsSetTest(void) const;
    /// Check whether it is safe or not to call GetTest method.
    bool CanGetTest(void) const;
    void ResetTest(void);
    const TTest& GetTest(void) const;
    void SetTest(const TTest& value);
    TTest& SetTest(void);

    /// mandatory
    /// typedef CDate TDate
    ///  Check whether the Date data member has been assigned a value.
    bool IsSetDate(void) const;
    /// Check whether it is safe or not to call GetDate method.
    bool CanGetDate(void) const;
    void ResetDate(void);
    const TDate& GetDate(void) const;
    void SetDate(TDate& value);
    TDate& SetDate(void);

    /// mandatory
    /// typedef CUser_object TOutput_data
    ///  Check whether the Output_data data member has been assigned a value.
    bool IsSetOutput_data(void) const;
    /// Check whether it is safe or not to call GetOutput_data method.
    bool CanGetOutput_data(void) const;
    void ResetOutput_data(void);
    const TOutput_data& GetOutput_data(void) const;
    void SetOutput_data(TOutput_data& value);
    TOutput_data& SetOutput_data(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSeq_test_result_Base(const CSeq_test_result_Base&);
    CSeq_test_result_Base& operator=(const CSeq_test_result_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Test;
    CRef< TDate > m_Date;
    CRef< TOutput_data > m_Output_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSeq_test_result_Base::IsSetTest(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSeq_test_result_Base::CanGetTest(void) const
{
    return IsSetTest();
}

inline
const CSeq_test_result_Base::TTest& CSeq_test_result_Base::GetTest(void) const
{
    if (!CanGetTest()) {
        ThrowUnassigned(0);
    }
    return m_Test;
}

inline
void CSeq_test_result_Base::SetTest(const CSeq_test_result_Base::TTest& value)
{
    m_Test = value;
    m_set_State[0] |= 0x3;
}

inline
CSeq_test_result_Base::TTest& CSeq_test_result_Base::SetTest(void)
{
#ifdef _DEBUG
    if (!IsSetTest()) {
        m_Test = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Test;
}

inline
bool CSeq_test_result_Base::IsSetDate(void) const
{
    return m_Date.NotEmpty();
}

inline
bool CSeq_test_result_Base::CanGetDate(void) const
{
    return true;
}

inline
const CSeq_test_result_Base::TDate& CSeq_test_result_Base::GetDate(void) const
{
    if ( !m_Date ) {
        const_cast<CSeq_test_result_Base*>(this)->ResetDate();
    }
    return (*m_Date);
}

inline
CSeq_test_result_Base::TDate& CSeq_test_result_Base::SetDate(void)
{
    if ( !m_Date ) {
        ResetDate();
    }
    return (*m_Date);
}

inline
bool CSeq_test_result_Base::IsSetOutput_data(void) const
{
    return m_Output_data.NotEmpty();
}

inline
bool CSeq_test_result_Base::CanGetOutput_data(void) const
{
    return true;
}

inline
const CSeq_test_result_Base::TOutput_data& CSeq_test_result_Base::GetOutput_data(void) const
{
    if ( !m_Output_data ) {
        const_cast<CSeq_test_result_Base*>(this)->ResetOutput_data();
    }
    return (*m_Output_data);
}

inline
CSeq_test_result_Base::TOutput_data& CSeq_test_result_Base::SetOutput_data(void)
{
    if ( !m_Output_data ) {
        ResetOutput_data();
    }
    return (*m_Output_data);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQTEST_SEQ_TEST_RESULT_BASE_HPP
