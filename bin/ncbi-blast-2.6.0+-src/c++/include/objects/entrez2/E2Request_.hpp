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
 */

/// @file E2Request_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'entrez2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ENTREZ2_E2REQUEST_BASE_HPP
#define OBJECTS_ENTREZ2_E2REQUEST_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CEntrez2_eval_boolean;
class CEntrez2_get_links;
class CEntrez2_hier_query;
class CEntrez2_id;
class CEntrez2_id_list;
class CEntrez2_term_pos;
class CEntrez2_term_query;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// request types
class NCBI_ENTREZ2_EXPORT CE2Request_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CE2Request_Base(void);
    // destructor
    virtual ~CE2Request_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,         ///< No variant selected
        e_Get_info,            ///< ask for info block
        e_Eval_boolean,        ///< Boolean lookup
        e_Get_docsum,          ///< get the DocSums
        e_Get_term_pos,        ///< get position in term list
        e_Get_term_list,       ///< get Term list by position
        e_Get_term_hierarchy,  ///< get a hierarchy from a term
        e_Get_links,           ///< get specific links from a UID list
        e_Get_linked,          ///< get subset of UID list which has links
        e_Get_link_counts      ///< get all links from one UID
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 10 ///< == e_Get_link_counts+1
    };

    /// Reset the whole object
    virtual void Reset(void);

    /// Reset the selection (set it to e_not_set).
    virtual void ResetSelection(void);

    /// Which variant is currently selected.
    E_Choice Which(void) const;

    /// Verify selection, throw exception if it differs from the expected.
    void CheckSelected(E_Choice index) const;

    /// Throw 'InvalidSelection' exception.
    NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;

    /// Retrieve selection name (for diagnostic purposes).
    static string SelectionName(E_Choice index);

    /// Select the requested variant if needed.
    void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
    /// Select the requested variant if needed,
    /// allocating CObject variants from memory pool.
    void Select(E_Choice index,
                EResetVariant reset,
                CObjectMemoryPool* pool);

    // types
    typedef CEntrez2_eval_boolean TEval_boolean;
    typedef CEntrez2_id_list TGet_docsum;
    typedef CEntrez2_term_query TGet_term_pos;
    typedef CEntrez2_term_pos TGet_term_list;
    typedef CEntrez2_hier_query TGet_term_hierarchy;
    typedef CEntrez2_get_links TGet_links;
    typedef CEntrez2_get_links TGet_linked;
    typedef CEntrez2_id TGet_link_counts;

    // getters
    // setters


    bool IsGet_info(void) const;
    void SetGet_info(void);

    // typedef CEntrez2_eval_boolean TEval_boolean
    bool IsEval_boolean(void) const;
    const TEval_boolean& GetEval_boolean(void) const;
    TEval_boolean& SetEval_boolean(void);
    void SetEval_boolean(TEval_boolean& value);

    // typedef CEntrez2_id_list TGet_docsum
    bool IsGet_docsum(void) const;
    const TGet_docsum& GetGet_docsum(void) const;
    TGet_docsum& SetGet_docsum(void);
    void SetGet_docsum(TGet_docsum& value);

    // typedef CEntrez2_term_query TGet_term_pos
    bool IsGet_term_pos(void) const;
    const TGet_term_pos& GetGet_term_pos(void) const;
    TGet_term_pos& SetGet_term_pos(void);
    void SetGet_term_pos(TGet_term_pos& value);

    // typedef CEntrez2_term_pos TGet_term_list
    bool IsGet_term_list(void) const;
    const TGet_term_list& GetGet_term_list(void) const;
    TGet_term_list& SetGet_term_list(void);
    void SetGet_term_list(TGet_term_list& value);

    // typedef CEntrez2_hier_query TGet_term_hierarchy
    bool IsGet_term_hierarchy(void) const;
    const TGet_term_hierarchy& GetGet_term_hierarchy(void) const;
    TGet_term_hierarchy& SetGet_term_hierarchy(void);
    void SetGet_term_hierarchy(TGet_term_hierarchy& value);

    // typedef CEntrez2_get_links TGet_links
    bool IsGet_links(void) const;
    const TGet_links& GetGet_links(void) const;
    TGet_links& SetGet_links(void);
    void SetGet_links(TGet_links& value);

    // typedef CEntrez2_get_links TGet_linked
    bool IsGet_linked(void) const;
    const TGet_linked& GetGet_linked(void) const;
    TGet_linked& SetGet_linked(void);
    void SetGet_linked(TGet_linked& value);

    // typedef CEntrez2_id TGet_link_counts
    bool IsGet_link_counts(void) const;
    const TGet_link_counts& GetGet_link_counts(void) const;
    TGet_link_counts& SetGet_link_counts(void);
    void SetGet_link_counts(TGet_link_counts& value);


private:
    // copy constructor and assignment operator
    CE2Request_Base(const CE2Request_Base& );
    CE2Request_Base& operator=(const CE2Request_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CE2Request_Base::E_Choice CE2Request_Base::Which(void) const
{
    return m_choice;
}

inline
void CE2Request_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CE2Request_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CE2Request_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CE2Request_Base::IsGet_info(void) const
{
    return m_choice == e_Get_info;
}

inline
void CE2Request_Base::SetGet_info(void)
{
    Select(e_Get_info, NCBI_NS_NCBI::eDoNotResetVariant);
}

inline
bool CE2Request_Base::IsEval_boolean(void) const
{
    return m_choice == e_Eval_boolean;
}

inline
bool CE2Request_Base::IsGet_docsum(void) const
{
    return m_choice == e_Get_docsum;
}

inline
bool CE2Request_Base::IsGet_term_pos(void) const
{
    return m_choice == e_Get_term_pos;
}

inline
bool CE2Request_Base::IsGet_term_list(void) const
{
    return m_choice == e_Get_term_list;
}

inline
bool CE2Request_Base::IsGet_term_hierarchy(void) const
{
    return m_choice == e_Get_term_hierarchy;
}

inline
bool CE2Request_Base::IsGet_links(void) const
{
    return m_choice == e_Get_links;
}

inline
bool CE2Request_Base::IsGet_linked(void) const
{
    return m_choice == e_Get_linked;
}

inline
bool CE2Request_Base::IsGet_link_counts(void) const
{
    return m_choice == e_Get_link_counts;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ENTREZ2_E2REQUEST_BASE_HPP
