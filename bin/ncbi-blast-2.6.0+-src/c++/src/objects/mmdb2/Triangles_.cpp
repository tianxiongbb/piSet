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
 *   'mmdb2.asn'.
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
#include <objects/mmdb2/Triangles.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTriangles_Base::ResetX(void)
{
    m_X.clear();
    m_set_State[0] &= ~0x30;
}

void CTriangles_Base::ResetY(void)
{
    m_Y.clear();
    m_set_State[0] &= ~0xc0;
}

void CTriangles_Base::ResetZ(void)
{
    m_Z.clear();
    m_set_State[0] &= ~0x300;
}

void CTriangles_Base::ResetV1(void)
{
    m_V1.clear();
    m_set_State[0] &= ~0x3000;
}

void CTriangles_Base::ResetV2(void)
{
    m_V2.clear();
    m_set_State[0] &= ~0xc000;
}

void CTriangles_Base::ResetV3(void)
{
    m_V3.clear();
    m_set_State[0] &= ~0x30000;
}

void CTriangles_Base::Reset(void)
{
    ResetNumber_of_points();
    ResetScale_factor();
    ResetX();
    ResetY();
    ResetZ();
    ResetNumber_of_triangles();
    ResetV1();
    ResetV2();
    ResetV3();
}

BEGIN_NAMED_BASE_CLASS_INFO("Triangles", CTriangles)
{
    SET_CLASS_MODULE("MMDB-Structural-model");
    ADD_NAMED_STD_MEMBER("number-of-points", m_Number_of_points)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("scale-factor", m_Scale_factor)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("x", m_X, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("y", m_Y, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("z", m_Z, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("number-of-triangles", m_Number_of_triangles)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("v1", m_V1, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("v2", m_V2, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("v3", m_V3, STL_list, (STD, (int)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTriangles_Base::CTriangles_Base(void)
    : m_Number_of_points(0), m_Scale_factor(0), m_Number_of_triangles(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CTriangles_Base::~CTriangles_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

