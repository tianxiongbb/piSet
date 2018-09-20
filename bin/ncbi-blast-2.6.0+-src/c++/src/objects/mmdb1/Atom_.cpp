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
 *   'mmdb1.asn'.
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
#include <objects/mmdb1/Atom.hpp>
BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

BEGIN_NAMED_ENUM_IN_INFO("", CAtom_Base::, EElement, false)
{
    SET_ENUM_INTERNAL_NAME("Atom", "element");
    SET_ENUM_MODULE("MMDB-Chemical-graph");
    ADD_ENUM_VALUE("h", eElement_h);
    ADD_ENUM_VALUE("he", eElement_he);
    ADD_ENUM_VALUE("li", eElement_li);
    ADD_ENUM_VALUE("be", eElement_be);
    ADD_ENUM_VALUE("b", eElement_b);
    ADD_ENUM_VALUE("c", eElement_c);
    ADD_ENUM_VALUE("n", eElement_n);
    ADD_ENUM_VALUE("o", eElement_o);
    ADD_ENUM_VALUE("f", eElement_f);
    ADD_ENUM_VALUE("ne", eElement_ne);
    ADD_ENUM_VALUE("na", eElement_na);
    ADD_ENUM_VALUE("mg", eElement_mg);
    ADD_ENUM_VALUE("al", eElement_al);
    ADD_ENUM_VALUE("si", eElement_si);
    ADD_ENUM_VALUE("p", eElement_p);
    ADD_ENUM_VALUE("s", eElement_s);
    ADD_ENUM_VALUE("cl", eElement_cl);
    ADD_ENUM_VALUE("ar", eElement_ar);
    ADD_ENUM_VALUE("k", eElement_k);
    ADD_ENUM_VALUE("ca", eElement_ca);
    ADD_ENUM_VALUE("sc", eElement_sc);
    ADD_ENUM_VALUE("ti", eElement_ti);
    ADD_ENUM_VALUE("v", eElement_v);
    ADD_ENUM_VALUE("cr", eElement_cr);
    ADD_ENUM_VALUE("mn", eElement_mn);
    ADD_ENUM_VALUE("fe", eElement_fe);
    ADD_ENUM_VALUE("co", eElement_co);
    ADD_ENUM_VALUE("ni", eElement_ni);
    ADD_ENUM_VALUE("cu", eElement_cu);
    ADD_ENUM_VALUE("zn", eElement_zn);
    ADD_ENUM_VALUE("ga", eElement_ga);
    ADD_ENUM_VALUE("ge", eElement_ge);
    ADD_ENUM_VALUE("as", eElement_as);
    ADD_ENUM_VALUE("se", eElement_se);
    ADD_ENUM_VALUE("br", eElement_br);
    ADD_ENUM_VALUE("kr", eElement_kr);
    ADD_ENUM_VALUE("rb", eElement_rb);
    ADD_ENUM_VALUE("sr", eElement_sr);
    ADD_ENUM_VALUE("y", eElement_y);
    ADD_ENUM_VALUE("zr", eElement_zr);
    ADD_ENUM_VALUE("nb", eElement_nb);
    ADD_ENUM_VALUE("mo", eElement_mo);
    ADD_ENUM_VALUE("tc", eElement_tc);
    ADD_ENUM_VALUE("ru", eElement_ru);
    ADD_ENUM_VALUE("rh", eElement_rh);
    ADD_ENUM_VALUE("pd", eElement_pd);
    ADD_ENUM_VALUE("ag", eElement_ag);
    ADD_ENUM_VALUE("cd", eElement_cd);
    ADD_ENUM_VALUE("in", eElement_in);
    ADD_ENUM_VALUE("sn", eElement_sn);
    ADD_ENUM_VALUE("sb", eElement_sb);
    ADD_ENUM_VALUE("te", eElement_te);
    ADD_ENUM_VALUE("i", eElement_i);
    ADD_ENUM_VALUE("xe", eElement_xe);
    ADD_ENUM_VALUE("cs", eElement_cs);
    ADD_ENUM_VALUE("ba", eElement_ba);
    ADD_ENUM_VALUE("la", eElement_la);
    ADD_ENUM_VALUE("ce", eElement_ce);
    ADD_ENUM_VALUE("pr", eElement_pr);
    ADD_ENUM_VALUE("nd", eElement_nd);
    ADD_ENUM_VALUE("pm", eElement_pm);
    ADD_ENUM_VALUE("sm", eElement_sm);
    ADD_ENUM_VALUE("eu", eElement_eu);
    ADD_ENUM_VALUE("gd", eElement_gd);
    ADD_ENUM_VALUE("tb", eElement_tb);
    ADD_ENUM_VALUE("dy", eElement_dy);
    ADD_ENUM_VALUE("ho", eElement_ho);
    ADD_ENUM_VALUE("er", eElement_er);
    ADD_ENUM_VALUE("tm", eElement_tm);
    ADD_ENUM_VALUE("yb", eElement_yb);
    ADD_ENUM_VALUE("lu", eElement_lu);
    ADD_ENUM_VALUE("hf", eElement_hf);
    ADD_ENUM_VALUE("ta", eElement_ta);
    ADD_ENUM_VALUE("w", eElement_w);
    ADD_ENUM_VALUE("re", eElement_re);
    ADD_ENUM_VALUE("os", eElement_os);
    ADD_ENUM_VALUE("ir", eElement_ir);
    ADD_ENUM_VALUE("pt", eElement_pt);
    ADD_ENUM_VALUE("au", eElement_au);
    ADD_ENUM_VALUE("hg", eElement_hg);
    ADD_ENUM_VALUE("tl", eElement_tl);
    ADD_ENUM_VALUE("pb", eElement_pb);
    ADD_ENUM_VALUE("bi", eElement_bi);
    ADD_ENUM_VALUE("po", eElement_po);
    ADD_ENUM_VALUE("at", eElement_at);
    ADD_ENUM_VALUE("rn", eElement_rn);
    ADD_ENUM_VALUE("fr", eElement_fr);
    ADD_ENUM_VALUE("ra", eElement_ra);
    ADD_ENUM_VALUE("ac", eElement_ac);
    ADD_ENUM_VALUE("th", eElement_th);
    ADD_ENUM_VALUE("pa", eElement_pa);
    ADD_ENUM_VALUE("u", eElement_u);
    ADD_ENUM_VALUE("np", eElement_np);
    ADD_ENUM_VALUE("pu", eElement_pu);
    ADD_ENUM_VALUE("am", eElement_am);
    ADD_ENUM_VALUE("cm", eElement_cm);
    ADD_ENUM_VALUE("bk", eElement_bk);
    ADD_ENUM_VALUE("cf", eElement_cf);
    ADD_ENUM_VALUE("es", eElement_es);
    ADD_ENUM_VALUE("fm", eElement_fm);
    ADD_ENUM_VALUE("md", eElement_md);
    ADD_ENUM_VALUE("no", eElement_no);
    ADD_ENUM_VALUE("lr", eElement_lr);
    ADD_ENUM_VALUE("other", eElement_other);
    ADD_ENUM_VALUE("unknown", eElement_unknown);
}
END_ENUM_INFO

