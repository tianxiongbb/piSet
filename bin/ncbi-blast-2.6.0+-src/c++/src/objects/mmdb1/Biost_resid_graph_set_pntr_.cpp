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
#include <objects/mmdb1/Biost_resid_graph_set_pntr.hpp>
#include <objects/mmdb1/Biostruc_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_residue_graph_set_pntr_Base::ResetBiostruc_residue_graph_set_id(void)
{
    if ( !m_Biostruc_residue_graph_set_id ) {
        m_Biostruc_residue_graph_set_id.Reset(new TBiostruc_residue_graph_set_id());
        return;
    }
    (*m_Biostruc_residue_graph_set_id).Reset();
}

void CBiostruc_residue_graph_set_pntr_Base::SetBiostruc_residue_graph_set_id(CBiostruc_residue_graph_set_pntr_Base::TBiostruc_residue_graph_set_id& value)
{
    m_Biostruc_residue_graph_set_id.Reset(&value);
}

void CBiostruc_residue_graph_set_pntr_Base::Reset(void)
{
    ResetBiostruc_residue_graph_set_id();
    ResetResidue_graph_id();
}

BEGIN_NAMED_BASE_CLASS_INFO("Biostruc-residue-graph-set-pntr", CBiostruc_residue_graph_set_pntr)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_REF_MEMBER("biostruc-residue-graph-set-id", m_Biostruc_residue_graph_set_id, CBiostruc_id);
    ADD_NAMED_MEMBER("residue-graph-id", m_Residue_graph_id, CLASS, (CResidue_graph_id))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBiostruc_residue_graph_set_pntr_Base::CBiostruc_residue_graph_set_pntr_Base(void)
    : m_Residue_graph_id(CResidue_graph_id(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetBiostruc_residue_graph_set_id();
    }
}

// destructor
CBiostruc_residue_graph_set_pntr_Base::~CBiostruc_residue_graph_set_pntr_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

