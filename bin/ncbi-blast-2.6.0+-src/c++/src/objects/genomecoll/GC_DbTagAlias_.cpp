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
 *   'genome_collection.asn'.
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
#include <objects/genomecoll/GC_DbTagAlias.hpp>
#include <objects/general/Dbtag.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CGC_DbTagAlias_Base::, ESimilarity, true)
{
    SET_ENUM_INTERNAL_NAME("GC-DbTagAlias", "similarity");
    SET_ENUM_MODULE("NCBI-GenomeCollection");
    ADD_ENUM_VALUE("unknown", eSimilarity_unknown);
    ADD_ENUM_VALUE("identical", eSimilarity_identical);
    ADD_ENUM_VALUE("different", eSimilarity_different);
}
END_ENUM_INFO

void CGC_DbTagAlias_Base::ResetRefseq(void)
{
    m_Refseq.Reset();
}

void CGC_DbTagAlias_Base::SetRefseq(CGC_DbTagAlias_Base::TRefseq& value)
{
    m_Refseq.Reset(&value);
}

CGC_DbTagAlias_Base::TRefseq& CGC_DbTagAlias_Base::SetRefseq(void)
{
    if ( !m_Refseq )
        m_Refseq.Reset(new ncbi::objects::CDbtag());
    return (*m_Refseq);
}

void CGC_DbTagAlias_Base::ResetGenbank(void)
{
    m_Genbank.Reset();
}

void CGC_DbTagAlias_Base::SetGenbank(CGC_DbTagAlias_Base::TGenbank& value)
{
    m_Genbank.Reset(&value);
}

CGC_DbTagAlias_Base::TGenbank& CGC_DbTagAlias_Base::SetGenbank(void)
{
    if ( !m_Genbank )
        m_Genbank.Reset(new ncbi::objects::CDbtag());
    return (*m_Genbank);
}

void CGC_DbTagAlias_Base::Reset(void)
{
    ResetRefseq();
    ResetGenbank();
    ResetSimilarity();
}

BEGIN_NAMED_BASE_CLASS_INFO("GC-DbTagAlias", CGC_DbTagAlias)
{
    SET_CLASS_MODULE("NCBI-GenomeCollection");
    ADD_NAMED_REF_MEMBER("refseq", m_Refseq, CDbtag)->SetOptional();
    ADD_NAMED_REF_MEMBER("genbank", m_Genbank, CDbtag)->SetOptional();
    ADD_NAMED_ENUM_MEMBER("similarity", m_Similarity, ESimilarity)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CGC_DbTagAlias_Base::CGC_DbTagAlias_Base(void)
    : m_Similarity((ESimilarity)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CGC_DbTagAlias_Base::~CGC_DbTagAlias_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

