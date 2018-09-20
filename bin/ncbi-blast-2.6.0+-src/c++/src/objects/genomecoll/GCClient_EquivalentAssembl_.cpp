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
 *   'gencoll_client.asn'.
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
#include <objects/genomecoll/GCClient_EquivalentAssembl.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CGCClient_EquivalentAssemblies_Base::C_E_Assemblies::ResetAccession(void)
{
    m_Accession.erase();
    m_set_State[0] &= ~0x3;
}

void CGCClient_EquivalentAssemblies_Base::C_E_Assemblies::Reset(void)
{
    ResetAccession();
}

BEGIN_NAMED_CLASS_INFO("", CGCClient_EquivalentAssemblies_Base::C_E_Assemblies)
{
    SET_INTERNAL_NAME("GCClient-EquivalentAssemblies.assemblies", "E");
    SET_CLASS_MODULE("NCBI-GencollClient");
    ADD_NAMED_STD_MEMBER("accession", m_Accession)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGCClient_EquivalentAssemblies_Base::C_E_Assemblies::C_E_Assemblies(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGCClient_EquivalentAssemblies_Base::C_E_Assemblies::~C_E_Assemblies(void)
{
}


void CGCClient_EquivalentAssemblies_Base::ResetAssemblies(void)
{
    m_Assemblies.clear();
    m_set_State[0] &= ~0x3;
}

void CGCClient_EquivalentAssemblies_Base::Reset(void)
{
    ResetAssemblies();
}

BEGIN_NAMED_BASE_CLASS_INFO("GCClient-EquivalentAssemblies", CGCClient_EquivalentAssemblies)
{
    SET_CLASS_MODULE("NCBI-GencollClient");
    ADD_NAMED_MEMBER("assemblies", m_Assemblies, STL_list_set, (STL_CRef, (CLASS, (C_E_Assemblies))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGCClient_EquivalentAssemblies_Base::CGCClient_EquivalentAssemblies_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGCClient_EquivalentAssemblies_Base::~CGCClient_EquivalentAssemblies_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
