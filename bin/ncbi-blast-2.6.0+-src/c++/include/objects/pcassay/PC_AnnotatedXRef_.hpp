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

/// @file PC_AnnotatedXRef_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pcassay.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_PCASSAY_PC_ANNOTATEDXREF_BASE_HPP
#define OBJECTS_PCASSAY_PC_ANNOTATEDXREF_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CPC_XRefData;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Annotated Cross-Reference (XRef) Information to allow the XRef to be qualified, as to its meaning or context
class NCBI_PCASSAY_EXPORT CPC_AnnotatedXRef_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPC_AnnotatedXRef_Base(void);
    // destructor
    virtual ~CPC_AnnotatedXRef_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum EType {
        eType_pcit  = 1,  ///< primary PMID/citation directly associated with the current assay data 
        eType_pgene = 2  ///< gene encoding the protein assay target
    };
    
    /// Access to EType's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EType)(void);
    
    // types
    typedef CPC_XRefData TXref;
    typedef string TComment;
    typedef int TType;

    // getters
    // setters

    /// Cross-Reference Information
    /// mandatory
    /// typedef CPC_XRefData TXref
    ///  Check whether the Xref data member has been assigned a value.
    bool IsSetXref(void) const;
    /// Check whether it is safe or not to call GetXref method.
    bool CanGetXref(void) const;
    void ResetXref(void);
    const TXref& GetXref(void) const;
    void SetXref(TXref& value);
    TXref& SetXref(void);

    /// Annotation qualifier describing Cross-Reference meaning
    /// optional
    /// typedef string TComment
    ///  Check whether the Comment data member has been assigned a value.
    bool IsSetComment(void) const;
    /// Check whether it is safe or not to call GetComment method.
    bool CanGetComment(void) const;
    void ResetComment(void);
    const TComment& GetComment(void) const;
    void SetComment(const TComment& value);
    TComment& SetComment(void);

    /// optional
    /// typedef int TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    TType GetType(void) const;
    void SetType(TType value);
    TType& SetType(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPC_AnnotatedXRef_Base(const CPC_AnnotatedXRef_Base&);
    CPC_AnnotatedXRef_Base& operator=(const CPC_AnnotatedXRef_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TXref > m_Xref;
    string m_Comment;
    int m_Type;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPC_AnnotatedXRef_Base::IsSetXref(void) const
{
    return m_Xref.NotEmpty();
}

inline
bool CPC_AnnotatedXRef_Base::CanGetXref(void) const
{
    return true;
}

inline
const CPC_AnnotatedXRef_Base::TXref& CPC_AnnotatedXRef_Base::GetXref(void) const
{
    if ( !m_Xref ) {
        const_cast<CPC_AnnotatedXRef_Base*>(this)->ResetXref();
    }
    return (*m_Xref);
}

inline
CPC_AnnotatedXRef_Base::TXref& CPC_AnnotatedXRef_Base::SetXref(void)
{
    if ( !m_Xref ) {
        ResetXref();
    }
    return (*m_Xref);
}

inline
bool CPC_AnnotatedXRef_Base::IsSetComment(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CPC_AnnotatedXRef_Base::CanGetComment(void) const
{
    return IsSetComment();
}

inline
const CPC_AnnotatedXRef_Base::TComment& CPC_AnnotatedXRef_Base::GetComment(void) const
{
    if (!CanGetComment()) {
        ThrowUnassigned(1);
    }
    return m_Comment;
}

inline
void CPC_AnnotatedXRef_Base::SetComment(const CPC_AnnotatedXRef_Base::TComment& value)
{
    m_Comment = value;
    m_set_State[0] |= 0xc;
}

inline
CPC_AnnotatedXRef_Base::TComment& CPC_AnnotatedXRef_Base::SetComment(void)
{
#ifdef _DEBUG
    if (!IsSetComment()) {
        m_Comment = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Comment;
}

inline
bool CPC_AnnotatedXRef_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CPC_AnnotatedXRef_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
void CPC_AnnotatedXRef_Base::ResetType(void)
{
    m_Type = (EType)(0);
    m_set_State[0] &= ~0x30;
}

inline
CPC_AnnotatedXRef_Base::TType CPC_AnnotatedXRef_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(2);
    }
    return m_Type;
}

inline
void CPC_AnnotatedXRef_Base::SetType(CPC_AnnotatedXRef_Base::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0x30;
}

inline
CPC_AnnotatedXRef_Base::TType& CPC_AnnotatedXRef_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Type;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_PCASSAY_PC_ANNOTATEDXREF_BASE_HPP
