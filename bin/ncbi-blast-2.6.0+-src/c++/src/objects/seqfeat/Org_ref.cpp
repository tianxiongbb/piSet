/* $Id: Org_ref.cpp 471648 2015-06-30 12:36:49Z kornbluh $
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
 *   'seqfeat.asn'.
 */

// standard includes

// generated includes
#include <ncbi_pch.hpp>
#include <objects/seqfeat/Org_ref.hpp>
#include <objects/general/Object_id.hpp>
#include <objects/general/Dbtag.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
COrg_ref::~COrg_ref(void)
{
}

// Appends a label to "label" based on content
void COrg_ref::GetLabel(string* label) const
{
    if (IsSetTaxname()) {
        *label += GetTaxname();
    } else if (IsSetCommon()) {
        *label += GetCommon();
    } else if (IsSetDb()) {
        GetDb().front()->GetLabel(label);
    }
}
    
static const char* const s_taxonName = "taxon" ;

int
COrg_ref::GetTaxId() const
{
    if( ! IsSetDb() ) {
        return 0;
    }
    const TDb& lDbTags = GetDb();
 
    for(TDb::const_iterator i = lDbTags.begin();
	i != lDbTags.end();
	++i) {
	if( i->GetPointer()
	    && i->GetObject().GetDb().compare(s_taxonName) == 0 ) {
	    const CObject_id& id = i->GetObject().GetTag();
	    if( id.IsId() )
		return id.GetId();
	}
    }
    return 0;
}

int
COrg_ref::SetTaxId( int tax_id )
{
    int old_id(0);

    TDb& lDbTags = SetDb();
    // Try to update existing tax id first
    for(TDb::iterator i = lDbTags.begin();
	i != lDbTags.end();
	++i) {
	if( *i && i->GetObject().GetDb() == s_taxonName ) {
	    CObject_id& id = i->GetObject().SetTag();
	    if( id.IsId() )
		old_id = id.GetId();
	    id.SetId() = tax_id;
	    return old_id;
	}
    }
    // Add new tag
    CRef< CDbtag > ref( new CDbtag() );
    ref->SetDb( s_taxonName );
    ref->SetTag().SetId( tax_id );
    SetDb().push_back( ref );

    return old_id;
}

bool COrg_ref::IsSetLineage(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetLineage ();
}

const string& COrg_ref::GetLineage(void) const
{
    return GetOrgname ().GetLineage ();
}

bool COrg_ref::IsSetGcode(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetGcode ();
}

int COrg_ref::GetGcode(void) const
{
    return GetOrgname ().GetGcode ();
}

bool COrg_ref::IsSetMgcode(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetMgcode ();
}

int COrg_ref::GetMgcode(void) const
{
    return GetOrgname ().GetMgcode ();
}

bool COrg_ref::IsSetPgcode(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetPgcode ();
}

int COrg_ref::GetPgcode(void) const
{
    return GetOrgname ().GetPgcode ();
}

bool COrg_ref::IsSetDivision(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetDiv ();
}

const string& COrg_ref::GetDivision(void) const
{
    return GetOrgname ().GetDiv ();
}

bool COrg_ref::IsSetOrgMod(void) const
{
    return IsSetOrgname () && GetOrgname ().IsSetMod ();
}


string COrg_ref::x_GetTaxnameAfterFirstTwoWords() const
{
    string taxname = "";
    if (IsSetTaxname()) {
        taxname = GetTaxname();
    }
    // Look for modifiers in taxname after first two words
    size_t pos = NStr::Find (taxname, " ");
    if (pos == string::npos) {
        taxname = "";
    } else {
        taxname = taxname.substr(pos + 1);
        NStr::TruncateSpacesInPlace(taxname);
        pos = NStr::Find (taxname, " ");
        if (pos == string::npos) {
            taxname = "";
        } else {
            taxname = taxname.substr(pos + 1);
            NStr::TruncateSpacesInPlace(taxname);
        }
    }
    return taxname;
}


