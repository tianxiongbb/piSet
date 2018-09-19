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
#include <objects/pcsubstance/PC_StereoGroup.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CPC_StereoGroup_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("PC-StereoGroup", "type");
    SET_ENUM_MODULE("NCBI-PCSubstance");
    ADD_ENUM_VALUE("absolute", eType_absolute);
    ADD_ENUM_VALUE("or", eType_or);
    ADD_ENUM_VALUE("and", eType_and);
    ADD_ENUM_VALUE("unknown", eType_unknown);
}
END_ENUM_INFO

void CPC_StereoGroup_Base::ResetAid(void)
{
    m_Aid.clear();
    m_set_State[0] &= ~0xc;
}

void CPC_StereoGroup_Base::Reset(void)
{
    ResetType();
    ResetAid();
}

BEGIN_NAMED_BASE_CLASS_INFO("PC-StereoGroup", CPC_StereoGroup)
{
    SET_CLASS_MODULE("NCBI-PCSubstance");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("aid", m_Aid, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPC_StereoGroup_Base::CPC_StereoGroup_Base(void)
    : m_Type((EType)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CPC_StereoGroup_Base::~CPC_StereoGroup_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

