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
#include <objects/mmdb1/Biostruc_graph.hpp>
#include <objects/mmdb1/Biomol_descr.hpp>
#include <objects/mmdb1/Inter_residue_bond.hpp>
#include <objects/mmdb1/Molecule_graph.hpp>
#include <objects/mmdb1/Residue_graph.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CBiostruc_graph_Base::ResetDescr(void)
{
    m_Descr.clear();
    m_set_State[0] &= ~0x3;
}

void CBiostruc_graph_Base::ResetMolecule_graphs(void)
{
    m_Molecule_graphs.clear();
    m_set_State[0] &= ~0xc;
}

void CBiostruc_graph_Base::ResetInter_molecule_bonds(void)
{
    m_Inter_molecule_bonds.clear();
    m_set_State[0] &= ~0x30;
}

void CBiostruc_graph_Base::ResetResidue_graphs(void)
{
    m_Residue_graphs.clear();
    m_set_State[0] &= ~0xc0;
}

void CBiostruc_graph_Base::Reset(void)
{
    ResetDescr();
    ResetMolecule_graphs();
    ResetInter_molecule_bonds();
    ResetResidue_graphs();
}

BEGIN_NAMED_BASE_CLASS_INFO("Biostruc-graph", CBiostruc_graph)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_MEMBER("descr", m_Descr, STL_list, (STL_CRef, (CLASS, (CBiomol_descr))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("molecule-graphs", m_Molecule_graphs, STL_list, (STL_CRef, (CLASS, (CMolecule_graph))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("inter-molecule-bonds", m_Inter_molecule_bonds, STL_list, (STL_CRef, (CLASS, (CInter_residue_bond))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("residue-graphs", m_Residue_graphs, STL_list, (STL_CRef, (CLASS, (CResidue_graph))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CBiostruc_graph_Base::CBiostruc_graph_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CBiostruc_graph_Base::~CBiostruc_graph_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

