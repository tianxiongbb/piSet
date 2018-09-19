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
#include <objects/genomecoll/GC_SequenceStats.hpp>
#include <objects/genomecoll/GC_Scaf_stats.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CGC_SequenceStats_Base::ResetAll_scaf(void)
{
    m_All_scaf.clear();
    m_set_State[0] &= ~0x3;
}

void CGC_SequenceStats_Base::ResetOrdered_scaf(void)
{
    m_Ordered_scaf.clear();
    m_set_State[0] &= ~0xc;
}

void CGC_SequenceStats_Base::ResetUnordered_scaf(void)
{
    m_Unordered_scaf.clear();
    m_set_State[0] &= ~0x30;
}

void CGC_SequenceStats_Base::ResetUnplaced_scaf(void)
{
    m_Unplaced_scaf.clear();
    m_set_State[0] &= ~0xc0;
}

void CGC_SequenceStats_Base::ResetAligned_scaf(void)
{
    m_Aligned_scaf.clear();
    m_set_State[0] &= ~0x300;
}

void CGC_SequenceStats_Base::ResetUnaligned_scaf(void)
{
    m_Unaligned_scaf.clear();
    m_set_State[0] &= ~0xc00;
}

void CGC_SequenceStats_Base::Reset(void)
{
    ResetAll_scaf();
    ResetOrdered_scaf();
    ResetUnordered_scaf();
    ResetUnplaced_scaf();
    ResetAligned_scaf();
    ResetUnaligned_scaf();
}

BEGIN_NAMED_BASE_CLASS_INFO("GC-SequenceStats", CGC_SequenceStats)
{
    SET_CLASS_MODULE("NCBI-GenomeCollection");
    ADD_NAMED_MEMBER("all-scaf", m_All_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("ordered-scaf", m_Ordered_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("unordered-scaf", m_Unordered_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("unplaced-scaf", m_Unplaced_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("aligned-scaf", m_Aligned_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("unaligned-scaf", m_Unaligned_scaf, STL_list_set, (STL_CRef, (CLASS, (CGC_Scaf_stats))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGC_SequenceStats_Base::CGC_SequenceStats_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGC_SequenceStats_Base::~CGC_SequenceStats_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

