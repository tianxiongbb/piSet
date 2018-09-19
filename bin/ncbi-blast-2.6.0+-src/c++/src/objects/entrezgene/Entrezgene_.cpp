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
 * File Description:
 *   This code was generated by application DATATOOL
 *   using the following specifications:
 *   'entrezgene.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serialimpl.hpp>

// generated includes
#include <objects/entrezgene/Entrezgene.hpp>
#include <objects/entrezgene/Gene_commentary.hpp>
#include <objects/entrezgene/Gene_source.hpp>
#include <objects/entrezgene/Gene_track.hpp>
#include <objects/entrezgene/Maps.hpp>
#include <objects/entrezgene/Xtra_Terms.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/seqfeat/BioSource.hpp>
#include <objects/seqfeat/Gene_ref.hpp>
#include <objects/seqfeat/Prot_ref.hpp>
#include <objects/seqfeat/RNA_ref.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CEntrezgene_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("Entrezgene", "type");
    SET_ENUM_MODULE("NCBI-Entrezgene");
    ADD_ENUM_VALUE("unknown", eType_unknown);
    ADD_ENUM_VALUE("tRNA", eType_tRNA);
    ADD_ENUM_VALUE("rRNA", eType_rRNA);
    ADD_ENUM_VALUE("snRNA", eType_snRNA);
    ADD_ENUM_VALUE("scRNA", eType_scRNA);
    ADD_ENUM_VALUE("snoRNA", eType_snoRNA);
    ADD_ENUM_VALUE("protein-coding", eType_protein_coding);
    ADD_ENUM_VALUE("pseudo", eType_pseudo);
    ADD_ENUM_VALUE("transposon", eType_transposon);
    ADD_ENUM_VALUE("miscRNA", eType_miscRNA);
    ADD_ENUM_VALUE("ncRNA", eType_ncRNA);
    ADD_ENUM_VALUE("biological-region", eType_biological_region);
    ADD_ENUM_VALUE("other", eType_other);
}
END_ENUM_INFO

void CEntrezgene_Base::ResetTrack_info(void)
{
    m_Track_info.Reset();
}

void CEntrezgene_Base::SetTrack_info(CEntrezgene_Base::TTrack_info& value)
{
    m_Track_info.Reset(&value);
}

CEntrezgene_Base::TTrack_info& CEntrezgene_Base::SetTrack_info(void)
{
    if ( !m_Track_info )
        m_Track_info.Reset(new ncbi::objects::CGene_track());
    return (*m_Track_info);
}

void CEntrezgene_Base::ResetSource(void)
{
    if ( !m_Source ) {
        m_Source.Reset(new TSource());
        return;
    }
    (*m_Source).Reset();
}

void CEntrezgene_Base::SetSource(CEntrezgene_Base::TSource& value)
{
    m_Source.Reset(&value);
}

void CEntrezgene_Base::ResetGene(void)
{
    if ( !m_Gene ) {
        m_Gene.Reset(new TGene());
        return;
    }
    (*m_Gene).Reset();
}

void CEntrezgene_Base::SetGene(CEntrezgene_Base::TGene& value)
{
    m_Gene.Reset(&value);
}

void CEntrezgene_Base::ResetProt(void)
{
    m_Prot.Reset();
}

void CEntrezgene_Base::SetProt(CEntrezgene_Base::TProt& value)
{
    m_Prot.Reset(&value);
}

CEntrezgene_Base::TProt& CEntrezgene_Base::SetProt(void)
{
    if ( !m_Prot )
        m_Prot.Reset(new ncbi::objects::CProt_ref());
    return (*m_Prot);
}

void CEntrezgene_Base::ResetRna(void)
{
    m_Rna.Reset();
}

void CEntrezgene_Base::SetRna(CEntrezgene_Base::TRna& value)
{
    m_Rna.Reset(&value);
}

CEntrezgene_Base::TRna& CEntrezgene_Base::SetRna(void)
{
    if ( !m_Rna )
        m_Rna.Reset(new ncbi::objects::CRNA_ref());
    return (*m_Rna);
}

void CEntrezgene_Base::ResetSummary(void)
{
    m_Summary.erase();
    m_set_State[0] &= ~0x3000;
}

void CEntrezgene_Base::ResetLocation(void)
{
    m_Location.clear();
    m_set_State[0] &= ~0xc000;
}

void CEntrezgene_Base::ResetGene_source(void)
{
    m_Gene_source.Reset();
}

