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
#include <objects/mmdb1/Biostruc_replace.hpp>
#include <objects/general/Date.hpp>
#include <objects/mmdb1/Biostruc_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_replace_Base::ResetId(void)
{
    if ( !m_Id ) {
        m_Id.Reset(new TId());
        return;
    }
    (*m_Id).Reset();
}

void CBiostruc_replace_Base::SetId(CBiostruc_replace_Base::TId& value)
{
    m_Id.Reset(&value);
}

void CBiostruc_replace_Base::ResetDate(void)
{
    if ( !m_Date ) {
        m_Date.Reset(new TDate());
        return;
    }
    (*m_Date).Reset();
}

void CBiostruc_replace_Base::SetDate(CBiostruc_replace_Base::TDate& value)
{
    m_Date.Reset(&value);
}

void CBiostruc_replace_Base::Reset(void)
{
    ResetId();
    ResetDate();
}

BEGIN_NAMED_BASE_CLASS_INFO("Biostruc-replace", CBiostruc_replace)
{
    SET_CLASS_MODULE("MMDB");
    ADD_NAMED_REF_MEMBER("id", m_Id, CBiostruc_id);
    ADD_NAMED_REF_MEMBER("date", m_Date, CDate);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBiostruc_replace_Base::CBiostruc_replace_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetId();
        ResetDate();
    }
}

// destructor
CBiostruc_replace_Base::~CBiostruc_replace_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

