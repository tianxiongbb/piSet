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

/// @file GBKeyword.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'gbseq.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: GBKeyword_.hpp


#ifndef OBJECTS_GBSEQ_GBKEYWORD_HPP
#define OBJECTS_GBSEQ_GBKEYWORD_HPP


// generated includes
#include <objects/gbseq/GBKeyword_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBSEQ_EXPORT CGBKeyword : public CGBKeyword_Base
{
    typedef CGBKeyword_Base Tparent;
public:
    CGBKeyword(void) {}

    /// Explicit constructor from the primitive type.
    explicit CGBKeyword(const std::string& data)
        : Tparent(data) {}

};

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBSEQ_GBKEYWORD_HPP
/* Original file checksum: lines: 70, chars: 2174, CRC32: 39ce175e */
