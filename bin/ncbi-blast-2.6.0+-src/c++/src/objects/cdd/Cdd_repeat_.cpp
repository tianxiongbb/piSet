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
 *   'cdd.asn'.
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
#include <objects/cdd/Cdd_repeat.hpp>
#include <objects/seqloc/Seq_loc.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCdd_repeat_Base::ResetLocation(void)
{
    m_Location.Reset();
}

void CCdd_repeat_Base::SetLocation(CCdd_repeat_Base::TLocation& value)
{
    m_Location.Reset(&value);
}

CCdd_repeat_Base::TLocation& CCdd_repeat_Base::SetLocation(void)
{
    if ( !m_Location )
        m_Location.Reset(new ncbi::objects::CSeq_loc());
    return (*m_Location);
}

void CCdd_repeat_Base::Reset(void)
{
    ResetCount();
    ResetLocation();
    ResetAvglen();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cdd-repeat", CCdd_repeat)
{
    SET_CLASS_MODULE("NCBI-Cdd");
    ADD_NAMED_STD_MEMBER("count", m_Count)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("location", m_Location, CSeq_loc)->SetOptional();
    ADD_NAMED_STD_MEMBER("avglen", m_Avglen)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCdd_repeat_Base::CCdd_repeat_Base(void)
    : m_Count(0), m_Avglen(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CCdd_repeat_Base::~CCdd_repeat_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

