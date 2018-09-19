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
 *   'pcassay.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/pcassay/NCBI_PCAssay_module.hpp>
#include <objects/pcassay/PC_AnnotatedXRef.hpp>
#include <objects/pcassay/PC_AssayContainer.hpp>
#include <objects/pcassay/PC_AssayDRAttr.hpp>
#include <objects/pcassay/PC_AssayData.hpp>
#include <objects/pcassay/PC_AssayDescription.hpp>
#include <objects/pcassay/PC_AssayPanel.hpp>
#include <objects/pcassay/PC_AssayPanelMember.hpp>
#include <objects/pcassay/PC_AssayPanelTestResult.hpp>
#include <objects/pcassay/PC_AssayResults.hpp>
#include <objects/pcassay/PC_AssaySubmit.hpp>
#include <objects/pcassay/PC_AssayTargetInfo.hpp>
#include <objects/pcassay/PC_CategorizedComment.hpp>
#include <objects/pcassay/PC_ConcentrationAttr.hpp>
#include <objects/pcassay/PC_IntegerMinMax.hpp>
#include <objects/pcassay/PC_RealMinMax.hpp>
#include <objects/pcassay/PC_ResultType.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_PCAssay_RegisterModuleClasses(void)
{
    ncbi::objects::CPC_AnnotatedXRef::GetTypeInfo();
    ncbi::objects::CPC_AssayContainer::GetTypeInfo();
    ncbi::objects::CPC_AssayDRAttr::GetTypeInfo();
    ncbi::objects::CPC_AssayData::GetTypeInfo();
    ncbi::objects::CPC_AssayDescription::GetTypeInfo();
    ncbi::objects::CPC_AssayPanel::GetTypeInfo();
    ncbi::objects::CPC_AssayPanelMember::GetTypeInfo();
    ncbi::objects::CPC_AssayPanelTestResult::GetTypeInfo();
    ncbi::objects::CPC_AssayResults::GetTypeInfo();
    ncbi::objects::CPC_AssaySubmit::GetTypeInfo();
    ncbi::objects::CPC_AssayTargetInfo::GetTypeInfo();
    ncbi::objects::CPC_CategorizedComment::GetTypeInfo();
    ncbi::objects::CPC_ConcentrationAttr::GetTypeInfo();
    ncbi::objects::CPC_IntegerMinMax::GetTypeInfo();
    ncbi::objects::CPC_RealMinMax::GetTypeInfo();
    ncbi::objects::CPC_ResultType::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

