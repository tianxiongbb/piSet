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
#include <objects/scoremat/CoreDef.hpp>
#include <objects/scoremat/CoreBlock.hpp>
#include <objects/scoremat/LoopConstraint.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCoreDef_Base::ResetBlocks(void)
{
    m_Blocks.clear();
    m_set_State[0] &= ~0xc;
}

void CCoreDef_Base::ResetLoops(void)
{
    m_Loops.clear();
    m_set_State[0] &= ~0x30;
}

void CCoreDef_Base::ResetInsertions(void)
{
    m_Insertions.clear();
    m_set_State[0] &= ~0x300;
}

void CCoreDef_Base::Reset(void)
{
    ResetNblocks();
    ResetBlocks();
    ResetLoops();
    ResetIsDiscontinuous();
    ResetInsertions();
}

BEGIN_NAMED_BASE_CLASS_INFO("CoreDef", CCoreDef)
{
    SET_CLASS_MODULE("NCBI-ScoreMat");
    ADD_NAMED_STD_MEMBER("nblocks", m_Nblocks)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("blocks", m_Blocks, STL_list, (STL_CRef, (CLASS, (CCoreBlock))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("loops", m_Loops, STL_list, (STL_CRef, (CLASS, (CLoopConstraint))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("isDiscontinuous", m_IsDiscontinuous)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("insertions", m_Insertions, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCoreDef_Base::CCoreDef_Base(void)
    : m_Nblocks(0), m_IsDiscontinuous(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CCoreDef_Base::~CCoreDef_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

