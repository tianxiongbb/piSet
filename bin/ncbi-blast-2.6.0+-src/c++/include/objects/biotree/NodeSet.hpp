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

/// @file NodeSet.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'biotree.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: NodeSet_.hpp


#ifndef OBJECTS_BIOTREE_NODESET_HPP
#define OBJECTS_BIOTREE_NODESET_HPP


// generated includes
#include <objects/biotree/NodeSet_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_BIOTREE_EXPORT CNodeSet : public CNodeSet_Base
{
    typedef CNodeSet_Base Tparent;
public:
    // constructor
    CNodeSet(void);
    // destructor
    ~CNodeSet(void);

private:
    // Prohibit copy constructor and assignment operator
    CNodeSet(const CNodeSet& value);
    CNodeSet& operator=(const CNodeSet& value);

};

/////////////////// CNodeSet inline methods

// constructor
inline
CNodeSet::CNodeSet(void)
{
}


/////////////////// end of CNodeSet inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BIOTREE_NODESET_HPP
/* Original file checksum: lines: 86, chars: 2378, CRC32: 829002bc */
