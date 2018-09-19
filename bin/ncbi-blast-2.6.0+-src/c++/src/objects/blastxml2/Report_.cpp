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
 *   'blastxml2.asn'.
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
#include <objects/blastxml2/Report.hpp>
#include <objects/blastxml2/Parameters.hpp>
#include <objects/blastxml2/Results.hpp>
#include <objects/blastxml2/Target.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

BEGIN_blastxml2_SCOPE // namespace ncbi::objects::blastxml2::


// generated classes

void CReport_Base::ResetProgram(void)
{
    m_Program.erase();
    m_set_State[0] &= ~0x3;
}

void CReport_Base::ResetVersion(void)
{
    m_Version.erase();
    m_set_State[0] &= ~0xc;
}

void CReport_Base::ResetReference(void)
{
    m_Reference.erase();
    m_set_State[0] &= ~0x30;
}

void CReport_Base::ResetSearch_target(void)
{
    if ( !m_Search_target ) {
        m_Search_target.Reset(new TSearch_target());
        return;
    }
    (*m_Search_target).Reset();
}

void CReport_Base::SetSearch_target(CReport_Base::TSearch_target& value)
{
    m_Search_target.Reset(&value);
}

void CReport_Base::ResetParams(void)
{
    if ( !m_Params ) {
        m_Params.Reset(new TParams());
        return;
    }
    (*m_Params).Reset();
}

void CReport_Base::SetParams(CReport_Base::TParams& value)
{
    m_Params.Reset(&value);
}

void CReport_Base::ResetResults(void)
{
    if ( !m_Results ) {
        m_Results.Reset(new TResults());
        return;
    }
    (*m_Results).Reset();
}

void CReport_Base::SetResults(CReport_Base::TResults& value)
{
    m_Results.Reset(&value);
}

void CReport_Base::Reset(void)
{
    ResetProgram();
    ResetVersion();
    ResetReference();
    ResetSearch_target();
    ResetParams();
    ResetResults();
}

BEGIN_NAMED_BASE_CLASS_INFO("Report", CReport)
{
    SET_CLASS_MODULE("NCBI-BlastOutput2");
    ADD_NAMED_STD_MEMBER("program", m_Program)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("version", m_Version)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("reference", m_Reference)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("search-target", m_Search_target, CTarget);
    ADD_NAMED_REF_MEMBER("params", m_Params, CParameters);
    ADD_NAMED_REF_MEMBER("results", m_Results, CResults);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CReport_Base::CReport_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetSearch_target();
        ResetParams();
        ResetResults();
    }
}

// destructor
CReport_Base::~CReport_Base(void)
{
}



END_blastxml2_SCOPE // namespace ncbi::objects::blastxml2::

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

