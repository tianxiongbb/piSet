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
 *   'scoremat.asn'.
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
#include <objects/scoremat/Pssm.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/scoremat/PssmFinalData.hpp>
#include <objects/scoremat/PssmIntermediateData.hpp>
#include <objects/seqset/Seq_entry.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPssm_Base::ResetIdentifier(void)
{
    m_Identifier.Reset();
}

void CPssm_Base::SetIdentifier(CPssm_Base::TIdentifier& value)
{
    m_Identifier.Reset(&value);
}

CPssm_Base::TIdentifier& CPssm_Base::SetIdentifier(void)
{
    if ( !m_Identifier )
        m_Identifier.Reset(new ncbi::objects::CObject_id());
    return (*m_Identifier);
}

void CPssm_Base::ResetRowLabels(void)
{
    m_RowLabels.clear();
    m_set_State[0] &= ~0x300;
}

void CPssm_Base::ResetQuery(void)
{
    m_Query.Reset();
}

void CPssm_Base::SetQuery(CPssm_Base::TQuery& value)
{
    m_Query.Reset(&value);
}

CPssm_Base::TQuery& CPssm_Base::SetQuery(void)
{
    if ( !m_Query )
        m_Query.Reset(new ncbi::objects::CSeq_entry());
    return (*m_Query);
}

void CPssm_Base::ResetIntermediateData(void)
{
    m_IntermediateData.Reset();
}

void CPssm_Base::SetIntermediateData(CPssm_Base::TIntermediateData& value)
{
    m_IntermediateData.Reset(&value);
}

CPssm_Base::TIntermediateData& CPssm_Base::SetIntermediateData(void)
{
    if ( !m_IntermediateData )
        m_IntermediateData.Reset(new ncbi::objects::CPssmIntermediateData());
    return (*m_IntermediateData);
}

void CPssm_Base::ResetFinalData(void)
{
    m_FinalData.Reset();
}

void CPssm_Base::SetFinalData(CPssm_Base::TFinalData& value)
{
    m_FinalData.Reset(&value);
}

CPssm_Base::TFinalData& CPssm_Base::SetFinalData(void)
{
    if ( !m_FinalData )
        m_FinalData.Reset(new ncbi::objects::CPssmFinalData());
    return (*m_FinalData);
}

void CPssm_Base::Reset(void)
{
    ResetIsProtein();
    ResetIdentifier();
    ResetNumRows();
    ResetNumColumns();
    ResetRowLabels();
    ResetByRow();
    ResetQuery();
    ResetIntermediateData();
    ResetFinalData();
}

BEGIN_NAMED_BASE_CLASS_INFO("Pssm", CPssm)
{
    SET_CLASS_MODULE("NCBI-ScoreMat");
    ADD_NAMED_STD_MEMBER("isProtein", m_IsProtein)->SetDefault(new TIsProtein(true))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("identifier", m_Identifier, CObject_id)->SetOptional();
    ADD_NAMED_STD_MEMBER("numRows", m_NumRows)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("numColumns", m_NumColumns)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("rowLabels", m_RowLabels, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("byRow", m_ByRow)->SetDefault(new TByRow(false))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("query", m_Query, CSeq_entry)->SetOptional();
    ADD_NAMED_REF_MEMBER("intermediateData", m_IntermediateData, CPssmIntermediateData)->SetOptional();
    ADD_NAMED_REF_MEMBER("finalData", m_FinalData, CPssmFinalData)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPssm_Base::CPssm_Base(void)
    : m_IsProtein(true), m_NumRows(0), m_NumColumns(0), m_ByRow(false)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPssm_Base::~CPssm_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

