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

/// @file GBComment_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBSEQ_GBCOMMENT_BASE_HPP
#define OBJECTS_GBSEQ_GBCOMMENT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>
#include <objects/gbseq/GBCommentParagraph.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBSEQ_EXPORT CGBComment_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGBComment_Base(void);
    // destructor
    virtual ~CGBComment_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TType;
    typedef list< CGBCommentParagraph > TParagraphs;

    // getters
    // setters

    /// optional
    /// typedef string TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    const TType& GetType(void) const;
    void SetType(const TType& value);
    TType& SetType(void);

    /// mandatory
    /// typedef list< CGBCommentParagraph > TParagraphs
    ///  Check whether the Paragraphs data member has been assigned a value.
    bool IsSetParagraphs(void) const;
    /// Check whether it is safe or not to call GetParagraphs method.
    bool CanGetParagraphs(void) const;
    void ResetParagraphs(void);
    const TParagraphs& GetParagraphs(void) const;
    TParagraphs& SetParagraphs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGBComment_Base(const CGBComment_Base&);
    CGBComment_Base& operator=(const CGBComment_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Type;
    list< CGBCommentParagraph > m_Paragraphs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGBComment_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGBComment_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
const CGBComment_Base::TType& CGBComment_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(0);
    }
    return m_Type;
}

inline
void CGBComment_Base::SetType(const CGBComment_Base::TType& value)
{
    m_Type = value;
    m_set_State[0] |= 0x3;
}

inline
CGBComment_Base::TType& CGBComment_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        m_Type = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Type;
}

inline
bool CGBComment_Base::IsSetParagraphs(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGBComment_Base::CanGetParagraphs(void) const
{
    return true;
}

inline
const CGBComment_Base::TParagraphs& CGBComment_Base::GetParagraphs(void) const
{
    return m_Paragraphs;
}

inline
CGBComment_Base::TParagraphs& CGBComment_Base::SetParagraphs(void)
{
    m_set_State[0] |= 0x4;
    return m_Paragraphs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBSEQ_GBCOMMENT_BASE_HPP
