/* $Id: GCClient_GetAssemblyReques.cpp 486570 2015-12-07 17:17:13Z shchekot $
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
 * Author:  .......
 *
 * File Description:
 *   .......
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'gencoll_client.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>

// generated includes
#include <objects/genomecoll/GCClient_GetAssemblyReques.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CGCClient_GetAssemblyRequest::~CGCClient_GetAssemblyRequest(void)
{
}

CGCClient_GetAssemblyRequest::SRequestParam::SRequestParam()
  : level           (CGCClient_GetAssemblyRequest::eLevel_component)
  , assembly_flags  (eGCClient_AttributeFlags_none)
  , chromosome_flags(eGCClient_AttributeFlags_biosource)
  , scaffold_flags  (eGCClient_AttributeFlags_none)
  , component_flags (eGCClient_AttributeFlags_none)
{
}

CGCClient_GetAssemblyRequest::SRequestParam::SRequestParam(int level_, int assembly_flags_, int chromosome_flags_,
                                                           int scaffold_flags_, int component_flags_)
    : level(level_)
    , assembly_flags(assembly_flags_)
    , chromosome_flags(chromosome_flags_)
    , scaffold_flags(scaffold_flags_)
    , component_flags(component_flags_)
{
}

bool CGCClient_GetAssemblyRequest::SRequestParam::SetMode(EAssemblyMode mode)
{
    level            = CGCClient_GetAssemblyRequest::eLevel_component;
    assembly_flags   = eGCClient_AttributeFlags_none;
    chromosome_flags = eGCClient_AttributeFlags_biosource;
    scaffold_flags   = eGCClient_AttributeFlags_none;
    component_flags  = eGCClient_AttributeFlags_none;

    switch (mode) {
    case eAssemblyMode_assembly_only:
        // param asm_fl  512   ('do not get stats, avoid frequently changing data')
        level          = CGCClient_GetAssemblyRequest::eLevel_assembly;
        assembly_flags = eGCClient_AttributeFlags_exclude_stats;
        break;
    case eAssemblyMode_ftp_export:
        // if ftp needs to different than euk-annotation, add it here.
    case eAssemblyMode_eukaryotic_annotation:
        // genome_pipeline_base.gpc uses asm_fl=0, chr_fl=3, scaf_fl=33792 (biosource on chromosomes, instantiate empty assmeblies, scaffolds for annotation)
        level            = CGCClient_GetAssemblyRequest::eLevel_component;
        assembly_flags   = eGCClient_AttributeFlags_none;
        chromosome_flags = eGCClient_AttributeFlags_all;
        scaffold_flags   = eGCClient_AttributeFlags_get_wgs_contigs |
                           eGCClient_AttributeFlags_include_unordered_scaffolds;
        break;
    case eAssemblyMode_prokaryotic_annotation:
        // bacterial_pipeline.gpc uses asm_fl=512, scaf_fl=33792 , chr_fl=8195 (no AlignDb, biosource, molinfo)
        level            = CGCClient_GetAssemblyRequest::eLevel_component;
        assembly_flags   = eGCClient_AttributeFlags_exclude_stats;
        chromosome_flags = eGCClient_AttributeFlags_exclude_aligndb |
                           eGCClient_AttributeFlags_molinfo |
                           eGCClient_AttributeFlags_biosource;
        scaffold_flags   = eGCClient_AttributeFlags_get_wgs_contigs |
                           eGCClient_AttributeFlags_include_unordered_scaffolds;
        break;
    case eAssemblyMode_entrez_indexing:
        level            = CGCClient_GetAssemblyRequest::eLevel_scaffold;
        assembly_flags   = eGCClient_AttributeFlags_none;
        chromosome_flags = eGCClient_AttributeFlags_biosource |
                           eGCClient_AttributeFlags_exclude_aligndb;
        break;
    case eAssemblyMode_assembly_backend:
        level          = CGCClient_GetAssemblyRequest::eLevel_scaffold;
        assembly_flags = eGCClient_AttributeFlags_only_gui_data;
        break;
    case eAssemblyMode_sequence_names:
        level            = CGCClient_GetAssemblyRequest::eLevel_scaffold;
        assembly_flags   = eGCClient_AttributeFlags_none;
        chromosome_flags = eGCClient_AttributeFlags_exclude_aligndb;
        scaffold_flags   = eGCClient_AttributeFlags_include_UCSC_pseudo_scaffolds |
                           eGCClient_AttributeFlags_get_wgs_contigs;
        component_flags  = eGCClient_AttributeFlags_none;
        break;
    default:
        return false;
    }
    return true;
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

/* Original file checksum: lines: 57, chars: 1787, CRC32: a0be062f */
