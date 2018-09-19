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
 *   'seqblock.asn'.
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
#include <objects/seqblock/PDB_replace.hpp>
#include <objects/general/Date.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CPDB_replace_Base::ResetDate(void)
{
    if ( !m_Date ) {
        m_Date.Reset(new TDate());
        return;
    }
    (*m_Date).Reset();
}

void CPDB_replace_Base::SetDate(CPDB_replace_Base::TDate& value)
{
    m_Date.Reset(&value);
}

void CPDB_replace_Base::ResetIds(void)
{
    m_Ids.clear();
    m_set_State[0] &= ~0xc;
}

void CPDB_replace_Base::Reset(void)
{
    ResetDate();
    ResetIds();
}

BEGIN_NAMED_BASE_CLASS_INFO("PDB-replace", CPDB_replace)
{
    SET_CLASS_MODULE("PDB-General");
    ADD_NAMED_REF_MEMBER("date", m_Date, CDate);
    ADD_NAMED_MEMBER("ids", m_Ids, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CPDB_replace_Base::CPDB_replace_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetDate();
    }
}

// destructor
CPDB_replace_Base::~CPDB_replace_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

