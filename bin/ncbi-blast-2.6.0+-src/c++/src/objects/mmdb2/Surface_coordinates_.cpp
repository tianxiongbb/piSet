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
 *   'mmdb2.asn'.
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
#include <objects/mmdb2/Surface_coordinates.hpp>
#include <objects/mmdb2/T_mesh.hpp>
#include <objects/mmdb2/Triangles.hpp>
#include <objects/mmdb3/Brick.hpp>
#include <objects/mmdb3/Chem_graph_pntrs.hpp>
#include <objects/mmdb3/Cone.hpp>
#include <objects/mmdb3/Cylinder.hpp>
#include <objects/mmdb3/Sphere.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSurface_coordinates_Base::C_Surface::Reset(void)
{
    if ( m_choice != e_not_set )
        ResetSelection();
}

void CSurface_coordinates_Base::C_Surface::ResetSelection(void)
{
    switch ( m_choice ) {
    case e_Sphere:
    case e_Cone:
    case e_Cylinder:
    case e_Brick:
    case e_Tmesh:
    case e_Triangles:
        m_object->RemoveReference();
        break;
    default:
        break;
    }
    m_choice = e_not_set;
}

void CSurface_coordinates_Base::C_Surface::DoSelect(E_Choice index, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    switch ( index ) {
    case e_Sphere:
        (m_object = new(pool) ncbi::objects::CSphere())->AddReference();
        break;
    case e_Cone:
        (m_object = new(pool) ncbi::objects::CCone())->AddReference();
        break;
    case e_Cylinder:
        (m_object = new(pool) ncbi::objects::CCylinder())->AddReference();
        break;
    case e_Brick:
        (m_object = new(pool) ncbi::objects::CBrick())->AddReference();
        break;
    case e_Tmesh:
        (m_object = new(pool) ncbi::objects::CT_mesh())->AddReference();
        break;
    case e_Triangles:
        (m_object = new(pool) ncbi::objects::CTriangles())->AddReference();
        break;
    default:
        break;
    }
    m_choice = index;
}

const char* const CSurface_coordinates_Base::C_Surface::sm_SelectionNames[] = {
    "not set",
    "sphere",
    "cone",
    "cylinder",
    "brick",
    "tmesh",
    "triangles"
};

