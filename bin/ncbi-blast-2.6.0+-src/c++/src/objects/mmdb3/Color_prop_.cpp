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
 *   'mmdb3.asn'.
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
#include <objects/mmdb3/Color_prop.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CColor_prop_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0xc0;
}

void CColor_prop_Base::Reset(void)
{
    ResetR();
    ResetG();
    ResetB();
    ResetName();
}

BEGIN_NAMED_BASE_CLASS_INFO("Color-prop", CColor_prop)
{
    SET_CLASS_MODULE("MMDB-Features");
    ADD_NAMED_STD_MEMBER("r", m_R)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("g", m_G)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("b", m_B)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CColor_prop_Base::CColor_prop_Base(void)
    : m_R(0), m_G(0), m_B(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CColor_prop_Base::~CColor_prop_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

