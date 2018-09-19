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
#include <objects/blast/Blast4_reply.hpp>
#include <objects/blast/Blast4_error.hpp>
#include <objects/blast/Blast4_reply_body.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBlast4_reply_Base::ResetErrors(void)
{
    m_Errors.clear();
    m_set_State[0] &= ~0x3;
}

void CBlast4_reply_Base::ResetBody(void)
{
    if ( !m_Body ) {
        m_Body.Reset(new TBody());
        return;
    }
    (*m_Body).Reset();
}

void CBlast4_reply_Base::SetBody(CBlast4_reply_Base::TBody& value)
{
    m_Body.Reset(&value);
}

void CBlast4_reply_Base::Reset(void)
{
    ResetErrors();
    ResetBody();
}

BEGIN_NAMED_BASE_CLASS_INFO("Blast4-reply", CBlast4_reply)
{
    SET_CLASS_MODULE("NCBI-Blast4");
    ADD_NAMED_MEMBER("errors", m_Errors, STL_list, (STL_CRef, (CLASS, (CBlast4_error))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("body", m_Body, CBlast4_reply_body);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBlast4_reply_Base::CBlast4_reply_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetBody();
    }
}

// destructor
CBlast4_reply_Base::~CBlast4_reply_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

