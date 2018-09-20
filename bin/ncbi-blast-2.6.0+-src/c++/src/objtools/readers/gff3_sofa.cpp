/*  $Id: gff3_sofa.cpp 520685 2016-11-30 18:53:22Z ivanov $
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
 * Author:  Frank Ludwig
 *
 * File Description:
 *   GFF file reader
 *
 */

#include <ncbi_pch.hpp>
#include <corelib/ncbistd.hpp>
#include <objtools/readers/gff3_sofa.hpp>

#include <objects/seq/sofa_type.hpp>
#include <objects/seq/sofa_map.hpp>
#include <objects/seqfeat/SeqFeatData.hpp>

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

#define GT( a, b ) CFeatListItem( CSeqFeatData::a, CSeqFeatData::b, "", "" )

//  --------------------------------------------------------------------------
CSafeStatic<TLookupSofaToGenbank> CGff3SofaTypes::m_Lookup;
CSafeStatic<TAliasToTerm> CGff3SofaTypes::m_Aliases;
//  --------------------------------------------------------------------------

//  --------------------------------------------------------------------------
CGff3SofaTypes& SofaTypes()
//  --------------------------------------------------------------------------
{
    static CSafeStatic<CGff3SofaTypes> m_Lookup;    
    return *m_Lookup;
}

//  --------------------------------------------------------------------------
CGff3SofaTypes::CGff3SofaTypes()
//  --------------------------------------------------------------------------
{
    typedef map<CFeatListItem, SofaType> SOFAMAP;
    typedef SOFAMAP::const_iterator SOFAITER;

    CSofaMap SofaMap;
    const SOFAMAP& entries = SofaMap.Map();
    TLookupSofaToGenbank& lookup = *m_Lookup;

    for (SOFAITER cit = entries.begin(); cit != entries.end(); ++cit) {
        lookup[cit->second.m_name] = cit->first;
    }
    //overrides:
    lookup["primary_transcript"] = GT(e_Imp, eSubtype_preRNA);
    lookup["sequence_alteration"] = GT(e_Variation, eSubtype_variation_ref);
    lookup["signal_peptide"] = GT(e_Imp, eSubtype_sig_peptide);

    TAliasToTerm& aliases = *m_Aliases;
    aliases["satellite"] = "satellite_DNA";
};

//  --------------------------------------------------------------------------
CGff3SofaTypes::~CGff3SofaTypes()
//  --------------------------------------------------------------------------
{
};

//  --------------------------------------------------------------------------
CSeqFeatData::ESubtype CGff3SofaTypes::MapSofaTermToGenbankType(
    const string& strSofa )
//  --------------------------------------------------------------------------
{
    TLookupSofaToGenbankCit cit = m_Lookup->find( strSofa );
    if ( cit == m_Lookup->end() ) {
        return CSeqFeatData::eSubtype_bad;
    }
    return CSeqFeatData::ESubtype(cit->second.GetSubtype());
}

//  --------------------------------------------------------------------------
CFeatListItem CGff3SofaTypes::MapSofaTermToFeatListItem(
    const string& strSofa )
//  --------------------------------------------------------------------------
{
    TLookupSofaToGenbankCit cit = m_Lookup->find( strSofa );
    if ( cit == m_Lookup->end() ) {
        return CFeatListItem(CSeqFeatData::e_Imp, 
            CSeqFeatData::eSubtype_bad, "", "");
    }
    return cit->second;
}

//  ---------------------------------------------------------------------------
bool CGff3SofaTypes::IsStringSofaAlias(
    const string& str)
//  ---------------------------------------------------------------------------
{
    return (m_Aliases->find(str) != m_Aliases->end());
}

//  ---------------------------------------------------------------------------
string CGff3SofaTypes::MapSofaAliasToSofaTerm(
    const string& alias)
//  ---------------------------------------------------------------------------
{
    TAliasToTermCit cit = m_Aliases->find(alias);
    if (cit == m_Aliases->end()) {
        return "";
    }
    return cit->second;
}

#undef GT

END_objects_SCOPE
END_NCBI_SCOPE