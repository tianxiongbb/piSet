/* $Id: Bioseq_set.cpp 519216 2016-11-14 16:06:08Z ivanov $
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
 *   using specifications from the ASN data definition file
 *   'seqset.asn'.
 *
 */

// standard includes
#include <ncbi_pch.hpp>
#include <serial/serial.hpp>
#include <serial/iterator.hpp>
#include <serial/enumvalues.hpp>

// generated includes
#include <objects/seqset/Bioseq_set.hpp>
#include <objects/seq/Bioseq.hpp>
#include <objects/seq/Seq_annot.hpp> // to make KCC happy
#include <objects/seq/Seq_inst.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seqloc/Textseq_id.hpp>
#include <objects/seq/Seq_descr.hpp>
#include <objects/seqset/Seq_entry.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CBioseq_set::~CBioseq_set(void)
{
}


static bool s_is_na(const CBioseq& seq)
{
    switch (seq.GetInst().GetMol()) {
    case CSeq_inst::eMol_dna:
    case CSeq_inst::eMol_rna:
    case CSeq_inst::eMol_na:
        return true;
    default:
        return false;
    }
}


static bool s_has_gb(const CSeq_id& id)
{
    switch (id.Which()) {
    case CSeq_id::e_Genbank:
    case CSeq_id::e_Embl:
    case CSeq_id::e_Ddbj:
    case CSeq_id::e_Other:
    case CSeq_id::e_Tpg:
    case CSeq_id::e_Tpe:
    case CSeq_id::e_Tpd:
        return true;
    default:
        return false;
    }
}


static bool s_has_accession(const CSeq_id& id)
{
    if (!id.GetTextseq_Id()) {
        return false;
    } else if (id.GetTextseq_Id()->IsSetAccession()) {
        return true;
    } else {
        return false;
    }
}

void CBioseq_set::GetLabel(string* label, ELabelType type) const
{
    // If no label, just return
    if (!label) {
        return;
    }

    // Get type label
    if (IsSetClass()  &&  type != eContent) {
        const CEnumeratedTypeValues* tv =
            CBioseq_set::GetTypeInfo_enum_EClass();
        const string& cn = tv->FindName(GetClass(), true);
        *label += cn;

        if (type != eType) {
            *label += ": ";
        }
    }

    if (type == eType) {
        return;
    }

    // Loop through CBioseqs looking for the best one to use for a label
    bool best_is_na = false;
    const CBioseq* best = 0;
    const CSeq_id* best_seq_id = 0;
    const CSeq_id* best_seq_id_with_gb = 0;
    const CSeq_id* best_seq_id_with_accession = 0;
    int max = 0;
    for (CTypeConstIterator<CBioseq> si(ConstBegin(*this)); si && max < 100; ++si, ++max) {
        bool takeit = false, is_na;
        const CSeq_id* current_seq_id = 0;
        const CSeq_id* current_seq_id_with_gb = 0;
        const CSeq_id* current_seq_id_with_accession = 0;
        is_na = s_is_na(*si);
        for (CTypeConstIterator<CSeq_id> ii(ConstBegin(*si)); ii; ++ii) {
            if (!current_seq_id) {
                current_seq_id = &(*ii);
            }
            if (s_has_gb(*ii)) {
                current_seq_id_with_gb = &(*ii);
            }
            if (s_has_accession(*ii)) {
                current_seq_id_with_accession = &(*ii);
            }
        }

        if (!best) {
            takeit = true;
        } else {
            bool longer = false;
            if (si->GetInst().GetLength() > best->GetInst().GetLength()) {
                longer = true;
            }
            if (best_seq_id_with_accession) {
                if (current_seq_id_with_accession) {
                    if(longer) {
                        takeit = true;
                    }
                }
            } else if (current_seq_id_with_accession) {
                takeit = true;
            } else if (best_seq_id_with_gb) {
                if (current_seq_id_with_gb) {
                    if (longer) {
                        takeit = true;
                    }
                }
            } else if (current_seq_id_with_gb) {
                takeit = true;
            } else if (best_is_na) {
                if (is_na) {
                    if (longer) {
                        takeit = true;
                    }
                }
            } else if (is_na) {
                takeit = true;
            } else if (longer) {
                takeit = true;
            }
        }

        if (takeit) {
            best = &(*si);
            best_seq_id = current_seq_id;
            best_seq_id_with_gb = current_seq_id_with_gb;
            best_seq_id_with_accession = current_seq_id_with_accession;
            best_is_na = is_na;
        }
    }

    // Add content to label.
    if (best_seq_id_with_accession) {
        best_seq_id = best_seq_id_with_accession;
    }
    else if (best_seq_id_with_gb) {
        best_seq_id = best_seq_id_with_gb;
    }
    if (!best_seq_id) {
        *label += "(No Bioseqs)";
    } else {
        //CNcbiOstrstream os;
        //os << best_seq_id->DumpAsFasta();
        //*label += CNcbiOstrstreamToString(os);
        *label += best_seq_id->GetSeqIdString();
        if (this->IsSetSeq_set()) {
            const TSeq_set& sset = this->GetSeq_set();
            size_t len = sset.size();
            if (len > 1) {
                *label += " (" + NStr::SizetToString(sset.size()) + " components)";
            } else if (len == 1) {
                *label += " (1 component)";
            }
        }
    }
}


