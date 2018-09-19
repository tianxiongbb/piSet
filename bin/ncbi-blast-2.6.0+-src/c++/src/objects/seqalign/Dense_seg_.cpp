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
 *   'seqalign.asn'.
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
#include <objects/seqalign/Dense_seg.hpp>
#include <objects/seqalign/Score.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CDense_seg_Base::ResetIds(void)
{
    m_Ids.clear();
    m_set_State[0] &= ~0x30;
}

void CDense_seg_Base::ResetStarts(void)
{
    m_Starts.clear();
    m_set_State[0] &= ~0xc0;
}

void CDense_seg_Base::ResetLens(void)
{
    m_Lens.clear();
    m_set_State[0] &= ~0x300;
}

void CDense_seg_Base::ResetStrands(void)
{
    m_Strands.clear();
    m_set_State[0] &= ~0xc00;
}

void CDense_seg_Base::ResetScores(void)
{
    m_Scores.clear();
    m_set_State[0] &= ~0x3000;
}

void CDense_seg_Base::Reset(void)
{
    ResetDim();
    ResetNumseg();
    ResetIds();
    ResetStarts();
    ResetLens();
    ResetStrands();
    ResetScores();
}

BEGIN_NAMED_BASE_CLASS_INFO("Dense-seg", CDense_seg)
{
    SET_CLASS_MODULE("NCBI-Seqalign");
    ADD_NAMED_STD_MEMBER("dim", m_Dim)->SetDefault(new TDim(2))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("numseg", m_Numseg)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("ids", m_Ids, STL_vector, (STL_CRef, (CLASS, (CSeq_id))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("starts", m_Starts, STL_vector, (STD, (TSignedSeqPos)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("lens", m_Lens, STL_vector, (STD, (TSeqPos)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("strands", m_Strands, STL_vector, (ENUM, (ENa_strand, ENa_strand)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("scores", m_Scores, STL_vector, (STL_CRef, (CLASS, (CScore))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CDense_seg_Base::CDense_seg_Base(void)
    : m_Dim(2), m_Numseg(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CDense_seg_Base::~CDense_seg_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

