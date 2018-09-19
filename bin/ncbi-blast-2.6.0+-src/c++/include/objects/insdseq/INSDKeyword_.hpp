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

/// @file INSDKeyword_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'insdseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_INSDSEQ_INSDKEYWORD_BASE_HPP
#define OBJECTS_INSDSEQ_INSDKEYWORD_BASE_HPP

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


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_INSDSEQ_EXPORT CINSDKeyword_Base : public CStringAliasBase< string >
{
    typedef CStringAliasBase< string > Tparent;
public:
    CINSDKeyword_Base(void);

    // type info
    DECLARE_STD_ALIAS_TYPE_INFO();

    // explicit constructor from the primitive type
    explicit CINSDKeyword_Base(const string& data);
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CINSDKeyword_Base::CINSDKeyword_Base(void)
{
}

inline
CINSDKeyword_Base::CINSDKeyword_Base(const string& data)
    : CStringAliasBase< string >(data)
{
}

inline
NCBI_NS_NCBI::CNcbiOstream& operator<<
(NCBI_NS_NCBI::CNcbiOstream& str, const CINSDKeyword_Base& obj)
{
    if (NCBI_NS_NCBI::MSerial_Flags::HasSerialFormatting(str)) {
        return WriteObject(str,&obj,obj.GetTypeInfo());
    }
    str << obj.Get();
    return str;
}

inline
NCBI_NS_NCBI::CNcbiIstream& operator>>
(NCBI_NS_NCBI::CNcbiIstream& str, CINSDKeyword_Base& obj)
{
    if (NCBI_NS_NCBI::MSerial_Flags::HasSerialFormatting(str)) {
        return ReadObject(str,&obj,obj.GetTypeInfo());
    }
    str >> obj.Set();
    return str;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_INSDSEQ_INSDKEYWORD_BASE_HPP
