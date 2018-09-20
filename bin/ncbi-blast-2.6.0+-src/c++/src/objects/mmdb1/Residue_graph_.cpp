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
#include <objects/mmdb1/Residue_graph.hpp>
#include <objects/mmdb1/Atom.hpp>
#include <objects/mmdb1/Biomol_descr.hpp>
#include <objects/mmdb1/Chiral_center.hpp>
#include <objects/mmdb1/Intra_residue_bond.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CResidue_graph_Base::, EResidue_type, true)
{
    SET_ENUM_INTERNAL_NAME("Residue-graph", "residue-type");
    SET_ENUM_MODULE("MMDB-Chemical-graph");
    ADD_ENUM_VALUE("deoxyribonucleotide", eResidue_type_deoxyribonucleotide);
    ADD_ENUM_VALUE("ribonucleotide", eResidue_type_ribonucleotide);
    ADD_ENUM_VALUE("amino-acid", eResidue_type_amino_acid);
    ADD_ENUM_VALUE("other", eResidue_type_other);
}
END_ENUM_INFO

void CResidue_graph_Base::ResetDescr(void)
{
    m_Descr.clear();
    m_set_State[0] &= ~0xc;
}

void CResidue_graph_Base::ResetIupac_code(void)
{
    m_Iupac_code.clear();
    m_set_State[0] &= ~0xc0;
}

void CResidue_graph_Base::ResetAtoms(void)
{
    m_Atoms.clear();
    m_set_State[0] &= ~0x300;
}

void CResidue_graph_Base::ResetBonds(void)
{
    m_Bonds.clear();
    m_set_State[0] &= ~0xc00;
}

void CResidue_graph_Base::ResetChiral_centers(void)
{
    m_Chiral_centers.clear();
    m_set_State[0] &= ~0x3000;
}

void CResidue_graph_Base::Reset(void)
{
    ResetId();
    ResetDescr();
    ResetResidue_type();
    ResetIupac_code();
    ResetAtoms();
    ResetBonds();
    ResetChiral_centers();
}

BEGIN_NAMED_BASE_CLASS_INFO("Residue-graph", CResidue_graph)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_MEMBER("id", m_Id, CLASS, (CResidue_graph_id))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("descr", m_Descr, STL_list, (STL_CRef, (CLASS, (CBiomol_descr))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("residue-type", m_Residue_type, EResidue_type)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("iupac-code", m_Iupac_code, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("atoms", m_Atoms, STL_list, (STL_CRef, (CLASS, (CAtom))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("bonds", m_Bonds, STL_list, (STL_CRef, (CLASS, (CIntra_residue_bond))))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_MEMBER("chiral-centers", m_Chiral_centers, STL_list, (STL_CRef, (CLASS, (CChiral_center))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CResidue_graph_Base::CResidue_graph_Base(void)
    : m_Id(CResidue_graph_id(0)), m_Residue_type((EResidue_type)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CResidue_graph_Base::~CResidue_graph_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
