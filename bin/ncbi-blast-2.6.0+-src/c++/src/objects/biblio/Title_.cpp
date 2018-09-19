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
 *   'biblio.asn'.
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
#include <objects/biblio/Title.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTitle_Base::C_E::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CTitle_Base::C_E::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Name:
    case e_Tsub:
    case e_Trans:
    case e_Jta:
    case e_Iso_jta:
    case e_Ml_jta:
    case e_Coden:
    case e_Issn:
    case e_Abr:
    case e_Isbn:
        m_string.Destruct();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CTitle_Base::C_E::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Name:
    case e_Tsub:
    case e_Trans:
    case e_Jta:
    case e_Iso_jta:
    case e_Ml_jta:
    case e_Coden:
    case e_Issn:
    case e_Abr:
    case e_Isbn:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CTitle_Base::C_E::sm_SelectionNames[] = {
    "not set",
    "name",
    "tsub",
    "trans",
    "jta",
    "iso-jta",
    "ml-jta",
    "coden",
    "issn",
    "abr",
    "isbn"
};

NCBI_NS_STD::string CTitle_Base::C_E::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CTitle_Base::C_E::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CTitle_Base::C_E::SetName(const CTitle_Base::C_E::TName& value)
{
    Select(e_Name, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetTsub(const CTitle_Base::C_E::TTsub& value)
{
    Select(e_Tsub, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetTrans(const CTitle_Base::C_E::TTrans& value)
{
    Select(e_Trans, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetJta(const CTitle_Base::C_E::TJta& value)
{
    Select(e_Jta, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetIso_jta(const CTitle_Base::C_E::TIso_jta& value)
{
    Select(e_Iso_jta, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetMl_jta(const CTitle_Base::C_E::TMl_jta& value)
{
    Select(e_Ml_jta, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetCoden(const CTitle_Base::C_E::TCoden& value)
{
    Select(e_Coden, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetIssn(const CTitle_Base::C_E::TIssn& value)
{
    Select(e_Issn, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetAbr(const CTitle_Base::C_E::TAbr& value)
{
    Select(e_Abr, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

void CTitle_Base::C_E::SetIsbn(const CTitle_Base::C_E::TIsbn& value)
{
    Select(e_Isbn, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CTitle_Base::C_E)
{
    SET_INTERNAL_NAME("Title", "E");
    SET_CHOICE_MODULE("NCBI-Biblio");
    ADD_NAMED_BUF_CHOICE_VARIANT("name", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("tsub", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("trans", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("jta", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("iso-jta", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("ml-jta", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("coden", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("issn", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("abr", m_string, STD, (string));
    ADD_NAMED_BUF_CHOICE_VARIANT("isbn", m_string, STD, (string));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CTitle_Base::C_E::C_E(void)
    : m_choice(e_not_set)
{
}

// destructor
CTitle_Base::C_E::~C_E(void)
{
    Reset();
}


void CTitle_Base::Reset(void)
{
    m_data.clear();
    m_set_State[0] &= ~0x3;
}

BEGIN_NAMED_BASE_IMPLICIT_CLASS_INFO("Title", CTitle)
{
    SET_CLASS_MODULE("NCBI-Biblio");
    ADD_NAMED_MEMBER("", m_data, STL_list_set, (STL_CRef, (CLASS, (C_E))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTitle_Base::CTitle_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CTitle_Base::~CTitle_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