void CEntrezgene_Base::SetGene_source(CEntrezgene_Base::TGene_source& value)
{
    m_Gene_source.Reset(&value);
}

CEntrezgene_Base::TGene_source& CEntrezgene_Base::SetGene_source(void)
{
    if ( !m_Gene_source )
        m_Gene_source.Reset(new ncbi::objects::CGene_source());
    return (*m_Gene_source);
}

void CEntrezgene_Base::ResetLocus(void)
{
    m_Locus.clear();
    m_set_State[0] &= ~0xc0000;
}

void CEntrezgene_Base::ResetProperties(void)
{
    m_Properties.clear();
    m_set_State[0] &= ~0x300000;
}

void CEntrezgene_Base::ResetRefgene(void)
{
    m_Refgene.clear();
    m_set_State[0] &= ~0xc00000;
}

void CEntrezgene_Base::ResetHomology(void)
{
    m_Homology.clear();
    m_set_State[0] &= ~0x3000000;
}

void CEntrezgene_Base::ResetComments(void)
{
    m_Comments.clear();
    m_set_State[0] &= ~0xc000000;
}

void CEntrezgene_Base::ResetUnique_keys(void)
{
    m_Unique_keys.clear();
    m_set_State[0] &= ~0x30000000;
}

void CEntrezgene_Base::ResetXtra_index_terms(void)
{
    m_Xtra_index_terms.clear();
    m_set_State[0] &= ~0xc0000000;
}

void CEntrezgene_Base::ResetXtra_properties(void)
{
    m_Xtra_properties.clear();
    m_set_State[1] &= ~0x3;
}

void CEntrezgene_Base::ResetXtra_iq(void)
{
    m_Xtra_iq.clear();
    m_set_State[1] &= ~0xc;
}

void CEntrezgene_Base::ResetNon_unique_keys(void)
{
    m_Non_unique_keys.clear();
    m_set_State[1] &= ~0x30;
}

void CEntrezgene_Base::Reset(void)
{
    ResetTrack_info();
    ResetType();
    ResetSource();
    ResetGene();
    ResetProt();
    ResetRna();
    ResetSummary();
    ResetLocation();
    ResetGene_source();
    ResetLocus();
    ResetProperties();
    ResetRefgene();
    ResetHomology();
    ResetComments();
    ResetUnique_keys();
    ResetXtra_index_terms();
    ResetXtra_properties();
    ResetXtra_iq();
    ResetNon_unique_keys();
}

BEGIN_NAMED_BASE_CLASS_INFO("Entrezgene", CEntrezgene)
{
    SET_CLASS_MODULE("NCBI-Entrezgene");
    ADD_NAMED_REF_MEMBER("track-info", m_Track_info, CGene_track)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("source", m_Source, CBioSource);
    ADD_NAMED_REF_MEMBER("gene", m_Gene, CGene_ref);
    ADD_NAMED_REF_MEMBER("prot", m_Prot, CProt_ref)->SetOptional();
    ADD_NAMED_REF_MEMBER("rna", m_Rna, CRNA_ref)->SetOptional();
    ADD_NAMED_STD_MEMBER("summary", m_Summary)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("location", m_Location, STL_list, (STL_CRef, (CLASS, (CMaps))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("gene-source", m_Gene_source, CGene_source)->SetOptional();
    ADD_NAMED_MEMBER("locus", m_Locus, STL_list, (STL_CRef, (CLASS, (CGene_commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("properties", m_Properties, STL_list, (STL_CRef, (CLASS, (CGene_commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("refgene", m_Refgene, STL_list, (STL_CRef, (CLASS, (CGene_commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("homology", m_Homology, STL_list, (STL_CRef, (CLASS, (CGene_commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("comments", m_Comments, STL_list, (STL_CRef, (CLASS, (CGene_commentary))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("unique-keys", m_Unique_keys, STL_list, (STL_CRef, (CLASS, (CDbtag))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("xtra-index-terms", m_Xtra_index_terms, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("xtra-properties", m_Xtra_properties, STL_list, (STL_CRef, (CLASS, (CXtra_Terms))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("xtra-iq", m_Xtra_iq, STL_list, (STL_CRef, (CLASS, (CXtra_Terms))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("non-unique-keys", m_Non_unique_keys, STL_list, (STL_CRef, (CLASS, (CDbtag))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CEntrezgene_Base::CEntrezgene_Base(void)
    : m_Type((EType)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSource();
        ResetGene();
    }
}

// destructor
CEntrezgene_Base::~CEntrezgene_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

