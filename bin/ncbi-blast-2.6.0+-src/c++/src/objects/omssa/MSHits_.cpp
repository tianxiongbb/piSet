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
 *   'omssa.asn'.
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
#include <objects/omssa/MSHits.hpp>
#include <objects/omssa/MSMZHit.hpp>
#include <objects/omssa/MSModHit.hpp>
#include <objects/omssa/MSPepHit.hpp>
#include <objects/omssa/MSScoreSet.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CMSHits_Base::ResetPephits(void)
{
    m_Pephits.clear();
    m_set_State[0] &= ~0xc0;
}

void CMSHits_Base::ResetMzhits(void)
{
    m_Mzhits.clear();
    m_set_State[0] &= ~0x300;
}

void CMSHits_Base::ResetPepstring(void)
{
    m_Pepstring.erase();
    m_set_State[0] &= ~0xc00;
}

void CMSHits_Base::ResetMods(void)
{
    m_Mods.clear();
    m_set_State[0] &= ~0xc000;
}

void CMSHits_Base::ResetPepstart(void)
{
    m_Pepstart.erase();
    m_set_State[0] &= ~0x30000;
}

void CMSHits_Base::ResetPepstop(void)
{
    m_Pepstop.erase();
    m_set_State[0] &= ~0xc0000;
}

void CMSHits_Base::ResetScores(void)
{
    m_Scores.clear();
    m_set_State[0] &= ~0xc000000;
}

void CMSHits_Base::ResetLibaccession(void)
{
    m_Libaccession.erase();
    m_set_State[0] &= ~0x30000000;
}

void CMSHits_Base::Reset(void)
{
    ResetEvalue();
    ResetPvalue();
    ResetCharge();
    ResetPephits();
    ResetMzhits();
    ResetPepstring();
    ResetMass();
    ResetMods();
    ResetPepstart();
    ResetPepstop();
    ResetProtlength();
    ResetTheomass();
    ResetOid();
    ResetScores();
    ResetLibaccession();
}

BEGIN_NAMED_BASE_CLASS_INFO("MSHits", CMSHits)
{
    SET_CLASS_MODULE("OMSSA");
    ADD_NAMED_STD_MEMBER("evalue", m_Evalue)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("pvalue", m_Pvalue)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("charge", m_Charge)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("pephits", m_Pephits, STL_list, (STL_CRef, (CLASS, (CMSPepHit))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("mzhits", m_Mzhits, STL_list, (STL_CRef, (CLASS, (CMSMZHit))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("pepstring", m_Pepstring)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("mass", m_Mass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("mods", m_Mods, STL_list, (STL_CRef, (CLASS, (CMSModHit))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("pepstart", m_Pepstart)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("pepstop", m_Pepstop)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("protlength", m_Protlength)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("theomass", m_Theomass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("oid", m_Oid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("scores", m_Scores, STL_list, (STL_CRef, (CLASS, (CMSScoreSet))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("libaccession", m_Libaccession)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CMSHits_Base::CMSHits_Base(void)
    : m_Evalue(0), m_Pvalue(0), m_Charge(0), m_Mass(0), m_Protlength(0), m_Theomass(0), m_Oid(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CMSHits_Base::~CMSHits_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

