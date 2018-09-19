/* $Id: Simple_replace.hpp 435989 2014-05-22 14:41:51Z bollin $
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

/// @file Simple_replace.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Simple_replace_.hpp


#ifndef OBJECTS_MACRO_SIMPLE_REPLACE_HPP
#define OBJECTS_MACRO_SIMPLE_REPLACE_HPP


// generated includes
#include <objects/macro/Simple_replace_.hpp>

// generated classes

#include <objects/macro/String_constraint.hpp>

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class CSimple_replace : public CSimple_replace_Base
{
    typedef CSimple_replace_Base Tparent;
public:
    // constructor
    CSimple_replace(void);
    // destructor
    ~CSimple_replace(void);

    bool ApplyToString(string& val, CRef<CString_constraint> find) const;

private:
    // Prohibit copy constructor and assignment operator
    CSimple_replace(const CSimple_replace& value);
    CSimple_replace& operator=(const CSimple_replace& value);

};

/////////////////// CSimple_replace inline methods

// constructor
inline
CSimple_replace::CSimple_replace(void)
{
}


/////////////////// end of CSimple_replace inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_SIMPLE_REPLACE_HPP
/* Original file checksum: lines: 86, chars: 2481, CRC32: c06c7da7 */