BEGIN_NAMED_ENUM_IN_INFO("", CAtom_Base::, EIonizable_proton, false)
{
    SET_ENUM_INTERNAL_NAME("Atom", "ionizable-proton");
    SET_ENUM_MODULE("MMDB-Chemical-graph");
    ADD_ENUM_VALUE("true", eIonizable_proton_true);
    ADD_ENUM_VALUE("false", eIonizable_proton_false);
    ADD_ENUM_VALUE("unknown", eIonizable_proton_unknown);
}
END_ENUM_INFO

void CAtom_Base::ResetName(void)
{
    m_Name.erase();
    m_set_State[0] &= ~0xc;
}

void CAtom_Base::ResetIupac_code(void)
{
    m_Iupac_code.clear();
    m_set_State[0] &= ~0x30;
}

void CAtom_Base::Reset(void)
{
    ResetId();
    ResetName();
    ResetIupac_code();
    ResetElement();
    ResetIonizable_proton();
}

BEGIN_NAMED_BASE_CLASS_INFO("Atom", CAtom)
{
    SET_CLASS_MODULE("MMDB-Chemical-graph");
    ADD_NAMED_MEMBER("id", m_Id, CLASS, (CAtom_id))->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_STD_MEMBER("name", m_Name)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_MEMBER("iupac-code", m_Iupac_code, STL_list, (STD, (string)))->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    ADD_NAMED_ENUM_MEMBER("element", m_Element, EElement)->SetSetFlag(MEMBER_PTR(m_set_State[0]));
    ADD_NAMED_ENUM_MEMBER("ionizable-proton", m_Ionizable_proton, EIonizable_proton)->SetSetFlag(MEMBER_PTR(m_set_State[0]))->SetOptional();
    info->RandomOrder();
    info->CodeVersion(21600);
}
END_CLASS_INFO

// constructor
CAtom_Base::CAtom_Base(void)
    : m_Id(CAtom_id(0)), m_Element((EElement)(0)), m_Ionizable_proton((EIonizable_proton)(0))
{
    memset(m_set_State,0,sizeof(m_set_State));
}

// destructor
CAtom_Base::~CAtom_Base(void)
{
}



END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE
