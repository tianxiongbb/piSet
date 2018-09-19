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
 *   'pcsubstance.asn'.
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
#include <objects/pcsubstance/PC_Coordinates.hpp>
#include <objects/pcsubstance/PC_AtomString.hpp>
#include <objects/pcsubstance/PC_Conformer.hpp>
#include <objects/pcsubstance/PC_InfoData.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPC_Coordinates_Base::ResetType(void)
{
    m_Type.clear();
    m_set_State[0] &= ~0x3;
}

void CPC_Coordinates_Base::ResetAid(void)
{
    m_Aid.clear();
    m_set_State[0] &= ~0xc;
}

void CPC_Coordinates_Base::ResetConformers(void)
{
    m_Conformers.clear();
    m_set_State[0] &= ~0x30;
}

void CPC_Coordinates_Base::ResetAtomlabels(void)
{
    m_Atomlabels.clear();
    m_set_State[0] &= ~0xc0;
}

void CPC_Coordinates_Base::ResetData(void)
{
    m_Data.clear();
    m_set_State[0] &= ~0x300;
}

void CPC_Coordinates_Base::Reset(void)
{
    ResetType();
    ResetAid();
    ResetConformers();
    ResetAtomlabels();
    ResetData();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-Coordinates", CPC_Coordinates)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_MEMBER("type", m_Type, STL_vector, (ENUM, (int, EPC_CoordinateType)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("aid", m_Aid, STL_vector, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("conformers", m_Conformers, STL_list, (STL_CRef, (CLASS, (CPC_Conformer))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("atomlabels", m_Atomlabels, STL_list, (STL_CRef, (CLASS, (CPC_AtomString))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("data", m_Data, STL_list, (STL_CRef, (CLASS, (CPC_InfoData))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPC_Coordinates_Base::CPC_Coordinates_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_Coordinates_Base::~CPC_Coordinates_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

