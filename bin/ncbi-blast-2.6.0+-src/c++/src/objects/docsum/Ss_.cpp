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
 *   'docsum.asn'.
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
#include <objects/docsum/Ss.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_subSnpClass, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "subSnpClass");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("snp", eAttlist_subSnpClass_snp);
    ADD_ENUM_VALUE("in-del", eAttlist_subSnpClass_in_del);
    ADD_ENUM_VALUE("heterozygous", eAttlist_subSnpClass_heterozygous);
    ADD_ENUM_VALUE("microsatellite", eAttlist_subSnpClass_microsatellite);
    ADD_ENUM_VALUE("named-locus", eAttlist_subSnpClass_named_locus);
    ADD_ENUM_VALUE("no-variation", eAttlist_subSnpClass_no_variation);
    ADD_ENUM_VALUE("mixed", eAttlist_subSnpClass_mixed);
    ADD_ENUM_VALUE("multinucleotide-polymorphism", eAttlist_subSnpClass_multinucleotide_polymorphism);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_orient, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "orient");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("forward", eAttlist_orient_forward);
    ADD_ENUM_VALUE("reverse", eAttlist_orient_reverse);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_strand, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "strand");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("top", eAttlist_strand_top);
    ADD_ENUM_VALUE("bottom", eAttlist_strand_bottom);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_molType, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "molType");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("genomic", eAttlist_molType_genomic);
    ADD_ENUM_VALUE("cDNA", eAttlist_molType_cDNA);
    ADD_ENUM_VALUE("mito", eAttlist_molType_mito);
    ADD_ENUM_VALUE("chloro", eAttlist_molType_chloro);
    ADD_ENUM_VALUE("unknown", eAttlist_molType_unknown);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_methodClass, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "methodClass");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("dHPLC", eAttlist_methodClass_dHPLC);
    ADD_ENUM_VALUE("hybridize", eAttlist_methodClass_hybridize);
    ADD_ENUM_VALUE("computed", eAttlist_methodClass_computed);
    ADD_ENUM_VALUE("sSCP", eAttlist_methodClass_sSCP);
    ADD_ENUM_VALUE("other", eAttlist_methodClass_other);
    ADD_ENUM_VALUE("unknown", eAttlist_methodClass_unknown);
    ADD_ENUM_VALUE("rFLP", eAttlist_methodClass_rFLP);
    ADD_ENUM_VALUE("sequence", eAttlist_methodClass_sequence);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CSs_Base::C_Attlist::, EAttlist_validated, false)
{
    SET_ENUM_INTERNAL_NAME("Ss.attlist", "validated");
    SET_ENUM_MODULE("Docsum-3-4");
    ADD_ENUM_VALUE("by-submitter", eAttlist_validated_by_submitter);
    ADD_ENUM_VALUE("by-frequency", eAttlist_validated_by_frequency);
    ADD_ENUM_VALUE("by-cluster", eAttlist_validated_by_cluster);
}
END_ENUM_INFO

void CSs_Base::C_Attlist::ResetHandle(void)
{
    m_Handle.erase();
    m_set_State[0] &= ~0xc;
}

void CSs_Base::C_Attlist::ResetLocSnpId(void)
{
    m_LocSnpId.erase();
    m_set_State[0] &= ~0xc0;
}

void CSs_Base::C_Attlist::ResetLinkoutUrl(void)
{
    m_LinkoutUrl.erase();
    m_set_State[0] &= ~0xc00000;
}

void CSs_Base::C_Attlist::ResetSsAlias(void)
{
    m_SsAlias.erase();
    m_set_State[0] &= ~0x3000000;
}

void CSs_Base::C_Attlist::ResetClinicalSignificance(void)
{
    m_ClinicalSignificance.erase();
    m_set_State[0] &= ~0x30000000;
}

void CSs_Base::C_Attlist::Reset(void)
{
    ResetSsId();
    ResetHandle();
    ResetBatchId();
    ResetLocSnpId();
    ResetSubSnpClass();
    ResetOrient();
    ResetStrand();
    ResetMolType();
    ResetBuildId();
    ResetMethodClass();
    ResetValidated();
    ResetLinkoutUrl();
    ResetSsAlias();
    ResetAlleleOrigin();
    ResetClinicalSignificance();
}

