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
 *   'seq.asn'.
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
#include <objects/seq/GIBB_method.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_INFO("GIBB-method", EGIBB_method, false)
{
    SET_ENUM_MODULE("NCBI-Sequence");
    ADD_ENUM_VALUE("concept-trans", eGIBB_method_concept_trans);
    ADD_ENUM_VALUE("seq-pept", eGIBB_method_seq_pept);
    ADD_ENUM_VALUE("both", eGIBB_method_both);
    ADD_ENUM_VALUE("seq-pept-overlap", eGIBB_method_seq_pept_overlap);
    ADD_ENUM_VALUE("seq-pept-homol", eGIBB_method_seq_pept_homol);
    ADD_ENUM_VALUE("concept-trans-a", eGIBB_method_concept_trans_a);
    ADD_ENUM_VALUE("other", eGIBB_method_other);
}
END_ENUM_INFO


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

