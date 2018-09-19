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
 *   'ncbimime.asn'.
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
#include <objects/ncbimime/Entrez_general.hpp>
#include <objects/medline/Medline_entry.hpp>
#include <objects/mmdb1/Biostruc.hpp>
#include <objects/mmdb1/Biostruc_annot_set.hpp>
#include <objects/seqset/Seq_entry.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CEntrez_general_Base::C_Data::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CEntrez_general_Base::C_Data::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Ml:
    case e_Prot:
    case e_Nuc:
    case e_Genome:
    case e_Structure:
    case e_StrucAnnot:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CEntrez_general_Base::C_Data::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Ml:
        (m_object = new(pool) ncbi::objects::CMedline_entry())->AddReference();
        break;
    case e_Prot:
        (m_object = new(pool) ncbi::objects::CSeq_entry())->AddReference();
        break;
    case e_Nuc:
        (m_object = new(pool) ncbi::objects::CSeq_entry())->AddReference();
        break;
    case e_Genome:
        (m_object = new(pool) ncbi::objects::CSeq_entry())->AddReference();
        break;
    case e_Structure:
        (m_object = new(pool) ncbi::objects::CBiostruc())->AddReference();
        break;
    case e_StrucAnnot:
        (m_object = new(pool) ncbi::objects::CBiostruc_annot_set())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CEntrez_general_Base::C_Data::sm_SelectionNames[] = {
    "not set",
    "ml",
    "prot",
    "nuc",
    "genome",
    "structure",
    "strucAnnot"
};

NCBI_NS_STD::string CEntrez_general_Base::C_Data::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CEntrez_general_Base::C_Data::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CEntrez_general_Base::C_Data::TMl& CEntrez_general_Base::C_Data::GetMl(void) const
{
    CheckSelected(e_Ml);
    return *static_cast<const TMl*>(m_object);
}