BEGIN_NAMED_CLASS_INFO("", CSs_Base::C_Attlist)
{
    SET_INTERNAL_NAME("Ss", "attlist");
    SET_CLASS_MODULE("Docsum-3-4");
    ADD_NAMED_STD_MEMBER("ssId", m_SsId)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("handle", m_Handle)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("batchId", m_BatchId)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("locSnpId", m_LocSnpId)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("subSnpClass", m_SubSnpClass, EAttlist_subSnpClass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("orient", m_Orient, EAttlist_orient)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("strand", m_Strand, EAttlist_strand)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("molType", m_MolType, EAttlist_molType)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("buildId", m_BuildId)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("methodClass", m_MethodClass, EAttlist_methodClass)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("validated", m_Validated, EAttlist_validated)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("linkoutUrl", m_LinkoutUrl)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("ssAlias", m_SsAlias)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("alleleOrigin", m_AlleleOrigin)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("clinicalSignificance", m_ClinicalSignificance)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->SetRandomOrder(true);
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSs_Base::C_Attlist::C_Attlist(void)
    : m_SsId(0), m_BatchId(0), m_SubSnpClass((EAttlist_subSnpClass)(0)), m_Orient((EAttlist_orient)(0)), m_Strand((EAttlist_strand)(0)), m_MolType((EAttlist_molType)(0)), m_BuildId(0), m_MethodClass((EAttlist_methodClass)(0)), m_Validated((EAttlist_validated)(0)), m_AlleleOrigin(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSs_Base::C_Attlist::~C_Attlist(void)
{
}


void CSs_Base::C_Sequence::ResetSeq5(void)
{
    m_Seq5.erase();
    m_set_State[0] &= ~0x3;
}

void CSs_Base::C_Sequence::ResetObserved(void)
{
    m_Observed.erase();
    m_set_State[0] &= ~0xc;
}

void CSs_Base::C_Sequence::ResetSeq3(void)
{
    m_Seq3.erase();
    m_set_State[0] &= ~0x30;
}

void CSs_Base::C_Sequence::Reset(void)
{
    ResetSeq5();
    ResetObserved();
    ResetSeq3();
}

BEGIN_NAMED_CLASS_INFO("", CSs_Base::C_Sequence)
{
    SET_INTERNAL_NAME("Ss", "sequence");
    SET_CLASS_MODULE("Docsum-3-4");
    ADD_NAMED_STD_MEMBER("seq5", m_Seq5)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_STD_MEMBER("observed", m_Observed)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("seq3", m_Seq3)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSs_Base::C_Sequence::C_Sequence(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CSs_Base::C_Sequence::~C_Sequence(void)
{
}


void CSs_Base::ResetAttlist(void)
{
    if ( !m_Attlist ) {
        m_Attlist.Reset(new TAttlist());
        return;
    }
    (*m_Attlist).Reset();
}

void CSs_Base::SetAttlist(CSs_Base::TAttlist& value)
{
    m_Attlist.Reset(&value);
}

void CSs_Base::ResetSequence(void)
{
    if ( !m_Sequence ) {
        m_Sequence.Reset(new TSequence());
        return;
    }
    (*m_Sequence).Reset();
}

void CSs_Base::SetSequence(CSs_Base::TSequence& value)
{
    m_Sequence.Reset(&value);
}

void CSs_Base::Reset(void)
{
    ResetAttlist();
    ResetSequence();
}

BEGIN_NAMED_BASE_CLASS_INFO("Ss", CSs)
{
    SET_CLASS_MODULE("Docsum-3-4");
    ADD_NAMED_REF_MEMBER("attlist", m_Attlist, C_Attlist);
    ADD_NAMED_REF_MEMBER("sequence", m_Sequence, C_Sequence);
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSs_Base::CSs_Base(void)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetAttlist();
        ResetSequence();
    }
}

// destructor
CSs_Base::~CSs_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

