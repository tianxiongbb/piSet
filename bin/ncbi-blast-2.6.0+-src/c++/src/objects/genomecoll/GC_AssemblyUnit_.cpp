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
 *   'genome_collection.asn'.
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
#include <objects/genomecoll/GC_AssemblyUnit.hpp>
#include <objects/general/Dbtag.hpp>
#include <objects/genomecoll/GC_AssemblyDesc.hpp>
#include <objects/genomecoll/GC_Replicon.hpp>
#include <objects/genomecoll/GC_Scaf_stats.hpp>
#include <objects/genomecoll/GC_SequenceStats.hpp>
#include <objects/genomecoll/GC_TaggedSequences.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGC_AssemblyUnit_Base::, EClass, true)
{
    SET_ENUM_INTERNAL_NAME("GC-AssemblyUnit", "class");
    SET_ENUM_MODULE("NCBI-GenomeCollection");
    ADD_ENUM_VALUE("haploid-unit", eClass_haploid_unit);
    ADD_ENUM_VALUE("alt-loci", eClass_alt_loci);
    ADD_ENUM_VALUE("assembly-patch", eClass_assembly_patch);
    ADD_ENUM_VALUE("other", eClass_other);
}
END_ENUM_INFO

void CGC_AssemblyUnit_Base::ResetId(void)
{
    m_Id.clear();
    m_set_State[0] &= ~0x3;
}

void CGC_AssemblyUnit_Base::ResetDesc(void)
{
    if ( !m_Desc ) {
        m_Desc.Reset(new TDesc());
        return;
    }
    (*m_Desc).Reset();
}

void CGC_AssemblyUnit_Base::SetDesc(CGC_AssemblyUnit_Base::TDesc& value)
{
    m_Desc.Reset(&value);
}

void CGC_AssemblyUnit_Base::ResetMols(void)
{
    m_Mols.clear();
    m_set_State[0] &= ~0xc0;
}

void CGC_AssemblyUnit_Base::ResetOther_sequences(void)
{
    m_Other_sequences.clear();
    m_set_State[0] &= ~0x300;
}

void CGC_AssemblyUnit_Base::ResetStats(void)
{
    m_Stats.Reset();
}

void CGC_AssemblyUnit_Base::SetStats(CGC_AssemblyUnit_Base::TStats& value)
{
    m_Stats.Reset(&value);
}

CGC_AssemblyUnit_Base::TStats& CGC_AssemblyUnit_Base::SetStats(void)
{
    if ( !m_Stats )
        m_Stats.Reset(new ncbi::objects::CGC_SequenceStats());
    return (*m_Stats);
}

void CGC_AssemblyUnit_Base::ResetUnplaced_stats(void)
{
    m_Unplaced_stats.clear();
    m_set_State[0] &= ~0x3000;
}

void CGC_AssemblyUnit_Base::ResetUnplaced_unlocalized_stats(void)
{
    m_Unplaced_unlocalized_stats.clear();
    m_set_State[0] &= ~0xc000;
}

void CGC_AssemblyUnit_Base::Reset(void)
{
    ResetId();
    ResetClass();
    ResetDesc();
    ResetMols();
    ResetOther_sequences();
    ResetStats();
    ResetUnplaced_stats();
    ResetUnplaced_unlocalized_stats();
}

BEGIN_NAMED_BASE_CLASS_INFO("GC-AssemblyUnit", CGC_AssemblyUnit)
{
    SET_CLASS_MODULE("NCBI-GenomeCollection");
    ADD_NAMED_MEMBER("id", m_Id, STL_list_set, (STL_CRef, (CLASS, (CDbtag))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("class", m_Class, EClass)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("desc", m_Desc, CGC_AssemblyDesc);
    ADD_NAMED_MEMBER("mols", m_Mols, STL_list_set, (STL_CRef, (CLASS, (CGC_Replicon))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("other-sequences", m_Other_sequences, STL_list_set, (STL_CRef, (CLASS, (CGC_TaggedSequences))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("stats", m_Stats, CGC_SequenceStats)->SetOptional();
    ADD_NAMED_MEMBER("unplaced-stats", m_Unplaced_stats, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("unplaced-unlocalized-stats", m_Unplaced_unlocalized_stats, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGC_AssemblyUnit_Base::CGC_AssemblyUnit_Base(void)
    : m_Class((EClass)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetDesc();
    }
}

// destructor
CGC_AssemblyUnit_Base::~CGC_AssemblyUnit_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

