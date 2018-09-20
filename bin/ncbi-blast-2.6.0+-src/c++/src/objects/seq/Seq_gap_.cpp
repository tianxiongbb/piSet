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
 *   'seq.asn'.
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
#include <objects/seq/Seq_gap.hpp>
#include <objects/seq/Linkage_evidence.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_gap_Base::, EType, true)
{
    SET_ENUM_INTERNAL_NAME("Seq-gap", "type");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("unknown", eType_unknown);
    ADD_ENUM_VALUE("fragment", eType_fragment);
    ADD_ENUM_VALUE("clone", eType_clone);
    ADD_ENUM_VALUE("short-arm", eType_short_arm);
    ADD_ENUM_VALUE("heterochromatin", eType_heterochromatin);
    ADD_ENUM_VALUE("centromere", eType_centromere);
    ADD_ENUM_VALUE("telomere", eType_telomere);
    ADD_ENUM_VALUE("repeat", eType_repeat);
    ADD_ENUM_VALUE("contig", eType_contig);
    ADD_ENUM_VALUE("scaffold", eType_scaffold);
    ADD_ENUM_VALUE("other", eType_other);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSeq_gap_Base::, ELinkage, true)
{
    SET_ENUM_INTERNAL_NAME("Seq-gap", "linkage");
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("unlinked", eLinkage_unlinked);
    ADD_ENUM_VALUE("linked", eLinkage_linked);
    ADD_ENUM_VALUE("other", eLinkage_other);
}
END_ENUM_INFO

void CSeq_gap_Base::ResetLinkage_evidence(void)
{
    m_Linkage_evidence.clear();
    m_set_State[0] &= ~0x30;
}

void CSeq_gap_Base::Reset(void)
{
    ResetType();
    ResetLinkage();
    ResetLinkage_evidence();
}

BEGIN_NAMED_BASE_CLASS_INFO("Seq-gap", CSeq_gap)
{
    SET_CLASS_MODULE("NCBI-Sequence");
    ADD_NAMED_ENUM_MEMBER("type", m_Type, EType)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("linkage", m_Linkage, ELinkage)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("linkage-evidence", m_Linkage_evidence, STL_list_set, (STL_CRef, (CLASS, (CLinkage_evidence))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSeq_gap_Base::CSeq_gap_Base(void)
    : m_Type((EType)(0)), m_Linkage((ELinkage)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSeq_gap_Base::~CSeq_gap_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
