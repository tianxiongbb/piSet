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
 *   'seqalign.asn'.
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
#include <objects/seqalign/Spliced_exon.hpp>
#include <objects/general/User_object.hpp>
#include <objects/seqalign/Product_pos.hpp>
#include <objects/seqalign/Score_set.hpp>
#include <objects/seqalign/Splice_site.hpp>
#include <objects/seqalign/Spliced_exon_chunk.hpp>
#include <objects/seqloc/Seq_id.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

void CSpliced_exon_Base::ResetProduct_start(void)
{
    if ( !m_Product_start ) {
        m_Product_start.Reset(new TProduct_start());
        return;
    }
    (*m_Product_start).Reset();
}

void CSpliced_exon_Base::SetProduct_start(CSpliced_exon_Base::TProduct_start& value)
{
    m_Product_start.Reset(&value);
}

void CSpliced_exon_Base::ResetProduct_end(void)
{
    if ( !m_Product_end ) {
        m_Product_end.Reset(new TProduct_end());
        return;
    }
    (*m_Product_end).Reset();
}

void CSpliced_exon_Base::SetProduct_end(CSpliced_exon_Base::TProduct_end& value)
{
    m_Product_end.Reset(&value);
}

void CSpliced_exon_Base::ResetProduct_id(void)
{
    m_Product_id.Reset();
}

void CSpliced_exon_Base::SetProduct_id(CSpliced_exon_Base::TProduct_id& value)
{
    m_Product_id.Reset(&value);
}

CSpliced_exon_Base::TProduct_id& CSpliced_exon_Base::SetProduct_id(void)
{
    if ( !m_Product_id )
        m_Product_id.Reset(new ncbi::objects::CSeq_id());
    return (*m_Product_id);
}

void CSpliced_exon_Base::ResetGenomic_id(void)
{
    m_Genomic_id.Reset();
}

void CSpliced_exon_Base::SetGenomic_id(CSpliced_exon_Base::TGenomic_id& value)
{
    m_Genomic_id.Reset(&value);
}

CSpliced_exon_Base::TGenomic_id& CSpliced_exon_Base::SetGenomic_id(void)
{
    if ( !m_Genomic_id )
        m_Genomic_id.Reset(new ncbi::objects::CSeq_id());
    return (*m_Genomic_id);
}

void CSpliced_exon_Base::ResetParts(void)
{
    m_Parts.clear();
    m_set_State[0] &= ~0x30000;
}

void CSpliced_exon_Base::ResetScores(void)
{
    m_Scores.Reset();
}

void CSpliced_exon_Base::SetScores(CSpliced_exon_Base::TScores& value)
{
    m_Scores.Reset(&value);
}

CSpliced_exon_Base::TScores& CSpliced_exon_Base::SetScores(void)
{
    if ( !m_Scores )
        m_Scores.Reset(new ncbi::objects::CScore_set());
    return (*m_Scores);
}

void CSpliced_exon_Base::ResetAcceptor_before_exon(void)
{
    m_Acceptor_before_exon.Reset();
}

void CSpliced_exon_Base::SetAcceptor_before_exon(CSpliced_exon_Base::TAcceptor_before_exon& value)
{
    m_Acceptor_before_exon.Reset(&value);
}

CSpliced_exon_Base::TAcceptor_before_exon& CSpliced_exon_Base::SetAcceptor_before_exon(void)
{
    if ( !m_Acceptor_before_exon )
        m_Acceptor_before_exon.Reset(new ncbi::objects::CSplice_site());
    return (*m_Acceptor_before_exon);
}

void CSpliced_exon_Base::ResetDonor_after_exon(void)
{
    m_Donor_after_exon.Reset();
}

void CSpliced_exon_Base::SetDonor_after_exon(CSpliced_exon_Base::TDonor_after_exon& value)
{
    m_Donor_after_exon.Reset(&value);
}

CSpliced_exon_Base::TDonor_after_exon& CSpliced_exon_Base::SetDonor_after_exon(void)
{
    if ( !m_Donor_after_exon )
        m_Donor_after_exon.Reset(new ncbi::objects::CSplice_site());
    return (*m_Donor_after_exon);
}

void CSpliced_exon_Base::ResetExt(void)
{
    m_Ext.clear();
    m_set_State[0] &= ~0xc000000;
}

void CSpliced_exon_Base::Reset(void)
{
    ResetProduct_start();
    ResetProduct_end();
    ResetGenomic_start();
    ResetGenomic_end();
    ResetProduct_id();
    ResetGenomic_id();
    ResetProduct_strand();
    ResetGenomic_strand();
    ResetParts();
    ResetScores();
    ResetAcceptor_before_exon();
    ResetDonor_after_exon();
    ResetPartial();
    ResetExt();
}

BEGIN_NAMED_BASE_CLASS_INFO("Spliced-exon", CSpliced_exon)
{
    SET_CLASS_MODULE("NCBI-Seqalign");
    ADD_NAMED_REF_MEMBER("product-start", m_Product_start, CProduct_pos);
    ADD_NAMED_REF_MEMBER("product-end", m_Product_end, CProduct_pos);
    ADD_NAMED_STD_MEMBER("genomic-start", m_Genomic_start)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("genomic-end", m_Genomic_end)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_REF_MEMBER("product-id", m_Product_id, CSeq_id)->SetOptional();
    ADD_NAMED_REF_MEMBER("genomic-id", m_Genomic_id, CSeq_id)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("product-strand", m_Product_strand, ENa_strand)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("genomic-strand", m_Genomic_strand, ENa_strand)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("parts", m_Parts, STL_list, (STL_CRef, (CLASS, (CSpliced_exon_chunk))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_REF_MEMBER("scores", m_Scores, CScore_set)->SetOptional();
    ADD_NAMED_REF_MEMBER("acceptor-before-exon", m_Acceptor_before_exon, CSplice_site)->SetOptional();
    ADD_NAMED_REF_MEMBER("donor-after-exon", m_Donor_after_exon, CSplice_site)->SetOptional();
    ADD_NAMED_STD_MEMBER("partial", m_Partial)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("ext", m_Ext, STL_list, (STL_CRef, (CLASS, (CUser_object))))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CSpliced_exon_Base::CSpliced_exon_Base(void)
    : m_Genomic_start(0), m_Genomic_end(0), m_Product_strand((ncbi::objects::ENa_strand)(0)), m_Genomic_strand((ncbi::objects::ENa_strand)(0)), m_Partial(0)
{
    memset(m_set_State,0,sizeof(m_set_State));
    if ( !IsAllocatedInPool() ) {
        ResetProduct_start();
        ResetProduct_end();
    }
}

// destructor
CSpliced_exon_Base::~CSpliced_exon_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