NCBI_NS_STD::string CSurface_coordinates_Base::C_Surface::SelectionName(E_Choice index)
{
    return NCBI_NS_NCBI::CInvalidChoiceSelection::GetName(index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

void CSurface_coordinates_Base::C_Surface::ThrowInvalidSelection(E_Choice index) const
{
    throw NCBI_NS_NCBI::CInvalidChoiceSelection(DIAG_COMPILE_INFO, this, m_choice, index, sm_SelectionNames, sizeof(sm_SelectionNames)/sizeof(sm_SelectionNames[0]));
}

const CSurface_coordinates_Base::C_Surface::TSphere& CSurface_coordinates_Base::C_Surface::GetSphere(void) const
{
    CheckSelected(e_Sphere);
    return *static_cast<const TSphere*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TSphere& CSurface_coordinates_Base::C_Surface::SetSphere(void)
{
    Select(e_Sphere, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TSphere*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetSphere(CSurface_coordinates_Base::C_Surface::TSphere& value)
{
    TSphere* ptr = &value;
    if ( m_choice != e_Sphere || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Sphere;
    }
}

const CSurface_coordinates_Base::C_Surface::TCone& CSurface_coordinates_Base::C_Surface::GetCone(void) const
{
    CheckSelected(e_Cone);
    return *static_cast<const TCone*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TCone& CSurface_coordinates_Base::C_Surface::SetCone(void)
{
    Select(e_Cone, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCone*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetCone(CSurface_coordinates_Base::C_Surface::TCone& value)
{
    TCone* ptr = &value;
    if ( m_choice != e_Cone || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Cone;
    }
}

const CSurface_coordinates_Base::C_Surface::TCylinder& CSurface_coordinates_Base::C_Surface::GetCylinder(void) const
{
    CheckSelected(e_Cylinder);
    return *static_cast<const TCylinder*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TCylinder& CSurface_coordinates_Base::C_Surface::SetCylinder(void)
{
    Select(e_Cylinder, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TCylinder*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetCylinder(CSurface_coordinates_Base::C_Surface::TCylinder& value)
{
    TCylinder* ptr = &value;
    if ( m_choice != e_Cylinder || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Cylinder;
    }
}

const CSurface_coordinates_Base::C_Surface::TBrick& CSurface_coordinates_Base::C_Surface::GetBrick(void) const
{
    CheckSelected(e_Brick);
    return *static_cast<const TBrick*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TBrick& CSurface_coordinates_Base::C_Surface::SetBrick(void)
{
    Select(e_Brick, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TBrick*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetBrick(CSurface_coordinates_Base::C_Surface::TBrick& value)
{
    TBrick* ptr = &value;
    if ( m_choice != e_Brick || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Brick;
    }
}

const CSurface_coordinates_Base::C_Surface::TTmesh& CSurface_coordinates_Base::C_Surface::GetTmesh(void) const
{
    CheckSelected(e_Tmesh);
    return *static_cast<const TTmesh*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TTmesh& CSurface_coordinates_Base::C_Surface::SetTmesh(void)
{
    Select(e_Tmesh, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTmesh*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetTmesh(CSurface_coordinates_Base::C_Surface::TTmesh& value)
{
    TTmesh* ptr = &value;
    if ( m_choice != e_Tmesh || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Tmesh;
    }
}

const CSurface_coordinates_Base::C_Surface::TTriangles& CSurface_coordinates_Base::C_Surface::GetTriangles(void) const
{
    CheckSelected(e_Triangles);
    return *static_cast<const TTriangles*>(m_object);
}

CSurface_coordinates_Base::C_Surface::TTriangles& CSurface_coordinates_Base::C_Surface::SetTriangles(void)
{
    Select(e_Triangles, NCBI_NS_NCBI::eDoNotResetVariant);
    return *static_cast<TTriangles*>(m_object);
}

void CSurface_coordinates_Base::C_Surface::SetTriangles(CSurface_coordinates_Base::C_Surface::TTriangles& value)
{
    TTriangles* ptr = &value;
    if ( m_choice != e_Triangles || m_object != ptr ) {
        ResetSelection();
        (m_object = ptr)->AddReference();
        m_choice = e_Triangles;
    }
}

// helper methods

// type info
BEGIN_NAMED_CHOICE_INFO("", CSurface_coordinates_Base::C_Surface)
{
    SET_INTERNAL_NAME("Surface-coordinates", "surface");
    SET_CHOICE_MODULE("MMDB-Structural-model");
    ADD_NAMED_REF_CHOICE_VARIANT("sphere", m_object, CSphere);
    ADD_NAMED_REF_CHOICE_VARIANT("cone", m_object, CCone);
    ADD_NAMED_REF_CHOICE_VARIANT("cylinder", m_object, CCylinder);
    ADD_NAMED_REF_CHOICE_VARIANT("brick", m_object, CBrick);
    ADD_NAMED_REF_CHOICE_VARIANT("tmesh", m_object, CT_mesh);
    ADD_NAMED_REF_CHOICE_VARIANT("triangles", m_object, CTriangles);
    info->CodeVersion(21600);
}
END_CHOICE_INFO

// constructor
CSurface_coordinates_Base::C_Surface::C_Surface(void)
    : m_choice(e_not_set)
{
}

// destructor
CSurface_coordinates_Base::C_Surface::~C_Surface(void)
{
    Reset();
}


void CSurface_coordinates_Base::ResetContents(void)
{
    if ( !m_Contents ) {
        m_Contents.Reset(new TContents());
        return;
    }
    (*m_Contents).Reset();
}

void CSurface_coordinates_Base::SetContents(CSurface_coordinates_Base::TContents& value)
{
    m_Contents.Reset(&value);
}

void CSurface_coordinates_Base::ResetSurface(void)
{
    if ( !m_Surface ) {
        m_Surface.Reset(new TSurface());
        return;
    }
    (*m_Surface).Reset();
}

void CSurface_coordinates_Base::SetSurface(CSurface_coordinates_Base::TSurface& value)
{
    m_Surface.Reset(&value);
}

void CSurface_coordinates_Base::Reset(void)
{
    ResetContents();
    ResetSurface();
}

BEGIN_NAMED_BASE_CLASS_INFO("Surface-coordinates", CSurface_coordinates)
{
    SET_CLASS_MODULE("MMDB-Structural-model");
    ADD_NAMED_REF_MEMBER("contents", m_Contents, CChem_graph_pntrs);
    ADD_NAMED_REF_MEMBER("surface", m_Surface, C_Surface);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSurface_coordinates_Base::CSurface_coordinates_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetContents();
        ResetSurface();
    }
}

// destructor
CSurface_coordinates_Base::~CSurface_coordinates_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
