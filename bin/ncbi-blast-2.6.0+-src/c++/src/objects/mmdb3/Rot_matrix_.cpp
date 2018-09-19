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
#include <objects/mmdb3/Rot_matrix.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CRot_matrix_Base::Reset(void)
{
    ResetScale_factor();
    ResetRot_11();
    ResetRot_12();
    ResetRot_13();
    ResetRot_21();
    ResetRot_22();
    ResetRot_23();
    ResetRot_31();
    ResetRot_32();
    ResetRot_33();
}

BEGIN_NAMED_BASE_CLASS_INFO("Rot-matrix", CRot_matrix)
{
    SET_CLASS_MODULE("MMDB-Features");
    ADD_NAMED_STD_MEMBER("scale-factor", m_Scale_factor)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-11", m_Rot_11)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-12", m_Rot_12)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-13", m_Rot_13)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-21", m_Rot_21)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-22", m_Rot_22)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-23", m_Rot_23)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-31", m_Rot_31)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-32", m_Rot_32)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("rot-33", m_Rot_33)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CRot_matrix_Base::CRot_matrix_Base(void)
    : m_Scale_factor(0), m_Rot_11(0), m_Rot_12(0), m_Rot_13(0), m_Rot_21(0), m_Rot_22(0), m_Rot_23(0), m_Rot_31(0), m_Rot_32(0), m_Rot_33(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CRot_matrix_Base::~CRot_matrix_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

