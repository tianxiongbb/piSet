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
 *   'mim.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/mim/NCBI_Mim_module.hpp>
#include <objects/mim/Mim_allelic_variant.hpp>
#include <objects/mim/Mim_author.hpp>
#include <objects/mim/Mim_cit.hpp>
#include <objects/mim/Mim_date.hpp>
#include <objects/mim/Mim_edit_item.hpp>
#include <objects/mim/Mim_entries.hpp>
#include <objects/mim/Mim_entry.hpp>
#include <objects/mim/Mim_index_term.hpp>
#include <objects/mim/Mim_link.hpp>
#include <objects/mim/Mim_page.hpp>
#include <objects/mim/Mim_reference.hpp>
#include <objects/mim/Mim_set.hpp>
#include <objects/mim/Mim_text.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_Mim_RegisterModuleClasses(void)
{
    ncbi::objects::CMim_allelic_variant::GetTypeInfo();
    ncbi::objects::CMim_author::GetTypeInfo();
    ncbi::objects::CMim_cit::GetTypeInfo();
    ncbi::objects::CMim_date::GetTypeInfo();
    ncbi::objects::CMim_edit_item::GetTypeInfo();
    ncbi::objects::CMim_entries::GetTypeInfo();
    ncbi::objects::CMim_entry::GetTypeInfo();
    ncbi::objects::CMim_index_term::GetTypeInfo();
    ncbi::objects::CMim_link::GetTypeInfo();
    ncbi::objects::CMim_page::GetTypeInfo();
    ncbi::objects::CMim_reference::GetTypeInfo();
    ncbi::objects::CMim_set::GetTypeInfo();
    ncbi::objects::CMim_text::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
