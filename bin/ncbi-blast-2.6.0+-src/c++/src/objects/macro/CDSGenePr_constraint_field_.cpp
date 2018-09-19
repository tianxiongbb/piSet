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
#include <objects/macro/CDSGenePr_constraint_field.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCDSGeneProt_constraint_field_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CCDSGeneProt_constraint_field_Base::ResetSelection(void)
{
    m_choice = e_not_set;
}

void CCDSGeneProt_constraint_field_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* )
{
    switch ( index ) {
    case e_Field:
        m_Field = (ncbi::objects::ECDSGeneProt_field)(0);
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CCDSGeneProt_constraint_field_Base::sm_SelectionNames[] = {
    "not set",
    "field"
};

NCBI_NS_STD::string CCDSGeneProt_constraint_field_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CCDSGeneProt_constraint_field_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("CDSGeneProt-constraint-field", CCDSGeneProt_constraint_field)
{
    SET_CHOICE_MODULE("NCBI-Macro");
    ADD_NAMED_ENUM_CHOICE_VARIANT("field", m_Field, ECDSGeneProt_field);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CCDSGeneProt_constraint_field_Base::CCDSGeneProt_constraint_field_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CCDSGeneProt_constraint_field_Base::~CCDSGeneProt_constraint_field_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