bool s_FindWholeWord (string taxname, string value)
{
    if (NStr::IsBlank(taxname) || NStr::IsBlank(value)) {
        return false;
    }
    size_t pos = NStr::Find (taxname, value);
    size_t value_len = value.length();
    while (pos != string::npos 
           && ( ( (pos != 0 && isalpha (taxname.c_str()[pos - 1]))
                || isalpha (taxname.c_str()[pos + value_len])))) {
        pos = NStr::Find(taxname, value, pos + value_len);
    }
    if (pos == string::npos) {
        return false;
    } else {
        return true;
    }
}


bool COrg_ref::IsVarietyValid(const string& variety) const
{
    if (NStr::IsBlank(variety)) {
        return true;
    }
    string taxname = x_GetTaxnameAfterFirstTwoWords();
    return s_FindWholeWord(taxname, variety);
}


bool COrg_ref::HasValidVariety() const
{
    if (!IsSetOrgname() || !GetOrgname().IsSetMod()) {
        return false;
    }
    ITERATE(COrgName::TMod, it, GetOrgname().GetMod()) {
        if ((*it)->IsSetSubtype() && (*it)->GetSubtype() == COrgMod::eSubtype_variety
            && (*it)->IsSetSubname() && !NStr::IsBlank((*it)->GetSubname())
            && IsVarietyValid((*it)->GetSubname())) {
            return true;
        }
    }
    return false;
}


bool COrg_ref::IsSubspeciesValid(const string& subspecies) const
{
    if (NStr::IsBlank(subspecies)) {
        return true;
    }
    string taxname = x_GetTaxnameAfterFirstTwoWords();
    if (s_FindWholeWord(taxname, subspecies)) {
        return true;
    } else {
        return HasValidVariety();
    }

}


#define MAKE_COMMON(o1,o2,o3,Field) if (o1.IsSet##Field() && o2.IsSet##Field() && NStr::Equal(o1.Get##Field(), o2.Get##Field())) o3.Set##Field(o1.Get##Field());

void s_MakeCommonStringList(const list< string >& list1, const list< string >& list2, list< string >& list3)
{
    ITERATE(list< string >, it1, list1) {
        bool found = false;
        ITERATE(list< string >, it2, list2) {
            if (NStr::Equal(*it1, *it2)) {
                found = true;
                break;
            }
        }
        if (found) {
            list3.push_back(*it1);
        }
    }
}


CRef<COrg_ref> COrg_ref::MakeCommon(const COrg_ref& other) const
{
    int taxid1 = GetTaxId();
    int taxid2 = other.GetTaxId();
    if (taxid1 != taxid2) {
        return CRef<COrg_ref>(NULL);
    }

    CRef<COrg_ref> common(new COrg_ref());
    if (Equals(other)) {
        common->Assign(*this);
    } else {
        MAKE_COMMON((*this), other, (*common), Taxname);
        MAKE_COMMON((*this), other, (*common), Common);

        // common mods
        if (IsSetMod() && other.IsSetMod()) {
            s_MakeCommonStringList(GetMod(), other.GetMod(), common->SetMod());
            if (common->GetMod().empty()) {
                common->ResetMod();
            }
        }

        // common synonyms
        if (IsSetSyn() && other.IsSetSyn()) {
            s_MakeCommonStringList(GetSyn(), other.GetSyn(), common->SetSyn());
            if (common->GetSyn().empty()) {
                common->ResetSyn();
            }
        }

        // common dbtags
        if (IsSetDb() && other.IsSetDb()) {
            ITERATE(TDb, it1, GetDb()) {
                bool found = false;
                ITERATE(TDb, it2, GetDb()) {
                    if ((*it1)->Equals(**it2)) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    CRef<CDbtag> add(new CDbtag());
                    add->Assign(**it1);
                    common->SetDb().push_back(add);
                }
            }
        }

        // common orgname
        if (IsSetOrgname() && other.IsSetOrgname()) {
            CRef<COrgName> orgname = GetOrgname().MakeCommon(other.GetOrgname());
            if (orgname) {
                common->SetOrgname().Assign(*orgname);
            }
        }
    }

    return common;
}


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

/* Original file checksum: lines: 61, chars: 1882, CRC32: c3300cc2 */
