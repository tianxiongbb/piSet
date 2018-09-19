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
 *   'macro.asn'.
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
#include <objects/macro/Location_constraint.hpp>
#include <objects/macro/Location_pos_constraint.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CLocation_constraint_Base::ResetEnd5(void)
{
    m_End5.Reset();
}

void CLocation_constraint_Base::SetEnd5(CLocation_constraint_Base::TEnd5& value)
{
    m_End5.Reset(&value);
}

CLocation_constraint_Base::TEnd5& CLocation_constraint_Base::SetEnd5(void)
{
    if ( !m_End5 )
        m_End5.Reset(new ncbi::objects::CLocation_pos_constraint());
    return (*m_End5);
}

void CLocation_constraint_Base::ResetEnd3(void)
{
    m_End3.Reset();
}

void CLocation_constraint_Base::SetEnd3(CLocation_constraint_Base::TEnd3& value)
{
    m_End3.Reset(&value);
}

CLocation_constraint_Base::TEnd3& CLocation_constraint_Base::SetEnd3(void)
{
    if ( !m_End3 )
        m_End3.Reset(new ncbi::objects::CLocation_pos_constraint());
    return (*m_End3);
}

void CLocation_constraint_Base::Reset(void)
{
    ResetStrand();
    ResetSeq_type();
    ResetPartial5();
    ResetPartial3();
    ResetLocation_type();
    ResetEnd5();
    ResetEnd3();
}

BEGIN_NAMED_BASE_CLASS_INFO("Location-constraint", CLocation_constraint)
{
    SET_CLASS_MODULE("NCBI-Macro");
    ADD_NAMED_ENUM_MEMBER("strand", m_Strand, EStrand_constraint)->SetDefault(new TStrand(eStrand_constraint_any))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("seq-type", m_Seq_type, ESeqtype_constraint)->SetDefault(new TSeq_type(eSeqtype_constraint_any))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("partial5", m_Partial5, EPartial_constraint)->SetDefault(new TPartial5(ePartial_constraint_either))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("partial3", m_Partial3, EPartial_constraint)->SetDefault(new TPartial3(ePartial_constraint_either))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("location-type", m_Location_type, ELocation_type_constraint)->SetDefault(new TLocation_type(eLocation_type_constraint_any))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("end5", m_End5, CLocation_pos_constraint)->SetOptional();
    ADD_NAMED_REF_MEMBER("end3", m_End3, CLocation_pos_constraint)->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CLocation_constraint_Base::CLocation_constraint_Base(void)
    : m_Strand(eStrand_constraint_any), m_Seq_type(eSeqtype_constraint_any), m_Partial5(ePartial_constraint_either), m_Partial3(ePartial_constraint_either), m_Location_type(eLocation_type_constraint_any)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CLocation_constraint_Base::~CLocation_constraint_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

