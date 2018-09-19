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
 *   'seqfeat.asn'.
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
#include <objects/seqfeat/Cdregion.hpp>
#include <objects/seqfeat/Code_break.hpp>
#include <objects/seqfeat/Genetic_code.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CCdregion_Base::, EFrame, false)
{
    SET_ENUM_INTERNAL_NAME("Cdregion", "frame");
    SET_ENUM_MODULE("NCBI-Seqfeat");
    ADD_ENUM_VALUE("not-set", eFrame_not_set);
    ADD_ENUM_VALUE("one", eFrame_one);
    ADD_ENUM_VALUE("two", eFrame_two);
    ADD_ENUM_VALUE("three", eFrame_three);
}
END_ENUM_INFO

void CCdregion_Base::ResetCode(void)
{
    m_Code.Reset();
}

void CCdregion_Base::SetCode(CCdregion_Base::TCode& value)
{
    m_Code.Reset(&value);
}

CCdregion_Base::TCode& CCdregion_Base::SetCode(void)
{
    if ( !m_Code )
        m_Code.Reset(new ncbi::objects::CGenetic_code());
    return (*m_Code);
}

void CCdregion_Base::ResetCode_break(void)
{
    m_Code_break.clear();
    m_set_State[0] &= ~0x3000;
}

void CCdregion_Base::Reset(void)
{
    ResetOrf();
    ResetFrame();
    ResetConflict();
    ResetGaps();
    ResetMismatch();
    ResetCode();
    ResetCode_break();
    ResetStops();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cdregion", CCdregion)
{
    SET_CLASS_MODULE("NCBI-Seqfeat");
    ADD_NAMED_STD_MEMBER("orf", m_Orf)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("frame", m_Frame, EFrame)->SetDefault(new TFrame(eFrame_not_set))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("conflict", m_Conflict)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("gaps", m_Gaps)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("mismatch", m_Mismatch)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("code", m_Code, CGenetic_code)->SetOptional();
    ADD_NAMED_MEMBER("code-break", m_Code_break, STL_list, (STL_CRef, (CLASS, (CCode_break))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("stops", m_Stops)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCdregion_Base::CCdregion_Base(void)
    : m_Orf(0), m_Frame(eFrame_not_set), m_Conflict(0), m_Gaps(0), m_Mismatch(0), m_Stops(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CCdregion_Base::~CCdregion_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

