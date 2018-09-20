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
 *   'gbproj.asn'.
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
#include <objects/gbproj/FolderInfo.hpp>
#include <objects/general/Date.hpp>
#include <objects/seq/Annotdesc.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CFolderInfo_Base::ResetTitle(void)
{
    m_Title.erase();
    m_set_State[0] &= ~0x3;
}

void CFolderInfo_Base::ResetCreate_date(void)
{
    if ( !m_Create_date ) {
        m_Create_date.Reset(new TCreate_date());
        return;
    }
    (*m_Create_date).Reset();
}

void CFolderInfo_Base::SetCreate_date(CFolderInfo_Base::TCreate_date& value)
{
    m_Create_date.Reset(&value);
}

void CFolderInfo_Base::ResetComment(void)
{
    m_Comment.erase();
    m_set_State[0] &= ~0x30;
}

void CFolderInfo_Base::ResetAnnot(void)
{
    m_Annot.clear();
    m_set_State[0] &= ~0x300;
}

void CFolderInfo_Base::Reset(void)
{
    ResetTitle();
    ResetCreate_date();
    ResetComment();
    ResetOpen();
    ResetAnnot();
}

BEGIN_NAMED_BASE_CLASS_INFO("FolderInfo", CFolderInfo)
{
    SET_CLASS_MODULE("NCBI-GBProject");
    ADD_NAMED_STD_MEMBER("title", m_Title)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("create-date", m_Create_date, CDate);
    ADD_NAMED_STD_MEMBER("comment", m_Comment)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("open", m_Open)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("annot", m_Annot, STL_list_set, (STL_CRef, (CLASS, (CAnnotdesc))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CFolderInfo_Base::CFolderInfo_Base(void)
    : m_Open(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetCreate_date();
    }
}

// destructor
CFolderInfo_Base::~CFolderInfo_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
