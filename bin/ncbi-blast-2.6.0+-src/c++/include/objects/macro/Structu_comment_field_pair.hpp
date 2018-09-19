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

/// @file Structu_comment_field_pair.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Structu_comment_field_pair_.hpp


#ifndef OBJECTS_MACRO_STRUCTU_COMMENT_FIELD_PAIR_HPP
#define OBJECTS_MACRO_STRUCTU_COMMENT_FIELD_PAIR_HPP


// generated includes
#include <objects/macro/Structu_comment_field_pair_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class CStructured_comment_field_pair : public CStructured_comment_field_pair_Base
{
    typedef CStructured_comment_field_pair_Base Tparent;
public:
    // constructor
    CStructured_comment_field_pair(void);
    // destructor
    ~CStructured_comment_field_pair(void);

private:
    // Prohibit copy constructor and assignment operator
    CStructured_comment_field_pair(const CStructured_comment_field_pair& value);
    CStructured_comment_field_pair& operator=(const CStructured_comment_field_pair& value);

};

/////////////////// CStructured_comment_field_pair inline methods

// constructor
inline
CStructured_comment_field_pair::CStructured_comment_field_pair(void)
{
}


/////////////////// end of CStructured_comment_field_pair inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_STRUCTU_COMMENT_FIELD_PAIR_HPP
/* Original file checksum: lines: 86, chars: 2748, CRC32: 2f6b4e53 */
