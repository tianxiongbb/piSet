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
 *   'varrep.asn'.
 *
 * ATTENTION:
 *   Don't edit or commit this file into CVS as this file will
 *   be overridden (by DATATOOL) without warning!
 * ===========================================================================
 */

#include <ncbi_pch.hpp>
#include <objects/varrep/NCBI_VariationIRep_module.hpp>
#include <objects/varrep/AaInterval.hpp>
#include <objects/varrep/AaLocation.hpp>
#include <objects/varrep/AaSite.hpp>
#include <objects/varrep/AaSiteRange.hpp>
#include <objects/varrep/Conversion.hpp>
#include <objects/varrep/Count.hpp>
#include <objects/varrep/CtermExtension.hpp>
#include <objects/varrep/Deletion.hpp>
#include <objects/varrep/Delins.hpp>
#include <objects/varrep/Duplication.hpp>
#include <objects/varrep/Frameshift.hpp>
#include <objects/varrep/Insertion.hpp>
#include <objects/varrep/Inversion.hpp>
#include <objects/varrep/NaIdentity.hpp>
#include <objects/varrep/NaSub.hpp>
#include <objects/varrep/NtIntLimit.hpp>
#include <objects/varrep/NtInterval.hpp>
#include <objects/varrep/NtLocation.hpp>
#include <objects/varrep/NtSite.hpp>
#include <objects/varrep/NtSiteRange.hpp>
#include <objects/varrep/NtermExtension.hpp>
#include <objects/varrep/ProteinExtension.hpp>
#include <objects/varrep/ProteinSub.hpp>
#include <objects/varrep/Repeat.hpp>
#include <objects/varrep/SeqInterval.hpp>
#include <objects/varrep/SeqLocation.hpp>
#include <objects/varrep/SequenceVariant.hpp>
#include <objects/varrep/SimpleVariant.hpp>
#include <objects/varrep/SimpleVariantSeq.hpp>
#include <objects/varrep/Subsequence.hpp>
#include <objects/varrep/Variant.hpp>
#include <objects/varrep/VariantExpression.hpp>


BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

void NCBI_VariationIRep_RegisterModuleClasses(void)
{
    ncbi::objects::CAaInterval::GetTypeInfo();
    ncbi::objects::CAaLocation::GetTypeInfo();
    ncbi::objects::CAaSite::GetTypeInfo();
    ncbi::objects::CAaSiteRange::GetTypeInfo();
    ncbi::objects::CConversion::GetTypeInfo();
    ncbi::objects::CCount::GetTypeInfo();
    ncbi::objects::CCtermExtension::GetTypeInfo();
    ncbi::objects::CDeletion::GetTypeInfo();
    ncbi::objects::CDelins::GetTypeInfo();
    ncbi::objects::CDuplication::GetTypeInfo();
    ncbi::objects::CFrameshift::GetTypeInfo();
    ncbi::objects::CInsertion::GetTypeInfo();
    ncbi::objects::CInversion::GetTypeInfo();
    ncbi::objects::CNaIdentity::GetTypeInfo();
    ncbi::objects::CNaSub::GetTypeInfo();
    ncbi::objects::CNtIntLimit::GetTypeInfo();
    ncbi::objects::CNtInterval::GetTypeInfo();
    ncbi::objects::CNtLocation::GetTypeInfo();
    ncbi::objects::CNtSite::GetTypeInfo();
    ncbi::objects::CNtSiteRange::GetTypeInfo();
    ncbi::objects::CNtermExtension::GetTypeInfo();
    ncbi::objects::CProteinExtension::GetTypeInfo();
    ncbi::objects::CProteinSub::GetTypeInfo();
    ncbi::objects::CRepeat::GetTypeInfo();
    ncbi::objects::CSeqInterval::GetTypeInfo();
    ncbi::objects::CSeqLocation::GetTypeInfo();
    ncbi::objects::CSequenceVariant::GetTypeInfo();
    ncbi::objects::CSimpleVariant::GetTypeInfo();
    ncbi::objects::CSimpleVariantSeq::GetTypeInfo();
    ncbi::objects::CSubsequence::GetTypeInfo();
    ncbi::objects::CVariant::GetTypeInfo();
    ncbi::objects::CVariantExpression::GetTypeInfo();
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

