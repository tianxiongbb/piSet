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
 *   'mmdb3.asn'.
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
#include <objects/mmdb3/Chem_graph_pntrs.hpp>
#include <objects/mmdb3/Atom_pntrs.hpp>
#include <objects/mmdb3/Molecule_pntrs.hpp>
#include <objects/mmdb3/Residue_pntrs.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CChem_graph_pntrs_Base::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CChem_graph_pntrs_Base::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Atoms:
    case e_Residues:
    case e_Molecules:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CChem_graph_pntrs_Base::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Atoms:
        (m_object = new(pool) ncbi::objects::CAtom_pntrs())->AddReference();
        break;
    case e_Residues:
        (m_object = new(pool) ncbi::objects::CResidue_pntrs())->AddReference();
        break;
    case e_Molecules:
        (m_object = new(pool) ncbi::objects::CMolecule_pntrs())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CChem_graph_pntrs_Base::sm_SelectionNames[] = {
    "not set",
    "atoms",
    "residues",
    "molecules"
};

NCBI_NS_STD::string CChem_graph_pntrs_Base::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CChem_graph_pntrs_Base::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CChem_graph_pntrs_Base::TAtoms& CChem_graph_pntrs_Base::GetAtoms(void) const
{
    CheckSelected(e_Atoms);
    return *static_cast<const TAtoms*>(m_object);
}

CChem_graph_pntrs_Base::TAtoms& CChem_graph_pntrs_Base::SetAtoms(void)
{
    Select(e_Atoms, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TAtoms*>(m_object);
}

void CChem_graph_pntrs_Base::SetAtoms(CChem_graph_pntrs_Base::TAtoms& value)
{
    TAtoms* ptr = &value;
    if ( m_choice != e_Atoms || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Atoms;
    }
}

const CChem_graph_pntrs_Base::TResidues& CChem_graph_pntrs_Base::GetResidues(void) const
{
    CheckSelected(e_Residues);
    return *static_cast<const TResidues*>(m_object);
}

CChem_graph_pntrs_Base::TResidues& CChem_graph_pntrs_Base::SetResidues(void)
{
    Select(e_Residues, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TResidues*>(m_object);
}

void CChem_graph_pntrs_Base::SetResidues(CChem_graph_pntrs_Base::TResidues& value)
{
    TResidues* ptr = &value;
    if ( m_choice != e_Residues || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Residues;
    }
}

const CChem_graph_pntrs_Base::TMolecules& CChem_graph_pntrs_Base::GetMolecules(void) const
{
    CheckSelected(e_Molecules);
    return *static_cast<const TMolecules*>(m_object);
}

CChem_graph_pntrs_Base::TMolecules& CChem_graph_pntrs_Base::SetMolecules(void)
{
    Select(e_Molecules, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TMolecules*>(m_object);
}

void CChem_graph_pntrs_Base::SetMolecules(CChem_graph_pntrs_Base::TMolecules& value)
{
    TMolecules* ptr = &value;
    if ( m_choice != e_Molecules || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Molecules;
    }
}

// helper methods

// type info
BEGIN_NAMED_BASE_CHOICE_INFO("Chem-graph-pntrs", CChem_graph_pntrs)
{
    SET_CHOICE_MODULE("MMDB-Features");
    ADD_NAMED_REF_CHOICE_VARIANT("atoms", m_object, CAtom_pntrs);
    ADD_NAMED_REF_CHOICE_VARIANT("residues", m_object, CResidue_pntrs);
    ADD_NAMED_REF_CHOICE_VARIANT("molecules", m_object, CMolecule_pntrs);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CChem_graph_pntrs_Base::CChem_graph_pntrs_Base(void)
    : m_choice(e_not_set)
{
}

// destructor
CChem_graph_pntrs_Base::~CChem_graph_pntrs_Base(void)
{
    Reset();
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

