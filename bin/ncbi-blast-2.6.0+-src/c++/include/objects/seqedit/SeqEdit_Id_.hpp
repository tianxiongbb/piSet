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

/// @file SeqEdit_Id_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqedit.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQEDIT_SEQEDIT_ID_BASE_HPP
#define OBJECTS_SEQEDIT_SEQEDIT_ID_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSeq_id;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQEDIT_EXPORT CSeqEdit_Id_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSeqEdit_Id_Base(void);
    // destructor
    virtual ~CSeqEdit_Id_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,   ///< No variant selected
        e_Bioseq_id,
        e_Bioseqset_id,
        e_Unique_num
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 4 ///< == e_Unique_num+1
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
    typedef CSeq_id TBioseq_id;
    typedef int TBioseqset_id;
    typedef int TUnique_num;

    // getters
    // setters

    // typedef CSeq_id TBioseq_id
    bool IsBioseq_id(void) const;
    const TBioseq_id& GetBioseq_id(void) const;
    TBioseq_id& SetBioseq_id(void);
    void SetBioseq_id(TBioseq_id& value);

    // typedef int TBioseqset_id
    bool IsBioseqset_id(void) const;
    TBioseqset_id GetBioseqset_id(void) const;
    TBioseqset_id& SetBioseqset_id(void);
    void SetBioseqset_id(TBioseqset_id value);

    // typedef int TUnique_num
    bool IsUnique_num(void) const;
    TUnique_num GetUnique_num(void) const;
    TUnique_num& SetUnique_num(void);
    void SetUnique_num(TUnique_num value);


private:
    // copy constructor and assignment operator
    CSeqEdit_Id_Base(const CSeqEdit_Id_Base& );
    CSeqEdit_Id_Base& operator=(const CSeqEdit_Id_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        TBioseqset_id m_Bioseqset_id;
        TUnique_num m_Unique_num;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CSeqEdit_Id_Base::E_Choice CSeqEdit_Id_Base::Which(void) const
{
    return m_choice;
}

inline
void CSeqEdit_Id_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CSeqEdit_Id_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CSeqEdit_Id_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CSeqEdit_Id_Base::IsBioseq_id(void) const
{
    return m_choice == e_Bioseq_id;
}

inline
bool CSeqEdit_Id_Base::IsBioseqset_id(void) const
{
    return m_choice == e_Bioseqset_id;
}

inline
CSeqEdit_Id_Base::TBioseqset_id CSeqEdit_Id_Base::GetBioseqset_id(void) const
{
    CheckSelected(e_Bioseqset_id);
    return m_Bioseqset_id;
}

inline
CSeqEdit_Id_Base::TBioseqset_id& CSeqEdit_Id_Base::SetBioseqset_id(void)
{
    Select(e_Bioseqset_id, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Bioseqset_id;
}

inline
void CSeqEdit_Id_Base::SetBioseqset_id(CSeqEdit_Id_Base::TBioseqset_id value)
{
    Select(e_Bioseqset_id, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Bioseqset_id = value;
}

inline
bool CSeqEdit_Id_Base::IsUnique_num(void) const
{
    return m_choice == e_Unique_num;
}

inline
CSeqEdit_Id_Base::TUnique_num CSeqEdit_Id_Base::GetUnique_num(void) const
{
    CheckSelected(e_Unique_num);
    return m_Unique_num;
}

inline
CSeqEdit_Id_Base::TUnique_num& CSeqEdit_Id_Base::SetUnique_num(void)
{
    Select(e_Unique_num, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Unique_num;
}

inline
void CSeqEdit_Id_Base::SetUnique_num(CSeqEdit_Id_Base::TUnique_num value)
{
    Select(e_Unique_num, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Unique_num = value;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQEDIT_SEQEDIT_ID_BASE_HPP