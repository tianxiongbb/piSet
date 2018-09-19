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

/// @file Biostruc_annot_set.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'mmdb1.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Biostruc_annot_set_.hpp


#ifndef OBJECTS_MMDB1_BIOSTRUC_ANNOT_SET_HPP
#define OBJECTS_MMDB1_BIOSTRUC_ANNOT_SET_HPP


// generated includes
#include <objects/mmdb1/Biostruc_annot_set_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_MMDB1_EXPORT CBiostruc_annot_set : public CBiostruc_annot_set_Base
{
    typedef CBiostruc_annot_set_Base Tparent;
public:
    // constructor
    CBiostruc_annot_set(void);
    // destructor
    ~CBiostruc_annot_set(void);

private:
    // Prohibit copy constructor and assignment operator
    CBiostruc_annot_set(const CBiostruc_annot_set& value);
    CBiostruc_annot_set& operator=(const CBiostruc_annot_set& value);

};

/////////////////// CBiostruc_annot_set inline methods

// constructor
inline
CBiostruc_annot_set::CBiostruc_annot_set(void)
{
}


/////////////////// end of CBiostruc_annot_set inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB1_BIOSTRUC_ANNOT_SET_HPP
/* Original file checksum: lines: 86, chars: 2575, CRC32: 28c4b241 */
