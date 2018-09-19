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

/// @file GBFeatureSet.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'gbseq.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: GBFeatureSet_.hpp


#ifndef OBJECTS_GBSEQ_GBFEATURESET_HPP
#define OBJECTS_GBSEQ_GBFEATURESET_HPP


// generated includes
#include <objects/gbseq/GBFeatureSet_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBSEQ_EXPORT CGBFeatureSet : public CGBFeatureSet_Base
{
    typedef CGBFeatureSet_Base Tparent;
public:
    // constructor
    CGBFeatureSet(void);
    // destructor
    ~CGBFeatureSet(void);

private:
    // Prohibit copy constructor and assignment operator
    CGBFeatureSet(const CGBFeatureSet& value);
    CGBFeatureSet& operator=(const CGBFeatureSet& value);

};

/////////////////// CGBFeatureSet inline methods

// constructor
inline
CGBFeatureSet::CGBFeatureSet(void)
{
}


/////////////////// end of CGBFeatureSet inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBSEQ_GBFEATURESET_HPP
/* Original file checksum: lines: 86, chars: 2461, CRC32: 53004eda */
