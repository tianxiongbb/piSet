/* $Id: Suspect_rule.cpp 513456 2016-09-12 14:18:13Z ivanov $
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
 * Author:  J. Chen
 *
 * File Description:
 *   suspect product name check against rule
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'macro.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>

// generated includes
#include <objects/macro/Suspect_rule.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CSuspect_rule::~CSuspect_rule(void)
{
}

bool CSuspect_rule :: StringMatchesSuspectProductRule(const string& str) const
{
  // CSearch_func: only about string
  const CSearch_func& func = GetFind();
  if (!func.Empty() && !func.Match(str)) {
      return false;
  }
  else if (CanGetExcept()) {
     const CSearch_func& exc_func = GetExcept();
     if (!exc_func.Empty() && exc_func.Match(str)) {
       return false;
     }
  }
  return true;
};


bool CSuspect_rule::ApplyToString(string& val) const
{
    if (!IsSetReplace() || !StringMatchesSuspectProductRule(val)) {
        return false;
    }

    CRef<CString_constraint> constraint(NULL);
    if (IsSetFind() && GetFind().IsString_constraint()) {
        constraint.Reset(new CString_constraint());
        constraint->Assign(GetFind().GetString_constraint());
    }
    return GetReplace().ApplyToString(val, constraint);
}


string CSuspect_rule::SummarizeReplaceRule(const CReplace_rule& repl) const
{
    string str = "Unknown replacement function";
    const CReplace_func& func = repl.GetReplace_func();
    if (func.Which() == CReplace_func::e_Simple_replace) {
        const CSimple_replace& simple = func.GetSimple_replace();
        str = "replace ";
        str += simple.GetWhole_string() ? "entire name with " : "with ";
        str += simple.CanGetReplace() ? "'" + simple.GetReplace() + "'": "''";
        str += simple.GetWeasel_to_putative() ? ", retain and normalize 'putative' synonym" : kEmptyStr;
    }
    else if (func.Which() == CReplace_func::e_Haem_replace) {
        str = "replace '" + func.GetHaem_replace() + "' with 'heme' if whole word, 'hem' otherwise";
    }
    str += repl.GetMove_to_note() ? ", move original to note" : kEmptyStr;
    return str;
}


string CSuspect_rule::SummarizeStringConstraint(const CString_constraint& cons) const
{
    if (cons.CanGetMatch_text()) {
        string loc_word;
        switch (cons.GetMatch_location()) {
            case eString_location_contains:
                loc_word = cons.GetNot_present() ? "does not contain" : "contains";
                break;
            case eString_location_equals:
                loc_word = cons.GetNot_present() ? "does not equal" : "equals";
                break;
            case eString_location_starts:
                loc_word = cons.GetNot_present() ? "does not start with" : "starts with";
                break;
            case eString_location_ends:
                loc_word = cons.GetNot_present() ? "does not end with" : "ends with";
                break;
            case eString_location_inlist:
                loc_word = cons.GetNot_present() ? "is not one of" : "is one of";
                break;
        }
        string sub_words;
        if (cons.CanGetIgnore_words()) {
            ITERATE (list<CRef<CWord_substitution> >, it, cons.GetIgnore_words().Get()) {
                string syns;
                if ((*it)->CanGetSynonyms() && !(*it)->GetSynonyms().empty()) {
                    const CWord_substitution::TSynonyms& synonyms = (*it)->GetSynonyms();
                    ITERATE (CWord_substitution::TSynonyms, sn, synonyms) {
                        if (!syns.empty()) {
                            CWord_substitution::TSynonyms::const_iterator z = sn;
                            syns += (++z == synonyms.end()) ? " and " : ", ";
                        }
                        syns += "\'" + *sn + "\'";
                    }
                    sub_words += sub_words.empty() ? "" : ", ";
                    sub_words += "allow '" + ((*it)->CanGetWord() ? (*it)->GetWord() : "") + "' to be replaced by " + syns;
                    if ((*it)->GetCase_sensitive()) sub_words += ", case-sensitive";
                    if ((*it)->GetWhole_word()) sub_words += ", whole word";
                }
            }
        }
        string params;
        params += cons.GetCase_sensitive() ? "case-sensitive" : kEmptyStr;
        params += cons.GetWhole_word() ? params.empty() ? "whole word" : ", whole word" : kEmptyStr;
        params += cons.GetIgnore_space() ? params.empty() ? "ignore spaces" : ", ignore spaces" : kEmptyStr;
        params += cons.GetIgnore_punct() ? params.empty() ? "ignore punctuation" : ", ignore punctuation" : kEmptyStr;
        params += cons.GetIgnore_weasel() ? params.empty() ? "ignore \'putative\' synonyms" : ", ignore \'putative\' synonyms" : kEmptyStr;

        string str = loc_word + " '" + cons.GetMatch_text() + "'";
        str += params.empty() ? kEmptyStr : " (" + params + ")";
        str += cons.GetIs_all_caps() ? ", all letters are uppercase" : kEmptyStr;
        str += cons.GetIs_all_lower() ? ", all letters are lowercase" : kEmptyStr;
        str += cons.GetIs_all_punct() ? ", all characters are punctuation" : kEmptyStr;
        return str;
    }
    return kEmptyStr;
}


string CSuspect_rule::SummarizeSearchFunc(const CSearch_func& func) const
{
    string summ;
    switch (func.Which()) {
        case CSearch_func::e_String_constraint:
            return SummarizeStringConstraint(func.GetString_constraint());
        case CSearch_func::e_Contains_plural:
            return "may contain plural";
        case CSearch_func::e_N_or_more_brackets_or_parentheses:
            return "contains " + NStr::IntToString(func.GetN_or_more_brackets_or_parentheses()) + " or more brackets or parentheses";
        case CSearch_func::e_Three_numbers:
            return "Three or more numbers together";
        case CSearch_func::e_Underscore:
            return "contains underscore";
        case CSearch_func::e_Prefix_and_numbers:
            return "is '" + func.GetPrefix_and_numbers() + "' followed by numbers";
        case CSearch_func::e_All_caps:
            return "is all capital letters";
        case CSearch_func::e_Unbalanced_paren:
            return "contains unbalanced brackets or parentheses";
        case CSearch_func::e_Too_long:
            return "is longer than " + NStr::IntToString(func.GetToo_long()) + " characters";
        case CSearch_func::e_Has_term:
            //if (short_version) summ = "contains " + strtmp;
            return "contains \'" + func.GetHas_term() + "\' at start or separated from other letters by numbers, spaces, or punctuation, but does not also contain 'domain'";
    }
    return "Unknown search function";
}


string CSuspect_rule::SummarizeEndDistance(const CLocation_pos_constraint& pos) const
{
    switch (pos.Which()) {
        case CLocation_pos_constraint::e_Dist_from_end:
            return "exactly " + NStr::IntToString(pos.GetDist_from_end());
        case CLocation_pos_constraint::e_Max_dist_from_end:
            return "no more than " + NStr::IntToString(pos.GetMax_dist_from_end());
        case CLocation_pos_constraint::e_Min_dist_from_end:
            return "no less than " + NStr::IntToString(pos.GetMin_dist_from_end());
    }
    return kEmptyStr;
}


string CSuspect_rule::SummarizeLocationConstraint(const CLocation_constraint& loc) const
{
    string partial;
    EPartial_constraint partial5 = loc.GetPartial5();
    EPartial_constraint partial3 = loc.GetPartial3();
    if (partial5 == ePartial_constraint_either && partial3 != ePartial_constraint_either) {
        partial = partial3 == ePartial_constraint_partial ? " that are 3\' partial" : " that are 3\' complete";
    }
    else if (partial3 == ePartial_constraint_either && partial5 != ePartial_constraint_either) {
        partial = partial5 == ePartial_constraint_partial ? " that are 5\' partial" : " that are 5\' complete";
    }
    else if (partial5 == ePartial_constraint_partial && partial3 == ePartial_constraint_partial) {
        partial = " that are partial on both ends";
    }
    else if (partial5 == ePartial_constraint_complete && partial3 == ePartial_constraint_complete) {
        partial = " that are complete on both ends";
    }
    else if (partial5 == ePartial_constraint_complete && partial3 == ePartial_constraint_partial) {
        partial = " that are 5' complete and 3' partial";
    }
    else if (partial5 == ePartial_constraint_partial && partial3 == ePartial_constraint_complete) {
        partial = " that are 5' partial and 3' complete";
    }
    string location_type;
    if (loc.GetLocation_type() == eLocation_type_constraint_single_interval) {
        location_type = " with single interval";
    }
    else if (loc.GetLocation_type() == eLocation_type_constraint_joined) {
        location_type = " with joined intervals";
    }
    else if (loc.GetLocation_type() == eLocation_type_constraint_ordered) {
        location_type = " with ordered intervals";
    }
    string dist5;
    if (loc.CanGetEnd5()) {
        dist5 = SummarizeEndDistance(loc.GetEnd5());
        dist5 = dist5.empty() ? dist5 : " with 5\' end " + dist5;
    }
    string dist3;
    if (loc.CanGetEnd3()) {
        dist3 = SummarizeEndDistance(loc.GetEnd3());
        dist3 = dist3.empty() ? dist3 : " with 3\' end " + dist3;
    }
    string seq_word;
    if (loc.GetSeq_type() == eSeqtype_constraint_nuc) {
        seq_word = "nucleotide sequences"; 
    }
    else if (loc.GetSeq_type() == eSeqtype_constraint_prot) {
        seq_word = "protein sequences"; 
    }
    string strand;
    if (loc.GetStrand() == eStrand_constraint_plus) {
        strand = " on plus strands"; 
    }
    else if (loc.GetStrand() == eStrand_constraint_minus) {
        strand = " on minus strands"; 
    }
    if (partial.empty() && location_type.empty() && dist5.empty() && dist3.empty() && seq_word.empty() && strand.empty()) {
        return kEmptyStr;
    }
    string str = "only objects";

    if (strand.empty() && !seq_word.empty()) {
        str += " on " + seq_word;
    }
    else if (!strand.empty()) {
        str += strand;
        str += seq_word.empty() ? kEmptyStr : " of " + seq_word;
    }
    str += partial;
    str += location_type;
    str += dist5;
    str += dist3;
    return str;
}


string CSuspect_rule::SummarizeFieldType(const CField_type& vnp) const
{
    string str = "Invalid field type";
    switch (vnp.Which()) {
        case CField_type::e_not_set: return "missing field";
        case CField_type::e_Source_qual:
return "e_Source_qual";
            //return SummarizeSourceQual (vnp.GetSource_qual());
        case CField_type::e_Feature_field:
            {
                const CFeature_field& ff = vnp.GetFeature_field();
                if (ff.GetField().Which() == CFeat_qual_choice::e_not_set) {
                    return "missing field";
                }
                else {
                    string label = ENUM_METHOD_NAME(EMacro_feature_type)()->FindName(ff.GetType(), false);
                    //string label = thisInfo.feattype_name[ff.GetType()];
                    //if (label.empty()) {
                    //    return "Unknown feature";
                    //}
                    //else str = FeatureFieldLabel (label, ff.GetField());
                    return label.empty() ? "Unknown feature" : label;
                }

            }
        case CField_type::e_Cds_gene_prot:
return "e_Cds_gene_prot";
	        //str = thisInfo.cgp_field_name[vnp.GetCds_gene_prot()];
            //if (str.empty()) str = "Invalid CDS-Gene-Prot Field";
        case CField_type::e_Molinfo_field:
return "e_Molinfo_field";
            //str = GetSequenceQualName (vnp.GetMolinfo_field());
            //if (str.empty()) str = "Invalid Sequence Qual Field";
        case CField_type::e_Pub:
return "e_Pub";
            //str = thisInfo.pubfield_label[vnp.GetPub()];
            //if (str.empty()) str = "Invalid field type";
        case CField_type::e_Rna_field:
return "e_Rna_field";
            //str = SummarizeRnaQual (vnp.GetRna_field());
        case CField_type::e_Struc_comment_field:
return "e_Struc_comment_field";
            //str = SummarizeStructuredCommentField (vnp.GetStruc_comment_field());
        case CField_type::e_Dblink:
return "e_Dblink";
            //str = thisInfo.dblink_names[(int)vnp.GetDblink()];
        case CField_type::e_Misc:
return "e_Misc";
            //str = thisInfo.miscfield_names[(int)vnp.GetMisc()];
    }
    return str;
}


string CSuspect_rule::SummarizeFieldConstraint(const CField_constraint& field) const
{
    string summ = SummarizeStringConstraint(field.GetString_constraint());
    string label = SummarizeFieldType(field.GetField());
    return summ.empty() || label.empty() ? kEmptyStr : "where " + label + " " + summ;
}


string CSuspect_rule::SummarizeSourceConstraint(const CSource_constraint& cons) const
{
        return kEmptyStr;
}


string CSuspect_rule::SummarizeConstraint(const CConstraint_choice& choice) const
{
    switch (choice.Which()) {
        case CConstraint_choice::e_String:
            {   string tmp = SummarizeStringConstraint(choice.GetString());
                return tmp.empty() ? kEmptyStr : "where object text " + tmp;
            }
        case CConstraint_choice::e_Location:
            return SummarizeLocationConstraint(choice.GetLocation()) + " [[LOCATION CONSTRAINT]]";
        case CConstraint_choice::e_Source:
            return SummarizeSourceConstraint (choice.GetSource()) + " [[SOURCE CONSTRAINT]]";
        case CConstraint_choice::e_Cdsgeneprot_qual:
            //phrase = SummarizeCDSGeneProtQualConstraint (cons_choice.GetCdsgeneprot_qual());
            return "[[CDS Gene Prot QUAL CONSTRAINT]]";
        case CConstraint_choice::e_Cdsgeneprot_pseudo:
            return "[[CDS Gene Prot PSEUDO CONSTRAINT]]";
            //phrase = SummarizeCDSGeneProtPseudoConstraint (cons_choice.GetCdsgeneprot_pseudo());
        case CConstraint_choice::e_Sequence:
            return "[[SEQUENCE CONSTRAINT]]";
            //phrase = SummarizeSequenceConstraint (cons_choice.GetSequence());
        case CConstraint_choice::e_Pub:
            return "[[PUB CONSTRAINT]]";
            //phrase = SummarizePublicationConstraint (cons_choice.GetPub());
        case CConstraint_choice::e_Field:
            return SummarizeFieldConstraint(choice.GetField());
        case CConstraint_choice::e_Molinfo:
            return "[[MOLINFO CONSTRAINT]]";
            //phrase = SummarizeMolinfoFieldConstraint (cons_choice.GetMolinfo());
        case CConstraint_choice::e_Field_missing:
            return "[[FIELD MISSING CONSTRAINT]]";
            //phrase = SummarizeMissingFieldConstraint (cons_choice.GetField_missing());
        case CConstraint_choice::e_Translation:
            return "[[TRANSLATION CONSTRAINT]]";
            //phrase = SummarizeTranslationConstraint (cons_choice.GetTranslation());
            break;
    }
    return kEmptyStr;
}


string CSuspect_rule::SummarizeConstraintSet(const CConstraint_choice_set& cons) const
{
    string str;
    ITERATE (list<CRef<CConstraint_choice> >, it, cons.Get()) {
        string tmp = SummarizeConstraint(**it);
        str += tmp.empty() || str.empty() ? kEmptyStr : " and ";
        str += tmp;
    }
    return str;
}


string CSuspect_rule::GetRuleTypeName() const
{
    static const char* rule_type[] = {
        "None",
        "Typo",
        "Putative Typo",
        "Quick fix",
        "Organelles not appropriate in prokaryote",
        "Suspicious phrase; should this be nonfunctional?",
        "May contain database identifier more appropriate in note; remove from product name",
        "Remove organism from product name",
        "Possible parsing error or incorrect formatting; remove inappropriate symbols",
        "Implies evolutionary relationship; change to -like protein",
        "Consider adding 'protein' to the end of the product name",
        "Correct the name or use 'hypothetical protein'",
        "Use American spelling",
        "Use short product name instead of descriptive phrase",
        "use protein instead of gene as appropriate"
    };
    return rule_type[GetRule_type()];
}


string CSuspect_rule::SummarizeRule() const
{
    string type = GetRuleTypeName();
    string descr = IsSetDescription() ? GetDescription() : kEmptyStr;
    string find = SummarizeSearchFunc(GetFind());
    string except = CanGetExcept() ? SummarizeSearchFunc(GetExcept()) : kEmptyStr;
    string replace = CanGetReplace() ? SummarizeReplaceRule(GetReplace()) : kEmptyStr;
    string feat_constraint = CanGetFeat_constraint() ? SummarizeConstraintSet(GetFeat_constraint()) : kEmptyStr;

    string out = find;
    if (!except.empty()) out += " but not " + except;
    if (!feat_constraint.empty()) out += ", " + feat_constraint;
    if (!replace.empty()) out += ", " + replace;
    if (!type.empty()) out += " (" + type + ")";
    if (!descr.empty()) out += " Description: " + descr;
    return out;

// debug output
/*
    string out = "Type: " + GetRuleTypeName();
    out += descr.empty() ? kEmptyStr : "\n\t\tDescr: " + descr;
    out += find.empty() ? kEmptyStr : "\n\t\tFind: " + find;
    out += except.empty() ? kEmptyStr : "\n\t\tExcept: " + except;
    out += feat_constraint.empty() ? kEmptyStr : "\n\t\tFeat-Constr: " + feat_constraint;
    out += replace.empty() ? kEmptyStr : "\n\t\tReplace: " + replace;
    return out;
*/
}


END_objects_SCOPE // namespace ncbi::objects::
END_NCBI_SCOPE