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
 *   'blastxml.asn'.
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
#include <objects/blastxml/Hit.hpp>
#include <objects/blastxml/Hsp.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CHit_Base::ResetId(void)
{
    m_Id.erase();
    m_set_State[0] &= ~0xc;
}

void CHit_Base::ResetDef(void)
{
    m_Def.erase();
    m_set_State[0] &= ~0x30;
}

void CHit_Base::ResetAccession(void)
{
    m_Accession.erase();
    m_set_State[0] &= ~0xc0;
}

void CHit_Base::ResetHsps(void)
{
    m_Hsps.clear();
    m_set_State[0] &= ~0xc00;
}

void CHit_Base::Reset(void)
{
    ResetNum();
    ResetId();
    ResetDef();
    ResetAccession();
    ResetLen();
    ResetHsps();
}

BEGIN_NAMED_BASE_CLASS_INFO("Hit", CHit)
{
    SET_CLASS_MODULE("NCBI-BlastOutput");
    ADD_NAMED_STD_MEMBER("num", m_Num)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("id", m_Id)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("def", m_Def)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("accession", m_Accession)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("len", m_Len)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("hsps", m_Hsps, STL_list, (STL_CRef, (CLASS, (CHsp))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CHit_Base::CHit_Base(void)
    : m_Num(0), m_Len(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CHit_Base::~CHit_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
