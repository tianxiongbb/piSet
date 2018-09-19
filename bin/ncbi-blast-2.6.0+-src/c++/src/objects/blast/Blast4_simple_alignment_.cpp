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
 *   'blast.asn'.
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
#include <objects/blast/Blast4_simple_alignment.hpp>
#include <objects/blast/Blast4_range.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_simple_alignment_Base::ResetSubject_id(void)
{
    m_Subject_id.erase();
    m_set_State[0] &= ~0x3;
}

void CBlast4_simple_alignment_Base::ResetFull_query_range(void)
{
    if ( !m_Full_query_range ) {
        m_Full_query_range.Reset(new TFull_query_range());
        return;
    }
    (*m_Full_query_range).Reset();
}

void CBlast4_simple_alignment_Base::SetFull_query_range(CBlast4_simple_alignment_Base::TFull_query_range& value)
{
    m_Full_query_range.Reset(&value);
}

void CBlast4_simple_alignment_Base::ResetFull_subject_range(void)
{
    if ( !m_Full_subject_range ) {
        m_Full_subject_range.Reset(new TFull_subject_range());
        return;
    }
    (*m_Full_subject_range).Reset();
}

void CBlast4_simple_alignment_Base::SetFull_subject_range(CBlast4_simple_alignment_Base::TFull_subject_range& value)
{
    m_Full_subject_range.Reset(&value);
}

void CBlast4_simple_alignment_Base::Reset(void)
{
    ResetSubject_id();
    ResetE_value();
    ResetBit_score();
    ResetNum_identities();
    ResetNum_indels();
    ResetFull_query_range();
    ResetFull_subject_range();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-simple-alignment", CBlast4_simple_alignment)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_STD_MEMBER("subject-id", m_Subject_id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("e-value", m_E_value)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("bit-score", m_Bit_score)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("num-identities", m_Num_identities)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("num-indels", m_Num_indels)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("full-query-range", m_Full_query_range, CBlast4_range);
    ADD_NAMED_REF_MEMBER("full-subject-range", m_Full_subject_range, CBlast4_range);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBlast4_simple_alignment_Base::CBlast4_simple_alignment_Base(void)
    : m_E_value(0), m_Bit_score(0), m_Num_identities(0), m_Num_indels(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetFull_query_range();
        ResetFull_subject_range();
    }
}

// destructor
CBlast4_simple_alignment_Base::~CBlast4_simple_alignment_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

