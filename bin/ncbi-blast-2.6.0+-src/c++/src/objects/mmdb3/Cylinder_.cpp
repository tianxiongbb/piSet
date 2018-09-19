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
#include <objects/mmdb3/Cylinder.hpp>
#include <objects/mmdb3/Model_space_point.hpp>
#include <objects/mmdb3/RealValue.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CCylinder_Base::ResetAxis_top(void)
{
    if ( !m_Axis_top ) {
        m_Axis_top.Reset(new TAxis_top());
        return;
    }
    (*m_Axis_top).Reset();
}

void CCylinder_Base::SetAxis_top(CCylinder_Base::TAxis_top& value)
{
    m_Axis_top.Reset(&value);
}

void CCylinder_Base::ResetAxis_bottom(void)
{
    if ( !m_Axis_bottom ) {
        m_Axis_bottom.Reset(new TAxis_bottom());
        return;
    }
    (*m_Axis_bottom).Reset();
}

void CCylinder_Base::SetAxis_bottom(CCylinder_Base::TAxis_bottom& value)
{
    m_Axis_bottom.Reset(&value);
}

void CCylinder_Base::ResetRadius(void)
{
    if ( !m_Radius ) {
        m_Radius.Reset(new TRadius());
        return;
    }
    (*m_Radius).Reset();
}

void CCylinder_Base::SetRadius(CCylinder_Base::TRadius& value)
{
    m_Radius.Reset(&value);
}

void CCylinder_Base::Reset(void)
{
    ResetAxis_top();
    ResetAxis_bottom();
    ResetRadius();
}

BEGIN_NAMED_BASE_CLASS_INFO("Cylinder", CCylinder)
{
    SET_CLASS_MODULE("MMDB-Features");
    ADD_NAMED_REF_MEMBER("axis-top", m_Axis_top, CModel_space_point);
    ADD_NAMED_REF_MEMBER("axis-bottom", m_Axis_bottom, CModel_space_point);
    ADD_NAMED_REF_MEMBER("radius", m_Radius, CRealValue);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CCylinder_Base::CCylinder_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAxis_top();
        ResetAxis_bottom();
        ResetRadius();
    }
}

// destructor
CCylinder_Base::~CCylinder_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

