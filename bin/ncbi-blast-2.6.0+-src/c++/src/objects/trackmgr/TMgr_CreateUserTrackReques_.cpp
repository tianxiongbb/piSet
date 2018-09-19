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
 *   'trackmgr.asn'.
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
#include <objects/trackmgr/TMgr_CreateUserTrackReques.hpp>
#include <objects/trackmgr/TMgr_Attribute.hpp>
#include <objects/trackmgr/TMgr_CreateUserDataItem.hpp>
#include <objects/trackmgr/TMgr_Identity.hpp>
#include <objects/trackmgr/TMgr_TrackACL_Permission.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CTMgr_CreateUserTrackRequest_Base::ResetIdentity(void)
{
    if ( !m_Identity ) {
        m_Identity.Reset(new TIdentity());
        return;
    }
    (*m_Identity).Reset();
}

void CTMgr_CreateUserTrackRequest_Base::SetIdentity(CTMgr_CreateUserTrackRequest_Base::TIdentity& value)
{
    m_Identity.Reset(&value);
}

void CTMgr_CreateUserTrackRequest_Base::ResetTrack_name(void)
{
    m_Track_name.erase();
    m_set_State[0] &= ~0xc;
}

void CTMgr_CreateUserTrackRequest_Base::ResetTrack_descr(void)
{
    m_Track_descr.erase();
    m_set_State[0] &= ~0x30;
}

void CTMgr_CreateUserTrackRequest_Base::ResetAssembly_acc(void)
{
    m_Assembly_acc.erase();
    m_set_State[0] &= ~0xc0;
}

void CTMgr_CreateUserTrackRequest_Base::ResetAttrs(void)
{
    m_Attrs.clear();
    m_set_State[0] &= ~0x300;
}

void CTMgr_CreateUserTrackRequest_Base::ResetData_items(void)
{
    m_Data_items.clear();
    m_set_State[0] &= ~0xc00;
}

void CTMgr_CreateUserTrackRequest_Base::ResetAccess_perms(void)
{
    if ( !m_Access_perms ) {
        m_Access_perms.Reset(new TAccess_perms());
        return;
    }
    (*m_Access_perms).Reset();
}

void CTMgr_CreateUserTrackRequest_Base::SetAccess_perms(CTMgr_CreateUserTrackRequest_Base::TAccess_perms& value)
{
    m_Access_perms.Reset(&value);
}

void CTMgr_CreateUserTrackRequest_Base::Reset(void)
{
    ResetIdentity();
    ResetTrack_name();
    ResetTrack_descr();
    ResetAssembly_acc();
    ResetAttrs();
    ResetData_items();
    ResetAccess_perms();
}

BEGIN_NAMED_BASE_CLASS_INFO("TMgr-CreateUserTrackRequest", CTMgr_CreateUserTrackRequest)
{
    SET_CLASS_MODULE("NCBI-TrackManager");
    ADD_NAMED_REF_MEMBER("identity", m_Identity, CTMgr_Identity);
    ADD_NAMED_STD_MEMBER("track-name", m_Track_name)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("track-descr", m_Track_descr)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("assembly-acc", m_Assembly_acc)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("attrs", m_Attrs, STL_list_set, (STL_CRef, (CLASS, (CTMgr_Attribute))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("data-items", m_Data_items, STL_list_set, (STL_CRef, (CLASS, (CTMgr_CreateUserDataItem))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("access-perms", m_Access_perms, CTMgr_TrackACL_Permission);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CTMgr_CreateUserTrackRequest_Base::CTMgr_CreateUserTrackRequest_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetIdentity();
        ResetAccess_perms();
    }
}

// destructor
CTMgr_CreateUserTrackRequest_Base::~CTMgr_CreateUserTrackRequest_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

