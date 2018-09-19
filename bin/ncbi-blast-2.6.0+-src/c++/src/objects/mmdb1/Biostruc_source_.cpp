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
 *   'mmdb1.asn'.
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
#include <objects/mmdb1/Biostruc_source.hpp>
#include <objects/general/Date.hpp>
#include <objects/mmdb1/Biostruc_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_source_Base::C_Version_of_database::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CBiostruc_source_Base::C_Version_of_database::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Release_code:
        m_string.Destruct();
        break;
    case e_Release_date:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CBiostruc_source_Base::C_Version_of_database::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Release_date:
        (m_object = new(pool) ncbi::objects::CDate())->AddReference();
        break;
    case e_Release_code:
        m_string.Construct();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CBiostruc_source_Base::C_Version_of_database::sm_SelectionNames[] = {
    "not set",
    "release-date",
    "release-code"
};

NCBI_NS_STD::string CBiostruc_source_Base::C_Version_of_database::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CBiostruc_source_Base::C_Version_of_database::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CBiostruc_source_Base::C_Version_of_database::TRelease_date& CBiostruc_source_Base::C_Version_of_database::GetRelease_date(void) const
{
    CheckSelected(e_Release_date);
    return *static_cast<const TRelease_date*>(m_object);
}

CBiostruc_source_Base::C_Version_of_database::TRelease_date& CBiostruc_source_Base::C_Version_of_database::SetRelease_date(void)
{
    Select(e_Release_date, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TRelease_date*>(m_object);
}

void CBiostruc_source_Base::C_Version_of_database::SetRelease_date(CBiostruc_source_Base::C_Version_of_database::TRelease_date& value)
{
    TRelease_date* ptr = &value;
    if ( m_choice != e_Release_date || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Release_date;
    }
}

void CBiostruc_source_Base::C_Version_of_database::SetRelease_code(const CBiostruc_source_Base::C_Version_of_database::TRelease_code& value)
{
    Select(e_Release_code, NCBI_NS_NCBI::eDoNotResetVariant);
    *m_string = value;
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CBiostruc_source_Base::C_Version_of_database)
{
    SET_INTERNAL_NAME("Biostruc-source", "version-of-database");
    SET_CHOICE_MODULE("MMDB");
    ADD_NAMED_REF_CHOICE_VARIANT("release-date", m_object, CDate);
    ADD_NAMED_BUF_CHOICE_VARIANT("release-code", m_string, STD, (string));
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CBiostruc_source_Base::C_Version_of_database::C_Version_of_database(void)
    : m_choice(e_not_set)
{
}

// destructor
CBiostruc_source_Base::C_Version_of_database::~C_Version_of_database(void)
{
    Reset();
}


void CBiostruc_source_Base::ResetName_of_database(void)
{
    m_Name_of_database.erase();
    m_set_State[0] &= ~0x3;
}

void CBiostruc_source_Base::ResetVersion_of_database(void)
{
    m_Version_of_database.Reset();
}

void CBiostruc_source_Base::SetVersion_of_database(CBiostruc_source_Base::TVersion_of_database& value)
{
    m_Version_of_database.Reset(&value);
}

CBiostruc_source_Base::TVersion_of_database& CBiostruc_source_Base::SetVersion_of_database(void)
{
    if ( !m_Version_of_database )
        m_Version_of_database.Reset(new C_Version_of_database());
    return (*m_Version_of_database);
}

void CBiostruc_source_Base::ResetDatabase_entry_id(void)
{
    if ( !m_Database_entry_id ) {
        m_Database_entry_id.Reset(new TDatabase_entry_id());
        return;
    }
    (*m_Database_entry_id).Reset();
}

void CBiostruc_source_Base::SetDatabase_entry_id(CBiostruc_source_Base::TDatabase_entry_id& value)
{
    m_Database_entry_id.Reset(&value);
}

void CBiostruc_source_Base::ResetDatabase_entry_date(void)
{
    if ( !m_Database_entry_date ) {
        m_Database_entry_date.Reset(new TDatabase_entry_date());
        return;
    }
    (*m_Database_entry_date).Reset();
}

void CBiostruc_source_Base::SetDatabase_entry_date(CBiostruc_source_Base::TDatabase_entry_date& value)
{
    m_Database_entry_date.Reset(&value);
}

void CBiostruc_source_Base::ResetDatabase_entry_history(void)
{
    m_Database_entry_history.clear();
    m_set_State[0] &= ~0x300;
}

void CBiostruc_source_Base::Reset(void)
{
    ResetName_of_database();
    ResetVersion_of_database();
    ResetDatabase_entry_id();
    ResetDatabase_entry_date();
    ResetDatabase_entry_history();
}

BEGIN_NAMED_BASE_CLASS_INFO("Biostruc-source", CBiostruc_source)
{
    SET_CLASS_MODULE("MMDB");
    ADD_NAMED_STD_MEMBER("name-of-database", m_Name_of_database)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("version-of-database", m_Version_of_database, C_Version_of_database)->SetOptional();
    ADD_NAMED_REF_MEMBER("database-entry-id", m_Database_entry_id, CBiostruc_id);
    ADD_NAMED_REF_MEMBER("database-entry-date", m_Database_entry_date, CDate);
    ADD_NAMED_MEMBER("database-entry-history", m_Database_entry_history, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBiostruc_source_Base::CBiostruc_source_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetDatabase_entry_id();
        ResetDatabase_entry_date();
    }
}

// destructor
CBiostruc_source_Base::~CBiostruc_source_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

