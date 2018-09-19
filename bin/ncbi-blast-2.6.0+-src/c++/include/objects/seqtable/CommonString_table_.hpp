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

/// @file CommonString_table_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqtable.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQTABLE_COMMONSTRING_TABLE_BASE_HPP
#define OBJECTS_SEQTABLE_COMMONSTRING_TABLE_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQ_EXPORT CCommonString_table_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCommonString_table_Base(void);
    // destructor
    virtual ~CCommonString_table_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef vector< CStringUTF8 > TStrings;
    typedef vector< int > TIndexes;

    // getters
    // setters

    /// set of possible values
    /// mandatory
    /// typedef vector< CStringUTF8 > TStrings
    ///  Check whether the Strings data member has been assigned a value.
    bool IsSetStrings(void) const;
    /// Check whether it is safe or not to call GetStrings method.
    bool CanGetStrings(void) const;
    void ResetStrings(void);
    const TStrings& GetStrings(void) const;
    TStrings& SetStrings(void);

    /// indexes of values in array 'strings' for each data row
    /// mandatory
    /// typedef vector< int > TIndexes
    ///  Check whether the Indexes data member has been assigned a value.
    bool IsSetIndexes(void) const;
    /// Check whether it is safe or not to call GetIndexes method.
    bool CanGetIndexes(void) const;
    void ResetIndexes(void);
    const TIndexes& GetIndexes(void) const;
    TIndexes& SetIndexes(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCommonString_table_Base(const CCommonString_table_Base&);
    CCommonString_table_Base& operator=(const CCommonString_table_Base&);

    // data
    Uint4 m_set_State[1];
    vector< CStringUTF8 > m_Strings;
    vector< int > m_Indexes;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCommonString_table_Base::IsSetStrings(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CCommonString_table_Base::CanGetStrings(void) const
{
    return true;
}

inline
const CCommonString_table_Base::TStrings& CCommonString_table_Base::GetStrings(void) const
{
    return m_Strings;
}

inline
CCommonString_table_Base::TStrings& CCommonString_table_Base::SetStrings(void)
{
    m_set_State[0] |= 0x1;
    return m_Strings;
}

inline
bool CCommonString_table_Base::IsSetIndexes(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCommonString_table_Base::CanGetIndexes(void) const
{
    return true;
}

inline
const CCommonString_table_Base::TIndexes& CCommonString_table_Base::GetIndexes(void) const
{
    return m_Indexes;
}

inline
CCommonString_table_Base::TIndexes& CCommonString_table_Base::SetIndexes(void)
{
    m_set_State[0] |= 0x4;
    return m_Indexes;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQTABLE_COMMONSTRING_TABLE_BASE_HPP