CEntrez_general_Base::C_Data::TMl& CEntrez_general_Base::C_Data::SetMl(void)
{
    Select(e_Ml, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMl*>(m_object);
}

void CEntrez_general_Base::C_Data::SetMl(CEntrez_general_Base::C_Data::TMl& value)
{
    TMl* ptr = &value;
    if ( m_choice != e_Ml || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Ml;
    }
}

const CEntrez_general_Base::C_Data::TProt& CEntrez_general_Base::C_Data::GetProt(void) const
{
    CheckSelected(e_Prot);
    return *static_cast<const TProt*>(m_object);
}

CEntrez_general_Base::C_Data::TProt& CEntrez_general_Base::C_Data::SetProt(void)
{
    Select(e_Prot, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TProt*>(m_object);
}

void CEntrez_general_Base::C_Data::SetProt(CEntrez_general_Base::C_Data::TProt& value)
{
    TProt* ptr = &value;
    if ( m_choice != e_Prot || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Prot;
    }
}

const CEntrez_general_Base::C_Data::TNuc& CEntrez_general_Base::C_Data::GetNuc(void) const
{
    CheckSelected(e_Nuc);
    return *static_cast<const TNuc*>(m_object);
}

CEntrez_general_Base::C_Data::TNuc& CEntrez_general_Base::C_Data::SetNuc(void)
{
    Select(e_Nuc, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TNuc*>(m_object);
}

void CEntrez_general_Base::C_Data::SetNuc(CEntrez_general_Base::C_Data::TNuc& value)
{
    TNuc* ptr = &value;
    if ( m_choice != e_Nuc || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Nuc;
    }
}

const CEntrez_general_Base::C_Data::TGenome& CEntrez_general_Base::C_Data::GetGenome(void) const
{
    CheckSelected(e_Genome);
    return *static_cast<const TGenome*>(m_object);
}

CEntrez_general_Base::C_Data::TGenome& CEntrez_general_Base::C_Data::SetGenome(void)
{
    Select(e_Genome, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TGenome*>(m_object);
}

void CEntrez_general_Base::C_Data::SetGenome(CEntrez_general_Base::C_Data::TGenome& value)
{
    TGenome* ptr = &value;
    if ( m_choice != e_Genome || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Genome;
    }
}

const CEntrez_general_Base::C_Data::TStructure& CEntrez_general_Base::C_Data::GetStructure(void) const
{
    CheckSelected(e_Structure);
    return *static_cast<const TStructure*>(m_object);
}

CEntrez_general_Base::C_Data::TStructure& CEntrez_general_Base::C_Data::SetStructure(void)
{
    Select(e_Structure, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TStructure*>(m_object);
}

void CEntrez_general_Base::C_Data::SetStructure(CEntrez_general_Base::C_Data::TStructure& value)
{
    TStructure* ptr = &value;
    if ( m_choice != e_Structure || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Structure;
    }
}

const CEntrez_general_Base::C_Data::TStrucAnnot& CEntrez_general_Base::C_Data::GetStrucAnnot(void) const
{
    CheckSelected(e_StrucAnnot);
    return *static_cast<const TStrucAnnot*>(m_object);
}

CEntrez_general_Base::C_Data::TStrucAnnot& CEntrez_general_Base::C_Data::SetStrucAnnot(void)
{
    Select(e_StrucAnnot, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TStrucAnnot*>(m_object);
}

void CEntrez_general_Base::C_Data::SetStrucAnnot(CEntrez_general_Base::C_Data::TStrucAnnot& value)
{
    TStrucAnnot* ptr = &value;
    if ( m_choice != e_StrucAnnot || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_StrucAnnot;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CEntrez_general_Base::C_Data)
{
    SET_INTERNAL_NAME("Entrez-general", "data");
    SET_CHOICE_MODULE("NCBI-Mime");
    ADD_NAMED_REF_CHOICE_VARIANT("ml", m_object, CMedline_entry);
    ADD_NAMED_REF_CHOICE_VARIANT("prot", m_object, CSeq_entry);
    ADD_NAMED_REF_CHOICE_VARIANT("nuc", m_object, CSeq_entry);
    ADD_NAMED_REF_CHOICE_VARIANT("genome", m_object, CSeq_entry);
    ADD_NAMED_REF_CHOICE_VARIANT("structure", m_object, CBiostruc);
    ADD_NAMED_REF_CHOICE_VARIANT("strucAnnot", m_object, CBiostruc_annot_set);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CEntrez_general_Base::C_Data::C_Data(void)
    : m_choice(e_not_set)
{
}

// destructor
CEntrez_general_Base::C_Data::~C_Data(void)
{
    Reset();
}


void CEntrez_general_Base::ResetTitle(void)
{
    m_Title.erase();
    m_set_State[0] &= ~0x3;
}

void CEntrez_general_Base::ResetData(void)
{
    if ( !m_Data ) {
        m_Data.Reset(new TData());
        return;
    }
    (*m_Data).Reset();
}

void CEntrez_general_Base::SetData(CEntrez_general_Base::TData& value)
{
    m_Data.Reset(&value);
}

void CEntrez_general_Base::ResetLocation(void)
{
    m_Location.erase();
    m_set_State[0] &= ~0xc0;
}

void CEntrez_general_Base::Reset(void)
{
    ResetTitle();
    ResetData();
    ResetStyle();
    ResetLocation();
}

BEGIN_NAMED_BASE_CLASS_INFO("Entrez-general", CEntrez_general)
{
    SET_CLASS_MODULE("NCBI-Mime");
    ADD_NAMED_STD_MEMBER("title", m_Title)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("data", m_Data, C_Data);
    ADD_NAMED_ENUM_MEMBER("style", m_Style, EEntrez_style)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("location", m_Location)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CEntrez_general_Base::CEntrez_general_Base(void)
    : m_Style((ncbi::objects::EEntrez_style)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetData();
    }
}

// destructor
CEntrez_general_Base::~CEntrez_general_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

