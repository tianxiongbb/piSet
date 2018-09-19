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
 *   'medline.asn'.
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
#include <objects/medline/Medline_entry.hpp>
#include <objects/biblio/Cit_art.hpp>
#include <objects/general/Date.hpp>
#include <objects/medline/Medline_field.hpp>
#include <objects/medline/Medline_mesh.hpp>
#include <objects/medline/Medline_rn.hpp>
#include <objects/medline/Medline_si.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CMedline_entry_Base::, EStatus, true)
{
    SET_ENUM_INTERNAL_NAME("Medline-entry", "status");
    SET_ENUM_MODULE("NCBI-Medline");
    ADD_ENUM_VALUE("publisher", eStatus_publisher);
    ADD_ENUM_VALUE("premedline", eStatus_premedline);
    ADD_ENUM_VALUE("medline", eStatus_medline);
}
END_ENUM_INFO

void CMedline_entry_Base::ResetEm(void)
{
    if ( !m_Em ) {
        m_Em.Reset(new TEm());
        return;
    }
    (*m_Em).Reset();
}

void CMedline_entry_Base::SetEm(CMedline_entry_Base::TEm& value)
{
    m_Em.Reset(&value);
}

void CMedline_entry_Base::ResetCit(void)
{
    if ( !m_Cit ) {
        m_Cit.Reset(new TCit());
        return;
    }
    (*m_Cit).Reset();
}

void CMedline_entry_Base::SetCit(CMedline_entry_Base::TCit& value)
{
    m_Cit.Reset(&value);
}

void CMedline_entry_Base::ResetAbstract(void)
{
    m_Abstract.erase();
    m_set_State[0] &= ~0xc0;
}

void CMedline_entry_Base::ResetMesh(void)
{
    m_Mesh.clear();
    m_set_State[0] &= ~0x300;
}

void CMedline_entry_Base::ResetSubstance(void)
{
    m_Substance.clear();
    m_set_State[0] &= ~0xc00;
}

void CMedline_entry_Base::ResetXref(void)
{
    m_Xref.clear();
    m_set_State[0] &= ~0x3000;
}

void CMedline_entry_Base::ResetIdnum(void)
{
    m_Idnum.clear();
    m_set_State[0] &= ~0xc000;
}

void CMedline_entry_Base::ResetGene(void)
{
    m_Gene.clear();
    m_set_State[0] &= ~0x30000;
}

void CMedline_entry_Base::ResetPub_type(void)
{
    m_Pub_type.clear();
    m_set_State[0] &= ~0x300000;
}

void CMedline_entry_Base::ResetMlfield(void)
{
    m_Mlfield.clear();
    m_set_State[0] &= ~0xc00000;
}

void CMedline_entry_Base::Reset(void)
{
    ResetUid();
    ResetEm();
    ResetCit();
    ResetAbstract();
    ResetMesh();
    ResetSubstance();
    ResetXref();
    ResetIdnum();
    ResetGene();
    ResetPmid();
    ResetPub_type();
    ResetMlfield();
    ResetStatus();
}

BEGIN_NAMED_BASE_CLASS_INFO("Medline-entry", CMedline_entry)
{
    SET_CLASS_MODULE("NCBI-Medline");
    ADD_NAMED_STD_MEMBER("uid", m_Uid)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("em", m_Em, CDate);
    ADD_NAMED_REF_MEMBER("cit", m_Cit, CCit_art);
    ADD_NAMED_STD_MEMBER("abstract", m_Abstract)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("mesh", m_Mesh, STL_list_set, (STL_CRef, (CLASS, (CMedline_mesh))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("substance", m_Substance, STL_list_set, (STL_CRef, (CLASS, (CMedline_rn))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("xref", m_Xref, STL_list_set, (STL_CRef, (CLASS, (CMedline_si))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("idnum", m_Idnum, STL_list_set, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("gene", m_Gene, STL_list_set, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("pmid", m_Pmid, CLASS, (CPubMedId))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("pub-type", m_Pub_type, STL_list_set, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("mlfield", m_Mlfield, STL_list_set, (STL_CRef, (CLASS, (CMedline_field))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("status", m_Status, EStatus)->SetDefault(new TStatus(eStatus_medline))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CMedline_entry_Base::CMedline_entry_Base(void)
    : m_Uid(0), m_Pmid(CPubMedId(0)), m_Status(eStatus_medline)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetEm();
        ResetCit();
    }
}

// destructor
CMedline_entry_Base::~CMedline_entry_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