const CBioseq& CBioseq_set::GetNucFromNucProtSet(void) const
{
    if (GetClass() != eClass_nuc_prot) {
        NCBI_THROW(CException, eUnknown,
            "CBioseq_set::GetNucFromNucProtSet() : incompatible class (" +
            ENUM_METHOD_NAME(EClass)()->FindName(GetClass(), true) + ")");
    }

    ITERATE (TSeq_set, it, GetSeq_set()) {
        const CSeq_entry& se = **it;
        if (se.IsSeq()  &&  se.GetSeq().IsNa()) {
            return se.GetSeq();
        } else if (se.IsSet()  &&
            se.GetSet().GetClass() == CBioseq_set::eClass_segset) {
            return se.GetSet().GetMasterFromSegSet();
        }
    }

    NCBI_THROW(CException, eUnknown, 
        "CBioseq_set::GetNucFromNucProtSet() : \
        nuc-prot set doesn't contain the nucleotide bioseq");
}


const CBioseq& CBioseq_set::GetGenomicFromGenProdSet(void) const
{
    if (GetClass() != eClass_gen_prod_set) {
         NCBI_THROW(CException, eUnknown,
            "CBioseq_set::GetGenomicFromGenProdSet() : incompatible class (" +
            ENUM_METHOD_NAME(EClass)()->FindName(GetClass(), true) + ")");
    }

    ITERATE (TSeq_set, it, GetSeq_set()) {
        if ((*it)->IsSeq()) {
            const CBioseq& seq = (*it)->GetSeq();
            if (seq.GetInst().IsSetMol()  &&
                seq.GetInst().GetMol() == CSeq_inst::eMol_dna) {
                return seq;
            }
        }
    }

    NCBI_THROW(CException, eUnknown, 
        "CBioseq_set::GetGenomicFromGenProdSet() : \
        gen-prod set doesn't contain the genomic bioseq");
}


const CBioseq& CBioseq_set::GetMasterFromSegSet(void) const
{
    if (GetClass() != eClass_segset) {
         NCBI_THROW(CException, eUnknown,
            "CBioseq_set::GetMasterFromSegSet() : incompatible class (" +
            ENUM_METHOD_NAME(EClass)()->FindName(GetClass(), true) + ")");
    }

    ITERATE (TSeq_set, it, GetSeq_set()) {
        if ((*it)->IsSeq()) {
            return (*it)->GetSeq();
        }
    }

    NCBI_THROW(CException, eUnknown, 
        "CBioseq_set::GetMasterFromSegSet() : \
        segset set doesn't contain the master bioseq");
}

CConstRef<CBioseq_set> CBioseq_set::GetParentSet(void) const
{
    CSeq_entry* se;

    se = GetParentEntry();
    if ( se ) {
        se = se->GetParentEntry();
        if ( se ) {
            if ( se->IsSet() ) {
                return CConstRef<CBioseq_set> (&se->GetSet());
            }
        }
    }

    return CConstRef<CBioseq_set> ();
}

// Implemented here to prevent CBioseq dependency on Bioseq_set
CConstRef<CBioseq_set> CBioseq::GetParentSet(void) const
{
    CSeq_entry* se;

    se = GetParentEntry();
    if ( se ) {
        se = se->GetParentEntry();
        if ( se ) {
            if ( se->IsSet() ) {
                return CConstRef<CBioseq_set> (&se->GetSet());
            }
        }
    }

    return CConstRef<CBioseq_set> ();
}


bool CBioseq_set::NeedsDocsumTitle(EClass set_class)
{
    bool rval = false;
    if (set_class == CBioseq_set::eClass_pop_set
        || set_class == CBioseq_set::eClass_phy_set
        || set_class == CBioseq_set::eClass_eco_set
        || set_class == CBioseq_set::eClass_mut_set) {
        rval = true;
    }
    return rval;
}


bool CBioseq_set::NeedsDocsumTitle() const
{
    bool rval = false;
    if (IsSetClass()) {
        rval = NeedsDocsumTitle(GetClass());
    }
    return rval;

}


END_objects_SCOPE // namespace ncbi::objects::
END_NCBI_SCOPE
