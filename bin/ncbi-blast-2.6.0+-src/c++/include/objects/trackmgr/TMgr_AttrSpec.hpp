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

/// @file TMgr_AttrSpec.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'trackmgr.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: TMgr_AttrSpec_.hpp


#ifndef OBJECTS_TRACKMGR_TMGR_ATTRSPEC_HPP
#define OBJECTS_TRACKMGR_TMGR_ATTRSPEC_HPP


// generated includes
#include <objects/trackmgr/TMgr_AttrSpec_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_TRACKMGR_EXPORT CTMgr_AttrSpec : public CTMgr_AttrSpec_Base
{
    typedef CTMgr_AttrSpec_Base Tparent;
public:
    // constructor
    CTMgr_AttrSpec(void);
    // destructor
    ~CTMgr_AttrSpec(void);

private:
    // Prohibit copy constructor and assignment operator
    CTMgr_AttrSpec(const CTMgr_AttrSpec& value);
    CTMgr_AttrSpec& operator=(const CTMgr_AttrSpec& value);

};

/////////////////// CTMgr_AttrSpec inline methods

// constructor
inline
CTMgr_AttrSpec::CTMgr_AttrSpec(void)
{
}


/////////////////// end of CTMgr_AttrSpec inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TRACKMGR_TMGR_ATTRSPEC_HPP
/* Original file checksum: lines: 86, chars: 2498, CRC32: cb577a74 */
