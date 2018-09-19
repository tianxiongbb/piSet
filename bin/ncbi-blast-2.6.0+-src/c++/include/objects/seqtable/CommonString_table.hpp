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

/// @file CommonString_table.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'seqtable.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: CommonString_table_.hpp


#ifndef OBJECTS_SEQTABLE_COMMONSTRING_TABLE_HPP
#define OBJECTS_SEQTABLE_COMMONSTRING_TABLE_HPP


// generated includes
#include <objects/seqtable/CommonString_table_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQ_EXPORT CCommonString_table : public CCommonString_table_Base
{
    typedef CCommonString_table_Base Tparent;
public:
    // constructor
    CCommonString_table(void);
    // destructor
    ~CCommonString_table(void);

private:
    // Prohibit copy constructor and assignment operator
    CCommonString_table(const CCommonString_table& value);
    CCommonString_table& operator=(const CCommonString_table& value);

};

/////////////////// CCommonString_table inline methods

// constructor
inline
CCommonString_table::CCommonString_table(void)
{
}


/////////////////// end of CCommonString_table inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQTABLE_COMMONSTRING_TABLE_HPP
/* Original file checksum: lines: 86, chars: 2588, CRC32: 10b488cc */
