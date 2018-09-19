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

/// @file SeqEdit_Cmd_RemoveSeqEntry_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqedit.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQEDIT_SEQEDIT_CMD_REMOVESEQENTRY_BASE_HPP
#define OBJECTS_SEQEDIT_SEQEDIT_CMD_REMOVESEQENTRY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CSeqEdit_Id;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Remove a seq entry from bioseq-set
class NCBI_SEQEDIT_EXPORT CSeqEdit_Cmd_RemoveSeqEntry_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSeqEdit_Cmd_RemoveSeqEntry_Base(void);
    // destructor
    virtual ~CSeqEdit_Cmd_RemoveSeqEntry_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CSeqEdit_Id TId;
    typedef CSeqEdit_Id TEntry_id;

    // getters
    // setters

    /// Bioseq_set id
    /// mandatory
    /// typedef CSeqEdit_Id TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    void SetId(TId& value);
    TId& SetId(void);

    /// Seq_entry for deletion
    /// mandatory
    /// typedef CSeqEdit_Id TEntry_id
    ///  Check whether the Entry_id data member has been assigned a value.
    bool IsSetEntry_id(void) const;
    /// Check whether it is safe or not to call GetEntry_id method.
    bool CanGetEntry_id(void) const;
    void ResetEntry_id(void);
    const TEntry_id& GetEntry_id(void) const;
    void SetEntry_id(TEntry_id& value);
    TEntry_id& SetEntry_id(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSeqEdit_Cmd_RemoveSeqEntry_Base(const CSeqEdit_Cmd_RemoveSeqEntry_Base&);
    CSeqEdit_Cmd_RemoveSeqEntry_Base& operator=(const CSeqEdit_Cmd_RemoveSeqEntry_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TId > m_Id;
    CRef< TEntry_id > m_Entry_id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSeqEdit_Cmd_RemoveSeqEntry_Base::IsSetId(void) const
{
    return m_Id.NotEmpty();
}

inline
bool CSeqEdit_Cmd_RemoveSeqEntry_Base::CanGetId(void) const
{
    return true;
}

inline
const CSeqEdit_Cmd_RemoveSeqEntry_Base::TId& CSeqEdit_Cmd_RemoveSeqEntry_Base::GetId(void) const
{
    if ( !m_Id ) {
        const_cast<CSeqEdit_Cmd_RemoveSeqEntry_Base*>(this)->ResetId();
    }
    return (*m_Id);
}

inline
CSeqEdit_Cmd_RemoveSeqEntry_Base::TId& CSeqEdit_Cmd_RemoveSeqEntry_Base::SetId(void)
{
    if ( !m_Id ) {
        ResetId();
    }
    return (*m_Id);
}

inline
bool CSeqEdit_Cmd_RemoveSeqEntry_Base::IsSetEntry_id(void) const
{
    return m_Entry_id.NotEmpty();
}

inline
bool CSeqEdit_Cmd_RemoveSeqEntry_Base::CanGetEntry_id(void) const
{
    return true;
}

inline
const CSeqEdit_Cmd_RemoveSeqEntry_Base::TEntry_id& CSeqEdit_Cmd_RemoveSeqEntry_Base::GetEntry_id(void) const
{
    if ( !m_Entry_id ) {
        const_cast<CSeqEdit_Cmd_RemoveSeqEntry_Base*>(this)->ResetEntry_id();
    }
    return (*m_Entry_id);
}

inline
CSeqEdit_Cmd_RemoveSeqEntry_Base::TEntry_id& CSeqEdit_Cmd_RemoveSeqEntry_Base::SetEntry_id(void)
{
    if ( !m_Entry_id ) {
        ResetEntry_id();
    }
    return (*m_Entry_id);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQEDIT_SEQEDIT_CMD_REMOVESEQENTRY_BASE_HPP
